#include <iostream>
#include<vector>
using namespace std;
int main() {
	vector<int> v;
	int num;
	//	while((cin.get())!='\n'){
	//		cin.unget();
	//		cin>>num;
	//		v.push_back(num);
	//	}
	v.push_back(5);
	v.push_back(15);
	v.push_back(7);
	v.push_back(12);
	int size = v.size();
	for (int i = 1; i<size; i++){
		int key = v[i];
		int index = i - 1;
		while (index >= 0 && v[index]>key){
			v[index + 1] = v[index];
			index = index - 1;
		}
		v[index + 1] = key;
	}
	cout << "the result of insertSort is :" << endl;
	for (int i = 0; i<size; i++){
		cout << v[i] << " ";
	}
	cout << endl;
	getchar();
	return 0;
}
