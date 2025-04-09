
## Shell基础

### 基本概念

- **Shell 提示符**: 显示用户名和当前路径。`$`表示当前用户不是root用户，`~`表示home目录。

### 常用命令

#### `echo`
- **功能**: 类似于print，打印指定的参数。
- **用法**: 
  ```shell
  echo 参数1 参数2
  echo "参数 包含 空格"
  ```
- **示例**:
  ```shell
  echo $PATH  # 打印环境变量PATH
  ```

#### `pwd`
- **功能**: 打印当前工作目录的路径。
- **用法**:
  ```shell
  pwd
  ```

#### `cd`
- **功能**: 跳转到指定路径。
- **用法**:
  ```shell
  cd 路径  # 绝对路径或相对路径
  cd .     # 当前目录
  cd ..    # 父目录
  cd -     # 返回上一次的目录
  ```

#### `ls`
- **功能**: 列出当前目录的文件和子目录。
- **选项**:
  - `-l`: 以长列表形式列出文件和目录的详细信息。
- **示例**:
  ```shell
  ls -l
  ```
- **输出解释**:
  ```
  lrwxrwxrwx 1 23259 197609 30 Jun 11  2024 'Application Data' -> /c/Users/2
  drwxr-xr-x 1 23259 197609 0 Aug  3  2024  Videos/
  ```
  - `l`: 符号链接
  - `d`: 目录
  - `rwxrwxrwx`: 权限字段，分别表示所有者、所属组、其他用户的权限。
  - `1`: 链接数
  - `23259`: 文件所有者的UID
  - `197609`: 文件所属组的GID
  - `30`: 符号链接的长度或目录大小
  - `Jun 11  2024`: 修改时间
  - `'Application Data' -> /c/Users/2`: 连接名和链接的目标
  - `Videos/`: 目录名

#### `命令 --help`
- **功能**: 获取命令的帮助信息。
- **示例**:
  ```shell
  ls --help
  ```

### 文件和目录操作

#### `mv`
- **功能**: 重命名或移动文件和目录。
- **用法**:
  ```shell
  mv oldname.txt newname.txt  # 重命名
  mv file.txt /home/user/docs/  # 移动文件
  mv file.txt /home/user/docs/newname.txt  # 移动并重命名
  ```
- **选项**:
  - `-i`: 交互模式，覆盖前询问。
  - `-f`: 强制覆盖，不提示。
  - `-n`: 不覆盖。

#### `cp`
- **功能**: 复制文件和目录。
- **用法**:
  ```shell
  cp file.txt backup.txt  # 复制文件
  cp file.txt /home/user/docs/  # 复制文件到指定目录
  cp file1.txt file2.txt /home/user/docs/  # 复制多个文件
  cp -r myfolder/ backupfolder/  # 复制整个目录
  ```
- **选项**:
  - `-r`: 递归复制目录。
  - `-v`: 显示复制过程。

#### `rm`
- **功能**: 删除文件和目录。
- **用法**:
  ```shell
  rm file.txt  # 删除文件
  rm file1.txt file2.txt  # 删除多个文件
  rm *.txt  # 删除所有txt文件
  rm -r myfolder/  # 删除整个目录
  ```
- **选项**:
  - `-f`: 强制删除，不提示。
  - `-i`: 每删除一个文件前询问确认。

#### `mkdir`
- **功能**: 创建目录。
- **用法**:
  ```shell
  mkdir 目录名  # 创建单个目录
  mkdir -p projects/2025/April  # 创建多级目录
  ```
- **选项**:
  - `-p`: 创建多级目录，如果不存在则创建。
  - `-v`: 显示创建过程。

### 获取帮助

- **`man`**: 获取命令的用户手册。
- **用法**:
  ```shell
  man 命令
  ```
- **退出**: 使用`q`键退出手册。

### 复制和粘贴

- **Windows**:
  - 复制: `Ctrl + Insert`
  - 粘贴: `Shift + Insert`
- **Mac**:
  - 复制: `Command + C`
  - 粘贴: `Command + V`
- **Linux**:
  - 复制: 选中文本后，右键点击选择“复制”。
  - 粘贴: 右键点击选择“粘贴”。
