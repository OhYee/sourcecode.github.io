---
title: 博弈
date: 2016-06-26 21:19:38
categories: 算法
tags: 
 - 博弈
 - 巴什博奕
 - 威佐夫博奕
 - 尼姆博弈
 - Nim Staircase博奕
---
# 巴什博奕
只有一堆n个物品,两个人轮流从这堆物品中取物,规定每次至少取一个,最多取m个.最后取光者得胜.  
**若`(m+1)%n`，则先手必败，否则先手必胜**   

显然,如果`n=m+1`,那么由于一次最多只能取m个,所以,无论先取者拿走多少个,后取者都能够一次拿走剩余的物品,后者取胜.  
因此有取胜的法则：如果`n=(m+1)r+s`,(r为任意自然数,s≤m),那么先取者要拿走s个物品,如果后取者拿走k(≤m)个,那么先取者再拿走m+1-k个,结果剩下(m+1)(r-1)个,以后保持这样的取法,那么先取者肯定获胜.  
总之,要保持给对手留下(m+1)的倍数,就能最后获胜.  
<!--more-->
# 威佐夫博奕

有两堆各若干个物品,两个人轮流从某一堆或同时从两堆中取同样多的物品,规定每次至少取一个,多者不限,最后取光者得胜.  
**奇异局势下先手必败，非奇异局势下先手必胜。**  

这种情况下是颇为复杂的.我们用(ak,bk)(ak ≤bk ,k=0,1,2,...,n)表示两堆物品的数量并称其为局势 
如果甲面对(0,0),那么甲已经输了,这种局势我们称为奇异局势.  
前几个奇异局势是：(0,0)、(1,2)、(3,5)、(4,7)、(6,10)、(8,13)、(9,15)、(11,18)、(12,20).  
可以看出,a0=b0=0,ak是未在前面出现过的最小自然数,而bk= ak + k,奇异局势有如下三条性质：  
1. 任何自然数都包含在一个且仅有一个奇异局势中.  
由于ak是未在前面出现过的最小自然数,所以有`ak > ak-1` ,而`bk= ak + k > ak-1 + k-1 = bk-1 > ak-1` .所以性质1.成立.  
2. 任意操作都可将奇异局势变为非奇异局势.  
事实上,若只改变奇异局势(ak,bk)的某一个分量,那么另一个分量不可能在其他奇异局势中,所以必然是非奇异局势.如果使(ak,bk)的两  
个分量同时减少,则由于其差不变,且不可能是其他奇异局势的差,因此也是非奇异局势.  
3. 采用适当的方法,可以将非奇异局势变为奇异局势.  

假设面对的局势是(a,b),若`b = a`,则同时从两堆中取走a个物体,就变为了奇异局势(0,0)
如果`a = ak`,`b > bk`,那么,取走`b - bk`个物体,即变为奇异局势
如果`a = ak`,`b < bk`,则同时从两堆中拿走`ak - ab - ak`个物体,变为奇异局势( ab - ak , ab - ak+ b - ak)  
如果`a > ak`,`b= ak + k`,则从第一堆中拿走多余的数量`a - ak` 即可
如果`a < ak`,`b= ak + k`,分两种情况,第一种,`a=aj (j < k)`,从第二堆里面拿走`b - bj` 即可
第二种,`a=bj (j < k)`,从第二堆里面拿走b - aj 即可. 

从如上性质可知,两个人如果都采用正确操作,那么面对非奇异局势,先拿者必胜；反之,则后拿者取胜.  

那么任给一个局势(a,b),怎样判断它是不是奇异局势呢？我们有如下公式：  
**`ak = k(1+√5)/2 (下取整), bk= ak + k (k∈N)`**   
奇妙的是其中出现了有关黄金分割数的式子：(1+√5)/2 =1.618...,若两堆物品个数分别为x,y(x&lt;y)，则k=y-x，再判断x是否等于`[(y-x)*( √5+1)/2]`即可得知是否是奇异局势。  

# 尼姆博弈

有三堆各若干个物品,两个人轮流从某一堆取任意多的物品,规定每次至少取一个,多者不限,最后取光者得胜.    
  
这种情况最有意思,它与二进制有密切关系,我们用(a,b,c)表示某种局势,首先(0,0,0)显然是奇异局势,无论谁面对奇异局势,都必然失败.  
第二种奇异局势是(0,n,n),只要与对手拿走一样多的物品,最后都将导致(0,0,0).  
仔细分析一下,(1,2,3)也是奇异局势,无论对手如何拿,接下来都可以变为(0,n,n)的情形.  
计算机算法里面有一种叫做按位模2加,也叫做异或的运算,我们用符号xor表示这种运算.这种运算和一般加法不同的一点是1+1=0.  
先看(1,2,3)的按位模2加的结果：  
> 1 =二进制01
> Xor 2 =二进制10
> Xor 3 =二进制11 
> ———————
> 0 =二进制00 

对于奇异局势(0,n,n)也一样,结果也是0.  
任何奇异局势(a,b,c)都有`a xor b xor c =0`。该结论可以推广至若干堆，都是成立的  
如果我们面对的是一个非奇异局势(a,b,c),要如何变为奇异局势呢？  
假设`a < b< c`,我们只要将c 变为`a xor b`,即可,因为有如下的运算  
结果: `a xor b xor (a xor b)=(a xor a) xor (b xor b)=0 xor 0=0`.  
要将`c` 变为`a xor b`,只要从`c`中减去`c-(a xor b)`即可.  

# Nim Staircase博奕:
这个问题是尼姆博弈的拓展：    
游戏开始时有许多硬币任意分布在楼梯上，共n阶楼梯从地面由下向上编号为0到n。  
游戏者在每次操作时可以将楼梯j(1&lt;=j&lt;=n)上的任意多但至少一个硬币移动到楼梯j-1上。  
游戏者轮流操作，将最后一枚硬币移至地上（0号）的人获胜。  
算法：将奇数楼层的状态异或，和为0则先手必败，否则先手必胜。  
