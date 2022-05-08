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



int moveX[] = { -1, 1, 0, 0};
int moveY[] = { 0, 0, -1, 1};

bool isValid(int x, int y)
{

    return ((x >= 0 && x < row) && (y >= 0 && y < col) && !visited[x][y]);
}

void dfs(int x, int y)
{
    visited[x][y] = 1;
    cout << "[" << x << "," << y << "]" << ",";


    for (int i = 0; i < 4; i++)
    {
        if (isValid(x+moveX[i],y+moveY[i]))
        {
            dfs(x+moveX[i],y+moveY[i]);
        }
        
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
        for (int k = 0; k < 4; k++)
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
     //dfs(2, 2);
     /*
     [2,2],[1,2],[0,2],[0,1],[1,1],[2,1],[3,1],[4,1],[5,1],[6,1],[7,1],[8,1],[9,1],[10,1],[10,0],[9,0],[8,0],[7,0],[6,0],[5,0],[4,0],[3,0],[2,0],[1,0],[0,0],[10,2],[9,2],[8,2],[7,2],[6,2],[5,2],[4,2],[3,2],[3,3],[2,3],[1,3],[0,3],[0,4],[1,4],[2,4],[3,4],[4,4],[5,4],[6,4],[7,4],[8,4],[9,4],[10,4],[10,3],[9,3],[8,3],[7,3],[6,3],[5,3],[4,3],[10,5],[9,5],[8,5],[7,5],[6,5],[5,5],[4,5],[3,5],[2,5],[1,5],[0,5],[0,6],[1,6],[2,6],[3,6],[4,6],[5,6],[6,6],[7,6],[8,6],[9,6],[10,6],[10,7],[9,7],[8,7],[7,7],[6,7],[5,7],[4,7],[3,7],[2,7],[1,7],[0,7],[0,8],[1,8],[2,8],[3,8],[4,8],[5,8],[6,8],[7,8],[8,8],[9,8],[10,8],[10,9],[9,9],[8,9],[7,9],[6,9],[5,9],[4,9],[3,9],[2,9],[1,9],[0,9],[0,10],[1,10],[2,10],[3,10],[4,10],[5,10],[6,10],[7,10],[8,10],[9,10],[10,10],

     */
    bfs(node{ 5,5 });
    printGrid();
    printLevelGrid();
    cout<<"We use left right top-bottom movement"<<endl;
    printShortestPath(node{ 10,10 }, node{ 10,9 });
    /*
    
    The original Grid: 

0,0     0,1     0,2     0,3     0,4     0,5     0,6     0,7     0,8     0,9     0,10

1,0     1,1     1,2     1,3     1,4     1,5     1,6     1,7     1,8     1,9     1,10

2,0     2,1     2,2     2,3     2,4     2,5     2,6     2,7     2,8     2,9     2,10

3,0     3,1     3,2     3,3     3,4     3,5     3,6     3,7     3,8     3,9     3,10

4,0     4,1     4,2     4,3     4,4     4,5     4,6     4,7     4,8     4,9     4,10

5,0     5,1     5,2     5,3     5,4     5,5     5,6     5,7     5,8     5,9     5,10

6,0     6,1     6,2     6,3     6,4     6,5     6,6     6,7     6,8     6,9     6,10

7,0     7,1     7,2     7,3     7,4     7,5     7,6     7,7     7,8     7,9     7,10

8,0     8,1     8,2     8,3     8,4     8,5     8,6     8,7     8,8     8,9     8,10

9,0     9,1     9,2     9,3     9,4     9,5     9,6     9,7     9,8     9,9     9,10

  9       8       7       6       5       4       5       6       7       8       9

  8       7       6       5       4       3       4       5       6       7       8

  7       6       5       4       3       2       3       4       5       6       7

  6       5       4       3       2       1       2       3       4       5       6

  5       4       3       2       1       0       1       2       3       4       5

  6       5       4       3       2       1       2       3       4       5       6

  7       6       5       4       3       2       3       4       5       6       7

  8       7       6       5       4       3       4       5       6       7       8

  9       8       7       6       5       4       5       6       7       8       9

 10       9       8       7       6       5       6       7       8       9      10


We use left right top-bottom movement
Shortest path from (5,5) to (0,0):

5,5 -> 4,5  -> 3,5  -> 2,5  -> 1,5  -> 0,5  -> 0,4  -> 0,3  -> 0,2  -> 0,1  -> 0,0
    
    */
    cout << endl << endl;
}