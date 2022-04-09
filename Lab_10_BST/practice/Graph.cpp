#include<iostream>
#include<queue>
using namespace std;

#define MAX_SIZE 10

int graph[MAX_SIZE][MAX_SIZE];
int node, edge;
bool visited[MAX_SIZE];
int level[MAX_SIZE];


void resetVisited() {
    for (int i = 0; i < MAX_SIZE; i++)
    {
        visited[i] = false;
    }
}

void seedEdges() {
    cin >> node >> edge;
    for (int i = 0; i < edge; i++) {
        int m, n;
        cin >> m >> n;
        graph[m][n] = 1;
        graph[n][m] = 1;
    }
}

void showGraph() {
    for (int i = 0; i < node; i++) {
        for (int j = 0; j < node; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void adjacentNode(int nd) {
    for (int i = 0; i < node; i++)
    {
        if (graph[nd][i] == 1)
            cout << i << " ";
    }cout << endl;
}

void DFS(int start) {
    visited[start] = true;
    cout << start << " ";
    for (int i = 0; i < node; i++)
    {
        if (graph[start][i] == 1) {
            if (!visited[i])
            {
                DFS(i);
            }
        }
    }
}

void BFS(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    level[start] = 0;

    while (!q.empty()) {
        int x = q.front();
        cout << x << " ";
        for (int i = 0; i < node; i++)
        {
            if (graph[x][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
                level[i] = level[x] + 1;
            }
        }
        q.pop();
    }
}

void printLevel() {
    for (int i = 0; i < node; i++)
    {
        cout << level[i] << " ";
    }
}

void sortestPath(int start, int end) {
    for (int i = 0; i < level[end]; i++)
    {
        if (graph[start][i] == 1);
    }
}


int main() {
    seedEdges();
    cout << endl;
    showGraph();
    // cout << endl;
    // adjacentNode(6);
    // cout << endl;
    // DFS(0);
    cout << endl;
    resetVisited();
    BFS(0);
    cout << endl;
    cout << endl;
    printLevel();

    return 0;
}

/*
9 14
0 1
0 7
1 7
1 2
7 8
7 6
2 8
8 6
2 3
2 5
5 6
3 5
3 4
4 5
*/