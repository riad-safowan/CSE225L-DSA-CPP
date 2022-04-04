#include<iostream>
using namespace std;
int const MAX_SIZE = 10;

int graph[MAX_SIZE][MAX_SIZE] = { 0 };
int node, edge;
bool visited[MAX_SIZE];

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
    cout << source << " ";
    for (int i = 0; i < node; i++) {
        if (graph[source][i] == 1) {
            if (visited[i] == false) {
                DFS(i);
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
    DFS(0);
    return 0;
}

/*
8 9
0 1
0 3
1 3
2 3
2 4
3 5
4 5
3 6
6 7
*/
