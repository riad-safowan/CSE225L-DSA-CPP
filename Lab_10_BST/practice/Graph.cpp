#include<iostream>
#include<queue>
using namespace std;

#define MAX_SIZE 10

int graph[MAX_SIZE][MAX_SIZE];
int node, edge;
bool visited[MAX_SIZE];
int level[MAX_SIZE];
int previous[MAX_SIZE];


void Initialize() {
    for (int i = 0; i < MAX_SIZE; i++)
    {
        visited[i] = false;
        level[i] = 0;
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
    }
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
    Initialize();
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
    seedEdges();
    cout << endl << "The graph: " << endl;
    showGraph();
    cout << endl << "All adjacents node of 6: ";
    adjacentNode(6);

    cout << endl << endl << "DFS: ";
    DFS(0);

    cout << endl << endl << "BFS: ";
    BFS(0);

    cout << endl << endl << "Levels: ";
    printLevel();

    cout << endl << endl << "All nodes shortest path from 0: ";
    shortestPath(0, 0);
    shortestPath(0, 1);
    shortestPath(0, 2);
    shortestPath(0, 3);
    shortestPath(0, 4);
    shortestPath(0, 5);
    shortestPath(0, 6);
    shortestPath(0, 7);
    shortestPath(0, 8);

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