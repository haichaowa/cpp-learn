# cpp-learn
c++个人学习记录

## third-party library

1. fmt: 
```text
sudo apt install -y libfmt-dev

ls /usr/include/fmt/  # 查看头文件
```
2. googleTest:
```text
sudo apt install libgtest-dev googletest  # 安装源码和编译依赖
cd /usr/src/googletest
sudo cmake CMakeLists.txt
sudo make
sudo cp lib/*.a /usr/lib  # 安装静态库
```


## cmake
https://blog.csdn.net/Yu_Lijing/article/details/149364720

## clion
### 远程开发
https://blog.csdn.net/weixin_74027669/article/details/142391303

/usr/bin/make 不是 /usr/bin/cmake

### 目录权限
```text
sudo chmod -R 777 /home/dev/whc
```
## Git
### command
```text
# 拉取远程
git pull origin main

# 直接推送
git push origin main

# 确认远程仓库地址正确
git remote -v   

# 绑定远程仓库地址
git remote set-url origin git@github.com:haichaowa/cpp-learn.git

首次推送（关联远程分支）
git push -u origin leetcode-mac
```

## github cli
### login
```text
# 生成git ssh协议秘钥:

ssh-keygen -t ed25519 -C "邮箱"

# win上git sshkey 路径:
C:\Users\用户名\.ssh 
# mac上git sshkey 路径:
/Users/wanghaichao/.ssh


# 将私钥匙上传到github
https://github.com/settings/keys

# 修改文件 ~/.ssh/config
Host github.com
  HostName ssh.github.com
  User git
  Port 443
  IdentityFile ~/.ssh/id_rsa  # 替换为你的私钥路径

# 校验sshkey与github是不是通的
ssh -T git@github.com

# 通过SSH的方式进行认证
gh auth login 

 PS D:\ProgrameFiles\Project\ClionProjects\cpp-learn> gh auth login 
? Where do you use GitHub? GitHub.com
? What is your preferred protocol for Git operations on this host? SSH
? Upload your SSH public key to your GitHub account? C:\Users\haichao\.ssh\id_ed25519.pub
? Title for your SSH key: (GitHub CLI) y9000p

? Title for your SSH key: y9000p
? How would you like to authenticate GitHub CLI? Paste an authentication token
Tip: you can generate a Personal Access Token here https://github.com/settings/tokens
The minimum required scopes are 'repo', 'read:org', 'admin:public_key'.
? Paste your authentication token: - gh config set -h github.com git_protocol ssh***********************************************
✓ Configured git protocol
✓ SSH key already existed on your GitHub account: C:\Users\haichao\.ssh\id_ed25519.pub
✓ Logged in as haichaowa
! You were already logged in to this account
```

### 常用命令
```text
# 通过web查看仓库
gh repo view --web 

# 检查登录状态
gh auth status 

# 通过gh创建PR
gh pr create --title "PR标题" --body "修改说明"
gh pr create --base main --head feature-branch --title "新功能" --body "详细说明"

# 查看最新提交
git log --oneline -n 3 

# 打开浏览器查看 PR
gh pr view --web  
```

### 无法使用push pull
```text
# 因使用https协议无法进行推送
PS D:\ProgrameFiles\Project\ClionProjects\cpp-learn> git push origin leetcode-mac
fatal: unable to access 'https://github.com/haichaowa/cpp-learn.git/': Failed to connect to github.com port 443 after 21096 ms: Timed out
PS D:\ProgrameFiles\Project\ClionProjects\cpp-learn> git remote -v
origin  https://github.com/haichaowa/cpp-learn.git (fetch)
origin  https://github.com/haichaowa/cpp-learn.git (push)

# 更改https协议为ssh
git remote set-url origin git@github.com:haichaowa/cpp-learn.git
```
