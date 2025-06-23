python并发编程有三种方式：

多线程Thread、多进程Process、多协程Coroutine

一个进程中可以启动很多个线程，一个线程中可以启动很多个协程

多进程(mutiprocessing模块):
优点：可以利用多核CPU进行并行运算
缺点：占用资源最多、可启动数目最少
适用于CPU密集计算

多线程(threading模块):
优点：相比于进程，更轻量级，占用资源更少
缺点：
1. 相比于进程，多线程只能并发执行（GIL）
2. 相比协程：启动数目有限，占用内存资源，有线程切换开销
适用于IO密集型运算，同时运行的任务数目要求不多

多协程(asyncio模块):
优点：内存开销最少、启动协程数目最多
缺点：支持的库有限（比如requests不支持，只能使用aiohttp）、代码实现比较复杂
适用于:IO密集型计算、需要超多任务执行、但有现成库支持的场景

### GIL
python速度慢的两个原因:
1. 是动态类型语言、边解释边执行
2. GIL

GIL，全局解释器锁，使得任何时刻只有一个线程在执行

如何规避GIL带来的限制？
1. 多线程threading仍然是有用的，可以用来IO密集型计算，但是对于计算密集型，效率反而会下降，因为无法发挥出多核并行的优势
2. 也可以使用mutiprocessing的多进程机制实现并行计算，利用多核cpu的优势

#### 创建多线程的方法
1.准备一个函数
```python
def my_func(a,b):
	do_craw(a,b)
```
2.创建一个线程
```python
import threading
t=threading.Thread(target=my_func,args=(100,200))
```
3.启动线程
`t.start()`
4.等待结束
`t.join()`