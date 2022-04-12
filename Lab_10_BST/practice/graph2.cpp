#include<iostream>
#include<queue>
using namespace std;

#define MAX_SIZE 100

int node, edge;
int graph[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE];
int t = 0;
/*
0t
1f
2f
3f
4f
5f
6f
7f
8f
*/
int startTime[MAX_SIZE];
/*
0
1
2
3
4
5
6
7
8
*/
int endTime[MAX_SIZE];

void init() {
    for (int i = 0; i < MAX_SIZE; i++)
    {
        visited[i] = false;
    }

}

void seedTheGraph() {
    cin >> node >> edge;

    for (int i = 0; i < edge; i++)
    {
        int m, n;
        cin >> m >> n;
        graph[m][n] = 1;
        graph[n][m] = 1;
    }
}

void printTheGraph() {
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void printAdjacent(int point) {
    cout << endl;
    for (int i = 0; i < node; i++)
    {
        if (graph[point][i] == 1) {
            cout << i << " ";
        }
    }
    cout << endl;
}

void DFS(int start) {
    visited[start] = true;
    startTime[start] = t++;
    cout << start << " ";
    for (int i = 0; i < node; i++)
    {
        if (graph[start][i] == 1 && visited[i] == false) {
            DFS(i);
        }
    }
    endTime[start] = t++;

    //  cout << start << " ";
}


int main() {
    seedTheGraph();
    printTheGraph();
    printAdjacent(5);

    DFS(0);

    cout << endl;
    for (int i = 0; i < node; i++)
    {
        cout << "(" << startTime[i] << "," << endTime[i] << ")" << endl;
    }

    return 0;
}

/*
6 5
0 1
0 2
2 3
2 4
3 5
*/