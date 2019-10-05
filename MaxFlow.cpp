//Ford-Fulkerson方法
//为什么叫Ford-Fulkerson方法而不是算法，原因在于可以用多种方式实现这一方法，
//方式并不唯一。
//下面介绍一种基于广度优先搜索(BFS)来计算增广路径P的算法：Edmonds-Karp算法。
#include <iostream>
#include <queue>
#include<cstring>
#include<limits.h>
using namespace std;

const int N = 210;
const int INF = INT_MAX; //无穷大
int m = 4;   //边的数量
int n = 5;   //节点数量：这里为查看方便，节点编号从1~4编号
//图的连接关系与边的容量数据
float edgeCosts[][3] = { { 1, 2, 40 }, { 1, 4, 20 }, { 2, 4, 20 }, { 2, 3, 30 }, { 3, 4, 10 } };
//广度优先搜索
int bfs(int **map, int *path, int *flow, int start, int end){
	for (int i = 0; i < m + 1; i++){
		path[i] = -1;
	}
	int  t;
	queue<int> q;
	while (!q.empty()) q.pop();
	path[start] = 0;
	flow[start] = INF;
	q.push(start);
	while (!q.empty())    {
		t = q.front();              //取队列的首元素
		q.pop();                    //把队列首元素弹出
		if (t == end) break;
		for (int i = 1; i <= m; i++){
			if (i != start && path[i] == -1 && map[t][i]) {
				flow[i] = flow[t] < map[t][i] ? flow[t] : map[t][i];
				q.push(i);
				path[i] = t;
			}
		}
	}
	if (path[end] != -1){
		int temp = end;
		cout << "bfs path:" << temp << " ";
		if (path[end] != -1){
			while (path[temp] != 0){
				cout << path[temp] << " ";
				temp = path[temp];
			}
		}
		cout << "this path can increase flow is:" << flow[end] << endl;
	}

	if (path[end] == -1)
		return -1;
	return flow[end];                   //一次遍历之后的流量增量
}

int Edmonds_Karp(int** map, int *path, int *flow, int start, int end){
	int max_flow = 0, step, now, pre;
	while (true) {
		step = bfs(map, path, flow, start, end);
		if (step == -1) break;      //找不到增路径时退出
		max_flow += step;
		now = end;
		while (now != start) {
			pre = path[now];
			map[pre][now] -= step;      //更新正向边的实际容量
			map[now][pre] += step;      //添加反向边
			now = pre;
		}
	}
	return max_flow;
}

void init(int **map, int *flow, int *path, int size){
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			map[i][j] = 0;
		}
	}
	for (int i = 0; i < size; i++){
		flow[i] = 0;
		path[i] = -1;
	}
}

int main() {
	//用邻接矩阵表示图的邻接关系，初始化所有权重为0
	int **map, *path, *flow, start, end;
	map = new int*[m + 1];
	for (int i = 0; i<m + 1; i++){
		map[i] = new int[m + 1];
	}
	path = new int[m + 1];
	flow = new int[m + 1];
	init(map, flow, path, m + 1);


	for (int i = 0; i < n; i++)
		map[(int)edgeCosts[i][0]][(int)edgeCosts[i][1]] = edgeCosts[i][2];

	start = 1;    //搜索源点
	end = m;      //搜索汇点

	//计算图的最大流
	int maxflow = Edmonds_Karp(map, path, flow, start, end);           //计算最大流
	cout << "the maxflow is:" << maxflow; //输出
	getchar();
	return 0;
}
