#include<bits/stdc++.h>
using namespace std;

#define ROW 10
#define COL 10

int moveX[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int moveY[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

struct node
{
    int x, y;
};

bool visited[ROW][COL];
node parent[ROW][COL];
int level[ROW][COL];

void Init() {
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            level[i][j] = -1;
            visited[i][j] = false;
        }
    }
}

bool isValid(node node) {
    return !visited[node.x][node.y] && node.x >= 0 && node.x < COL&& node.y >= 0 && node.y < ROW;
}

void BFS(node start) {
    queue<node> q;
    q.push(start);
    visited[start.x][start.y] = true;
    level[start.x][start.y] = 0;

    while (!q.empty()) {
        node x = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            node next = node{ x.x + moveX[i], x.y + moveY[i] };
            if (isValid(next)) {
                visited[next.x][next.y] = true;
                level[next.x][next.y] = level[x.x][x.y] + 1;
                q.push(next);
            }
        }
    }
}

void printLevelGrid()
{
    cout << endl << "Path level: " << endl;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("%3d", level[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int startX, startY;
    cin >> startX >> startY;

    int endX, endY;
    cin >> endX >> endY;

    int mine;
    cin >> mine;
    int mines[ROW][COL];

    Init();
    for (int i = 0; i < mine; i++)
    {
        int x, y;
        cin >> x >> y;
        mines[x][y] = 1;
        visited[x][y] = 1;
    }
    BFS(node{ startX,startY });
    int detector1 = level[endX][endY];

    Init();
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (mines[i][j] == 1) {
                visited[i][j] = true;
                for (int k = 0; k < 8; k++)
                {
                    int x = i + moveX[k];
                    int y = j + moveY[k];
                    if (x >= 0 && x < COL && y >= 0 && y < ROW)
                        visited[x][y] = true;
                }
            }
        }
    }

    BFS(node{ startX,startY });
    int detector2 = level[endX][endY];

    if (detector1 != -1 && detector2 != -1) {
        if (detector1 < detector2) {
            cout << "detector 1";
        }
        else {
            cout << "detector 2";
        }
    }
    else if (detector2 == -1 && detector1 != -1) {
        cout << "detector 1";
    }
    else if (detector2 != -1 && detector1 == -1) {
        cout << "detector 2";
    }
    else {
        cout << "not possible";
    }
}

/*
0 0
9 9
6
2 2
9 0
4 5
7 5
9 3
3 8
*/