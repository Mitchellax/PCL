import requests
import os
url = "https://edu-image.nosdn.127.net/3321D6673EB82C94D08E1B80E8344166.jpg"
root = "D://pics//"
path = root + url.split('/')[-1]
kv = {'user-agent':'Mozilla/5.0'}
try:
	if not os.path.exists(root):
		os.mkdir(root)
	if not os.path.exists(path):
		r = requests.get(url, headers=kv)
		r.raise_for_status()
		with open(path, 'wb') as f:
			f.write(r.content)
			f.close()
			print("文件保存成功")
	else:
		print("文件已存在")
	
except:
	print("产生异常")