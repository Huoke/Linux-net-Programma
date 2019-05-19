# Git 和GitHub 关联
因为本地 Git仓库和 GitHub仓库 之间的传输是通过SSH加密传输的, GitHub需要识别是否是你推送, GitHub只要知道了你的公钥, 就可以确认只有你自己才能推送, 所以需要配置ssh key。

1. 在用户主目录(C:\Users\Administrator) 下, 看看有没有.ssh文件, 如果有, 再看看文件下有没有id_rsa和id_rsa.pub这两个文件, 如果已经有了, 可直接到下一步.
如果没有, 打开git bash , 输入命令, 创建SSH key
ssh-keygen -t rsa -C “7306@qq.com” //7306 是你自己注册的GitHub 邮箱
直接回车就是喽:
见下图:
![avatar](http://baidu.com/pic/doge.png)
出现上图, 就说创建成功了, 再去用户主目录里找.ssh文件夹, 里面有id_rsa和id_rsa.pub两个文件,这两个就是SSH Key的秘钥对.
id_rsa是私钥, id_rsa.pub是公钥, 可以公开.
2. 接下来到GitHub上, 打开 "Accouny settings" -- "SSH Key" 页面, 然后点击 “Add SSH Key”, 填上 Title(随意写),
在Key文件框里粘粘 id_rsa.pub 文件里面的全部内容。
见下图:
![avatar](http://baidu.com/pic/doge.png)
点击 “Add Keys”, 你就应该看到已经添加的Key, 可以添加多个Key
见下图:
![avatar](http://baidu.com/pic/doge.png)

3. 验证是否成功, 在git bash 里面输入下面命令:
 > ssh -T git@github.com 
 ![avatar](http://baidu.com/pic/doge.png)

 4.下面开始设置username和email，因为github每次commit都会记录他们
 $ git config --global user.name  "name"//你的GitHub登陆名
 $ git config --global user.email "123@126.com"//你的GitHub注册邮箱   

 5.接下来就是把本地仓库传到github上去，之前在GitHub上建好一个新的仓库,有一个页面,完全按照上面指示操作就可以了.
 >echo "# Linux-net-Programma" >> README.md
 >git init
 >git add README.md
 >git commit -m "first commit"
 >git remote add origin git@github.com:Huoke/Linux-net-Programma.git //关联一个远程库命令, git@github.com:Huoke/Linux-net-Programma.git这个是自己远程库
 >git push -u origin master //关联后,第一次推送 master 分支的所有内容命令，此后，每次本地提交后，就可以使用命令git push origin master推送最新修改



