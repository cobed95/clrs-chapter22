#include <iostream>
#include <vector>

using namespace std;

vector<int> path_for_all_edges {};
vector<int> color {};

const int white = 0;
const int gray = 1;
const int black = 2;

void get_path_for_all_edges (vector<vector<int>>& adj_lst, int u) {

    color[u] = gray;

    path_for_all_edges.push_back(u);

    for (int v: adj_lst[u]) {

        if (color[v] == white) {

            get_path_for_all_edges(adj_lst, v);           
            path_for_all_edges.push_back(u);

        }
        
        else if (color[v] == black) {

            path_for_all_edges.push_back(v);
            path_for_all_edges.push_back(u);

        }

    }

    color[u] = black;

}

int main() {

    vector<vector<int>> adj_lst = {
        {1, 2, 3},
        {0, 2, 4, 5},
        {0, 1, 4, 5, 6},
        {0, 6},
        {1, 2},
        {1, 2},
        {2, 3},
    };

    color.resize((int)adj_lst.size(), white);

    get_path_for_all_edges(adj_lst, 0);

    for (auto e: path_for_all_edges) cout << e << ", ";
    cout << endl;
    
    return 0;
    
}
