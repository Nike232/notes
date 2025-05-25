### 代理
代理ip是一个IP，指向的是一个代理服务器
代理服务器能帮我们向目标服务器转发请求

#### 正向代理和反向代理的区别
1. 从发送请求的一方的角度，来区分正向或反向代理
2. 为浏览器或客户端（发送请求的一方）转发请求的，叫做正向代理
	浏览器知道最终处理请求的服务器的真实ip地址，例如VPN
3. 不为浏览器或客户端（发送请求的一方）转发请求，而是为最终处理请求的服务器转发请求的叫做反向代理
	浏览器不知道服务器的真实地址

#### 代理ip的分类
根据匿名度分为透明代理、匿名代理和高匿代理。**高匿代理的效果最好**

根据协议分类分为http、https、socks代理

键为协议名 值为ip地址和端口号
#### 如何使用代理ip
只需要设置proxies参数即可
proxies的形式：字典

代理使用成功能正常获得信息，不会有报错
使用失败要么卡滞，要么报错

### 使用verify参数忽略CA证书
设置参数verify=False 只会弹出一个警告

### requests模块发送post请求
`response=requests.post(url,data)`

data是一个字典

### post数据来源
1. 固定值 抓包比较不变的值
2. 输入值 抓包比较根据自身变化的值
3. 预设值-静态文件 需要提前从html中提取到的值
4. 预设值-发请求 需要对指定地址发送请求
5. 在客户端生成的  一般需要js生成出来数据

### 使用requests.session进行状态保持
requests模块中的session类能自动处理cookie
**场景：连续多次请求**
```python
session=requests.session()#实例化session对象
response=session.get(url,headers,...)
response=session.post(url,data,...)
```
### XPath
XPath 是一门在 XML 文档中查找信息的语言。

XML 文档是被作为节点树来对待的。

节点间的关系就是最常见的父、子、同胞、祖先、后代

XPath 使用路径表达式来选取 XML 文档中的节点或节点集。节点是通过沿着路径 (path) 或者步 (steps) 来选取的。

|          |                                      |
| -------- | ------------------------------------ |
| nodename | 选取此节点的所有子节点。                         |
| /        | 从根节点选取（取子节点）。                        |
| //       | 从匹配选择的当前节点选择文档中的节点，而不考虑它们的位置（取子孙节点）。 |
| .        | 选取当前节点。                              |
| ..       | 选取当前节点的父节点。                          |
| @        | 选取属性。                                |
**其中`//`比`/`更常用**,因为`/`只能是根节点下的，但是``//``是在全文中搜寻

| 路径表达式           | 结果                                                            |
| --------------- | ------------------------------------------------------------- |
| bookstore       | 选取所有名为 bookstore 的节点。                                         |
| /bookstore      | 选取根元素 bookstore。<br><br>注释：假如路径起始于正斜杠( / )，则此路径始终代表到某元素的绝对路径！ |
| bookstore/book  | 选取属于 bookstore 的子元素的所有 book 元素。                               |
| //book          | 选取所有 book 子元素，而不管它们在文档中的位置。                                   |
| bookstore//book | 选择属于 bookstore 元素的后代的所有 book 元素，而不管它们位于 bookstore 之下的什么位置。    |
| //@lang         | 选取名为 lang 的所有属性。                                              |

谓语用来查找某个特定的节点或者包含某个指定的值的节点。

谓语被嵌在方括号中。

| 路径表达式                               | 结果                                                              |
| ----------------------------------- | --------------------------------------------------------------- |
| /bookstore/book[1]                  | 选取属于 bookstore 子元素的第一个 book 元素。                                 |
| /bookstore/book[last()]             | 选取属于 bookstore 子元素的最后一个 book 元素。                                |
| /bookstore/book[last()-1]           | 选取属于 bookstore 子元素的倒数第二个 book 元素。                               |
| /bookstore/book[position()<3]       | 选取最前面的两个属于 bookstore 元素的子元素的 book 元素。                           |
| //title[@lang]                      | 选取所有拥有名为 lang 的属性的 title 元素。                                    |
| //title[@lang='eng']                | 选取所有 title 元素，且这些元素拥有值为 eng 的 lang 属性。                          |
| /bookstore/book[price>35.00]        | 选取 bookstore 元素的所有 book 元素，且其中的 price 元素的值须大于 35.00。            |
| /bookstore/book[price>35.00]//title | 选取 bookstore 元素中的 book 元素的所有 title 元素，且其中的 price 元素的值须大于 35.00。 |
|                                     |                                                                 |
XPath 通配符可用来选取未知的 XML 元素。

| 通配符          | 描述                     |
| ------------ | ---------------------- |
| *            | 匹配任何元素节点。              |
| @*           | 匹配任何属性节点。              |
| node()       | 匹配任何类型的节点。             |
| 路径表达式        | 结果                     |
| /bookstore/* | 选取 bookstore 元素的所有子元素。 |
| //*          | 选取文档中的所有元素。            |
| //title[@*]  | 选取所有带有属性的 title 元素。    |
通过在路径表达式中使用"|"运算符，您可以选取若干个路径。

在下面的表格中，我们列出了一些路径表达式，以及这些表达式的结果：

| 路径表达式                            | 结果                                                        |
| -------------------------------- | --------------------------------------------------------- |
| //book/title \| //book/price     | 选取 book 元素的所有 title 和 price 元素。                           |
| //title \| //price               | 选取文档中的所有 title 和 price 元素。                                |
| /bookstore/book/title \| //price | 选取属于 bookstore 元素的 book 元素的所有 title 元素，以及文档中所有的 price 元素。 |
### lxml
`from lxml import etree`我们只需要导入一部分功能
我们get到的数据都是字符串的形式，要通过lmxl进行xpath解决，必须先转化为html格式
```
response=requests.get(...)
html=etree.HTML(response.text)
result=html.xpath(...)
```
**注意如果原来得到的有标签缺失什么的，转为html的时候会自动补全**

### 正则表达式

**XPath 负责抓位置，正则/字符串处理负责抓具体内容**

### jsonpath模块
使用场景：一个多层嵌套的复杂字典，用json模块直接提取比较复杂,可以使用jsonpath直接提取数据

jsonpath的结果为列表，获取数据需要索引
使用方法:
```python
from jsonpath import jsonpath
ret=jsonpath(a,'jsonpath语法规则字符串')
```
语法
$根节点(最外层的大括号)
. 子节点
.. 内部任意位置 子孙位置(跟xpath中的//一样)