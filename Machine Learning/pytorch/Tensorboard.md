导入头文件并创建对象
```python
from torch.utils.tensorboard import SummaryWriter
writer=SummaryWriter("logs")#记录日志的目录
```
主要函数：
1.添加标量
```python
writer.add_scalar(tag,函数值,步长)
```
2.添加图像
```python
writer.add_image(tag,img,dataformats='CHW'\'HWC')
```
注意img主要支持两种类型
1）`torch.Tensor` 默认是"CHW"(其中C为通道)
2)`numpy.ndarray`默认格式为"HWC"

所以二者一定要匹配，不然会报错

关闭
```python
writer.close()
```

在终端中打开tensorboard
```bash
tensorboard --logdir="logs"
```
