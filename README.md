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