/*
By:OhYee
Github:OhYee
Email:oyohyee@oyohyee.com
Blog:http://www.cnblogs.com/ohyee/

かしこいかわいい？
エリーチカ！
要写出来Хорошо的代码哦~
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
using namespace std;

//DEBUG MODE
#define debug 0

//循环
#define REP(n) for(int o=0;o<n;o++)



const int maxn = 10;
int n,m;
char Map[maxn][maxn];


const int delta[4] = {1,-1,0,0};

struct point {
	int x,y;
	bool time;
	point(int a,int b,bool c) {
		x = a;
		y = b;
		time = c;
	}
};

int BFS(int s1,int s2,int v1,int v2) {
	priority_queue<pair<int,point>,> Q;
	//queue<point> Q;
	int dis[maxn][maxn];
	memset(dis,-1,sizeof(dis));

	#define distance(x1,y1) (-(abs(x1-v1)+abs(y1-v2)))

	Q.push(pair<int,point>(distance(s1,s2),point(s1,s2,false)));
	dis[s1][s2] = 0;
	while(!Q.empty()) {
		point temp = Q.top().second;
		Q.pop();

		int x = temp.x;
		int y = temp.y;
		bool time = temp.time;



		REP(4) {
			int xx = x + delta[o];
			int yy = y + delta[3 - o];
			bool tt = !time;

			if(xx < 0 || xx >= n || yy < 0 || yy >= m
				|| Map[xx][yy] == '*')
				continue;
			if(((Map[xx][yy] == '-'&& tt) || (Map[xx][yy] == '|'&&time)) && xx == x)
				yy += yy - y;
			if(((Map[xx][yy] == '-'&& time) || (Map[xx][yy] == '|'&&tt)) && yy == y)
				xx += xx - x;
			if(xx < 0 || xx >= n || yy < 0 || yy >= m
				|| Map[xx][yy] != '.')
				continue;




			if(dis[xx][yy] == -1) {
				dis[xx][yy] = dis[x][y] + 1;
				if(xx == v1 && yy == v2)
					break;
				Q.push(pair<int,point>(distance(xx,yy),point(xx,yy,tt)));
			}
		}
	}

	return dis[v1][v2];
}

bool Do() {
	int s1,v1;
	int s2,v2;
	if(scanf("%d%d\n",&n,&m) == EOF)
		return false;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			scanf("\n%c\n",&Map[i][j]);
			if(Map[i][j] == 'S') {
				s1 = i;
				s2 = j;
				Map[i][j] = '.';
			}
			if(Map[i][j] == 'T') {
				v1 = i;
				v2 = j;
				Map[i][j] = '.';
			}
		}
	printf("%d\n",BFS(s1,s2,v1,v2));
	return true;
}


int main() {
	while(Do());

	return 0;
}