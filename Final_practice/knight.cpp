#include<bits/stdc++.h>
using namespace std;

#define ROW 5
#define COL 5

//strait[0,3]   = up, down, left, right
//diagonal[4,7] = up-left, up-right, down-left, down-right
//knight[8,15]  = up-right, up-left, down-right, down-right, right-up, right-down, left-up, left-down
int moveX[] = { -1, 1, 0, 0, -1, 1, -1, 1, 1, -1, 1, -1, 2, 2, -2, -2 };
int moveY[] = { 0, 0, -1, 1, -1, -1, 1, 1, -2, -2, 2, 2, -1, 1, -1, 1 };

struct node
{
    int x, y;
};

bool visited[ROW][COL];
node parent[ROW][COL];

void Init() {
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            visited[i][j] = false;
        }
    }
}

bool isValid(node node) {
    return !visited[node.x][node.y] && node.x >= 0 && node.x < COL&& node.y >= 0 && node.y < ROW;
}

void DFS(node start) {
    cout << start.x << " " << start.y << "   ";
    visited[start.x][start.y] = true;

    for (int i = 0; i < 4; i++)
    {
        node next = node{ start.x + moveX[i], start.y + moveY[i] };
        if (isValid(next))
        {
            DFS(next);
        }
    }
}

void BFS(node start) {
    Init();
    queue<node> q;
    q.push(start);
    visited[start.x][start.y] = true;

    while (!q.empty()) {
        node x = q.front();
        q.pop();
        cout << x.x << " " << x.y << "   ";
        for (int i = 8; i < 16; i++)
        {
            node next = node{ x.x + moveX[i], x.y + moveY[i] };
            if (isValid(next)) {
                visited[next.x][next.y] = true;
                q.push(next);
            }
        }
    }
}

void shortestPath(node start, node end)
{
    if (end.x == start.x && end.y == start.y)
    {
        cout << end.x << "," << end.y;
        return;
    }

    shortestPath(start, parent[end.x][end.y]);
    cout << " -> " << end.x << "," << end.y;
}

void printShortestPath(node start, node end) {
    Init();
    queue<node> q;
    q.push(start);
    visited[start.x][start.y] = true;

    while (!q.empty()) {
        node x = q.front();
        q.pop();
        cout << x.x << " " << x.y << "   ";
        for (int i = 8; i < 16; i++)
        {
            node next = node{ x.x + moveX[i], x.y + moveY[i] };
            if (isValid(next)) {
                visited[next.x][next.y] = true;
                parent[next.x][next.y] = x;
                q.push(next);
            }
        }
    }
    cout << "\n\nShortest path from (" << start.x << "," << start.y << ") to (" << end.x << "," << end.y << "): ";
    shortestPath(start, end);
    cout << endl << endl;
}

int main() {
    DFS(node{ 2,2 });
    cout << endl;
    BFS(node{ 2,2 });
    printShortestPath(node{ 2,2 }, node{ 3,2 });
}