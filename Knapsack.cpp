#include <iostream>
#include<time.h>
#include<vector>
#include<algorithm>
using namespace std;
const int mSize = 100;
void init(vector<int> &v, vector<int> &w){
	v.push_back(0);
	v.push_back(6);
	v.push_back(3);
	v.push_back(5);
	v.push_back(4);
	v.push_back(6);
	w.push_back(0);
	w.push_back(2);
	w.push_back(2);
	w.push_back(6);
	w.push_back(5);
	w.push_back(4);
}


//m中的第二个数表示包的大小，第一个数表示放入的东西的个数，最开始从最大的物品开始放入，然后再放入第二大的物品
void knapsack(vector<int> w, vector<int> v, int c, int **m){
	int n = v.size() - 1;
	int jMax = min(w[n] - 1, c);
	for (int j = 0; j <= jMax; j++){
		m[n][j] = 0;
	}
	for (int j = w[n]; j <= c; j++){
		m[n][j] = v[n];
	}
	for (int i = n - 1; i>1; i--){
		jMax = min(w[i] - 1, c);
		for (int j = 0; j <= jMax; j++)
			m[i][j] = m[i + 1][j];
		for (int j = w[i]; j <= c; j++)
			m[i][j] = max(m[i + 1][j], m[i + 1][j - w[i]] + v[i]);
	}
	m[1][c] = m[2][c];
	if (w[1] <= c) {
		m[1][c] = max(m[2][c], m[2][c - w[1]] + v[1]);
	}
}

void trackback(int *x, int **m, int c, vector<int> w) {
	int n = w.size() - 1;
	for (int i = 1; i < n; i++) {
		if (m[i][c] == m[i + 1][c])
			x[i] = 0;
		else {
			x[i] = 1;
			c -= w[i];
		}
	}
	x[n] = (m[n][c] > 0) ? 1 : 0;
}


int main(){
	vector<int> v;
	vector<int> w;
	int c = 10;
	init(v, w);
	int **m = new int*[mSize];
	for (int i = 0; i<v.size(); i++){
		m[i] = new int[mSize];
	}
	knapsack(w, v, c, m);
	int *x = new int[v.size()];
	trackback(x, m, c, w);
	for (int i = 1; i<v.size(); i++){
		cout << " " << x[i] << endl;
	}
	getchar();
}
