//Lab 12
//BCS-3J
//21K3210
//Qasim Hasan
//Task 4
//PRIMS ALGORITHM
#include<queue>
#include<list>
#include<iostream>
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> iPair;
class Graph{
    int V;
    list<pair<int,int> > *adj;
public:
Graph(int V){
    this->V = V;
    adj = new list<iPair>[this->V];
}
void addEdge(int u,int v,int w){
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}
void primMST(){
    priority_queue<iPair,vector<iPair>,greater<iPair> > pq;
    int src = 0;
    vector<int> key(V,INF);
    vector<int> parent(V,-1);
    vector<bool> inMST(V,false);
    pq.push(make_pair(0,src));
    key[src] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;
        list<pair<int,int> >::iterator it;
        for(it = adj[u].begin();it!=adj[u].end();it++){
            int v = (*it).first;
            int weight = (*it).second;

            if(!inMST[v] && key[v] > weight){
                key[v] = weight;
                pq.push(make_pair(key[v],v));
                parent[v] = u;
            }
        }
    }
    for(int i=1;i<V;i++){
        cout << parent[i] << " - "  << i << endl;
    }
}    
};
int main(){
    int V = 7;
    Graph g(V);
    //HERE
    //a=0 b=1 c=2 d=3 e=4 f=5 g=6
    g.addEdge(0,1,1);
    g.addEdge(0,2,5);
    g.addEdge(1,2,4);
    g.addEdge(1,3,8);
    g.addEdge(1,4,7);
    g.addEdge(2,3,6);
    g.addEdge(2,5,2);
    g.addEdge(3,5,9);
    g.addEdge(3,4,11);
    g.addEdge(4,5,3);
    g.addEdge(4,6,10);
    g.addEdge(5,6,12);
    cout << "Minimum Spanning Tree:";
    g.primMST();
}