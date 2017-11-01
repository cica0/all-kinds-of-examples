import requests
#url = "https://item.jd.com/1150557.html"
try:
    kv = {'user-agent':'Mozilla/5.0'}
    url = "https://www.amazon.cn/gp/product/B00DNX7Y3W/ref=br_bsl_pdt-1/462-6395513-9052449?pf_rd_m=A1AJ19PSB66TGU&pf_rd_s=desktop-bestsellers-1&pf_rd_r=STM9SP8JRWYH819X4KYE&pf_rd_r=STM9SP8JRWYH819X4KYE&pf_rd_t=36701&pf_rd_p=29c4df77-45a7-428e-85f2-ade9026644f5&pf_rd_p=29c4df77-45a7-428e-85f2-ade9026644f5&pf_rd_i=desktop"
    r = requests.get(url, headers=kv)
    print r.request.headers
    print r.status_code
    r.encoding = r.apparent_encoding
    print r.text
except:
    print "error!"
