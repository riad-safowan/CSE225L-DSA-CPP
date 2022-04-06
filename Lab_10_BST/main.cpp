#include<iostream>
#include<queue>
using namespace std;
int const MAX_SIZE = 10;

int graph[MAX_SIZE][MAX_SIZE] = { 0 };
int node, edge;
bool visited[MAX_SIZE];

int level[MAX_SIZE];

void Initialize() {
    for (int i = 0; i < node; i++)
        visited[i] = false;
}

void AdjacentNode(int source) {
    for (int i = 0; i < node; i++) {
        if (graph[source][i] == 1)
            cout << i << " ";
    }
}

void DFS(int source) {
    visited[source] = true;

    for (int i = 0; i < node; i++) {
        if (graph[source][i] == 1) {
            if (visited[i] == false) {
                DFS(i);
            }
        }
    }
    cout << source << " ";
}

void BFS(int source) {
    queue<int> q;                                                                              
    visited[source] = true;
    q.push(source);
    while (!q.empty()) {
        int x = q.front();
        cout << x << " ";
        q.pop();
        for (int i = 0; i < node; i++) {
            if (graph[x][i] == 1) {
                if (visited[i] == false) {
                    q.push(i);
                    visited[i] = true;
                    level[i] = level[x] + 1;
                }
            }
        }
    }
}

int main() {
    cin >> node >> edge;
    for (int i = 0; i < edge; i++) {
        int m, n;
        cin >> m >> n;
        graph[m][n] = 1;
        graph[n][m] = 1;
    }

    for (int i = 0; i < node; i++) {
        for (int j = 0; j < node; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    AdjacentNode(3);
    cout << endl;
    Initialize();
    BFS(0);
    return 0;
}

/*
7 10
0 1
0 2
2 5
1 5
1 3
3 4
5 4
4 6
3 6
5 6
*/
