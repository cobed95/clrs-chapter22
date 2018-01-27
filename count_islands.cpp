#include <iostream>
#include <vector>
using namespace std;

int island = 0;

//0 1 2
//  3 
//
//  4 5
//
//  6
vector<vector<int>> g {
  {1},
  {0, 2, 3},
  {1},
  {1},
  {5},
  {4},
  {}
};


vector<bool> visited ((int)g.size(), false);

void dfs(vector<vector<int>>& g, vector<bool>& visited, int u){
  
  visited[u] = true;
  
  for (int v: g[u]){
    
    if (visited[v] == true)
      continue;
    
    dfs(g, visited, v);
  
  }

}

void count_islands(vector<vector<int>>& g, vector<bool>& visited){
  
  for (int i = 0; i < (int)visited.size(); i++){ 
    
    if (visited[i] == false){
      dfs(g, visited, i);
      island += 1;
    }
  
  }
}

int main(){
  count_islands(g, visited);
  cout << island << endl;
}
