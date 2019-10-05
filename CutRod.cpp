#include <iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

int cutRod(vector<int> &p, int n){
	if (n == 0)
		return 0;
	int q = INT_MIN;
	for (int i = 1; i <= n&&i<p.size(); i++){
		q = max(q, p[i] + cutRod(p, n - i));
	}
	return q;
}

int memoizedCutRodAux(vector<int> &p, int n, vector<int> &r){
	if (r[n] >= 0)
		return r[n];
	int q;
	if (n == 0){
		q = 0;
	}
	else{
		q = INT_MIN;
		for (int i = 1; i <= n&&i<p.size(); i++){
			q = max(q, p[i] + memoizedCutRodAux(p, n - i, r));
		}
	}
	r[n] = q;
	return q;
}

int memoizedCutRod(vector<int> &p, int n){
	vector<int> r;
	for (int i = 0; i <= n; i++){
		r.push_back(INT_MIN);
	}
	return memoizedCutRodAux(p, n, r);
}

int* buttonUpCutRod(vector<int> &p, int n){
	int *r = new int[n + 1];
	r[0] = 0;
	for (int j = 1; j <= n; j++){
		int q = INT_MIN;
		for (int i = 1; i <= j&&i<p.size(); i++){
			q = max(q, p[i] + r[j - i]);
		}
		r[j] = q;
	}
	return r;
}

vector<int> init(){
	vector<int> p;
	p.push_back(0);
	p.push_back(1);
	p.push_back(5);
	p.push_back(8);
	p.push_back(9);
	p.push_back(10);
	p.push_back(17);
	p.push_back(17);
	p.push_back(20);
	p.push_back(24);
	p.push_back(30);
	return p;
}

int main() {
	vector<int> p = init();
	//int q= memoizedCutRod(p,30);
	//int q=cutRod(p,30);
	int *r = buttonUpCutRod(p, 40);
	for (int i = 0; i <= 40; i++){
		cout << "the length of rod is:" << i << "  the best price is:" << r[i] << endl;
	}
	cout << endl;
	//cout<<q<<endl;
	vector<int> test;
	getchar();
	return 0;
}
