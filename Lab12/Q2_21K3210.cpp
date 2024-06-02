//Lab 12
//BCS-3J
//21K3210
//Qasim Hasan
//Task 2
//BREATH FIRST TRAVERSAL      
#include<iostream>
#include<list>
#include<queue>
using namespace std;
class Graph{
public:
int vertices;
list<int> *adj;
Graph(int v){
    vertices=v;
    adj=new list<int>[vertices];
}
void addEdge(int v1,int v2){
    adj[v1].push_back(v2);
}
void BFS(int current){
bool *visited=new bool[vertices];
 for(int i=0;i<vertices;i++)
    visited[i]=false;
 queue<int> q;
 visited[current]=true;
 q.push(current);
 list<int>::iterator i;
 while(!q.empty()){
    current=q.front();
    cout << current << " ";
    q.pop();
    for(i=adj[current].begin();i!=adj[current].end();i++){
        if(!visited[*i]){
            visited[*i]=true;
            q.push(*i);
        }
    }
 }
}
};
int main(){
      Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,0);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,1);
    g.addEdge(2,4);
    g.addEdge(3,0);
    g.addEdge(4,2);
    cout << "Following is Breath First Traversal "<< "(starting from vertex 2) \n";
    g.BFS(2);

}
