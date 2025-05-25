### http和https
HTTP比HTTP更安全，但是性能较低
* HTTP：默认端口号为80 明文传输
* HTTPS:默认端口号为443,增加了安全套接层

### 常见的请求头与响应头
请求头：
* host 域名
* Connection 长连接
* **User-Agent 用户代理
* **Referer 页面跳转处，防盗链（图片/视频）检查请求从哪里来的
* **Cookie  用户信息，状态保持**
响应头：
* Set-Cookie

**注意转态码并不完全可信，返回的转态码不一定是真实情况，比如服务器已经识别出你是爬虫，但是为了让你疏忽大意，照样给你转态码为200，但是响应体没有数据**

**浏览器能访问到才是真的能访问到**

**所有的状态码都不可信，一切以是否从抓包的得到的相应中得到数据为准**

**network中抓包得到的源码才是判断依据，elements中的源码是渲染之后的源码，不能作为判断标准**
### requests
```python
import requests  
#通过requests模拟发送网络请求  
#模拟构造headers请求头信息  
headers={  
    'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/136.0.0.0 Safari/537.36'  
}  
response=requests.get(url="https://www.douban.com",headers=headers)  
print(response.status_code)
```
user-agent 来伪装成浏览器

### 浏览器请求的过程
浏览器
	发送所有请求，进行渲染
爬虫
	只发送指定请求，不会渲染
浏览器渲染出来的页面和爬虫请求的页面很多时候是不一样的，因为爬虫不具备渲染能力
* **浏览器最终展示的结果是由多个url地址分别发送的多次请求**
* **所以在爬虫中，需要以发送请求的一个url地址对应的响应为准来进行数据的提取**
三种文件类型：
骨骼文件:
	html静态文件
肌肉文件:
	js/ajax请求
皮肤文件:
	css/font/图片

抓包过程：
	根据发送请求的流程分别在三类文件中寻找数据

#### url 统一资源定位符
协议://ip地址或域名：端口/资源路径
```python
print response.text #查看响应内容，返回unicode格式的数据
print response.content #查看响应内容，返回字节流数据

```

凡是出现乱码都是因为编码模式不匹配，在网页可以查看到网页的编码，`print (response.encoding)`可以知道我们的编码模式

设置编码模式
`response.encoding='utf-8`

在浏览器中能正常得到信息，但是在程序中不行，那就是请求头不对

### response.text和response.content

**response.text是requests模块按照charset模块推测出的编码字符集进行解码的结果**
网络传输的字符串都是bytes类型，所以response.text=response.content.decode
**response.text是str类型，而是response.content是bytes类型**

#### 通过对response.content进行decode，来解决中文乱码
* response.content.decode() 默认utf-8
* response.content.decode('GBK')
* 还有常见的gb2312 ascii iso-8859-1

### 常见的响应对象参数和方法
* response.url 响应url
* response.status_code
* response.request.headers 响应对应的请求头
* response.headers 响应头
* response.cookies 响应设置cookies(set-cookie)

#### 设置url中的参数
有两种方法：
1. 直接写在url里面
2. 创建一个字典，写在字典里面

### 在请求中携带cookie
在headers中直接携带cookie 

也可以直接使用cookie参数
创建cookie字典再赋值给cookies参数

#### 构造cookie字典
```python
temp='里面是cookie'
cookie_list=temp.split('; ')
cookies={cookie.split('=')[0]:cookie.split('=')[-1]for cookie in cookie_list}
```

### cookieJar对象转化为cookies字典
	使用requests获取到的response对象，具有cookies属性，该属性值是一个cookieJar类型，包含了对方服务器设置在本地的cookie,我们该如何将其转化为cooies字典呢?
```python
cookies_dict=requests.utils.dict_from_cookiejar(response.cookies)
```


### 超时参数timeout的使用
在爬虫中，一个请求很久没有结果，就会让整个项目的效率变得非常低，我们就需要强制要求，让它在特定的时间内返回结果，不然就报错

在请求的时候设置timeout参数就可以了
### 结构化数据和非结构化数据
数据分为结构化数据和非结构化数据
结构化数据比如json(高频出现): json模块、正则、(jsonpath模块)   xml(低频出现):re lxml
非结构化数据比如html 正则、lxml

非结构化数据转化为结构化数据:
电话、邮箱.....：使用正则表达式
html、css......：使用正则表达式、xpath、css选择器
