#!encoding=utf-8

import traceback
import locale
import json
import sys
import time
import uuid
from pprint import pprint

sys.path.append("/home/bjliuchang5/datacenter/common/interface/gen-py")

from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol

from rec.RankingService import *
from rec.ttypes import UIRequest
from rec.ttypes import PageRequest
from rec.ttypes import AbTest
from rec.ttypes import AbTestProfile
from rec.ttypes import RankingServiceResponse
from rec import RankingService

def Error(msg):
    """ Print message to stderr."""
    sys.stderr.write("%s\n" %(msg))
    traceback.print_exc()
    logging.fatal(traceback.format_exc())
    logging.warning(msg)

class RankRequestClient:
    def __init__(self, host, port):
        self.host = host
        self.port = port
        self.client = None

    def InitialClient(self):
        try:
            Socket = TSocket.TSocket(self.host, self.port)
            transport = TTransport.TFramedTransport(Socket)
            protocol = TBinaryProtocol.TBinaryProtocol(transport)
            rank_client = RankingService.Client(protocol)
            transport.open()
            self.client = rank_client
            return True
        except Exception, e:
            Error(e)
            print("InitialClient Failed from %s:%s" %(self.host ,self.port))
            return False

    def Search(self, ui_req):
        if None != self.client:
            rank_response = self.client.search(ui_req)
            return rank_response
        else:
            print "rank_client Not Initialized!"
            raise Exception("RankClient_Not_Initialized, ip=%s port=%s" 
                    %(self.host, self.port))
            return None

class PageRequestBuilder:
    def __init__(self):
        self.page_request = None

    @staticmethod
    def BuildRequest():
        page_req = PageRequest()
        page_req.page_id = "toutiao"
        page_req.page_type = PAGE_TYPE.CHANNEL
        page_req.fresh_num = 10
        page_req.offset = 1
        return page_req
        # page_req.refer_type = None
        # page_req.refer = None
        # page_req.url = None
        # page_req.url_refer = None
        # page_req.open = None
        # page_req.open_path = None
        # page_req.location_source = None
        # page_req.query_id = None
        # page_req.query_text = None
        # page_req.search_time = None
        # page_req.last_doc = None

class RequestBuilder:
    """ 请求中用户信息
     struct UserRequest {
         1:optional UID_TYPE uid_type
         2:optional string uid
         3:optional Device device
         4:optional Network network
         5:optional Gps gps
         6:optional App app                  // 新闻客户端app相关信息
         7:optional Location location        // 废弃
         8:optional string user_source       // 用户来源，区分新闻客户端，第三方
     }"""
    def __init__(self):
        self.user_request = UserRequest

    def BuildUIRequest(self):
        ui_request = UIRequest()
        ui_request.abtest_profile = self.BuildAbTestProfile()
        ui_request.search_type = SEARCH_TYPE.MOBILE_RECOMMEND
        ui_request.sid = uuid.uuid1().hex
        ui_request.req_num = 10
        ui_request.page_request = PageRequestBuilder.BuildRequest()
        ui_request.user_request = self.BuildUserRequest()
        ui_request.timestamp = time.time()
        ui_request.channel_type = CHANNEL_TYPE.HEADLINE
        return ui_request

    def BuildUserRequest(self):
        user_req = UserRequest()
        user_req.uid = "m13811533972@163" # m18612295510@163
        user_req.uid_type = UID_TYPE.DEVICE_ID
        user_req.gps = self.BuildGpsInfo(GPS_TYPE.WGS84, 29.11, 106.30)
        device_uuid = '41CAC8DD-F3B5-4283-9DDF-4A11FEA952F9'
        user_req.device = self.BuildDeviceInfo(DEVICE_TYPE.MOBILE, device_uuid, OS_TYPE.IOS)
        return user_req

    def BuildDeviceInfo(self, device_type, device_uuid, os_type):
        device = Device()
        device.device_type = device_type
        device.os_type = os_type
        device_id = DeviceID()
        device_id.uuid = device_uuid
        device.device_id = device_id
        return device

    def BuildGpsInfo(self, gps_type, lat, lng):
        gps = Gps()
        gps.gps_type = gps_type
        gps.latitude = lat
        gps.longitude = lng
        return gps

    def BuildAbTestProfile(self):
        abtest = AbTest()
        abtest.exp_id=267
        abtest.exp_name="B10023"
        abtest.numbers = ["B10023","B10012"]
        abtest_vec = [abtest]
        abtests = {}
        abtests[ABTEST_MODULE.RANK] = abtest_vec;
        abtest_profile = AbTestProfile()
        abtest_profile.abtests = abtests
        return abtest_profile
 

def PrintKeyValueObject(obj):
    for key in obj:
        if key:
            print("%s : %s" %(k, obj[value]))


def PrintRankDocInfo(doc_in_rank):
    print "\n%s" %("*"*16)
    print ("* ResponseInfo *")
    print "%s" %("*"*16)
    doc = doc_in_rank
    kItemInfoFields = {'url', 'list_title', 'original_title', 'desc'}
    PrintKvItemInfo(doc.item_info, 'ItemInfo', kItemInfoFields)

    kHeadDocInfoFields = {'has_head', 'has_ad'}
    PrintKvItemInfo(doc.head_doc_info, 'HeadDocInfo', kHeadDocInfoFields)

    kSpecialFields = {'special_id', 'special_tip', 'special_logo'}
    PrintKvItemInfo(doc.special_info, 'SpecialInfo', kSpecialFields)
    print "%s" %("-"*50)


def PrintKvItemInfo(item_info, desc, fields, decorate_char='-'):
    if decorate_char:
        print "%s" %(decorate_char*50)
    else:
        print "%s" %("-"*50)
    print(desc)
    if item_info:
        kv_type_item = vars(item_info)
        for field in fields:
            print("%20s: %-20s" %(field, kv_type_item[field]))
    else:
        print('[%s] is None' %(desc))


def PrintHeadDocInfo(head_doc_info):
    print(head_doc_info)

if __name__ == "__main__":
    # print locale.getdefaultlocale()
    #rank_client = RankRequestClient('10.170.164.73', int(8106))
    rank_client = RankRequestClient('10.160.247.71', int(8106))
    if not rank_client.InitialClient():
        print("InitialClient FAILED!")
        sys.exit(-1)

    request_builder = RequestBuilder()
    ui_req = request_builder.BuildUIRequest()
    print ui_req
    PrintKvItemInfo(ui_req, 'UI_REQUEST', {'sid', 'search_type', 'user_request'}, '~'*2)
    rank_res = rank_client.Search(ui_req)
    if None != rank_res:
        # print rank_res
        print("error_code: %-12s" %rank_res.err_code)
        print("msg:        %-12s" %rank_res.msg)
        print("total:      %-12s" %rank_res.total)
        kNumPrintDoc = 0
        if None != rank_res.doc_list:
            print("RankItem:   %-12s" %len(rank_res.doc_list))
            kNumPrintDoc = len(rank_res.doc_list)
        for i in range(0, kNumPrintDoc):
            rank_doc_item = rank_res.doc_list[i]
#        print rank_doc_item
            PrintRankDocInfo(rank_doc_item)
    else:
        print "Response is None!"


# # kv_type_item = vars(doc_item)
# # print kv_type_item
# for field in kv_type_item:
#     if field and kv_type_item[field]:
#         print("%s : %s" %(field, kv_type_item[field]))
#         PrintKeyValueObject(kv_type_item[field])
