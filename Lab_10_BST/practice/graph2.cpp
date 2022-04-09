#include<iostream>
#include<queue>
using namespace std;

#define MAX_SIZE 100

int node, edge;
int graph[MAX_SIZE][MAX_SIZE];

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


int main() {
    seedTheGraph();
    printTheGraph();

    printAdjacent(5);
    return 0;
}

/*
9 14
0 1
0 7
1 7
1 2
8 7
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