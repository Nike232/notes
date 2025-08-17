## ✅ 什么是 SQL？

**SQL** 是用于管理关系型数据库的数据查询语言。你可以用它来：

- 创建表（存储结构）
    
- 插入数据（记录）
    
- 查询数据（搜索、筛选、排序）
    
- 更新或删除数据
    

几乎所有主流数据库（如 MySQL、PostgreSQL、SQLite）都支持 SQL。

---

## 📦 SQL 管理的数据长什么样？

SQL 管理的是**表格数据**，类似 Excel：

|id|name|score|
|---|---|---|
|1|Tom|1000|
|2|Alice|1200|
|3|Bob|900|

使用MySQL时，不同的表还可以使用不同的数据库引擎。如果你不知道应该采用哪种引擎，记住总是选择**InnoDB**就好了。

### 下载MySQL
https://dev.mysql.com/downloads/mysql/

MySQL安装后会自动在后台运行。为了验证MySQL安装是否正确，我们需要通过`mysql`这个命令行程序来连接MySQL服务器。(记得先配环境变量)

在命令提示符下输入`mysql -u root -p`，然后输入口令，如果一切正确，就会连接到MySQL服务器，同时提示符变为`mysql>`。

输入`exit`退出MySQL命令行。注意，MySQL服务器仍在后台运行。

### 主键
在关系数据库中，一张表中的每一行数据被称为一条记录。一条记录就是由多个字段组成的。例如，`students`表的两行记录：

| id  | class_id | name | gender | score |
| --- | -------- | ---- | ------ | ----- |
| 1   | 1        | 小明   | M      | 90    |
| 2   | 1        | 小红   | F      | 95    |

每一条记录都包含若干定义好的字段。同一个表的所有记录都有相同的字段定义。

对于关系表，有个很重要的约束，就是任意两条记录不能重复。不能重复不是指两条记录不完全相同，而是指能够通过某个字段唯一区分出不同的记录，这个字段被称为**主键**。

因为主键需要唯一性，所以最好不要修改，因而最好选择与业务逻辑无关的信息作为主键，我们一般把这个字段命名为`id`
1. 自增整数类型：数据库会在插入数据时自动为每一条记录分配一个自增整数，这样我们就完全不用担心主键重复，也不用自己预先生成主键；
2. 全局唯一GUID类型：也称UUID，使用一种全局唯一的字符串作为主键，类似`8f55d96b-8acc-4636-8cb8-76bf8abc2f57`。GUID算法通过网卡MAC地址、时间戳和随机数保证任意计算机在任意时间生成的字符串都是不同的，大部分编程语言都内置了GUID算法，可以自己预算出主键。

对于大部分应用来说，通常自增类型的主键就能满足需求。

通过外键实现一对多(外键可以通过约束也可通过自身的逻辑来实现)，通过中间表实现多对多(了解)

### 索引
索引是关系数据库中对某一列或多个列的值进行预排序的数据结构。通过使用索引，可以让数据库系统不必扫描整个表，而是直接定位到符合条件的记录，这样就大大加快了查询速度。（用哈希表去想）

对于主键，关系数据库会自动对其创建主键索引。使用主键索引的效率是最高的，因为主键会保证绝对唯一。

也可以自己创建索引（索引可以多个）

### 查询数据SELECT
使用SELECT查询的基本语句`SELECT * FROM <表名>`可以查询一个表的所有行和所有列的数据；`SELECT`是关键字 `*`代表所有列，`FROM`表示从哪个表查询，结果为二维表的形式

**条件查询**:
`SELECT * FROM <表名> WHERE <条件表达式>
`
逻辑表达式可用`AND` `OR` `NOT`来连接多个表达式

**投影查询**:
如果我们只希望返回某些列的数据，而不是所有列的数据，我们可以用`SELECT 列1, 列2, 列3 FROM ...`，让结果集仅包含指定列。这种操作称为投影查询。

eg:`SELECT id,score,name FROM students;

使用`SELECT 列1, 列2, 列3 FROM ...`时，还可以给每一列起个别名，这样，结果集的列名就可以与原表的列名不同。它的语法是`SELECT 列1 别名1, 列2 别名2, 列3 别名3 FROM ...`。

**分页查询**:
比如排行榜，可以一次只显示几十条
`LIMIT <N-M> OFFSET <M>`
- `LIMIT`总是设定为`pageSize`；
- `OFFSET`计算公式为`pageSize * (pageIndex - 1)`
#### 排序
默认情况下通常是按主键id排序的，如果要按其他条件排序，加上`ORDER BY`子句
eg:```
```-- 按score从低到高:
SELECT id, name, gender, score FROM students ORDER BY score;
```

如果要反过来，在结尾加上DESC

如果`score`列有相同的数据，要进一步排序，可以继续添加列名。例如，使用`ORDER BY score DESC, gender`表示先按`score`列倒序，如果有相同分数的，再按`gender`列排序：

### 插入数据
向表格中插入一条新纪录
`INSERT INTO <表名> (字段1, 字段2, ...) VALUES (值1, 值2, ...);
`
注意id字段是一个自增主键，可以由数据库自己推断
字段顺序不需要与表的字段顺序一致，只需要字段和value对应就好了

也可以一次性添加多个记录，用括号分隔就好了

### 更新数据
`UPDATE <表名> SET 字段1=值1, 字段2=值2, ... WHERE ...;
`
如果WHERE条件没有匹配到任何记录，不会报错也不会有任何记录被更新
在执行UPDATE之前最好先用SELECT来测试是否筛选了期望的数据集

### 删除数据
`DELETE FROM <表名> WHERE ...;
`
更新数据和删除数据如果不带WHERE语句会操作整个表
在mysql中这两个操作会返回操作的行数和条件匹配的行数

----
命令行程序`mysql`实际上是MySQL客户端，真正的MySQL服务器程序是`mysqld`，在后台运行

### 管理MySQL
可视化图形界面:https://dev.mysql.com/downloads/workbench/

本质上，MySQL Workbench和MySQL Client命令行都是客户端，和MySQL交互，唯一的接口就是SQL。

列出所有数据库：
````
mysql> SHOW DATABASES;
````
 创建一个数据库:
 ````
mysql> CREATE DATABASE test;
````
删除一个数据库：
```
mysql> DROP DATABASE test;
```
其他命令需要时再学习

### cpp中连接数据库
首先，vcpkg需要下载 `mysql-connector-cpp`

`CMakeLists.txt`配置:
```
find_package(MySQL CONFIG REQUIRED)
target_link_libraries(your_app PRIVATE MySQL::ConnectorCpp)
```

常规步骤:
```
1. 加载驱动并创建连接（sql::Driver → sql::Connection）
2. 创建 Statement 或 PreparedStatement
3. 执行 SQL（executeQuery, executeUpdate）
4. 处理结果（sql::ResultSet）
5. 关闭资源（connection, statement, resultSet）
```

完整示例:
```cpp
#include <iostream>
#include <memory>
#include <mysql/jdbc.h>  // 包含 Connector/C++ 的头文件

using namespace std;

int main() {
    try {
        // 1. 获取驱动
        sql::Driver* driver = sql::mysql::get_driver_instance();

        // 2. 创建连接
        unique_ptr<sql::Connection> conn(driver->connect("tcp://localhost:3306", "root", "你的密码"));

        // 3. 连接到数据库
        conn->setSchema("tank_game"); // 使用你创建的数据库名

        // 4. 创建 Statement 并执行插入
        unique_ptr<sql::Statement> stmt(conn->createStatement());

        // 插入示例
        stmt->executeUpdate("INSERT INTO players (username, score) VALUES ('Alice', 1000)");

        // 查询示例
        unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM players"));
        while (res->next()) {
            cout << "玩家: " << res->getString("username")
                 << ", 分数: " << res->getInt("score") << endl;
        }

        // 更新分数
        stmt->executeUpdate("UPDATE players SET score = 1200 WHERE username = 'Alice'");

        // 删除示例
        stmt->executeUpdate("DELETE FROM players WHERE username = 'Alice'");
    } catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
    }

    return 0;
}

```

开发流程：
使用模块封装MySQL的连接、增删查改等操作 ->其他文件中直接调用api