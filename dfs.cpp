#include <iostream>
#include <vector>

using namespace std;

vector<int> pi {};
vector<int> d {};
vector<int> f {};
vector<int> color {};

const int white = 0;
const int gray = 1;
const int black = 2;

int t;

void print(vector<int> array) {

  for (auto e: array) cout << e << " ";
  cout << endl;
}

void dfs_visit(vector<vector<int>>& adj_lst, int u) {

  t += 1;
  d[u] = t;
  color[u] = gray;

  for (int v: adj_lst[u]) {
  
    if (color[v] != white) continue;

    else if (color[v] == white) {

      pi[v] = u;

      dfs_visit(adj_lst, v);
    }
  }

  t += 1;
  f[u] = t;

  color[u] = black;
}

vector<vector<int>> dfs(vector<vector<int>>& adj_lst) {

  pi.resize((int)adj_lst.size(), 0);
  d.resize((int)adj_lst.size(), 0);
  f.resize((int)adj_lst.size(), 0);
  color.resize((int)adj_lst.size(), white);

  t = 0;

  for (int u = 0; u < (int)adj_lst.size(); u++) {
    if (color[u] == white) dfs_visit(adj_lst, u); 
  }

  vector<vector<int>> data {};

  data.push_back(pi);
  data.push_back(d);
  data.push_back(f);

  return data;
}

int main() {

  vector<vector<int>> adj_lst {
    {1, 3},
    {4},
    {4, 5},
    {1}, 
    {3}, 
    {5}
  };

  vector<vector<int>> data = dfs(adj_lst);

  for (auto e: data) print(e);

  return 0;
}
