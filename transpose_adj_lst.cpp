#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& adj_lst){
  
  vector<vector<int>> transposed((int)adj_lst.size());

  for (int u = 0; u < (int)adj_lst.size(); u++){
    for (auto& v: adj_lst[u]){
      
      transposed[v].push_back(u);

    }
  }

  return transposed;

}

int main(){

  vector<vector<int>> adj_lst {{2,3,4},{0,2,4},{4},{1,5},{3},{4,2}};
  vector<vector<int>> transposed = transpose(adj_lst);
  
  for (int u = 0; u < (int)transposed.size(); u++){
    
    cout << u << ", ";

    for (auto v: transposed[u]){
      
      cout << v << " ";

    }

    cout << endl;

  }
  
  return 0;

}
