#include <iostream>
#include <queue>
using namespace std;

#define row 11
#define col 11

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
int moveX[] = { -1, 1, 0, 0, -1, -1, 1, 1, 1, -1, 1, -1, 2, 2, -2, -2 };
int moveY[] = { 0, 0, -1, 1, -1, -1, 1, 1, -2, -2, 2, 2, -1, 1, -1, 1 };


bool isValid(int x, int y)
{

    return ((x >= 0 && x < row) && (y >= 0 && y < col) && !visited[x][y]);
}

void dfs(int x, int y)
{
    visited[x][y] = 1;
    cout << "[" << x << "," << y << "]" << ", ";
    if (isValid(x - 1, y))
    {
        dfs(x - 1, y);//up
    }
    if (isValid(x + 1, y))
    {
        dfs(x + 1, y);//down
    }
    if (isValid(x, y - 1))
    {
        dfs(x, y - 1);//down
    }
    if (isValid(x, y + 1))
    {
        dfs(x, y + 1);
    }
}

void bfs(node nn)
{
    queue<node> q;
    q.push(nn);
    visited[nn.x][nn.y] = true;
    level[nn.x][nn.y] = 0;

    while (!q.empty())
    {
        node n = q.front();
        // cout << x << " ";
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
    cout << endl << "Path level: " << endl << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            //  cout << level[i][j] << " ";
            printf("%3d\t", level[i][j]);
        }
        cout << endl << endl;
    }
    cout << endl << endl;
}

void printGrid()
{
    cout << endl << "The original Grid: " << endl << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << i << "," << j << "\t";
        }
        cout << endl << endl;
    }
}
void shortestPath(node start, node en)
{
    if (en.x == start.x && en.y == start.y)
    {
        cout << endl << en.x << "," << en.y;
        return;
    }

    shortestPath(start, previous[en.x][en.y]);
    cout << " -> " << en.x << "," << en.y << " ";
}
void printShortestPath(node start, node en)
{
    cout << "Shortest path from (" << start.x << "," << start.y << ") to (" << en.x << "," << en.y << "): " << endl;
    shortestPath(start, en);
    cout << endl << endl;
}

int main()
{
    // dfs(2, 2);
    bfs(node{ 10,10 });
    printGrid();
    printLevelGrid();
    printShortestPath(node{ 10,10 }, node{ 0,0 });
    cout << endl << endl;
}
