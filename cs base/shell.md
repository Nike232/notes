
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
#### 创建文件
1. **使用 `touch` 命令**：  
    `touch` 命令可以用来创建空文件。例如，要在当前目录下创建一个名为 `example.txt` 的文件，可以使用以下命令：
    
    ```
    touch example.txt
    ```
    
2. **使用重定向操作符 `>`**：  
    你可以使用重定向操作符 `>` 将输出重定向到一个文件，如果该文件不存在，则会创建它。例如：
    
    ```
    echo "Hello, World!" > example.txt
    ```
    
    这条命令会在当前目录下创建一个名为 `example.txt` 的文件，并写入 "Hello, World!"。
    
3. **使用文本编辑器**：  
    你可以使用文本编辑器如 `nano`、`vim` 或 `gedit` 来创建和编辑文件。例如，使用 `nano` 创建一个文件：
    
    ```
    nano example.txt
    ```
    
    这将打开 `nano` 编辑器，你可以在其中输入文本，然后保存并退出。
    
4. **使用 `cat` 命令**：  
    `cat` 命令也可以用来创建文件。例如：
    
    ```
    cat > example.txt
    ```
    
    这将打开一个输入流，你可以输入文本，然后按 `Ctrl+D` 结束输入并创建文件。
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
### 重定向输入输出
* 在 shell 中，程序有两个主要的“流”：它们的输入流和输出流。 当程序尝试读取信息时，它们会从输入流中进行读取，当程序打印信息时，它们会将信息输出到输出流中。 通常，一个程序的输入输出流都是您的终端。也就是，您的键盘作为输入，显示器作为输出。 但是，我们也可以重定向这些流！
#### 输出重定向 `>`

`>` 符号用于将程序的输出重定向到一个文件中。如果文件不存在，它将被创建；如果文件已经存在，它将被覆盖。例如：

```bash
echo "Hello, World!" > output.txt
```

这条命令会将 `echo` 命令的输出 "Hello, World!" 写入到 `output.txt` 文件中。如果 `output.txt` 文件已经存在，它将被覆盖。

如果你想在文件末尾追加内容而不是覆盖，可以使用 `>>` 符号：

```bash
echo "Another line" >> output.txt
```

这条命令会在 `output.txt` 文件的末尾添加 "Another line"。

#### 输入重定向 `<`

`<` 符号用于将文件的内容作为程序的输入。例如：

```bash
sort < input.txt
```

这条命令会将 `input.txt` 文件的内容作为 `sort` 命令的输入，并输出排序后的结果到终端。

### 示例

假设你有一个文件 `numbers.txt`，内容如下：

```
3
1
4
2
```

你可以使用 `sort` 命令对其进行排序，并将结果输出到一个新的文件 `sorted_numbers.txt`：

```bash
sort < numbers.txt > sorted_numbers.txt
```

执行上述命令后，`sorted_numbers.txt` 文件的内容将是：

```
1
2
3
4
```

### 总结

- `>` 用于将程序的输出重定向到文件，覆盖文件内容。
- `>>` 用于将程序的输出重定向到文件，追加到文件末尾。
- `<` 用于将文件的内容作为程序的输入。
### 管道 `|`

管道 `|` 操作符允许你将一个程序的输出作为另一个程序的输入。这使得你可以将多个命令组合在一起，形成一个处理链，从而更高效地处理数据。例如：

```bash
cat input.txt | sort | uniq > output.txt
```

这条命令的执行过程如下：

1. `cat input.txt`：读取 `input.txt` 文件的内容。
2. `sort`：将 `cat` 命令的输出进行排序。
3. `uniq`：将排序后的输出去重。
4. `> output.txt`：将最终的输出写入 `output.txt` 文件。

### 示例

假设你有一个文件 `numbers.txt`，内容如下：

```
3
1
4
2
3
1
```

你可以使用管道将文件内容排序并去重，然后将结果输出到一个新的文件 `sorted_unique_numbers.txt`：

```bash
sort numbers.txt | uniq > sorted_unique_numbers.txt
```

执行上述命令后，`sorted_unique_numbers.txt` 文件的内容将是：

```
1
2
3
4
```
### root

#### 根用户（root user）

- **特殊性**：根用户几乎不受任何限制，可以创建、读取、更新和删除系统中的任何文件。
- **使用建议**：通常不直接以根用户登录系统，而是使用 `sudo` 命令来执行需要特权的操作。

#### 使用 `sudo` 命令

- **作用**：允许用户以超级用户（root）的身份执行某些操作。
- **注意事项**：确保在执行特权操作前确认操作的必要性，以避免系统破坏。

#### 修改 `sysfs` 文件

- **路径**：系统被挂载在 `/sys` 下，`sysfs` 文件暴露了一些内核参数。
- **用途**：可以在运行期间配置系统内核。

#### 示例：修改屏幕亮度

1. **查找 `brightness` 文件**：
    
    ```bash
    sudo find -L /sys/class/backlight -maxdepth 2 -name '*brightness*'
    ```
    
    输出示例：
    
    ```
    /sys/class/backlight/thinkpad_screen/brightness
    ```
    
2. **尝试直接修改**：
    
    ```bash
    cd /sys/class/backlight/thinkpad_screen
    sudo echo 3 > brightness
    ```
    
    **错误**：`open: Permission denied`
    
    - **原因**：`>` 操作符由 shell 执行，而不是 `sudo`，因此权限不足。
3. **使用 `tee` 命令**：
    
    ```bash
    echo 3 | sudo tee brightness
    ```
    
    - **解释**：`tee` 命令以 root 权限打开 `brightness` 文件并写入内容。

#### 示例：修改 LED 状态

- **路径**：`/sys/class/leds/`
- **命令**：
    
    ```bash
    echo 1 | sudo tee /sys/class/leds/input6::scrolllock/brightness
    ```
## `chmod` 命令

`chmod` 命令用于更改文件或目录的访问权限。权限可以分为三类：用户（user）、组（group）和其他用户（others）。每类权限可以有读（read）、写（write）和执行（execute）三种操作。

### 基本语法

```bash
chmod [选项] 模式 文件...
```

### 权限表示法

权限可以用符号模式或数字模式来表示。

#### 符号模式

符号模式使用符号来表示权限的更改。基本格式为：

```
[who][operator][permission]
```

- **who**：
    
    - `u`：用户（文件所有者）
    - `g`：组
    - `o`：其他用户
    - `a`：所有用户（相当于 `ugo`）
- **operator**：
    
    - `+`：添加权限
    - `-`：移除权限
    - `=`：设置权限
- **permission**：
    
    - `r`：读权限（4）
    - `w`：写权限（2）
    - `x`：执行权限（1）

**示例**：

- 给文件 `example.txt` 的所有者添加执行权限：
    
    ```bash
    chmod u+x example.txt
    ```
    
- 移除文件 `example.txt` 的组写权限：
    
    ```bash
    chmod g-w example.txt
    ```
    
- 设置文件 `example.txt` 的其他用户只有读权限：
    
    ```bash
    chmod o=r example.txt
    ```
    
- 设置文件 `example.txt` 的所有用户都有读和执行权限：
    
    ```bash
    chmod a+rx example.txt
    ```
    

#### 数字模式

数字模式使用数字来表示权限。每个权限位对应一个数字：

- `r`：读权限（4）
- `w`：写权限（2）
- `x`：执行权限（1）

权限的总和表示权限组合。例如：

- `7`（4+2+1）：读、写、执行
- `6`（4+2）：读、写
- `5`（4+1）：读、执行
- `4`（4）：读
- `3`（2+1）：写、执行
- `2`（2）：写
- `1`（1）：执行
- `0`（0）：无权限

**示例**：

- 设置文件 `example.txt` 的所有者有读、写、执行权限，组有读、执行权限，其他用户只有读权限：
    
    ```bash
    chmod 755 example.txt
    ```
    
- 设置文件 `example.txt` 的所有者有读、写权限，组和其他用户无权限：
    
    ```bash
    chmod 600 example.txt
    ```
    

### 常用选项

- `-R`：递归地更改目录及其子目录和文件的权限。
    
    ```bash
    chmod -R 755 directory_name
    ```
    
- `-v`：显示详细的更改信息。
    
    ```bash
    chmod -v 755 example.txt
    ```