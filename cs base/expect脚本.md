**Expect** 是一种基于 **Tcl（Tool Command Language）** 的自动化交互脚本语言

主要用于自动化交互
### 常见命令
|命令|含义|
|---|---|
|`spawn`|启动一个外部命令（相当于执行 shell 命令）|
|`expect`|等待特定输出（模式匹配）|
|`send`|向进程发送输入（加上 `\r` 表示回车）|
|`exp_continue`|在匹配一个条件后继续匹配其他条件|
|`interact`|把控制权交还给用户|
|`set timeout`|设置等待时间（默认 10 秒）|
|`puts`|打印信息（相当于 echo）|
|`exit`|退出脚本|
### 一个常见的误区
🔹 **Bash** 只是用来启动 Expect 解释器。  
🔹 **Expect** 自身是一个基于 **Tcl 语言** 的独立脚本执行环境。  
🔹 所以脚本里的命令并不是在 Bash 中执行，而是在 **Expect 的 Tcl 环境** 中执行。

所以比如我要执行ssh命令，不能直接send"ssh xxx"这没有用
而是应该通过spawn来启动ssh服务

### 一个示例
```expect
#!/usr/bin/expect -f   
# ======================================
# 功能: 自动上传文件到远程服务器
# 作者: tom
# 日期: 2025-10-11
# ======================================

log_user 1  #显示交互
set timeout 10  #设置超时时间

# 参数：端口、密码、本地路径、远程路径、主机
set port [lindex $argv 0]
set password [lindex $argv 1]
set local_path [lindex $argv 2]
set remote_path [lindex $argv 3]
set host [lindex $argv 4]

spawn scp -P $port -r $local_path root@$host:$remote_path

expect {
    "yes/no" {
        send "yes\r"
        exp_continue
    }
    "*assword:" {
        send "$password\r"
    }
    timeout {
        puts "传输超时"
        exit 1
    }
    eof {
        puts "文件传输完成"
    }
}

```
最基本的结构便是
1.spawn 启用一个服务
2.expect 匹配字段，然后进行自动化反应
3.timeout做出反应 eof代表启用的子程序已经执行结束

|状态|说明|
|---|---|
|`"pattern"`|表示匹配到了程序输出中的某段文字|
|`timeout`|等待时间到了但没有匹配到任何输出|
|`eof`|被 `spawn` 启动的程序结束、输出流关闭|
### 关于exp_continue
一个expect中可以包含多个字段，如果匹配到其中一个字段，就会执行对应的命令，如果没有exp_continue就会退出这个expect

而如果使用了exp_continue，就会再次匹配这个expect中的任何字段，直到结束


如果需要将多个命令写在同一行，那么需要用`;`进行分隔
