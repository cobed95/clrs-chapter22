#include <iostream>
#include <vector>

using namespace std;

vector<int> visited {};
vector<int> pi {};
vector<int> d {};
vector<int> f {};

int t;

vector<vector<int>> dfs_tree {};

void get_dfs_tree (vector<vector<int>>& adj_lst, int u) {

    visited[u] = true;
    t += 1;
    d[u] = t;

    for (int v: adj_lst[u]) {

        if (visited[v]) continue;

        pi[v] = u;
        dfs_tree[u].push_back(v);
        get_dfs_tree(adj_lst, v);
    }

    t += 1;
    f[u] = t;
}

int get_tree_diameter_dfs (vector<vector<int>>& adj_lst) {
    
    visited.resize((int)adj_lst.size(), false);
    pi.resize((int)adj_lst.size(), 0);
    d.resize((int)adj_lst.size(), 0);
    f.resize((int)adj_lst.size(), 0);

    t = 0;

    for (int i = 0; i < (int)adj_lst.size(); i++) {

        if (!visited[i]) get_dfs_tree(adj_lst, i);
    }



    return 0;
}

int main() {

    vector<vector<int>> adj_lst {
        {1, 2, 3},
        {0},
        {0},
        {0, 4, 5},
        {3, 6, 7, 8},
        {3, 9},
        {4},
        {4, 10},
        {4},
        {5, 11},
        {7}, 
        {9, 12},
        {11}
    };

    dfs_tree.resize((int)adj_lst.size());
    get_dfs_tree(adj_lst, 0);

    for (auto e: dfs_tree) {
        for (auto x: e) cout << x << " ";
        cout << endl;
    }

    return 0;
}
