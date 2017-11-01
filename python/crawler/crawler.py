import requests
#url = "https://item.jd.com/1150557.htmls"
def search(keyword):
    try:
        #url = "https://www.amazon.cn/gp/product/B00DNX7Y3W/ref=br_bsl_pdt-1/462-6395513-9052449?pf_rd_m=A1AJ19PSB66TGU&pf_rd_s=desktop-bestsellers-1&pf_rd_r=STM9SP8JRWYH819X4KYE&pf_rd_r=STM9SP8JRWYH819X4KYE&pf_rd_t=36701&pf_rd_p=29c4df77-45a7-428e-85f2-ade9026644f5&pf_rd_p=29c4df77-45a7-428e-85f2-ade9026644f5&pf_rd_i=desktop"
        url = "http://www.baidu.com/s"
        #kv = {'user-agent':'Mozilla/5.0'}
        #r = requests.get(url, headers=kv)
        kv = {'wd':'Python'}
        r = requests.get(url, params = kv)
        print r.request.headers
        print r.request.url
        print r.status_code
        r.encoding = r.apparent_encoding
        print len(r.text)
        #print r.text
    except:
        print "error!"

def searchbaidu(keyword):
    try:
        url = "http://www.baidu.com/s"
        kv = {'wd' : keyword}
        r = requests.get(url, params = kv)
        print ("the request headers is %s" % r.request.headers)
        print ("the request url is %s" % r.request.url)
        r.encoding = r.apparent_encoding
        print ("the len of result is %d" % len(r.text))
        print r.text
    except:
        print "error!"

def getpicture(keyword):
    try:
        url = "http://www.baidu.com/s"
        path = ""
        r = requests.get(url, params = kv)
        print r.request.headers
        print r.request.url
        print r.status_code
        r.encoding = r.apparent_encoding
        print len(r.text)
        #print r.text
    except:
        print "error!"

def main():
    searchbaidu("hello");

if __name__ == "__main__":
    main()
