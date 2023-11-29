# 🦄爪哇后端第一次考核

[toc]

## 🏨晨曦酒店_C语言项目💯

**([New-Dawn-Hotel_C](https://github.com/aaaaabin/New-Dawn-Hotel_C/tree/main))**

### 🍬项目介绍

在11.27下午，艰难的看完了最后几个可变数组，链表（虽然这里没用上），开始了后端组的第一次考核，持续奋战至11.29凌晨，封包成功。其中最困难的是**从0开始学习文件的输入的输出，实现数据的持久化，也即程序关闭之后，用户、房间等的信息不会消失，而是被保存到磁盘中，下次运行程序时可以被重新加载。**几乎整个周二都在思考这个问题，因为每次重新启动程序都会把原有数据覆盖😭。最后在各种粗制滥造，一个**小而美**的==晨曦酒店==诞生了，成为了**Abin**的结课之作。

![1.png](https://github.com/aaaaabin/New-Dawn-Hotel_C/blob/main/image/1.png?raw=true)



### 🍭项目特征

1. 该项目**100%**使用C语言；
2. 该程序既包含了**用户**程序也包含了**管理员**程序，但进入**管理员**程序需要输入密码；
3. 实现酒店房间的增删改查：
   - 只有管理员才能对酒店房间进行删除和权限增加。
   - 顾客可以订房间，需要输入相应票面。
   - 顾客可以查询房间的类型、价格、剩余数量、预订等。
4. 实现数据的**持久化**，也即程序关闭之后，用户、房间等的信息不会消失，而是被保存到磁盘中，下次运行程序时可以被重新加载；
5. 没有好看的前端界面，使用命令行窗口代替。

### 🍳项目功能

#### 1.程序主界面

![1.png](https://github.com/aaaaabin/New-Dawn-Hotel_C/blob/main/image/1.png?raw=true)

- 简洁的外观，小而强大的功能，更适合新一代年轻人的UI界面！

- 程序主界面便写出了本酒店的**剩余房间**，使用劲爆的**价格提醒**，引人哄抢。

- 输入**0**即可退出程序，高效！

  

#### 2.用户_查询预订

![2.png](https://github.com/aaaaabin/New-Dawn-Hotel_C/blob/main/image/2.png?raw=true)

程序内预置了一位已入住的顾客**Trashwbin**，预留电话号码为**119**，我们分别输入后，即可查询到**Trashwbin**的预订信息，包括**：房间号、预订时长和所付房费。**如果输入信息有误或未预订房间，将提示**查询失败**字样，考虑周到。



#### 3.用户_预订房间

![3.png](https://github.com/aaaaabin/New-Dawn-Hotel_C/blob/main/image/3.png?raw=true)

由于**经费问题**，==晨曦酒店==目前只能提供一种房型可供选择，毕竟**房价**摆在那，俺们**经济实惠**。

现在我们让**Abin**入住，他输入的票面是222，相应的，酒店将**找零**，当然，如果票面刚好相等，是**不会找零**的，如图：![3.1.png](https://github.com/aaaaabin/New-Dawn-Hotel_C/blob/main/image/3.1.png?raw=true)

当然当然，如果你钱不够，当然会**预订失败**的！

现在，我们来查询一下**Abin**的入住信息：![4.png](https://github.com/aaaaabin/New-Dawn-Hotel_C/blob/main/image/4.png?raw=true)

查询成功！！



#### 4.用户_管理员入口

我们的管理员入口当然是需要**输入正确密码**才能进入，预置的管理员密码为：==**admin**==，如果密码错误，当然是进不去哒：

![5.png](https://github.com/aaaaabin/New-Dawn-Hotel_C/blob/main/image/5.png?raw=true)

现在我们输入正确的**管理员密码：**==**admin**==，成功进入！

![6.png](https://github.com/aaaaabin/New-Dawn-Hotel_C/blob/main/image/6.png?raw=true)

此时，我们便可以看到**管理员菜单**的功能，也是相当的**强大**，==**遥遥领先**==同行！



#### 5.管理员_查询入住房间

该功能能一键查询所有入住房间的用户信息，便于管理和**操作退房**。

![7.png](https://github.com/aaaaabin/New-Dawn-Hotel_C/blob/main/image/7.png?raw=true)



#### 6.管理员_超级开房

来自管理员的**一键开房**功能，使开房**无需额外支付**，快人一步！！

![8.png](https://github.com/aaaaabin/New-Dawn-Hotel_C/blob/main/image/8.png?raw=true)

为了彰显软件的**美**，我们选用了==**“抓马 部落”**==作为测试数据。经过测试可以发现，无论是多么奇怪的名字，都能办理入住我们酒店，**遥遥领先！！**



#### 7.管理员_用户退房

我们先来看看此时我们所有入住了的房间，就决定对**抓马**下手了！

![9.png](https://github.com/aaaaabin/New-Dawn-Hotel_C/blob/main/image/9.png?raw=true)

操作也是相当快捷，只需要输入**抓马**的**房间号**即可，此时显示我们退房成功。

![10.png](https://github.com/aaaaabin/New-Dawn-Hotel_C/blob/main/image/10.png?raw=true)

再次查询可以发现，**抓马**已经退房了。

![11.png](https://github.com/aaaaabin/New-Dawn-Hotel_C/blob/main/image/11.png?raw=true)

ok，以上就是该程序的所有功能，**感谢观看！**



### 🚀LAST

这个程序吧，写的很烂，我知道。用的是死循环，当误输入字母，会导致程序死循环且反复输入菜单，是个头大的问题，现在11.30凌晨，经过周三一天的**满课=早八~晚八**，在空余时间从**0**接触**Markdown**，最后用**Typora**写下了这篇README.md，写的不好，望见谅🙏🏻🙏🏻🙏🏻🙏🏻。

剩下的周四，去完成**算法组**那个考核，还差几题😭

然后放假！

# Hello Word！

