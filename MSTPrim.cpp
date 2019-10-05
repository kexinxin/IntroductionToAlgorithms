#include<iostream>
#include<limits.h>
using namespace std;

void prim(int n, float c[7][7]){

}

void addEdge(float **c, int start, int end, int weight){
	c[start][end] = weight;
	c[end][start] = weight;
}

void init(float **c, int size){
	int m = INT_MAX;
	addEdge(c, 1, 2, 6);
	addEdge(c, 1, 3, 1);
	addEdge(c, 1, 4, 5);
	addEdge(c, 1, 5, m);
	addEdge(c, 1, 6, m);
	addEdge(c, 2, 3, 5);
	addEdge(c, 2, 4, m);
	addEdge(c, 2, 5, 3);
	addEdge(c, 2, 6, m);
	addEdge(c, 3, 4, 5);
	addEdge(c, 3, 5, 6);
	addEdge(c, 3, 6, 4);
	addEdge(c, 4, 5, m);
	addEdge(c, 4, 6, 2);
	addEdge(c, 4, 5, m);
	addEdge(c, 5, 6, 6);
}

void print(float **c, int size){
	for (int i = 0; i<size; i++){
		for (int j = 0; j<size; j++){
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
}

void prim(int n, float **c){
	float *lowcost = new float[n + 1]; // lowcost[j]用来表示与j的距离最小值为lowcost[j]
	int *closest = new int[n + 1]; // closest[j]标志j与哪一号已经标志的序号的距离最小,也就是相连接的节点
	bool *s = new bool[n + 1];// s[j]用来标志j是否已经选中了
	s[1] = true;
	//只有一个节点的时候初始化lowcost,closest
	for (int i = 2; i <= n; i++){
		lowcost[i] = c[1][i];
		closest[i] = 1;
		s[i] = false;
	}
	//还需要找总节点数-1个节点
	for (int i = 1; i<n; i++){
		float min = INT_MAX;
		int j = 1;
		for (int k = 2; k <= n; k++){
			//找到与已经选中的点的最小值
			if ((lowcost[k] < min) && (!s[k])){
				min = lowcost[k];
				j = k;
			}
		}
		cout << j << "," << closest[j] << endl;
		s[j] = true;
		//初始化其他点与（增加节点J之后）的最小值
		for (int k = 2; k <= n; k++){
			if ((c[j][k]<lowcost[k]) && (!s[k])){
				lowcost[k] = c[j][k];
				closest[k] = j;
			}
		}
	}
}

int main(){
	int size = 7;
	float **c = new float*[size];
	c = new float*[size];
	for (int i = 0; i<size; i++){
		c[i] = new float[size];
	}
	init(c, size);
	prim(size - 1, c);
	getchar();
}
