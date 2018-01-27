#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> color {};
vector<int> d {};
vector<int> pi {};
queue<int> q {};

void print (vector<int>& array) {

  for (auto e: array)
    cout << e << ", ";
  cout << endl;

}

void bfs_matrix (vector<vector<int>>& matrix, int s) {

  d[s] = 0;
  pi[s] = 0;

  q.push(s);

  while (!q.empty()) {

    int u = q.front();
    q.pop();

    cout << "At" << u << endl;

    for (int i = 0; i < (int)matrix[u].size(); i++) {
      
      if (matrix[u][i] == 1 && color[i] == 0) {
        d[i] = d[u] + 1;
        pi[i] = u;
        
        q.push(i);
      }
    
    }

    color[u] = 1;

  }

}

int main() {
  vector<vector<int>> matrix {
    {0,1,0,0,0,0},
    {1,0,1,1,0,0},
    {0,1,0,0,0,0},
    {0,1,0,0,1,1},
    {0,0,0,1,0,0},
    {0,0,0,1,0,0}
  };

  color.resize((int)matrix.size(), 0);
  d.resize((int)matrix.size(), -1);
  pi.resize((int)matrix.size(), -1);

  bfs_matrix(matrix, 0);

  print(color);
  print(d);
  print(pi);

  return 0;

}
