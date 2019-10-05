#include <iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
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

int randomzidPartition(vector<int> &v, int p, int r){
	int i = rand() % (r - p);
	int temp = v[i];
	v[i] = v[r];
	v[r] = temp;
	return partition(v, p, r);
}

int randomziedSelect(vector<int> &v, int p, int r, int i){
	if (p == r)
		return v[p];
	int q = randomzidPartition(v, p, r);
	int k = q - p;
	if (i == k)
		return v[q];
	else if (i<k)
		return randomziedSelect(v, p, q - 1, i);
	else
		return randomziedSelect(v, q + 1, r, i - k - 1);
}

int main() {
	vector<int> v;
	//	int num;
	//	while ((cin.get()) != '\n'){
	//		cin.unget();
	//		cin >> num;
	//		v.push_back(num);
	//	}
	v.push_back(15);
	v.push_back(25);
	v.push_back(35);
	v.push_back(10);
	int size = v.size();
	int number = randomziedSelect(v, 0, size - 1, 0);
	//返回的第i小的数字，i从0开始
	cout << number << endl;
	cout << endl;
	getchar();
	return 0;
}
