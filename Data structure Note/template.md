在 C++ 中，**模板（Template）** 是实现泛型编程的核心工具，允许你编写与类型无关的代码。模板分为两种主要形式：**模板函数**和**模板类**。

---

### **一、模板函数（Function Template）**
#### 1. 基本概念
模板函数允许你定义一个通用的函数框架，支持多种数据类型。编译器会根据调用时的具体类型自动生成对应的代码。

#### 2. 语法格式
```cpp
template <typename T>
返回值类型 函数名(参数列表) {
    // 函数体（使用 T 作为类型）
}
```
- `typename T` 表示一个类型占位符，也可以用 `class T`（两者等价）。
- 可以有多个类型参数，如 `template <typename T1, typename T2>`。

#### 3. 示例
```cpp
// 交换两个变量的值
template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// 返回两个值中的较大者
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}
```

#### 4. 使用方式
编译器会根据调用时的参数类型自动推导 `T`：
```cpp
int x = 1, y = 2;
swap(x, y); // T 推导为 int

double a = 3.14, b = 2.71;
cout << max(a, b); // T 推导为 double
```

也可以显式指定类型：
```cpp
cout << max<double>(3, 4.2); // 强制 T 为 double
```

---

### **二、模板类（Class Template）**
#### 1. 基本概念
模板类允许你定义一个通用的类框架，成员变量或函数可以使用泛型类型。常用于容器类（如动态数组、链表等）。

#### 2. 语法格式
```cpp
template <typename T>
class 类名 {
public:
    // 成员变量和函数（使用 T 作为类型）
};
```

#### 3. 示例
```cpp
// 一个简单的泛型容器类
template <typename T>
class Box {
private:
    T content;
public:
    void setContent(T newContent) {
        content = newContent;
    }
    T getContent() {
        return content;
    }
};

// 成员函数在类外定义时需额外声明模板
template <typename T>
void Box<T>::setContent(T newContent) {
    content = newContent;
}
```

#### 4. 使用方式
使用模板类时必须显式指定类型参数：
```cpp
Box<int> intBox;       // 存储 int 类型
intBox.setContent(42);

Box<string> strBox;    // 存储 string 类型
strBox.setContent("Hello");
```

#### 5. 更复杂的示例：动态数组类
```cpp
template <typename T>
class DynamicArray {
private:
    T* data;
    int size;
public:
    DynamicArray(int n) : size(n) {
        data = new T[size];
    }
    ~DynamicArray() {
        delete[] data;
    }
    T& operator[](int index) {
        return data[index];
    }
};

// 使用
DynamicArray<int> arr(10);  // 一个长度为 10 的整型数组
arr[0] = 100;
```

---

### **三、模板参数的高级用法**
#### 1. 非类型模板参数
模板参数可以是具体的值（如整数、指针），而不仅是类型：
```cpp
template <typename T, int N>
class FixedArray {
private:
    T data[N];  // 固定大小的数组
public:
    // ...
};
```

#### 2. 默认模板参数
可以为模板参数指定默认值：
```cpp
template <typename T = int>
class MyContainer {
    // ...
};

MyContainer<> obj; // 默认使用 int 类型
```

---

### **四、模板的优势**
1. **代码复用**：无需为不同类型重复编写相同逻辑。
2. **类型安全**：比宏或 `void*` 更安全，编译器会进行类型检查。
3. **灵活性**：支持自定义类型（如类、结构体）。

---

### **五、注意事项**
1. **编译时代码生成**：模板会导致代码膨胀（多份生成代码）。
2. **声明与实现分离**：模板的声明和实现通常需要放在同一个头文件中。
3. **错误信息复杂**：模板错误可能难以理解（如类型不支持某些操作）。

---

通过模板，C++ 实现了强大的泛型编程能力，标准库中的 `vector`、`list`、`map` 等容器均基于模板实现。合理使用模板可以大幅提高代码的复用性和灵活性。