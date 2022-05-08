#include<iostream>
using namespace std;
#include<queue>
#define max_size 100
int graph[max_size][max_size] = { 0 };
int node, edge;
int level[max_size];
bool visited[max_size];

void AdjacentNode(int source)
{
    for (int i = 0; i < node; i++)
    {
        if (graph[source][i] == 1)
        {
            cout << i << " ";
        }
    }
}
void Initialize()
{
    for (int i = 0; i < node; i++)
    {
        visited[i] = false;
        level[i] = 0;
    }
}

void DFS(int source)
{
    visited[source] = true;
    cout << source << " ";
    for (int i = 0; i < node; i++)
    {
        if (graph[source][i] == 1)
        {
            if (visited[i] == false)
            {
                DFS(i);
            }
        }
    }
    //cout<<source<<" ";
}


void BFS(int source)
{
    queue<int> q;
    visited[source] = true;
    q.push(source);

    while (!q.empty())
    {
        int x = q.front();
        cout << x << " ";
        q.pop();
        for (int i = 0; i < node; i++)
        {
            if (graph[x][i] == 1)
            {
                if (visited[i] == false)
                {
                    visited[i] = true;
                    level[i] = level[x] + 1;
                    q.push(i);
                }
            }
        }
    }
}
int main()
{
    cin >> node >> edge;
    for (int i = 0; i < edge; i++)
    {
        int m, n;
        cin >> m >> n;
        graph[m][n] = 1;
        graph[n][m] = 1;
    }
    Initialize();
    DFS(0);
    cout << endl;
    Initialize();
    BFS(0);
    cout << endl;
    for (int i = 0; i < node; i++) {
        cout << level[i] << " ";
    }
    return 0;
}
/*
11 11
0 1
1 8
1 2
1 6
1 3
8 9
2 4
6 5
6 7
3 10
4 7
*/