# -*- coding: UTF-8 -*- #

import urllib
import urllib2
import re 

page = 1
url = "http://www.qiushibaike.com/hot/page/"+str(page)
user_agent ='Mozilla/4.0 (compatible; MSIE 5.5; Windows NT)'
headers = {'User-Agent' : user_agent}
try:
    request = urllib2.Request(url,headers = headers)
    response = urllib2.urlopen(request)
    content = response.read().decode('utf-8')
    pattern = re.compile('<div.*?author.*?title="(.*?)".*?<span>(.*?)</span>',re.S)
    items = re.findall(pattern, content)
    for item in items:
        print "author:"+item[0]
        print "content :"+item[1]
        print '\n'
except urllib2.URLError,e:
    if hasattr(e,'code'):
        print e.code
    if hasattr(e, 'reason'):
        print e.reason
