---
title: 最小生成树
categories: 算法
tags:
  - 树
  - 最小生成树
  - Kruskal
  - Prim
date: 2016-03-26 23:23:00
---
**最小生成树**

> 对于无向图G=(V,E)，连接G中所有点，且边集是E的子集的树成为G的生成树

> 其中权值最小的生成树叫做最小生成树(MST)

 

# Kruskal算法

Kruskal算法 是一种最小生成树算法。

```

首先对所有边按照权值进行排序

初始化连通分量(并查集)

初始化树

循环考察每条边

　　如果边的两个节点不在同一个连通分量

　　　　将这个边插入到树中

　　　　将两个节点对应的连通分量合并 
```
 

# Prim算法

Prim算法是另一种最小生成树算法。

```

对所有边按照权值排序

初始化集合S[i]为false

声明队列Q

将所有边加入到Q中

队列不为空

若Q的最顶部的两个节点不全在集合中

　　将两个点加入到集合中

　　将边插入到树中

否则

　　从队列中删除这条边
```
 

两种最小生成树的算法，大概思路都是对边排序后，将不会产生环的边逐个加入到树中

 