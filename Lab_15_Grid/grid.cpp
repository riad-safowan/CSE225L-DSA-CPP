#include <iostream>
#include <queue>
using namespace std;

#define row 5
#define col 5

struct node
{
    int x;
    int y;
};

bool visited[row][col] = { 0 };
int level[row][col] = { 0 };
node previous[row][col];

//strait[0,3]   = up, down, left, right
//diagonal[4,7] = up-left, up-right, down-left, down-right
//knight[8,15]  = up-right, up-left, down-right, down-right, right-up, right-down, left-up, left-down
int moveX[] = { -1, 1, 0, 0,     -1, -1, 1, 1,    1, -1, 1, -1, 2, 2, -2, -2 };
int moveY[] = { 0, 0, -1, 1,     -1, -1, 1, 1,    -2, -2, 2, 2, -1, 1, -1, 1 };

void Initialize() {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            visited[i][j] = false;
            level[i][j] = 0;
        }
}

bool isValid(int x, int y)
{
    return ((x >= 0 && x < row) && (y >= 0 && y < col) && !visited[x][y]);
}

void DFS(int x, int y)
{
    visited[x][y] = 1;
    cout << "[" << x << "," << y << "]" << ", ";

    for (int i = 0; i < 4; i++)
        if (isValid(x + moveX[i], y + moveY[i]))
            DFS(x + moveX[i], y + moveY[i]);
}

void BFS(node start, bool doPrint)
{
    Initialize();
    queue<node> q;
    q.push(start);
    visited[start.x][start.y] = true;
    level[start.x][start.y] = 0;

    while (!q.empty())
    {
        node n = q.front();
        if (doPrint) cout << "[" << n.x << "," << n.y << "]" << ", ";
        for (int k = 8; k < 16; k++)
        {
            if (isValid(n.x + moveX[k], n.y + moveY[k]))
            {
                q.push(node{ n.x + moveX[k], n.y + moveY[k] });
                visited[n.x + moveX[k]][n.y + moveY[k]] = true;
                level[n.x + moveX[k]][n.y + moveY[k]] = level[n.x][n.y] + 1;
                previous[n.x + moveX[k]][n.y + moveY[k]] = n;
            }
        }
        q.pop();
    }
}

void printLevelGrid()
{
    cout << endl << "Path level: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%3d", level[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

void printGrid()
{
    cout << "The original Grid: " << endl << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%2d,%2d   ", i, j);
        }
        cout << endl << endl;
    }
}
void shortestPath(node start, node en)
{
    if (en.x == start.x && en.y == start.y)
    {
        cout << en.x << "," << en.y;
        return;
    }

    shortestPath(start, previous[en.x][en.y]);
    cout << " -> " << en.x << "," << en.y;
}
void printShortestPath(node start, node en)
{
    BFS(start, false);
    cout << "Shortest path from (" << start.x << "," << start.y << ") to (" << en.x << "," << en.y << "): ";
    shortestPath(start, en);
    cout << endl << endl;
}

int main()
{
    printGrid();
    cout << "\nDFS: ";
    DFS(2, 2);
    cout << "\n\nBFS: ";
    BFS(node{ 2 , 2 }, true);
    cout << endl;
    printLevelGrid();
    printShortestPath(node{ 1,1 }, node{ 1,2 });
    cout << endl << endl;
}

/*
The original Grid:

 0, 0    0, 1    0, 2    0, 3    0, 4

 1, 0    1, 1    1, 2    1, 3    1, 4

 2, 0    2, 1    2, 2    2, 3    2, 4

 3, 0    3, 1    3, 2    3, 3    3, 4

 4, 0    4, 1    4, 2    4, 3    4, 4


DFS: [2,2], [1,2], [0,2], [0,1], [1,1], [2,1], [3,1], [4,1], [4,0], [3,0], [2,0], [1,0], [0,0], [4,2], [3,2], [3,3], [2,3], [1,3], [0,3], [0,4], [1,4], [2,4], [3,4], [4,4], [4,3],

BFS: [2,2], [1,2], [3,2], [2,1], [2,3], [0,2], [1,1], [1,3], [4,2], [3,1], [3,3], [2,0], [2,4], [0,1], [0,3], [1,0], [1,4], [4,1], [4,3], [3,0], [3,4], [0,0], [0,4], [4,0], [4,4],

Path level:
  4  3  2  3  4
  3  2  1  2  3
  2  1  0  1  2
  3  2  1  2  3
  4  3  2  3  4

Shortest path from (1,1) to (4,4): 1,1 -> 2,1 -> 3,1 -> 4,1 -> 4,2 -> 4,3 -> 4,4
*/