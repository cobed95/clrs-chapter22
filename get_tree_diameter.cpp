#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> d {};
vector<bool> visited {};

queue<int> q {};

void bfs (vector<vector<int>>& adj_lst, int& s) {

    visited[s] = true;
    d[s] = 0;
    q.push(s);

    while (!q.empty()) {

        int u = q.front();
        q.pop();

        for (int v: adj_lst[u]) {

            if (!visited[v]) {
                d[v] = d[u] + 1;
                visited[v] = true;
                q.push(v);   
            }
        }
    }
}

pair<int, int> get_largest (vector<int>& d) {

    int largest = d[0];
    int idx = 0;

    for (int i = 1; i < (int)d.size(); i++) {
        
        if (d[i] > largest) {

            largest = d[i];
            idx = i;
        }
    }

    pair<int, int> largest_and_idx {largest, idx};

    return largest_and_idx;
}

int get_tree_diameter (vector<vector<int>>& adj_lst) {

    visited.resize((int)adj_lst.size(), false);
    d.resize((int)adj_lst.size(), 0);

    int s = 0;
    bfs(adj_lst, s);

    int furthest_leaf = get_largest(d).second;

    for (int i = 0; i < (int)visited.size(); i++) visited[i] = false;

    bfs(adj_lst, furthest_leaf);

    int diameter = get_largest(d).first;

    return diameter;
}

int main() {

    vector<vector<int>> adj_lst {
        {1, 2},
        {0, 3, 4, 5},
        {0, 6},
        {1},
        {1, 7},
        {1, 8, 9},
        {2},
        {4},
        {5},
        {5}
    };

    int diameter = get_tree_diameter(adj_lst);

    cout << diameter << endl;

    return 0;
}
