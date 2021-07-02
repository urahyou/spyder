# -*- coding: utf-8 -*-
"""
Created on Fri Jul  2 20:26:28 2021

@author: koneko
"""

import requests


url = 'https://fanyi.baidu.com/v2transapi'
headers={'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/75.0.3770.100 Safari/537.36'}
#word = input('请输入:')
param = {}
form ={'from':'en',
       'to':'jp',
       'query':'dog',
       'token':'143a8a123fa28d44a101f44423a12219',
       'simple_means_flag':'3',
       'sign':'143310.445695',
       'domain':'common'}

r = requests.post(url,headers=headers,data=form)
print(r.json())