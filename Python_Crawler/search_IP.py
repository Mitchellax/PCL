import requests

try:
	url = "http://m.ip138.com/ip.asp?ip="
	kv1 = {'user-agent':'Mozilla/5.0'}
	kv2 = {'wd':'Python'}
	r = requests.get(url + '119.75.216.20', headers=kv1, params=kv2, timeout=30)
	r.raise_for_status()
	r.encoding = r.apparent_encoding
	print(r.text[-1000:])
except:
	print("产生异常")