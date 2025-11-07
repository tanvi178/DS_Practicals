//DFS
#include <iostream>
#define MAX 10
using namespace std;

int adj[MAX][MAX], visited[MAX];

void dfs(int v, int n) {
    visited[v] = 1;
    cout << "\nIndexed page: " << v;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i])
            dfs(i, n);
    }
}

int main() {
    int n, e, from, to, start;
    cout << "Enter number of web pages (max 10): ";
    cin >> n;
    cout << "Enter number of hyperlinks: ";
    cin >> e;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    cout << "Enter links (from to):" << endl;
    for (int i = 0; i < e; i++) {
        cin >> from >> to;
        adj[from][to] = 1;
    }
    cout << "Enter seed (start) page number: ";
    cin >> start;
    cout << "\nStarting DFS web crawling from page: " << start << endl;
    dfs(start, n);
    return 0;
}
