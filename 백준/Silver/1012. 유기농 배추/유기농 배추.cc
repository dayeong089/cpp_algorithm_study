#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int t, m, n, k, x, y;
int arr[51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    arr[x][y] = 0;

    while(!q.empty())
    {
        auto now = q.front(); q.pop();

        for(int i=0; i<4; i++)
        {
            int nowx = now.first + dx[i];
            int nowy = now.second + dy[i];

            if(nowx < 0 || nowx >= n || nowy < 0 || nowy >= m) continue;
            if(arr[nowx][nowy] == 0) continue;

            q.push({nowx, nowy});
            arr[nowx][nowy] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> m >> n >> k;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++) arr[i][j] = 0;
        }

        while(k--)
        {
            cin >> x >> y;
            arr[y][x] = 1;
        }

        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(arr[i][j] == 1)
                {
                    bfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }
    
    return 0;
}