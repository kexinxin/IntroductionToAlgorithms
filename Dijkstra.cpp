#include<iostream>
#include<vector>
using namespace std;



const int MAXNUM = 10000;
void init(vector<vector<float> > &a, int size){
	for (int i = 0; i<size; i++){
		vector<float> v;
		for (int j = 0; j<size; j++){
			v.push_back(MAXNUM);
		}
		a.push_back(v);
	}
	a[1][1] = 0;
	a[1][2] = 10;
	a[1][4] = 30;
	a[1][5] = 100;
	a[2][2] = 0;
	a[2][3] = 50;
	a[3][3] = 0;
	a[3][5] = 10;
	a[4][3] = 20;
	a[4][4] = 0;
	a[4][5] = 60;
	a[5][5] = 0;
}

void print(vector<vector<float> > a){
	for (int i = 0; i<a.size(); i++){
		for (int j = 0; j<a.size(); j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void dijkstra(int v, vector<vector<float> > a, float *dist, int *prev){
	int n = a.size() - 1;
	if (v<1 || v>n){
		return;
	}
	bool *s = new bool[n + 1];
	for (int i = 1; i <= n; i++) {
		dist[i] = a[v][i];
		s[i] = false;
		if (dist[i] == MAXNUM)
			prev[i] = 0;
		else
			prev[i] = v;
	}
	dist[v] = 0;
	s[v] = true;
	for (int i = 1; i < n; i++) {
		float temp = MAXNUM;
		int u = v;
		//找到距离最小的节点
		for (int j = 1; j <= n; j++)
		if ((!s[j]) && (dist[j] < temp)) {
			u = j;
			temp = dist[j];
		}
		s[u] = true;
		//根据找到的节点更新所有的节点
		for (int j = 1; j <= n; j++)
		if ((!s[j]) && (a[u][j] < MAXNUM)) {
			float newdist = dist[u] + a[u][j];
			if (newdist < dist[j]) {
				dist[j] = newdist;
				prev[j] = u;
			}
		}
	}
}

void traceback(int v, int n, int *prev) {
	if (n == v)
		cout << n;
	else
		cout << n << "->";
	if (n == v)
		return;
	traceback(v, prev[n], prev);
}
int main(){
	int size = 6;
	vector<vector<float> > a;
	init(a, size);
	float *dist = new float[size + 1];
	int *prev = new int[size + 1];
	dijkstra(1, a, dist, prev);
	traceback(1, size - 1, prev);
	getchar();
}
