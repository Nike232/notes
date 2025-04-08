在 C++ 中，如果输入的数的个数未知，可以使用以下几种方法来处理：

---

### **方法 1：使用 `while (cin >> x)`**
`cin` 在读取失败（比如遇到文件结尾或输入流错误）时会返回 `false`，可以利用这一点不断读取数据：

```cpp
#include <iostream>
using namespace std;

int main() {
    int x;
    while (cin >> x) {  // 读取直到遇到输入终止
        cout << "Read: " << x << endl;
    }
    return 0;
}
```
**适用场景：**  
- 适用于终端输入 (`cin`) 和重定向文件输入 (`< input.txt`)
- 适用于纯数值输入

**输入示例：**
```
1 2 3 4 5
```
**输出：**
```
Read: 1
Read: 2
Read: 3
Read: 4
Read: 5
```
（然后当输入流结束时，程序退出）

---

### **方法 2：使用 `vector` 存储所有数据**
如果需要存储所有数据，可以使用 `vector`：

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums;
    int x;
    while (cin >> x) {
        nums.push_back(x);
    }

    cout << "Numbers read: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
```

---

### **方法 3：使用 `getline()` 读取整行，再解析**
如果输入数据格式可能包含空格、换行等（比如字符串或多个数据类型混合），可以用 `getline()` 读取整行，然后使用 `istringstream` 解析：

```cpp
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string line;
    getline(cin, line);  // 读取整行
    istringstream iss(line);
    vector<int> nums;
    int x;
    
    while (iss >> x) {
        nums.push_back(x);
    }

    cout << "Numbers read: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
```

**适用场景：**
- 需要先读完整行，然后再解析
- 处理带空格的字符串输入

**输入示例：**
```
10 20 30 40
```
**输出：**
```
Numbers read: 10 20 30 40
```

---

### **方法 4：`cin.eof()` 检测输入结束**
适用于文件输入或者标准输入流：

```cpp
#include <iostream>
using namespace std;

int main() {
    int x;
    while (!cin.eof()) {  
        cin >> x;
        if (!cin.eof()) // 避免多读一次
            cout << "Read: " << x << endl;
    }
    return 0;
}
```

**适用场景：**  
- 适用于文件输入（`./a.out < input.txt`）
- **不适用于** 交互式终端输入，因为 `cin.eof()` 只有在尝试读取**失败**后才会返回 `true`，可能导致多读取一次。

---

### **总结**
| 方法 | 适用情况 | 备注 |
|------|---------|------|
| `while (cin >> x)` | 适用于终端或文件输入 | 推荐，简单高效 |
| `vector<int>` 存储 | 需要存储所有数据 | 适用于动态数据量 |
| `getline() + istringstream` | 需要处理整行输入 | 适用于混合数据类型 |
| `while (!cin.eof())` | 适用于文件输入 | 可能多读一次，不太推荐 |

如果是处理未知数量的输入，**推荐使用 `while (cin >> x)`**，因为它最简洁且适用于大多数情况。