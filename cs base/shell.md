## shell

* shell提示符  用户名和当前路径 “$”表示当前的身份不是root用户 **~是home目录**

* echo 类似于print 会打印出指定的参数 **不同的参数间用空格分隔 如果有一个参数里面包含空格的时候用引号括起来**
* `echo $PATH`打印出环境变量，这里的环境变量就是shell去找你所要运行程序的路径
* pwd打印当前路径
* cd 路径（可以是绝对路径也可以是相对路径） 跳转到指定路径
  * '.'代表当前路径 '..'代表父路径
  * **`cd -`返回上一次的目录**

* ls列出当前目录的文件
  * -l 以长列表的形式列出 additional information
    1. `lrwxrwxrwx 1 23259 197609       30 Jun 11  2024 'Application Data' -> /c/Users/2`
       * l表示符号链接
       * rwxrwxrwx是权限字段分别表示所有者、所属组、其他用户的权限，三个字符为一组，rwx(read write execute)
       * 1是链接数
       * 23259是文件所有者的uid
       * 197609是gid
       * 30是符号链接的长度
       * 修改时间
       * 连接名和链接的目标
    2. `drwxr-xr-x 1 23259 197609        0 Aug  3  2024  Videos/`
       * d代表是一个目录
       * rwx说明所有者有所有权限
       * r-x说明所属组成员没有写权限
       * r-x说明其他人没有写权限
       * 然后是所属者和所属组的uid
       * 修改日期
       * 目录名
       * 为了进入某个文件夹，用户需要具备该文件夹以及其父文件夹的“搜索”权限（以“可执行”：`x`）权限表示。为了列出它的包含的内容，用户必须对该文件夹具备读权限（`r`）

* `命令 --help`获得该指令的帮助
* 不带参数值的为flag 带参数值的为option
* mv用于重命名或者移动文件
  * `mv oldname.txt newname.txt`重命名
  * `mv file.txt /home/user/docs/`移动文件（当然也能移动目录）
  * `mv file.txt /home/user/docs/newname.txt`移动文件的同时改名
  * 常用选项:
    * -i 交互模式 会询问是否覆盖（如果目标文件存在）
    * -f 直接覆盖（默认）
    * -n 不覆盖

* cp把“源文件”复制到“目标路径”去，不影响原来的文件。**区别mv的移动**
  * `cp file.txt backup.txt`复制文件
  * `cp file.txt /home/user/docs/`
  * `cp file1.txt file2.txt /home/user/docs/`复制多个文件
  * `cp -r myfolder/ backupfolder/`复制整个目录 **注意一定要加-r**

* rm 删除操作
  * `rm file.txt`
  * `rm file1.txt file2.txt`删除多个文件
  * `rm *.txt`删除该目录下的所有txt文件 (使用通配符)
  * `rm -r myfolder/`删除整个目录 **必须加-r**
  * -f 强制删除 不提示 -i 每删除一个文件之前都需要确认（保险）

* mkdir（创建目录或者文件夹）
  * `mkdir [选项] 目录名`会在当前目录下新建一个文件夹 可以一次性创建多个
  * `mkdir -p projects/2025/April`创建多级目录，如果不存在就创建
  * -p 创建多级目录 -v 显示创建的过程
  * **目录已经存在时会报错**

* 创建文件
  * 
* man得到命令的用户手册，使用q可以推出该程序
* 关于shell程序中的复制和粘贴（不是ctrl c v!!!）
  * win可以用ctrl+insert复制 用shift+insert粘贴
  * mac可以用command c v
  * 原生linux上可以选中然后鼠标右键复制 再次点击是粘贴