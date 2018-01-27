#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g {
    //0, 1, 5, 8
    //   2, 6,
    //   3, 7,
    //   4, 
    {1},
    {0, 2, 5},
    {1, 3, 6},
    {2, 4, 7},
    {3},
    {1, 8},
    {2},
    {3},
    {5}
};
//white = 0, gray = 1, black = 2
vector<int> color ((int)g.size(), 0);
vector<int> d ((int)g.size(), 0);
vector<int> pi ((int)g.size(), 0);
vector<int> queue ((int)g.size(), 0);
int head = 0;
int tail = 0;

void enqueue(vector<int>& queue, int x) {
    queue[tail] = x;
    if (tail == (int)queue.size()-1)
        tail = 0;
    else 
        tail += 1;
}

int dequeue(vector<int>& queue) {
    int x = queue[head];
    if (head == (int)queue.size()-1)
        head = 0;
    else
        head += 1;
    return x;
}

void bfs(vector<vector<int>>& g, int s) {
    color[s] = 1; 
    d[s] = 0;
    pi[s] = 0;
    enqueue(queue, s);
    while (head != tail) {
        int u = dequeue(queue);
        cout << "At" << u << endl;
        for (auto v: g[u]) {
            if (color[v] == 0) {
                color[v] = 1;
                d[v] = d[u] + 1;
                pi[v] = u;
                enqueue(queue, v);
            }
        }
        color[u] = 2;
    }
}

int main() {
    bfs(g, 0);
    for (auto e: color) 
        cout << e << ", ";
    cout << endl;
    for (auto e: d)
        cout << e << ", ";
    cout << endl;
    for (auto e: pi)
        cout << e << ", ";
    cout << endl;

    return 0;
} 
