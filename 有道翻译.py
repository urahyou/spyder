# -*- coding: utf-8 -*-
"""
Created on Thu Jul  1 23:46:15 2021

@author: koneko
"""

from urllib import parse
import requests
import json

def translate(content):
    url = 'https://fanyi.youdao.com/translate'
    Form_Data = {}
    Form_Data['i'] = content
    Form_Data['doctype']= 'json'
    data = parse.urlencode(Form_Data).encode('utf-8')
    r = requests.get(url,data)
    js = json.loads(r.text)
    print(content+' : '+js['translateResult'][0][0]['tgt'])
    
    

translate('我好开心啊')