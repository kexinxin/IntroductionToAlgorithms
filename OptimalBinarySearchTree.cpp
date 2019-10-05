#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
void init(vector<double> &p, vector<double> &q){
	p.push_back(0);
	p.push_back(0.15);
	p.push_back(0.10);
	p.push_back(0.05);
	p.push_back(0.10);
	p.push_back(0.20);
	q.push_back(0.05);
	q.push_back(0.10);
	q.push_back(0.05);
	q.push_back(0.05);
	q.push_back(0.05);
	q.push_back(0.10);
}

void optimalBST(vector<double> p, vector<double> q, int n, double **e, double **w, int **root){
	for (int i = 1; i <= n; i++){
		e[i][i - 1] = q[i - 1];
		w[i][i - 1] = q[i - 1];
	}
	for (int l = 1; l<n; l++){
		for (int i = 1; i<n - l + 1; i++){
			int j = i + l - 1;
			e[i][j] = INT_MAX;
			w[i][j] = w[i][j - 1] + p[j] + q[j];
			for (int r = i; r <= j; r++){
				double t = e[i][r - 1] + e[r + 1][j] + w[i][j];
				if (t<e[i][j]){
					e[i][j] = t;
					root[i][j] = r;
				}
			}
		}
	}
}

int main(){
	vector<double> p;
	vector<double> q;
	init(p, q);
	int xSize = p.size();
	int ySize = q.size();
	double **e = new double*[xSize + 1];
	int **root = new int*[xSize];
	double **w = new double*[xSize + 1];
	for (int i = 0; i<xSize + 1; i++){
		e[i] = new double[ySize];
		w[i] = new double[ySize];
	}
	for (int i = 0; i<xSize; i++){
		root[i] = new int[ySize];
	}
	optimalBST(p, q, xSize, e, w, root);
	for (int i = 1; i<xSize; i++){
		cout << endl;
		for (int j = 0; j<i; j++){
			cout << " " << " ";
		}
		for (int j = i; j<xSize; j++){
			cout << root[i][j] << " ";
		}
	}
	getchar();
}
