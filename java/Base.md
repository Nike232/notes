java代码的执行过程：
```
Java源代码(.java)
        │
        ▼
    javac 编译
        │
        ▼
  字节码(.class) ——> JVM 加载
        │
        ▼
  解释执行 / JIT编译
        │
        ▼
    程序运行输出
```
[![image.png](https://pic1.imgdb.cn/item/68cf775bc5157e1a882107ad.png)](https://pic1.imgdb.cn/item/68cf775bc5157e1a882107ad.png)
每条语句用`;`结束

### 三种注释
1.//
2.`/* */`
3.
```java
/**
*
*
*/
```
这种注释需要写在类和方法的定义处，可以用于自动创建文档

### 标识符命名规则
由字母、数字、下划线和$组成，但是开头不能是数字

**类名和接口名用驼峰命名法**
**变量名和方法名用小驼峰命名法**
### 变量
变量分为基本类型的变量和引用类型的变量

- 整数类型：byte，short，int，long
- 浮点数类型：float，double
- 字符类型：char
- 布尔类型：boolean

#### 整型
java只定义了带符号的整型
byte为1字节

#### 浮点型
默认为double类型，要使得为float类型需要带f

#### 字符类型
占两个字节 0-65535

#### 常量
在定义变量的时候，加上`final`修饰符就变成常量
一般常量名**全部大写**

#### var关键字
类似于auto,但是只能用于**局部变量**
自动推断数据类型

### 运算
#### 溢出
溢出**不会出错**（环状）

#### 自增自减
++ --

#### 移位运算符
1.<<
2.>>(补符号位)
3.>>>(补0)

#### 短路运算

#### +用于字符串连接

#### 多行字符串
```java
"""
这里
可以是
多行
字符串
"""
```

### 空值null
引用类型的变量**可以指向一个空值null**,它表示不存在，即该变量不指向任何对象


### 数组类型
```java
int []arr=new int[5];//长度为5，默认初始化为0
int []arr2=new int[]{2,3,5,2};
int []arr3={3,4,54,52};
System.out.println(arr.length)//可以用arr.length来获取数组大小
```

```java
int []arr=new int[5];
arr={3,4,5};
```
原本的5个元素没有变，只是arr的指向变了，所以这也是为什么叫做引用数据类型


### 输入和输出
println是print line的缩写，表示输出并换行，如果输出后不想换行，可以直接使用print

printf格式化输出（C）
```java
double d=3.2532452;
System.out.printf("%.2f\n",d);
System.out.printf("%.4.f\n",d);
```

#### 输入
```java
import java.util.Scanner;
public class Main{
	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);//创建Scanner对象
		System.out.print("Input your name: ");
		String name=scanner.nextline();//读取一行输入并获取字符串
		System.out.print("Input your age: ");
		int age=scanner.nextInt();//读取一行输入并获取整数
		System.out.printf("Hi,%s,your are %d\n",name,age);//格式化输出
	}
}
```

### 判断相等
判断浮点数相等不用`==`，而是采用小于一个很小的数

判断引用类型相等
`==`表示引用是否相等，也就是是否是指向同一个对象，而不会比较实际的内容
比如下面的例子，输出s1!=s2
```java
public class Compare  
{  
    public static void main(String []args)  
    {  
        String s1 = "hello";  
        String s2 = "HELLO".toLowerCase();  
        if (s1==s2)System.out.println("s1=s2");  
        else System.out.println("s1!=s2");  
    }  
}
```

要判断引用类型的变量内容是否相等，必须使用`equals()`的方法
上面条件可以改成
```java
if(s1.equals(s2))...
```
但是注意s1不能为null，不然会报错

所以进一步可以优化成
```java
if (s1!=null &&s1.equals(s2))...
```

### switch语句
旧版和cpp同

从java12开始，支持switch新特性
```java
        String fruit = "apple";
        switch (fruit) {
        case "apple" -> System.out.println("Selected apple");
        case "pear" -> System.out.println("Selected pear");
        case "mango" -> {
            System.out.println("Selected mango");
            System.out.println("Good choice!");
        }
        default -> System.out.println("No fruit selected");
        }
```
 还具有返回值
```java
        String fruit = "apple";
        int opt = switch (fruit) {
            case "apple" -> 1;
            case "pear", "mango" -> 2;
            default -> 0;
        }; // 注意赋值语句要以;结束
        System.out.println("opt = " + opt);
```
如果是代码块中返回值，则必须用yield