Tensor类似于martix，但是有两个显著的优势，第一是可以自动微分（在梯度计算的时候很有用），第二是可以利用gpu并行计算的优势加速训练

### tensor初始化
1.直接从数据创建（列表、元组）
2.从numpy数组转换
3.从tensor数据类型转换
```python
import torch
data=[[1,2],[2,3]]
a=torch.tensor(data,dtype=torch.float)
array=np.array(data)  
b=torch.from_numpy(array)  
print(b)

c=torch.zeros_like(a,dtype=torch.float)  
d=torch.ones_like(a,dtype=torch.float)  
e=torch.rand_like(a,dtype=torch.float)  
print(c)  
print(d)  
print(e)
```

### tensor属性
```python
tensor=torch.rand(3,4)  
print(tensor.shape)  
print(tensor.dtype)  
print(tensor.device)# tensor存储在哪个设备里面
```

### 部分运算
```python
tensor=torch.ones(4,4)  
tensor[:,1]=5  
print(tensor)  
  
t1=torch.cat([tensor,tensor],dim=0)  
print(t1)  
t2=torch.cat([tensor,tensor],dim=1)  
print(t2)  
#dim为维度  
  
print(t2.T)  
print(t2*3)  
print(t2*t2)#对应元素相乘，所以形状必须是一样的  
print(t2@t2.T)#矩阵乘法  
  
print(t2.add_(5))#带下划线的是原地对张量进行操作  
print(t2.t_())#原地操作虽然会更快一点，但是根据之前的原理，由于会消灭历史记录  
#所以不建议使用
```
