---
title: AOJ 865.青铜莲花池
date: 2017-05-05 11:42:03
categories: 题解
tags:
 - AOJ
 - BFS
 - 最短路
---

# 题目

{% fold 点击显/隐题目 %}
<div class="oj"><div class="part" title="Description">
为了让奶牛们娱乐和锻炼，农夫约翰建造了一个美丽的池塘。这个长方形的池子被分成了M行N列个方格（1 ≤ M, N ≤ 30）。一些格子是坚固得令人惊讶的莲花，还有一些格子是岩石，其余的只是美丽、纯净、湛蓝的水。
贝西正在练习芭蕾舞，她站在一朵莲花上，想跳到另一朵莲花上去，她只能从一朵莲花跳到另一朵莲花上，既不能跳到水里，也不能跳到岩石上。
贝西的舞步很像象棋中的马步：每次总是先横向移动M1 （1 ≤ M1 ≤ 30）格，再纵向移动M2 （1 ≤ M2 ≤ 30, M1 M2）格，或先纵向移动M1格，再横向移动M2格。最多时，贝西会有八个移动方向可供选择。
给定池塘的布局和贝西的跳跃长度，请计算贝西从起点出发，到达目的地的最小步数，我们保证输入数据中的目的地一定是可达的。

</div><div class="part" title="Input">
第一行：四个用空格分开的整数：M，N，M1和M2
第二行到M + 1行：第i + 1行有N个用空格分开的整数，描述了池塘第i行的状态：0 为水，1 为莲花，2 为岩石，3 为贝西所在的起点，4 为贝西想去的终点。

</div><div class="part" title="Output">
第一行：从起点到终点的最少步数

</div><div class="samp"><div class="clear"></div><div class="input part" title="Sample Input">
4 5 1 2 
1 0 1 0 1 
3 0 2 0 4 
0 1 2 0 0 
0 0 0 1 0 4 5 1 2 
1 0 1 0 1 
3 0 2 0 4 
0 1 2 0 0 
0 0 0 1 0

</div><div class="output part" title="Sample Output">
22

</div><div class="clear"></div></div></div>
{% endfold %}

<!--more-->
# 题解
标准的BFS问题,节点的拓展方式比较多  
题意为每一步是先跳到一个荷叶,再跳到另一片荷叶  
实际操作**不考虑中间的荷叶是否能走**


# 代码
{% fold 点击显/隐代码 %}```cpp 青铜莲花池 https://github.com/OhYee/ACM.github.io/blob/master/AOJ/865.%E9%9D%92%E9%93%9C%E8%8E%B2%E8%8A%B1%E6%B1%A0.cpp 代码备份
/*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int maxn = 35;
const int delta[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
int Map[maxn][maxn];

struct Point {
    int x, y;
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    bool operator==(const Point &rhs) const { return x == rhs.x && y == rhs.y; }
};

queue<Point> Q;
int dis[maxn][maxn];
int bfs(int m, int n, int d1, int d2, Point s, Point v) {
    memset(dis, 0, sizeof(dis));
    while (!Q.empty())
        Q.pop();

    Q.push(s);
    dis[s.x][s.y] = 0;

    while (!Q.empty()) {
        Point t = Q.front();
        Q.pop();
        if (t == v)
            break;

        for (int i = 0; i < 4; i++) {
            int xx = t.x + delta[i][0] * d1;
            int yy = t.y + delta[i][1] * d2;

            if (xx < 0 || xx >= m || yy < 0 || yy >= n)
                continue;
            if (dis[xx][yy] || Map[xx][yy] == 0 || Map[xx][yy] == 2)
                continue;
            // if (!(Map[t.x][yy] == 1 || Map[xx][t.y] == 1 || Map[t.x][yy] == 4 || Map[xx][t.y] == 4))
            //     continue;

            dis[xx][yy] = dis[t.x][t.y] + 1;
            Q.push(Point(xx, yy));
        }
        for (int i = 0; i <= 3; i++) {
            int xx = t.x + delta[i][0] * d2;
            int yy = t.y + delta[i][1] * d1;

            if (xx < 0 || xx >= m || yy < 0 || yy >= n)
                continue;
            if (dis[xx][yy] || Map[xx][yy] == 0 || Map[xx][yy] == 2)
                continue;
            // if (!(Map[t.x][yy] == 1 || Map[xx][t.y] == 1 || Map[t.x][yy] == 4 || Map[xx][t.y] == 4))
            //     continue;

            dis[xx][yy] = dis[t.x][t.y] + 1;
            Q.push(Point(xx, yy));
        }
    }
    return dis[v.x][v.y];
}

int main() {
#ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
#endif

    cin.tie(0);
    cin.sync_with_stdio(false);
    int M, N, M1, M2;
    Point s, v;
    while (scanf("%d%d%d%d", &M, &N, &M1, &M2) != EOF) {
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++) {
                scanf("%d", &Map[i][j]);
                if (Map[i][j] == 3) {
                    s.x = i;
                    s.y = j;
                }
                if (Map[i][j] == 4) {
                    v.x = i;
                    v.y = j;
                }
            }
    }
    printf("%d\n", bfs(M, N, M1, M2, s, v));
    // for (int i = 0; i < M; i++) {
    //     for (int j = 0; j < N; j++)
    //         printf("%d ", dis[i][j]);
    //     printf("\n");
    // }
#ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
#endif
    return 0;
}
```
{% endfold %}   30342,115430343,115430344,115430345,115430346,115430347,115430348,115430349,115430350,115430351,115430352,115430353,115430354,115430355,115430356,115430357,115430358,115430359,115430360,115430361,115430362,115430363,115430364,115430365,115430366,115430367,115430368,115430369,115430370,115430371,115430372,115430373,115430374,115430375,115430376,115430377,115430378,115430379,115430380,115430381,11