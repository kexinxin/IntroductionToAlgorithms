#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct EdgeNode{
    int adjvex;//该邻接节点在定点数组中的下标
    struct EdgeNode *next;//指向下一个邻接点
};

struct VertexNode{
    int data; //顶点信息
    int color;
    int depth;
    int f;
    VertexNode *privous;
    EdgeNode *firstedge;//边表头指针
};

struct Graph{
    vector<VertexNode> adjList;
    int numVertexes, numEdges;
};

void addEdgeNode(int i, int j, Graph &G){
    EdgeNode *ptrEdgeNode = new EdgeNode;
    ptrEdgeNode->adjvex = j;
    ptrEdgeNode->next = G.adjList[i].firstedge;
    G.adjList[i].firstedge = ptrEdgeNode;

    ptrEdgeNode = new EdgeNode;
    ptrEdgeNode->adjvex = i;
    ptrEdgeNode->next = G.adjList[j].firstedge;
    G.adjList[j].firstedge = ptrEdgeNode;
}

void init(Graph &G){
    int numVertexes = 5;
    int numEdges = 7;
    G.numVertexes = numVertexes;
    G.numEdges = numEdges;
    for (int i = 0; i<G.numVertexes; i++){
        VertexNode *node = new VertexNode;
        node->data = i;
        node->firstedge = NULL;
        G.adjList.push_back(*node);
    }
    addEdgeNode(0, 1, G);
    addEdgeNode(0, 4, G);
    addEdgeNode(1, 3, G);
    addEdgeNode(1, 2, G);
    addEdgeNode(2, 3, G);
    addEdgeNode(4, 3, G);
    addEdgeNode(1, 4, G);
}

//图的广度优先搜素
void BFS(Graph &G){
    for (int i = 0; i<G.numVertexes; i++){
        G.adjList[i].color = 0;
        G.adjList[i].depth = 0;
    }
    queue<VertexNode> q;
    for (int i = 0; i<G.numVertexes; i++){
        if (G.adjList[i].color == 0){
            G.adjList[i].color = 1;
            cout << G.adjList[i].data << " " << endl;
            G.adjList[i].privous = NULL;
            q.push(G.adjList[i]);
            while (!q.empty()){
                VertexNode u = q.front();
                q.pop();
                EdgeNode *p = u.firstedge;
                while (p){
                    if (G.adjList[p->adjvex].color == 0){
                        G.adjList[p->adjvex].color = 1;
                        G.adjList[p->adjvex].depth = u.depth + 1;
                        G.adjList[p->adjvex].privous = new VertexNode;
                        G.adjList[p->adjvex].privous->data = u.data;
                        cout << G.adjList[p->adjvex].data << " " << G.adjList[p->adjvex].depth << endl;
                        q.push(G.adjList[p->adjvex]);
                    }
                    p = p->next;
                }
            }
        }
    }
}

//广度优先树
void printPath(Graph &G, VertexNode s, VertexNode v){
    if (s.data == v.data){
        cout << s.data << endl;
    }
    else if (v.privous == NULL){
        cout << "no path from" << s.data << " to " << v.data << " exists" << endl;
    }
    else{
        printPath(G, s, G.adjList[v.privous->data]);
        cout << v.data << endl;
    }
}

//指定起点的广度优先搜索
void BFS(Graph &G, int index){
    for (int i = 0; i<G.numVertexes; i++){
        if (i != index){
            G.adjList[i].color = 0;
        }
        else{
            G.adjList[i].color = 1;
            cout << G.adjList[i].data << " " << endl;
            G.adjList[i].privous = NULL;
        }
        G.adjList[i].depth = 0;
    }
    queue<VertexNode> q;
    q.push(G.adjList[index]);
    while (!q.empty()){
        VertexNode u = q.front();
        q.pop();
        EdgeNode *p = u.firstedge;
        while (p){
            if (G.adjList[p->adjvex].color == 0){
                G.adjList[p->adjvex].color = 1;
                G.adjList[p->adjvex].depth = u.depth + 1;
                G.adjList[p->adjvex].privous = new VertexNode;
                G.adjList[p->adjvex].privous->data = u.data;
                cout << G.adjList[p->adjvex].data << " depth:" << G.adjList[p->adjvex].depth << " privous:" << G.adjList[p->adjvex].privous->data << endl;
                q.push(G.adjList[p->adjvex]);
            }
            p = p->next;
        }
    }
}

void DFSVisit(Graph &G, VertexNode &u, int *time){
    *time = *time + 1;
    u.depth = *time;
    u.color = 1;

    EdgeNode *p = u.firstedge;
    while (p){
        if (G.adjList[p->adjvex].color == 0){
            G.adjList[p->adjvex].privous = new VertexNode;
            G.adjList[p->adjvex].privous->data = u.data;
            DFSVisit(G, G.adjList[p->adjvex], time);

        }
        p = p->next;
    }
    *time = *time + 1;
    u.f = *time;
    cout << u.data << " start time:" << u.depth << "  finish time:" << u.f << endl;
}


void DFS(Graph &G){
    for (int i = 0; i<G.numVertexes; i++){
        G.adjList[i].color = 0;
        G.adjList[i].privous = NULL;
    }
    for (int i = 0; i<G.numVertexes; i++){
        if (G.adjList[i].color == 0){
            int *time = new int(0);
            DFSVisit(G, G.adjList[i], time);
        }
    }
}



int main(){
    Graph G;
    init(G);
    //BFS(G,0);
    //BFS(G);
    //printPath(G, G.adjList[0], G.adjList[2]);
    DFS(G);
    getchar();
}
