#!encoding=utf-8

import os
import sys
import uuid
import ctypes

import traceback
import locale
import sys
import time
import uuid
from pprint import pprint

sys.path.append("../../datacenter/common/interface/gen-py")

from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol

from rec import UserProfileService
from rec.RankingService import *
from rec.ttypes import UIRequest
from rec.ttypes import PageRequest
from rec.ttypes import AbTest
from rec.ttypes import AbTestProfile
from rec.ttypes import RankingServiceResponse
from rec import RankingService

print "hello world"
print "你好"

def Error(msg):
    """ Print message to stderr."""
    sys.stderr.write("%s\n" %(msg))
    traceback.print_exc()
    logging.fatal(traceback.format_exc())
    logging.warning(msg)

class RequestClient:
    def __init__(self, host, port):
        self.host = host
        self.port = port
        self.client = None

    def InitClient(self):
        try:
            socket = TSocket.TSocket(self.host, self.port)
            transport = TTransport.TFramedTransport(socket)
            protocol = TBinaryProtocol.TBinaryProtocol(transport)
            client = UserProfileService.Client(protocol)
            transport.open()
            self.client = client
            return True
        except Exception, e:
            Error(e)
            print ("InitClient failed from %s:%s" %(self.host, self.port))
            return False

    def Search(self, ui_req):
        if None != self.client:
            response = self.client.search(ui_req)
            return response
        else:
            print "client has not been initialized!"
            return None

class RequestBuilder:
    """struct UIRequest {
        1:optional SEARCH_TYPE search_type
        2:optional string sid                //检索id
        3:optional i32 req_num               //请求item条数 @size@ 客户端请求条数
        4:optional UserRequest user_request
        5:optional PageRequest page_request
        6:optional i64 timestamp
        7:optional string session_id        //会话id
        8:optional AbTestProfile abtest_profile

        // 配置用,TODO(bjzhangdongyue) 新版会去掉这个
        1000: optional CHANNEL_TYPE channel_type;  
    }"""
    def __init__(self):
        self.user_request = UserRequest

#    def BuildUserProfileServiceRequest(self):
#        self.ui_request = self.BuildUIRequest()

    def BuildUserProfileServiceRequest(self):
        ui_request = UIRequest()
        ui_request.search_type = SEARCH_TYPE.PUSH_USER
        ui_request.sid = uuid.uuid1().hex
        ui_request.user_request = self.BuildUserRequest()
        ui_request.page_request = PageRequestBuilder.BuildRequest()
        ui_request.abtest_profile = self.BuildAbTestProfile()
        user_profile_request = UserProfileServiceRequest()
        user_profile_request.ui_request = ui_request
        return user_profile_request

    def BuildUserRequest(self):
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
        user_req = UserRequest()
        #user_req.uid_type = UID_TYPE.PASSPORT
        user_req.uid_type = UID_TYPE.PUSH_ID
        #user_req.uid = "ogm9zs6uj_81f426c3f2a21f3b6c106c0744bb6217@wx.163.com"
        user_req.uid = "uu3hx4gut53c0ffd7218a9014b1beac06b96c3e609@meizu.163.com"
        return user_req

    def BuildAbTestProfile(self):
        abtest = AbTest()
        abtest.exp_id = 268
        abtest.exp_name = "realtimeprofile_test"
        abtest_list = []
        abtest_list.append(abtest)
        abtests = {ABTEST_MODULE.UFS : abtest_list}
        abtest_profile = AbTestProfile()
        abtest_profile.abtests = abtests
        return abtest_profile

class PageRequestBuilder:
    def __init__(self):
        self.page_request = None

    @staticmethod
    def BuildRequest():
        page_req = PageRequest()
        page_req.page_type = PAGE_TYPE.CHANNEL
        page_req.page_id = 0x10
        page_req.push_type = 0x10
        return page_req

def PrintKvItemInfo(item_info, desc, fields, decorate_char='-'):
    if decorate_char:
        print "%s" %(decorate_char*50)
    else:
        print "%s" %("-"*50)
    print (desc)
    if item_info:
        kv_type_item = vars(item_info)
        for field in fields:
            print("%20s: %-20s" %(field, kv_type_item[field]))
    else:
        print("[%s] is NONE!!" %(desc))

if __name__ == '__main__':
    print "start connect"
#client = RequestClient("10.160.247.71",8019)
    client = RequestClient("127.0.0.1",8019)
    print "host ip : " + client.host
    print "host port : %d"  %(client.port)
    if not client.InitClient():
        print "connect failed!"
        sys.exit(-1)

    print "connect!!!!"

    request_builder = RequestBuilder()
    request = request_builder.BuildUserProfileServiceRequest()

    PrintKvItemInfo(request.ui_request, "UI_REQUEST", {'sid', 'search_type', 'user_request'})

    result = client.Search(request)
    if None != result:
        print "has result"
        print("error_code: %-12s" %result.err_code)
        print("msg: %-12s" %result.msg)
#        print result
    else:
        print "result is NONE"
        page_req.page_id = 0x10
