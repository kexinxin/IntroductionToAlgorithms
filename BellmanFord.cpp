#include<iostream>
#include<cstdio>
using namespace std;

#define MAX 100000
#define N 1010
int nodenum, edgenum, original; //点，边，起点

typedef struct Edge //边
{
    int u, v;
    int cost;
}Edge;

Edge edge[N];
int dis[N], pre[N];

bool Bellman_Ford()
{
    for (int i = 1; i <= nodenum; ++i) //初始化
        dis[i] = (i == original ? 0 : MAX);
    for (int i = 1; i <= nodenum - 1; ++i)
    for (int j = 1; j <= edgenum; ++j)
    if (dis[edge[j].v] > dis[edge[j].u] + edge[j].cost) //松弛
    {
        dis[edge[j].v] = dis[edge[j].u] + edge[j].cost;
        pre[edge[j].v] = edge[j].u;
    }
    bool flag = 1; //判断是否含有负权回路
    for (int i = 1; i <= edgenum; ++i)
    if (dis[edge[i].v] > dis[edge[i].u] + edge[i].cost)
    {
        flag = 0;
        break;
    }
    return flag;
}

void print_path(int root) //打印最短路的路径（反向）
{
    while (root != pre[root]) //前驱
    {
        cout << root << "<--";
        root = pre[root];
    }
    if (root == pre[root])
        cout << root;
}

void init(){
    int edgeCosts[][3] = { { 4, 6, 1 }, { 1, 2, 2 }, { 1, 3, 5 }, { 4, 1, 10 }, { 2, 4, 4 }, { 4, 2, 4 }, { 3, 4, 2 } };
    for (int i = 0; i <= edgenum; i++){
        edge[i].u = edgeCosts[i][0];
        edge[i].v = edgeCosts[i][1];
        edge[i].cost = edgeCosts[i][2];
    }


}

int main()
{
    nodenum = 4;
    edgenum = 6;
    original = 1;
    pre[original] = original;
    init();
    if (Bellman_Ford())
    for (int i = 1; i <= nodenum; ++i) //每个点最短路
    {
        cout << "Path:";
        print_path(i);
        cout << " cost:" << dis[i] << endl;
    }
    else
        printf("have negative circle\n");
    getchar();
    return 0;
}
