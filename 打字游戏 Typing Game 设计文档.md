# 打字游戏 Typing Game 设计文档

## 需求概述

程序实现一个带管理员后台的多用户的CLI打字游戏。游戏中打字内容设定难度分级，支持中文、英文及中英文混合，支持保存游戏记录。程序运行环境为Windows x64。

## 总体架构

- typing_game.h 实现相关的变量、函数、类的声明
- admin.cpp 实现管理员相关的操作
- system.cpp 实现游戏的初始化、游戏的存储等操作
- game.cpp 实现游戏的主要内容
- user.cpp 实现用户相关的操作
- main.cpp 实现程序主函数main()
- game.data 存储游戏数据

各模块间关系见流程图

![流程图](流程图.png)

### admin.cpp

主要用于实现管理员的操作：打字练习文本的增改删，用户管理，游戏设定调整

- GameTextAdd()

从控制台或指定文件路径获取新的打字练习文本

- GameTextEdit()

输出需要修改的原文本到控制台，管理员将其拷贝到文本编辑器修改后再从控制台输入。

- GameTextDelete()

删除指定的打字练习文本

- UserAllQuery()

获取所有的用户信息，输出到控制台

- UserQuery()

获取指定用户的信息，输出到控制台

- UserEdit()

在程序的引导下修改用户的包括密码在内的各项信息或删除用户

- GameLevelEdit()

修改游戏向用户开放的最低和最高难度

### system.cpp

- GameInitialize()

游戏初始化

- GameSave()

保存游戏但不退出

- GameExit()

退出游戏

### game.cpp

- RoundSelect()

引导用户选择游戏文本

- NewRound()

指定游戏文本，开始新游戏

- GetRank()

获取游戏所有用户战绩排名

- GetGameRecord()

获取当前用户的所有游戏记录

### user.cpp

- UserInitialize()

从文件初始化用户列表

- NewUser()

创建一个新用户

- QueryGameRecord()

查询指定用户所有游戏记录

- RankAllUser()

对所有用户进行一定规则的排序并返回

- UserProfileEdit()

引导用户修改个人资料

### 数据结构

几乎全部使用std::vector存储数据