#include <iostream>
using namespace std;

#define NUM 50

//这里假设 w[], v[] 已按要求排好序
void Knapsack(int n, float M, float v[], float w[], float x[])
{
	int i;
	for (i = 1; i <= n; i++) x[i] = 0;    //初始化数组
	float c = M;
	for (i = 1; i <= n; i++)                //全部被装下的物品,且将 x[i] = 1
	{
		if (w[i]>c) break;
		x[i] = 1;
		c -= w[i];
	}

	if (i <= n) x[i] = c / w[i];  //将物品i 的部分装下
}

int main()
{
	float M = 50;                //背包所能容纳的重量
	float w[] = { 0, 10, 20, 30 };   //这里给定的物品按价值降序排序
	float v[] = { 0, 60, 100, 120 };
	float x[NUM];                //存储每个物品装入背包的比例

	int n = (sizeof(w) / sizeof(w[0])) - 1;

	Knapsack(n, M, v, w, x);

	for (int i = 1; i <= n; i++)
		cout << "item " << i << " load rate: " << x[i] << endl;
	getchar();
	return 0;
}
