#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g {
  {1},
    {0,2,3},
    {1},
    {1},
    {5},
    {4},
    {}
};
vector<bool> visited ((int)g.size(), false);
int count = 0;

void dfs(vector<vector<int>>& g, vector<bool>& visited, int u){

  visited[u] = true;
  cout << u << " ";
  count += 1;

  for (int v: g[u]){

    if (visited[v] == true){
      continue; 
    }

    dfs(g, visited, v);
  }
}

void find_island(vector<vector<int>>& g, vector<bool>& visited){

  for (int i = 0; i < (int)visited.size(); i++){

    if (visited[i] == false){
      dfs(g, visited, i);

      cout << endl;
      cout << "The number of elements in island:" << count << endl;
      count = 0;
    }
  }
}

int main(){

  find_island(g, visited);

  return 0;

}
