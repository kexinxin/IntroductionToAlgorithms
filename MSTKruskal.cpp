#include<iostream>
#include<queue>
using namespace std;

struct EdgeNode{
	int u, v;
	int weight;
	bool operator < (const EdgeNode &edgeNode) const {
		return weight>edgeNode.weight;//最小值优先
	}
};

int *id;//用于并查集的索引
int totolcount;//一共有几个类别

void initUnionSet(int numNodes){
	id = new int[numNodes + 1];
	for (int i = 0; i <= numNodes; i++){
		id[i] = i;
	}
	totolcount = 0;
}
int findSet(int p){
	return id[p];
}

void unionSet(int p, int q, int numNodes){
	//获得p和q的组号
	int pID = findSet(p);
	int qID = findSet(q);
	//如果两个组号相等，直接返回
	if (pID == qID){
		return;
	}
	//遍历一次，改变组号使他们属于一个组
	for (int i = 0; i<numNodes + 1; i++){
		if (id[i] == pID){
			id[i] = qID;
		}
	}
	totolcount--;
}

void init(priority_queue<EdgeNode> &minHeap){
	EdgeNode edgeNode1 = { 1, 3, 1 };
	EdgeNode edgeNode2 = { 1, 2, 6 };
	EdgeNode edgeNode3 = { 1, 4, 5 };
	EdgeNode edgeNode4 = { 2, 3, 5 };
	EdgeNode edgeNode5 = { 2, 5, 3 };
	EdgeNode edgeNode6 = { 3, 5, 6 };
	EdgeNode edgeNode7 = { 3, 4, 5 };
	EdgeNode edgeNode8 = { 3, 6, 4 };
	EdgeNode edgeNode9 = { 4, 6, 2 };
	EdgeNode edgeNode0 = { 5, 6, 6 };
	minHeap.push(edgeNode0);
	minHeap.push(edgeNode1);
	minHeap.push(edgeNode3);
	minHeap.push(edgeNode4);
	minHeap.push(edgeNode5);
	minHeap.push(edgeNode6);
	minHeap.push(edgeNode7);
	minHeap.push(edgeNode8);
	minHeap.push(edgeNode9);
}



void kruskal(int numNodes, priority_queue<EdgeNode> minHeap, vector<EdgeNode> &result){
	int k = 0;
	int e = minHeap.size();
	while (e>0 && k<numNodes - 1){
		EdgeNode edge = minHeap.top();
		minHeap.pop();
		e--;
		int u = findSet(edge.u);
		int v = findSet(edge.v);
		if (u != v){
			result.push_back(edge);
			unionSet(u, v, numNodes);
		}
	}
}

void show(vector<EdgeNode> result){
	for (int i = 0; i<result.size(); i++){
		cout << result[i].u << "," << result[i].v << " weight:" << result[i].weight << endl;
	}
}

int main(){
	priority_queue<EdgeNode> minHeap;
	init(minHeap);
	int numNodes = 6;
	initUnionSet(numNodes);
	vector<EdgeNode> result;
	kruskal(numNodes, minHeap, result);
	show(result);
	getchar();
}
