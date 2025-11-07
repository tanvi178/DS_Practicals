#include <iostream>
#define MAX 10
using namespace std;

int queueArr[MAX], front = -1, rear = -1;
int visited[MAX] = {0};
int adj[MAX][MAX];

void enqueue(int v) {
    if (rear == MAX - 1)
        cout << "Queue Overflow\n";
    else {
        if (front == -1)
            front = 0;
        queueArr[++rear] = v;
    }
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queueArr[front++];
}

void bfs(int start, int n) {
    enqueue(start);
    visited[start] = 1;
    cout << "\nIndexing pages starting from: " << start << endl;
    while (front <= rear) {
        int v = dequeue();
        cout << "Indexed page: " << v << endl;
        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
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
    cout << "Enter seed/start page number: ";
    cin >> start;
    bfs(start, n);
    return 0;
}
