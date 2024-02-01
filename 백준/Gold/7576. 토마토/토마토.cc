#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> m >> n;
    int board[1001][1001];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> board[i][j];
        }
    }

    queue<pair<int, int>> q;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(board[i][j] == 1)
            {
                q.push({i, j});
            }
        }
    }
    
    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            if(x<0 || x>=n || y<0 || y>=m) continue;
            if(board[x][y] == -1) continue;
            if(board[x][y] == 0 || board[x][y] > board[cur.first][cur.second]+1)
            {
                board[x][y] = board[cur.first][cur.second]+1;
                q.push({x, y});
            }
        }
    }

    int day = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(board[i][j] == 0)
            {
                cout << -1;
                return 0;
            }
            if(board[i][j] > day) day = board[i][j];
        }
    }

    cout << day-1;
    return 0;
}