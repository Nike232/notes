运算高效（底层用C）应用广泛

```python
import numpy as np
```
创建数组
```python
array1=np.array([1,2,3,4,5])#创建一个一维数组
array2=np.zeros((3,4)) #创建一个3行4列的全零数组
array3=np.ones((4,3)) #创建一个4行3列的全1数组
array4=np.arange(1,11)#创建一个递增数组  (左闭右开)
array5=np.linspace(0,1,5)#创建一个区间等间距的数组 前面两个是区间的范围 最后一个是数组元素的个数
```
数组默认的数据类型为np.float64 可以在创建数组时通过指定dtype的参数来显示指定数据类型
对于现有的数组可以通过astype()来转换数据类型

获取数据的尺寸
```python
print(array.shape)
```

基本运算
两个相同尺寸的数组可以直接进行四则运算，等价于同一个位置上的数进行对应运算

```python
np.dot(a,b)
a@b #进行矩阵乘法运算
np.sqrt(a)
np.sin(a)
np.cos(a)
np.log(a)
np.power(a,2)
#都是对数组中的所有数进行操作
5*a  #广播 可以一个数与一个数组相乘
a+b #两个不一样尺寸的数组也可以做加法运算，在相加之前numpy会先将他们扩展到相同尺寸
```

```python
a.min()
a.max()#返回最值
a.argmin()
a.argmax()#返回最值所对应的索引
a.sum()#返回总和
a.mean()#返回均值
a.median()#返回中位数
a.var()#返回方差
a.std()#返回标准方差
```
上面的操作对于多维数组可以指定axis参数0,1,2表示对哪一个维度进行操作
（可以按照深度来理解）

获取元素
```python
a[2,3] #通过索引直接获得元素
a[a<3] #筛选
a[(a<3)&(a%2==0)]
a[0,0:2]#获取第一行前两列的所有元素
a[0 :]
a[0]
#获取第一行所有列的元素
a[0:9:2]#第三个参数为跨度（可以取负号）
a[::-1]#翻转数组
```

与PIL结合
```python
from PIL import Image
import numpy as np
image=Image.open(path)
array=np.array(image)
array[::0]#提取所有像素点的红色分量 第三个参数表示通道
```