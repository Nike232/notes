用来对图像进行预处理和数据增强的模块，它能把原始数据转成神经网络需要的格式，并在训练的时候引入随机扰动，增加模型的泛化能力
```python
from torchvision import transforms
```
```python
img=Image.open(path) #Image类型的图片
tensor_trans=transforms.ToTensor()#创建对象
tensor_img=tensor_trans(img) #转化为tensor类型
```