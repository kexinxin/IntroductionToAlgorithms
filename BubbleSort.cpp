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
	v.push_back(7);
	v.push_back(8);
	v.push_back(15);
	v.push_back(3);
	v.push_back(5);
	int size=v.size();
	for(int i=0;i<size;i++){
		for(int j=0;j<size-i-1;j++){
			if(v[j]>v[j+1]){
				int temp=v[j];
				v[j]=v[j+1];
				v[j+1]=temp;
			}
		}
	}
	for(int i=0;i<size;i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	getchar();
	return 0;
}
