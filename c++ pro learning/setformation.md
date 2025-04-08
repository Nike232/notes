在 C++ 中，可以使用 `setw()` 和 `setfill()` 控制输出的格式，使数字始终保持 4 位数的形式，例如 `12` 输出为 `0012`。以下是几种常见的方法：

---

## **方法 1：使用 `setw()` 和 `setfill()`**
`setw(n)` 设置宽度，`setfill(ch)` 用指定字符填充空缺部分：
```cpp
#include <iostream>
#include <iomanip>  // 需要包含这个头文件
using namespace std;

int main() {
    int num = 12;
    cout << setw(4) << setfill('0') << num << endl;
    return 0;
}
```
**输出：**
```
0012
```
✅ **适用于整数，不影响后续的 `cout`**

---

## **方法 2：使用 `printf()`（C 风格）**
如果熟悉 C 语言的 `printf`，可以使用 `%04d` 来格式化整数：
```cpp
#include <iostream>
using namespace std;

int main() {
    int num = 12;
    printf("%04d\n", num);
    return 0;
}
```
**输出：**
```
0012
```
✅ **适用于格式化输出，不适用于 `string` 处理**

---

## **方法 3：使用 `to_string()` + `string` 处理**
如果需要字符串格式（如 `std::string`），可以手动补零：
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int num = 12;
    string str = to_string(num);
    str = string(4 - str.length(), '0') + str;  // 在前面补 '0'
    cout << str << endl;
    return 0;
}
```
**输出：**
```
0012
```
✅ **适用于字符串处理，例如存储、拼接字符串**

---

## **方法 4：C++20 `std::format()`（现代 C++ 推荐）**
如果使用 C++20 及以上版本，可以用 `std::format()`：
```cpp
#include <iostream>
#include <format>  // 需要 C++20
using namespace std;

int main() {
    int num = 12;
    cout << format("{:04}", num) << endl;
    return 0;
}
```
**输出：**
```
0012
```
✅ **更现代、简洁，但需要 C++20**

---

## **总结**
| 方法 | 适用情况 | 备注 |
|------|---------|------|
| `setw(4) + setfill('0')` | C++ 标准方式，适用于 `cout` | 最常用 |
| `printf("%04d")` | C 风格格式化输出 | 适合 `printf` |
| `to_string() + string(4 - len, '0')` | 需要字符串格式 | 适用于字符串拼接 |
| `std::format("{:04}", num)` | C++20 及以上 | 现代写法 |

如果你只是想在 `cout` 里格式化输出，推荐 **方法 1**（`setw(4) + setfill('0')`）。如果要处理字符串数据，推荐 **方法 3**。