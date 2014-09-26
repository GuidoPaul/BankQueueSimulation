BankQueueSimulation
===================

### This is a Bank Queue Simulation Program.

## 银行的排队策略：
先来先服务，客人分成VIP客人及普通客人，VIP客人可以直接享受服务，
普通客人需要排队等待服务，当服务柜台有空闲时，队首客人接受服务。

## 具体功能

### 程序具有如下六个菜单项：

1、顾客到达（选择该菜单后，再根据用户选择，区别两种级别的客人类型）

2、顾客离开（输入离开的顾客及接受服务的柜台号，并给出评价，
排队中的队首顾客应该取得服务资格）

3、查看业务办理情况（显示目前正在接受服务的柜台和顾客对应关系）

4、查看排队情况（显示目前等待的人数及相应顾客编号）

5、系统查询（显示服务了多少顾客，及平均服务时间）

6、退出系统

## 如何运行

该程序支持在Linux下运行， cd 进入 src 目录

    chmod +x main
    ./main
  
## 如何调式

该程序的所有函数都已经写成了一个个 .cpp 文件，所以只需要修改相应的 .cpp 文件即可。
修改后，需要执行 go 脚本，重新生成 main 可执行文件

    chmod +x go
    ./go
    ./main
