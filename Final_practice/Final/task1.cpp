#include<iostream>
#include<queue>
using namespace std;
int const MAX_SIZE = 100;

int graph[MAX_SIZE][MAX_SIZE];

bool visited[MAX_SIZE];
int level[MAX_SIZE];

void Initialize(int node) {
    for (int i = 0; i < node; i++) {
        visited[i] = false;
        level[i] = 0;
    }
}

void BFS(int source, int node) {
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while (!q.empty()) {
        int x = q.front();
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


int main() {
    int entry;
    cin >> entry;
    int entries[entry];
    for (int i = 0; i < entry; i++)
    {
        int e;
        cin >> e;
        entries[i] = e;
    }

    int node;
    cin >> node;
    int nodes[node];
    for (int i = 0; i < node; i++)
    {
        int e;
        cin >> e;
        nodes[i] = e;
    }

    int endPoint;
    cin >> endPoint;

    int edge;
    cin >> edge;
    for (int i = 0; i < edge; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    int startPoint;
    cin >> startPoint;

    Initialize(node + entry + 1);
    BFS(endPoint, node + entry + 1);
    cout << level[startPoint] << endl;

    int shortest = edge;
    for (int i = 0; i < entry; i++)
    {
        if (level[entries[i]] < shortest)
        {
            shortest = level[entries[i]];
        }
    }

    for (int i = 0; i < entry; i++)
    {
        if (level[entries[i]] == shortest)
        {
            cout << entries[i] << " ";
        }
    }

    return 0;
}

/*
Input:
4
0 1 2 3
6
4 5 6 7 8 9
10
14
0 4
4 5
4 6
1 6
1 8
5 10
6 10
6 7
10 9
6 3
7 9
8 9
3 9
2 7
2
*/
