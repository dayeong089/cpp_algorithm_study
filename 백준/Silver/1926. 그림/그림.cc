#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    int board[501][501];

    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> board[i][j];
        }
    }

    queue<pair<int, int>> q;
    int max_size = 0;
    vector<int> v;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(board[i][j])
            {
                int now_size = 1;
                q.push({i, j});
                board[i][j] = 0;
                
                while(!q.empty())
                {
                    pair<int, int> cur = q.front(); 
                    q.pop();
                    for(int k=0; k<4; k++)
                    {
                        int x = cur.first + dx[k];
                        int y = cur.second + dy[k];

                        if(x<0 || x>=n || y<0 || y>=m) continue;
                        if(board[x][y])
                        {
                            q.push({x, y});
                            board[x][y] = 0;
                            now_size ++;
                        }
                    }
                }
                v.push_back(now_size);
            }
        }
    }

    for(int i=0; i<v.size(); i++)
    {
        if(v[i] > max_size) max_size = v[i];
    }

    cout << v.size() << '\n';
    cout << max_size << '\n';

    return 0;
}