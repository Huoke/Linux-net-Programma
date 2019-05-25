# Git 和GitHub 关联
使用git 将项目上传到GitHub上,首先要有GitHub账号,这就不用说了，没有的先注册，地址：https://github.com. 
没有仓库的话，先新创建一个仓库.
![avatar](https://github.com/Huoke/Linux-net-Programma/blob/master/gitLinkGitHub04.png)
因为本地 Git仓库和 GitHub仓库 之间的传输是通过SSH加密传输的, GitHub需要识别是否是你推送, GitHub只要知道了你的公钥, 就可以确认只有你自己才能推送, 所以需要配置ssh key。
1. 在用户主目录(C:\Users\Administrator) 下, 看看有没有.ssh文件, 如果有, 再看看文件下有没有id_rsa和id_rsa.pub这两个文件, 如果已经有了, 可直接到下一步.
如果没有, 打开git bash , 输入命令, 创建SSH key
ssh-keygen -t rsa -C “7306@qq.com” //7306 是你自己注册的GitHub 邮箱
直接回车就是喽:
见下图:
![avatar](https://github.com/Huoke/Linux-net-Programma/blob/master/gitLinkGitHub05.png)
出现上图, 就说创建成功了, 再去用户主目录里找.ssh文件夹, 里面有id_rsa和id_rsa.pub两个文件,这两个就是SSH Key的秘钥对.
id_rsa是私钥, id_rsa.pub是公钥, 可以公开.
2. 接下来到GitHub上, 打开 "Accouny settings" -- "SSH Key" 页面, 然后点击 “Add SSH Key”, 填上 Title(随意写),
在Key文件框里粘粘 id_rsa.pub 文件里面的全部内容。
见下图:
![avatar](https://github.com/Huoke/Linux-net-Programma/blob/master/gitLinkGitHub02.png)
点击 “Add Keys”, 你就应该看到已经添加的Key, 可以添加多个Key
见下图:
![avatar](https://github.com/Huoke/Linux-net-Programma/blob/master/gitLinkGitHub01.png)
3. 验证是否成功, 在git bash 里面输入下面命令:
 > ssh -T git@github.com 
 ![avatar](https://github.com/Huoke/Linux-net-Programma/blob/master/gitLinkGitHub03.png)
4. 下面开始设置username和email，因为github每次commit都会记录他们
```vb
 $ git config --global user.name  "name"//你的GitHub登陆名
 $ git config --global user.email "123@126.com"//你的GitHub注册邮箱   
```
5. 接下来就是把本地仓库传到github上去，之前在GitHub上建好一个新的仓库,有一个页面,完全按照上面指示操作就可以了.
 ```vb
 echo "# Linux-net-Programma" >> README.md
 git init
 git add README.md
 git commit -m "first commit"
 git remote add origin git@github.com:Huoke/Linux-net-Programma.git //关联一个远程库命令, git@github.com:Huoke/Linux-net-Programma.git这个是自己远程库
 git push -u origin master //关联后,第一次推送 master 分支的所有内容命令，此后，每次本地提交后，就可以使用命令git push origin master推送最新修改
```
# VS Code 关联 git
1. 文件->首选项->设置->搜索git.path->点击编辑->找到你的电脑git的安装目录，找到里面的bin文件夹，里面的git.exe文件把该文件的完整路径复制下来
   参见下图:
   ![avatar]()
2. 为了方便可以把VSCode的终端配置成为 Git -bash 终端
   还是在设置里 搜索 terminal.integrated.shell.windows,然后复制安装目录下的bin文件夹里面的bash.exe文件目录更新到用户设置里面
   
   如图:
   ![avatar]()
3. 快捷键 Ctrl+~ 打开终端

# VScode Remote 远程开发与调试
## 简介
最近VScode发布了远程编程与调试的插件 Remote Development，使用这个插件可以在很多情况下替代vim直接远程修改与调试服务器上的代码，同时具备代码高亮与不全功能，就和在本地使用VScode一样。终于不用在服务器端翻来覆去的配置vim插件了。

本文介绍如何通过ssh的方法连接到远程服务器上，另外插件还提供了连接到WSL和容器的功能。
>No source code needs to be on your local machine to gain these benefits since Remote Development runs commands and extensions directly on the remote machine.

这个远程开发插件包包含三个插件:
1. Remote - SSH -  通过使用SSH 打开在远程机器/ VM 或者 WSL 上的文件夹，在任何地方都能操作源代码 .
2. Remote - Container - 可以打开容器中的任何文件夹。
3. Remote - WSL - 可以打开windows的linux子系统的任何文件夹。

## Installation
安装vs code-insiders和这个扩展包。 
remote-ssh:windows：安装一个与openssh兼容的ssh客户机，并确保ssh命令在您的路径中。
远程容器：为您的操作系统安装和配置Docker。 
### Windows/MacOS用户： 
1. 为Mac/Windows安装Docker桌面。（目前不支持Docker工具箱。） 
2. 右键单击Docker任务栏项，并更新设置/首选项>共享驱动器/文件与要在容器中打开的任何源代码位置共享。如果遇到麻烦，请参阅此处了解避免共享常见问题的提示。
3. 
### Linux用户：
### Remote-WSL：
## 配置过程
- 第一步
  
  1. 远程主机安装ssh-server