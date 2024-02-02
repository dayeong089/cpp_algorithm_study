#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    string map[1002];
    int escape[1002][1002];
    int fire[1002][1002];

    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
        cin >> map[i];
    }

    queue<pair<int, int>> q;
    queue<pair<int, int>> q2;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(map[i][j] == 'F')
            {
                q.push({i, j});
                fire[i][j] = 1;
            }
            if(map[i][j] == 'J')
            {
                q2.push({i, j});
                escape[i][j] = 1;
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
            if(map[x][y] != '#' && fire[x][y] == 0)
            {
                fire[x][y] = fire[cur.first][cur.second]+1;
                q.push({x, y});
            }
        }
    }

    while(!q2.empty())
    {
        pair<int, int> cur = q2.front();
        q2.pop();
        for(int i=0; i<4; i++)
        {
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            if(x<0 || x>=n || y<0 || y>=m)
            {
                cout << escape[cur.first][cur.second];
                return 0;
            }
            if(map[x][y] != '#' && escape[x][y] == 0 && (fire[x][y]==0 || fire[x][y] > escape[cur.first][cur.second]+1))
            {
                escape[x][y] = escape[cur.first][cur.second]+1;
                q2.push({x, y});
            }
        }
    }

    // for(int i=0; i<n; i++)
    // {
    //     for(int j=0; j<m; j++)
    //     {
    //         cout << fire[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    // for(int i=0; i<n; i++)
    // {
    //     for(int j=0; j<m; j++)
    //     {
    //         cout << escape[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << "IMPOSSIBLE";
    return 0;
}