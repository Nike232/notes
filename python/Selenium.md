### 无头浏览器
```python
from selenium import webdriver  
from selenium.webdriver.chrome.options import Options  
options = Options()  
options.add_argument('--headless')  
driver = webdriver.Chrome(options=options)  
driver.get("https://www.baidu.com")
```
只需要设置选项为无头模式就可以了
有头和无头浏览器的区别在于图形化界面

在开发的时候需要使用有头浏览器方便调试
在部署的时候尤其是在服务器上的时候选择无头浏览器

#### options的其他配置
使用代理
`options.add_argument('--proxy-server=https://...')`
更换user-agent
`options.add_argument('--user-agent=...')`
### 使用
创建浏览器对象
driver=webdriver.xxx()
发送请求
driver.get(url)

#### 元素定位
##### driver对象的常用属性
1. `driver.page_source`渲染后的源码
2. `driver.current_url`当前的url
3. `driver.close()`关闭当前标签
4. `driver.quit()`关闭浏览器
5. `driver.save_screenshot("")`截图并保存

#### 元素定位
点击检查选中需要的节点，复制xpath id名 css名啥的
用对应的by

xpath css选择器 name属性值 class属性 id属性
链接文本 link_text('名字')名字就是对应的网页展现出来的名字 不匹配时报错
partial_link_text（）只需要部分包含名字

#### 元素处理
	find_element(s)获得的只是元素，不能直接获得其中的数据
* `element.text`获取文本 
* `element.get_attribute('属性名')`获得属性
* send_keys  针对text input
* `clear`对输入框做清空操作
* click()

### 其他操作
#### 切换标签页
我们如果点开了其他界面但是selenium的操作其实还停留在原界面
获取所有标签页的句柄
利用窗口句柄字切换到句柄指向的标签页
```python
current_windows=driver.window_handles#获取当前所有标签页构成的句柄的列表
driver.switch_to.window(current_windows[0])#切换窗口
```

### 切换到frame框架
frame框架常用在登录页面
相当于一个网页里面有另外一个网页
所以我们直接去定位是定位不到frame框架里面的元素（会报错）
```python
driver.switch_to.frame('定位到这个框架')比如是这个框架的id
#或者是
el_frame=driver.find_element(By.XPATH,'//...')
driver.switch_to.frame(el_frame)
```

### 对cookie的处理
`driver.get_cookies()`以列表的形式返回cookie

将得到的cookie列表转化为一个字典,方便requests模块使用
```python
cookies={}
for data in driver.get_cookies():
	cookies[data['name']]=data['value']
```
也可以使用字典推导式
```python
cookies={data['name']:data['value']for data in driver.get_cookies()}
```

### 执行js代码
	selenium可以让浏览器执行我们规定的js代码
```python
js='...'#js代码
driver.execute_script(js)#执行js
```
比如适用于数据没有出现在视野当中，需要下滑获取新的数据，但是selenium模块又没有下滑功能，所以这时候就可以执行js代码来实现

#### 页面等待
分类：
1. 强制等待：
	`time.sleep()`
2. 隐式等待
	针对的是元素定位，隐式等待设置了一个时间，在一段时间内判断元素是否定位成功，如果完成了就进行下一步，否则报超时加载
	`driver.implicitly_wait(10)`
	只需设置一次，后面的查找都适用
3. 显示等待(了解，一般不用)
	明确的等待某一个元素

