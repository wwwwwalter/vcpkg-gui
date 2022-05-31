# vcpkg-gui
![](https://img.shields.io/github/contributors/wwwwwalter/vcpkg-gui?color=BrightGreen)
![](https://img.shields.io/github/issues-pr/wwwwwalter/vcpkg-gui)
![](https://img.shields.io/github/issues-pr-closed/wwwwwalter/vcpkg-gui)
![](https://img.shields.io/github/issues/wwwwwalter/vcpkg-gui)
![](https://img.shields.io/github/issues-closed/wwwwwalter/vcpkg-gui)
![](https://img.shields.io/github/release/wwwwwalter/vcpkg-gui)
![](https://img.shields.io/github/last-commit/wwwwwalter/vcpkg-gui)
![](https://img.shields.io/github/repo-size/wwwwwalter/vcpkg-gui)
![](https://img.shields.io/github/stars/wwwwwalter/vcpkg-gui)
[![github-watchers](https://img.shields.io/github/watchers/wwwwwalter/vcpkg-gui?label=Watch&style=social&logo=github)](https://github.com/wwwwwalter/vcpkg-gui)
[![github-stars](https://img.shields.io/github/stars/wwwwwalter/vcpkg-gui?style=social&logo=github)](https://github.com/wwwwwalter/vcpkg-gui)
[![github-forks](https://img.shields.io/github/forks/wwwwwalter/vcpkg-gui?label=Fork&style=social&logo=github)](https://github.com/wwwwwalter/vcpkg-gui)


Author: :boy:Albert  :email:  15221024927@163.com, C/C++ software engineer.

## With this software you can easily use Microsoft VCPKG package manager.

### build and install

```shell
new Qt git cmake ninja MSVC or MinGW
```



## :heartbeat: Welcome to contribute your wisdom to the repository.
**Some software you might use**

  * [Git](https://git-scm.com/docs)
  * [Fork](https://git-fork.com/)
  * [GitHub](https://docs.github.com/cn/get-started/quickstart/hello-world)
  * [Typora](https://pan.baidu.com/s/1L29j-3L2CfjRi2U7VFhT7Q?pwd=vc7p)
  * [Markdown](https://www.jianshu.com/p/191d1e21f7ed)

![Alt](https://repobeats.axiom.co/api/embed/e2ed4e96f3a6420e9a6234a77cd82ce8873fdf8c.svg "Repobeats analytics image")
---
**Step 1: GIt configuration** 

copy `help document/Git/.gitconfig` file to your home folder, like `C:/Users/gzyit`. This configuration file contains your identity and email address, as well as the configuration of some other functions. All Git clients will automatically search for this configuration file on your system. If the file is not found, they generate a new configuration file, which is not expected.

> Don't forget to change your name and email address to your own.

![image-20220525051015454](./images/image-20220525051015454.png)

**Step 2: ssh configuration**

If you don't want to manually enter the account name and password every time you submit a code, you're better off generating an SSH key pair locally. 

```shell
open git-shell
$ ssh-keygen
```

Running this command on a terminal will generate a .ssh directory with a pair of passwords in your user directory. The pub is the public key, and the other private key should be protected. Then copy the public key into your GitHub SSH manager.

![Snipaste_2022-05-25_05-21-21](./images/Snipaste_2022-05-25_05-21-21.png)



**Step 3: Git commit format**

In order to quickly see what was committed, we agreed to write the commit log in the following format.

```c
new file: + filename
edit file: * filename
delete file: - filename
```
