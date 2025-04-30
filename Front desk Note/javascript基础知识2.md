### 箭头函数基本知识
创建函数还有一种非常简单的语法，并且这种方法通常比函数表达式更好，被称为箭头函数
```
let func=(arg1,arg2,...,argN)=>expression;
```
这里创建了一个函数func，它接受参数arg1到argN,然后使用参数对右侧的expression求值并返回其结果。
相当于
```
let func=function(arg1,arg2,...,argN)
{
	return expression;
};
```

举个例子
```
let sum=(a,b)=>a+b;
```

如果只有一个参数可以省略掉圆括号，但是如果没有参数，括号则是空的（**但括号必须保留**）
改写之前的例子：
```
let age=prompt("What is your age?",18);
let welcom=(age<18)?
()=>alert("Hello"):
()=>alert("Greeting");
welcome();
```

如果函数体比较复杂，我们用花括号括起来，但是**注意用花括号括起来之后，需要包含return才能返回值（跟普通函数一样）**
