#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& g, vector<bool>& visited, int u, vector<int>& members){

  visited[u] = true;
  members.push_back(u);

  for (int v: g[u]){

    if (visited[v] == true)
      continue;

    dfs(g, visited, v, members);

  }

}

vector<int> dfs_with_return_value(vector<vector<int>>& g, vector<bool>& visited, int u){

  vector<int> members {};
  dfs(g, visited, u, members);

  return members;

}

int main(){

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

  vector<int> members = dfs_with_return_value(g, visited, 0);

  for (auto e: members){
    cout << e << " ";
  }
  cout << endl;

  return 0;

}
