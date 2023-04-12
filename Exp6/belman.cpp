#include<bits/stdc++.h>
using namespace std;

int V;
void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}

void BellmanFord(int ** graph,int src, vector<pair<int,int>> edges){

    int dist[V];
  
  for(int i=0;i<V;i++){
    dist[V]=INT_MAX;
  }
    dist[src]=0;

  for(int it=1;it<=V-1;it++){

    for(int i=0;i<edges.size();i++){
      int u=edges[i].first;
      int v=edges[i].second;

      if(dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v]){
        dist[v]=dist[u]+graph[u][v];
      }
        
    }
  }

  for (int i = 0; i < edges.size(); i++) {
        int u=edges[i].first;
    int v=edges[i].second;
        int weight = graph[u][v];
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle");
          return; 
      }
  }
  
  printSolution(dist);

}


int main(){
  
  cout<<"Enter the number of vertices :";
  cin>>V;

  int **graph=new int*[V];
    for(int i=0;i<V;i++)
  {
    graph[i]=new int[V];
  }

  for(int i=0;i<V;i++){
    for(int j=0;j<V;j++){
      graph[i][j]=INT_MAX;
    }
  }

  cout<<"Enter the number of edges :";
  int e; cin >> e;

  vector<pair<int,int>> edges;
    
  for(int i=0;i<e;i++){

    cout<<"\nEnter the Vertices of the edge "<<i<<" :";
    int a,b,w;
    cin>>a>>b;
    a--;b--;
    edges.push_back(make_pair(a,b));
        
  
    cout<<"Enter the Weight of the edge "<<i<<" :";
    cin>>w;
        
    graph[a][b]=w;

    
  }

  BellmanFord(graph,0,edges);

    return 0;
}
