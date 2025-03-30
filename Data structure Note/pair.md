在 C++ 中，`std::pair` 是一个模板类，定义在 `<utility>` 头文件中。它可以存储两个不同或相同类型的值，常用于 STL 容器（如 `map`、`set`）或作为函数的返回值。

## 1. **创建 `pair`**
```cpp
#include <iostream>
#include <utility>  // std::pair

int main() {
    // 直接初始化
    std::pair<int, std::string> p1(1, "hello");

    // 使用 `make_pair`
    auto p2 = std::make_pair(2, "world");

    // 结构化绑定 (C++17)
    auto [num, str] = p1;

    std::cout << "p1: (" << p1.first << ", " << p1.second << ")\n";
    std::cout << "p2: (" << p2.first << ", " << p2.second << ")\n";
    std::cout << "Unpacked p1: (" << num << ", " << str << ")\n";

    return 0;
}
```

### **输出**
```
p1: (1, hello)
p2: (2, world)
Unpacked p1: (1, hello)
```

---

## 2. **`pair` 在 `map` 中的应用**
`std::pair` 常用于 `std::map`，因为 `map` 需要键值对存储数据：
```cpp
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;

    // 插入 pair
    myMap.insert(std::make_pair(1, "apple"));
    myMap.insert({2, "banana"}); // C++11 方式

    // 遍历 map
    for (const auto& p : myMap) {
        std::cout << "Key: " << p.first << ", Value: " << p.second << '\n';
    }

    return 0;
}
```

### **输出**
```
Key: 1, Value: apple
Key: 2, Value: banana
```

---

## 3. **`pair` 作为函数返回值**
`pair` 可以用于函数返回两个相关值：
```cpp
#include <iostream>
#include <utility>

std::pair<int, double> getPair() {
    return {42, 3.14};  // 直接返回 pair
}

int main() {
    auto result = getPair();
    std::cout << "Integer: " << result.first << ", Double: " << result.second << '\n';

    return 0;
}
```

### **输出**
```
Integer: 42, Double: 3.14
```

---

## 4. **比较 `pair`**
`pair` 支持**字典序**比较：
- 先比较 `first`，若相等再比较 `second`。
```cpp
#include <iostream>
#include <utility>

int main() {
    std::pair<int, int> p1 = {1, 5};
    std::pair<int, int> p2 = {1, 10};

    if (p1 < p2) {
        std::cout << "p1 is smaller than p2\n";
    }

    return 0;
}
```

### **输出**
```
p1 is smaller than p2
```

---

## 5. **交换 `pair`**
可以使用 `swap()` 交换 `pair` 的值：
```cpp
#include <iostream>
#include <utility>

int main() {
    std::pair<int, std::string> p1 = {1, "A"};
    std::pair<int, std::string> p2 = {2, "B"};

    p1.swap(p2);

    std::cout << "p1: (" << p1.first << ", " << p1.second << ")\n";
    std::cout << "p2: (" << p2.first << ", " << p2.second << ")\n";

    return 0;
}
```

### **输出**
```
p1: (2, B)
p2: (1, A)
```

---

### **总结**
- `std::pair<T1, T2>` 用于存储两个值，可用于 `map`、函数返回值等。
- 可用 `{}`、`std::make_pair()` 或直接初始化来创建 `pair`。
- 通过 `.first` 和 `.second` 访问 `pair` 的成员。
- `pair` 支持字典序比较，可以用作 `map` 的键。
- `swap()` 可交换两个 `pair` 的值。
