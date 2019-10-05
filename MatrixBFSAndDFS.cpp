#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct  Date{
    int isRelation; //是否有关联
};

struct VertexNode{
    int data; //顶点信息
    int color;
    int depth;
    int f;
    VertexNode *privous;
};

void addEdge(vector<vector<Date> > &G,int start,int end){
    G[start][end].isRelation=1;
    G[end][start].isRelation=1;
}

void init(vector<vector<Date> > &G,vector<VertexNode> &nodes){
    int numVertexes=5;
    for(int i=0;i<numVertexes;i++){
        vector<Date> vector;
        for(int j=0;j<numVertexes;j++){
            Date date;
            date.isRelation=0;
            vector.push_back(date);
        }
        G.push_back(vector);
    }
    for(int i=0;i<numVertexes;i++){
        VertexNode node;
        node.data=i;
        node.color=0;
        node.privous=NULL;
        nodes.push_back(node);
    }
    addEdge(G,0,1);
    addEdge(G,0,4);
    addEdge(G,1,3);
    addEdge(G,1,2);
    addEdge(G,2,3);
    addEdge(G,4,3);
    addEdge(G,1,4);
}

void BFS(vector<vector<Date> > G,vector<VertexNode> &nodes){
    queue<VertexNode> q;
    for(int i=0;i<G.size();i++){
        if(nodes[i].color==0){
            nodes[i].color=1;
            cout<<nodes[i].data<<" "<<endl;
            q.push(nodes[i]);
            while(!q.empty()){
                VertexNode u=q.front();
                q.pop();
                for(int i=0;i<G.size();i++){
                    if(G[u.data][i].isRelation==1&&nodes[i].color==0){
                        nodes[i].color=1;
                        cout<<nodes[i].data<<" "<<endl;
                        q.push(nodes[i]);
                    }
                }
            }
        }
    }
}

void DFSVisit(vector<vector<Date> > G,vector<VertexNode> &nodes,int index){
    nodes[index].color=1;
    for(int i=0;i<G.size();i++){
        if(G[index][i].isRelation==1&&nodes[i].color==0){
            DFSVisit(G,nodes,i);
        }
    }
    cout<<nodes[index].data<<endl;
}

void DFS(vector<vector<Date> > G,vector<VertexNode> &nodes){
    for(int i=0;i<G.size();i++){
        if(nodes[i].color==0){
           DFSVisit(G,nodes,i);
        }
    }
}

int main(){
    vector<vector<Date> > G;
    vector<VertexNode> nodes;
    init(G,nodes);
    //DFS(G,nodes);
    BFS(G,nodes);
    getchar();
}
