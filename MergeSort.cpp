#include <iostream>
#include<vector>
#include<math.h>
#include<limits.h>
using namespace std;

void merge(vector<int> &v, int p, int q, int r){
	int a = q - p;
	int b = r - q + 1;
	int *L = new int[a + 1];
	int *R = new int[b + 1];
	for (int i = 0; i < a; i++){
		L[i] = v[p + i];
	}
	for (int i = 0; i < b; i++){
		R[i] = v[q + i];
	}
	L[a] = INT_MAX;
	R[b] = INT_MAX;
	int i = 0;
	int j = 0;
	for (int k = p; k <= r; k++){
		if (L[i] <= R[j]){
			v[k] = L[i];
			i++;
		}
		else{
			v[k] = R[j];
			j++;
		}
	}
}

void mergeSort(vector<int> &v, int p, int r){
	if (p < r){
		int q = floor((p + r) / 2);
		mergeSort(v, p, q);
		mergeSort(v, q + 1, r);
		merge(v, p, q + 1, r);
	}
}
int main() {
	vector<int> v;
	//	int num;
	//		while ((cin.get()) != '\n'){
	//			cin.unget();
	//			cin >> num;
	//			v.push_back(num);
	//		}
	v.push_back(6);
	v.push_back(12);
	v.push_back(16);
	v.push_back(2);
	v.push_back(5);
	int size = v.size();
	mergeSort(v, 0, size - 1);
	for (int i = 0; i<size; i++){
		cout << v[i] << " ";
	}
	cout << endl;
	getchar();
	return 0;
}
