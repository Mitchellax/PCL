import requests

try:
	url = "https://www.amazon.cn/b/?&node=1403206071&tag=baiduiclickcn-23&ref=pz_ic_AGS_N_17228_6"
	kv1 = {'user-agent':'Mozilla/5.0'}
	kv2 = {'wd':'Python'}
	r = requests.get(url, headers=kv1, params=kv2, timeout=30)
	r.raise_for_status()
	r.encoding = r.apparent_encoding
	print(r.text[1000:2000])
except:
	print("产生异常")