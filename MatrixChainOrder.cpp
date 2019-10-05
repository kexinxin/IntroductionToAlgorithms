#include <iostream>
#include<vector>
#include<limits.h>
using namespace std;

struct Maxtrix{
	int rows;
	int columns;
};

vector<int> init(){
	vector<int> p;
	p.push_back(30);
	p.push_back(35);
	p.push_back(15);
	p.push_back(5);
	p.push_back(10);
	p.push_back(20);
	p.push_back(25);
	return p;
}

void matrixChainOrder(vector<int> p, int **m, int **s){
	int n = p.size() - 1;
	for (int i = 1; i <= n; i++){
		m[i][i] = 0;
	}
	//l表示每次迭代时i,j之间的长度,i表示起始位置，j表示结束位置,k表示i与j之间的位置
	for (int l = 2; l <= n; l++){
		for (int i = 1; i <= n - l + 1; i++){
			int j = i + l - 1;
			m[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; k++){
				int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q<m[i][j]){
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}

void printOptimalParsens(int **s, int i, int j){
	if (i == j)
		cout << "A";
	else{
		cout << "(";
		printOptimalParsens(s, i, s[i][j]);
		printOptimalParsens(s, s[i][j] + 1, j);
		cout << ")";
	}
}

int main() {
	vector<int> p = init();
	int size = p.size() + 1;
	int **m = new int*[size];
	int **s = new int*[size];
	for (int i = 0; i<size; i++)
	{
		s[i] = new int[size];
		m[i] = new int[size];
	}
	matrixChainOrder(p, m, s);
	printOptimalParsens(s, 1, 6);
	getchar();
}
