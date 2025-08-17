### 分支
`git checkout -b xxx`创建新的分支并切换到这个分支
`git checkout xxx`切换分支
`git merge xxx`合并分支，如果没有冲突自动合并，如果有冲突，需手动解决冲突然后再merge

### gitignore
注意这里的仓库是本地仓库
如果把敏感文件已经commit到了仓库，
`git rm --cached xxx`把该文件从本地仓库中删除
`.gitignore`文件里面的文件可以防止git跟踪

### 安全地撤销已经推送的提交
如果要撤销一个版本，但是不改变历史记录的话用`git revert xxx`
其中xxx用`git log`来获得，这个是提交一个新的更改，这个更改是revert 原来的更改 这是最安全的做法

如果需要在远程仓库中也修改，只需要完了再push到远程仓库里面就可以了

这是最安全、最推荐的撤销方式

### 整理本地提交记录
假如现在在我本地的分支上进行了多次提交，现在我要合并到主分支，但是为了保持提交历史的整洁，需要把多个提交合并为一个有意义的提交
假如合并三个历史记录
`git rebase -i HEAD~3`
然后交互
把后面的pick变成s

### 紧急bug修复流程
假如在feature分支上开发一个新功能，写了一半，这时main分支突然出现一个紧急bug需要修复。
```bash
#存储当前未完成的修改
git stash save "WIP on new feature"
#切换到主分支
git switch main
#拉取最新的主分支代码，确保基于最新代码进行修改
git pull origin main
#从主分支创建用于修复bug的分支
git switch -c hotfix/fix-critical-bug
#修改代码
...
#提交修复
git add .
git commit -m"fix:Resolve critical production bug"

#切换回主分支
git switch main

#合并
git merge --no-ff hotfix/fix-critical-bug

#将修复推送到远程仓库
git push origin main

#回到之前的工作
git switch feature

#恢复之前存储的工作内容
git stash pop
```
### fetch和pull的区别
**核心区别**:

- `git fetch`：**只拉取**。它会从远程仓库下载最新的数据（如新的分支和提交）到你的本地仓库，但**不会**自动修改你的本地工作分支。它更新的是你的远程跟踪分支（如 `origin/main`），让你能看到远程的变动，但你的本地 `main` 分支保持不变。
    
- `git pull`：**拉取并合并**。它本质上是两个命令的组合：`git fetch` + `git merge`。它会先执行 `git fetch` 下载最新数据，然后立即尝试将远程跟踪分支（如 `origin/main`）的更改合并到你当前所在的本地分支中。

