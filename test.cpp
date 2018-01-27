#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  
  vector<vector<int>> color (2);

  color[0].push_back(0);

  for (auto e: color[0])
    cout << e << endl;

  return 0;

}
