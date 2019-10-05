#include <iostream>
#include<vector>
#include<string>
using namespace std;

void init(vector<char> &x, vector<char> &y){
	x.push_back('0');
	x.push_back('A');
	x.push_back('B');
	x.push_back('C');
	x.push_back('B');
	x.push_back('D');
	x.push_back('A');
	x.push_back('B');
	y.push_back('0');
	y.push_back('B');
	y.push_back('D');
	y.push_back('C');
	y.push_back('A');
	y.push_back('B');
	y.push_back('A');
}

void LCSLENGTH(vector<char> x, vector<char> y, string **b, int **c){
	int m = x.size();
	int n = y.size();
	for (int i = 1; i<m; i++){
		c[i][0] = 0;
	}
	for (int j = 0; j<n; j++){
		c[0][j] = 0;
	}
	for (int i = 1; i<m; i++){
		for (int j = 1; j<n; j++){
			if (x[i] == y[j]){
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = "t";
			}
			else if (c[i - 1][j] >= c[i][j - 1]){
				c[i][j] = c[i - 1][j];
				b[i][j] = "u";
			}
			else{
				c[i][j] = c[i][j - 1];
				b[i][j] = "l";
			}
		}
	}
}

void printLCS(string **b, vector<char> x, int i, int j){
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == "t"){
		printLCS(b, x, i - 1, j - 1);
		cout << x[i];
	}
	else if (b[i][j] == "u"){
		printLCS(b, x, i - 1, j);
	}
	else{
		printLCS(b, x, i, j - 1);
	}
}

int main() {
	vector<char> x;
	vector<char> y;
	init(x, y);
	int xSize = x.size();
	int ySize = y.size();
	int **c = new int*[xSize];
	string **b = new string*[xSize];
	for (int i = 0; i<xSize; i++)
	{
		b[i] = new string[ySize];
		c[i] = new int[ySize];
	}
	LCSLENGTH(x, y, b, c);
	cout << "the LCSLENGTH is:" << endl;
	//cout<<c[xSize-1][ySize-1]<<endl;
	printLCS(b, x, xSize - 1, ySize - 1);
	getchar();
}
