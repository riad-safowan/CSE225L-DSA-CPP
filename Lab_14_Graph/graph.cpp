#include<iostream>
#include<queue>
using namespace std;
int const MAX_SIZE = 100;

int graph[MAX_SIZE][MAX_SIZE];
int node, edge;
bool visited[MAX_SIZE];
int level[MAX_SIZE];
int previous[MAX_SIZE];


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

void BFS(int source) {
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while (!q.empty()) {
        int x = q.front();
        cout << x << " ";
        for (int i = 0; i < node; i++) {
            if (graph[x][i] == 1) {
                if (visited[i] == false) {
                    q.push(i);
                    visited[i] = true;
                    level[i] = level[x] + 1;
                }
            }
        }
        q.pop();
    }
}

void printShortestPath(int start, int end) {
    if (end == start)
    {
        cout << endl << end;
        return;
    }

    printShortestPath(start, previous[end]);
    cout << " -> " << end;
}

void shortestPath(int start, int end) {
    bool done = false;
    Initialize();

    queue<int> q;
    q.push(start);
    visited[start] = true;
    level[start] = 0;

    while (!q.empty() && !done) {
        int x = q.front();
        for (int i = 0; i < node; i++)
        {
            if (graph[x][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
                level[i] = level[x] + 1;
                previous[i] = x;
                done = i == end;
            }
            if (done) break;
        }
        q.pop();
    }

    printShortestPath(start, end);
}

int main() {
    cin >> node >> edge;
    for (int i = 0; i < edge; i++) {
        int m, n;
        cin >> m >> n;
        graph[m][n] = 1;
        graph[n][m] = 1;
    }

    cout << "\nGraph adjacent matrix:\n";
    for (int i = 0; i < node; i++) {
        for (int j = 0; j < node; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nAdjacent nodes of node 1: ";
    AdjacentNode(1);
    cout << "\nDFS: ";
    DFS(0);
    Initialize();
    cout << "\nBFS: ";
    BFS(0);
    cout << "\nLevel: ";
    for (int i = 0; i < node; i++)
        cout << level[i] << " ";
    cout << endl << endl << "All nodes shortest path from 0: ";
    shortestPath(0, 1);
    shortestPath(0, 2);
    shortestPath(0, 3);
    shortestPath(0, 4);
    shortestPath(0, 5);
    shortestPath(0, 6);
        
    return 0;
}

/*
         1  ---  3
       / | \     | \
      /  |  \    |  \
     0   |   \   4 - 6
      \  |    \  |  /
       \ |     \ | /
         2  ---  5
Input:
7 11
0 1
0 2
1 2
2 5
1 5
1 3
3 4
5 4
4 6
3 6
5 6

Output:
Graph adjacent matrix:
0 1 1 0 0 0 0
1 0 1 1 0 1 0
1 1 0 0 0 1 0
0 1 0 0 1 0 1
0 0 0 1 0 1 1
0 1 1 0 1 0 1
0 0 0 1 1 1 0

Adjacent nodes of node 1: 0 2 3 5
DFS: 0 1 2 5 4 3 6
BFS: 0 1 2 3 5 4 6
Level: 0 1 1 2 3 2 3

All nodes shortest path from 0:
0 -> 1
0 -> 2
0 -> 1 -> 3
0 -> 1 -> 3 -> 4
0 -> 1 -> 5
0 -> 1 -> 3 -> 6

*/
