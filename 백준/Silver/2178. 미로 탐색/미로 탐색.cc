#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int board[101][101];
    int vis[101][101] = {0, };
    int n, m;

    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        string str;
        cin >> str;
        for(int j=0; j<str.size(); j++)
        {
            int x = str[j]-'0';
            board[i][j] = x;
        }
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for(int k=0; k<4; k++)
        {
            int x = cur.first + dx[k];
            int y = cur.second + dy[k];
            if(x<0 || x>=n || y<0 || y>=m) continue;
            if(!board[x][y] || vis[x][y]) continue;
            board[x][y] = board[cur.first][cur.second] + 1;
            vis[x][y] = 1;
            q.push({x, y}); 
        }
    }

    cout << board[n-1][m-1];

    return 0;
}