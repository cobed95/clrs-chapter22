#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> color {};
vector<int> team {};
queue<int> q {};

void print_vector (vector<int>& array) {

  for (auto e: array) 
    cout << e << ", ";
  cout << endl;

}

vector<vector<int>> build_adj_lst (vector<int>& wrestlers, vector<vector<int>>& rivalry) {

  vector<vector<int>> adj_lst ((int)wrestlers.size());

  for (int i = 0; i < (int)rivalry.size(); i++) {

    adj_lst[rivalry[i][0]].push_back(rivalry[i][1]);
    adj_lst[rivalry[i][1]].push_back(rivalry[i][0]);
  
  }

  return adj_lst;

}

bool bfs_test_for_team_validity (vector<vector<int>>& adj_lst, int s) {

  color[s] = 0;
  team[s] = 0;

  q.push(s);

  while (!q.empty()) {

    int u = q.front();
    q.pop();

    for (int v: adj_lst[u]) {

      if (color[v] == 1)
        return false;

      else if (color[v] == 0) {

        color[v] = 1;

        if (team[u] == 0)
          team[v] = 1;
        else if (team[u] == 1)
          team[v] = 0;
        
      q.push(v);

      }

    }

    color[u] = 2;

  }

  return true;

}

vector<vector<int>> team_members () {

  vector<vector<int>> member_lst (2);

  for (int i = 0; i < (int)team.size(); i++) {

    member_lst[team[i]].push_back(i);

  }

  return member_lst;

}

int main () {

  vector<int> wrestlers {0,1,2,3,4,5};

  vector<vector<int>> rivalry {
    {0, 1},
    {0, 2},
    {0, 3},
    {1, 4},
    {1, 5},
    {4, 5}
  };
  
  color.resize((int)wrestlers.size(), 0);
  team.resize((int)wrestlers.size(), 0);

  vector<vector<int>> adj_lst = build_adj_lst(wrestlers, rivalry);

  if (bfs_test_for_team_validity(adj_lst, 0) == true) {

    vector<vector<int>> member_lst = team_members();

    print_vector(member_lst[0]);
    print_vector(member_lst[1]);

  }

  else {

    cout << "Team assignment is not valid." << endl;

  }

  return 0;

}
