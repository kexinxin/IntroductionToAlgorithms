#include <stdio.h>
#include<iostream>
using namespace std;

const int MAXNUM = 100000;


//基本思想是：最开始只允许经过1号顶点进行中转，接下来只允许经过1和2号顶点
//进行中转......允许经过1~n号所有顶点进行中转，求任意两点之间的最短路程。
//用一句话概括就是：从i号顶点到j号顶点只经过前k号点的最短路程。其实这是一种“动态规划”的思想。
void floydWarshall(int **e, int size){
	for (int k = 1; k <= size; k++)
	for (int i = 1; i <= size; i++)
	for (int j = 1; j <= size; j++)
	if (e[i][j]>e[i][k] + e[k][j])
		e[i][j] = e[i][k] + e[k][j];
}

void init(int **e, int size){
	//初始化
	for (int i = 1; i <= size; i++)
	for (int j = 1; j <= size; j++)
	if (i == j) e[i][j] = 0;
	else e[i][j] = MAXNUM;
	e[1][2] = 2;
	e[1][3] = 6;
	e[1][4] = 4;
	e[2][3] = 3;
	e[3][1] = 7;
	e[3][4] = 1;
	e[4][1] = 5;
	e[4][3] = 12;
}

void print(int **e, int size){
	//输出最终的结果
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			printf("%10d", e[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int size = 4;
	int **e = new int*[size + 1];
	for (int i = 0; i <= size; i++){
		e[i] = new int[size + 1];
	}
	init(e, size);
	floydWarshall(e, size);
	print(e, size);
	getchar();
}
