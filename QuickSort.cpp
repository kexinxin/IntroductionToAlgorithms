#include <iostream>
#include<vector>
using namespace std;
int partition(vector<int> &v, int p, int r){
	int x = v[r];
	int i = p - 1;
	for (int j = p; j < r; j++){
		if (v[j] <= x){
			i = i + 1;
			int temp = v[i];
			v[i] = v[j];
			v[j] = temp;
		}
	}
	int temp = v[i + 1];
	v[i + 1] = v[r];
	v[r] = temp;
	return i + 1;
}
void quickSort(vector<int> &v, int p, int r){
	if (p<r){
		int q = partition(v, p, r);
		quickSort(v, p, q - 1);
		quickSort(v, q + 1, r);
	}
}
int main() {
	vector<int> v;
	//	int num;
	//	while ((cin.get()) != '\n'){
	//		cin.unget();
	//		cin >> num;
	//		v.push_back(num);
	//	}
	v.push_back(6);
	v.push_back(15);
	v.push_back(25);
	v.push_back(16);
	v.push_back(10);
	v.push_back(5);
	int size = v.size();
	quickSort(v, 0, size - 1);
	for (int i = 0; i<size; i++){
		cout << v[i] << " ";
	}
	cout << endl;
	getchar();
	return 0;
}
