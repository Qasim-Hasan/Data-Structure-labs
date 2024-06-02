//Lab 12
//BCS-3J
//21K3210
//Qasim Hasan
//Task 3
//DEPTH FIRST TRAVERSAL   
#include<iostream>
#include<list>
#include<stack>
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
void DFS(int current){
    bool *visited=new bool[vertices];
    for(int i=0;i<vertices;i++){
        visited[i]=false;
    }
    stack<int> s;
    visited[current]=true;
    s.push(current);
    list<int> :: iterator i;
    while(!s.empty()){
        current = s.top();
        cout << current << " ";
        s.pop();
        for(i=adj[current].begin();i!=adj[current].end();i++){
            if(!visited[*i]){
                visited[*i]=true;
                s.push(*i);
            }
        }
    }
}
};
int main(){
    Graph g(6);
    g.addEdge(0,2);
    g.addEdge(0,1);
    g.addEdge(0,5);
    g.addEdge(1,0);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(3,2);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(4,2);
    g.addEdge(4,3);
    g.addEdge(5,3);
    g.addEdge(5,0);
    cout << "Following is Depth First Traversal "<< "(starting from vertex 0) \n";
    g.DFS(0);
}
