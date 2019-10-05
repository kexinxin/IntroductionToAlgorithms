#include<iostream>
#include<string>
using namespace std;
#define NUM 27 //字母数(叶子节点)
#define TNUM 53 //(总的节点个数)
#define LTH 15 //编码最大长度
struct Node{
	char date;
	int weight;
	Node *parent;
	Node *lchild;
	Node *rchild;
};
int main(){
	char chars[] = { ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	int weight[] = { 183, 64, 13, 22, 32, 103, 21, 15, 47, 57, 1, 5, 32, 20, 57, 63, 15, 1, 48, 51, 80, 23, 8, 18, 1, 16, 1 };
	Node *node[TNUM];
	for (int i = 0; i <TNUM; i++){
		node[i] = new Node;
	}
	//初始化叶子节点
	for (int i = 0; i<NUM; i++){
		node[i]->date = chars[i];
		node[i]->parent = NULL;
		node[i]->weight = weight[i];
		node[i]->lchild = NULL;
		node[i]->rchild = NULL;
	}
	//初始化中间节点
	for (int i = NUM; i<TNUM; i++){
		node[i]->parent = NULL;
		node[i]->weight = -1;
		node[i]->lchild = NULL;
		node[i]->rchild = NULL;
	}
	//找出没有父节点的最小的两个节点one,two。并合并one节点和two节点到一个新的节点j
	for (int i = NUM; i <TNUM; i++){
		int one = 10000;
		int two = 10000;
		int a = 0;
		int b = 0;
		int j = 0;
		for (; j < i; j++){
			if (node[j]->parent == NULL){
				if (node[j]->weight <= one){
					two = one;
					b = a;
					one = node[j]->weight;
					a = j;
				}
				else if (node[j]->weight>one&&node[j]->weight <= two){
					two = node[j]->weight;
					b = j;
				}
			}

		}
		node[j]->lchild = node[a];
		node[j]->rchild = node[b];
		node[a]->parent = node[j];
		node[b]->parent = node[j];
		node[j]->weight = node[a]->weight + node[b]->weight;

	}
	//定义数组来存储哈夫曼编码并初始化,用7作为编码结束的标志。
	char HT[NUM][LTH];
	for (int i = 0; i < LTH; i++){
		for (int j = 0; j <NUM; j++){
			HT[j][i] = '7';
		}
	}
	for (int i = 0; i < NUM; i++){
		int j = LTH - 1;
		Node *m = node[i];
		while (m->parent != NULL){
			Node *temp = m->parent;
			if (m == temp->lchild){
				HT[i][j] = '0';
			}
			if (m == temp->rchild) {
				HT[i][j] = '1';
			}
			m = m->parent;
			j--;
		}
	}
	//将编码存到s数组中
	string s[NUM];
	for (int i = 0; i<NUM; i++)
	{
		for (int j = 0; j<LTH; j++)
		{
			if (HT[i][j] != '7')
			{
				s[i].append(1, HT[i][j]);
			}
		}
	}
	for (int i = 0; i < NUM; i++){
		cout << node[i]->date << "   " << s[i] << endl;
	}
	//编码
	string code;
	string input;
	cout << "please enter the word  :";
	cin >> input;
	for (int i = 0; i <input.size(); i++){
		code.append(s[input.at(i) - 'a' + 1]);
	}
	cout << code << endl;
	//译码
	string yima;
	//根据二叉树的构造,node[TNUM-1]为根节点
	Node* head = node[TNUM - 1];
	for (int i = 0; i < code.size(); i++){
		if (code.at(i) == '1'&&head->rchild != NULL)
			head = head->rchild;
		if (code.at(i) == '0'&&head->lchild != NULL)
			head = head->lchild;
		if (head->lchild == NULL){
			yima.append(1, head->date);
			head = node[TNUM - 1];
		}

	}
	cout << "the word is: " << yima << endl;
	system("pause");
}
