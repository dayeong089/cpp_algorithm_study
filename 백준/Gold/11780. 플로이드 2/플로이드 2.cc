#include<iostream>
#include<cstdio>
#include<queue>
#define INF 10000005

using namespace std;

int n, m;
int arr[105][105];
int nxt[105][105];
queue<int> q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i == j) arr[i][j] = 0;
            else arr[i][j] = INF;
            nxt[i][j] = 0;
        }
    }

    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if(arr[a][b] > c) arr[a][b] = c;
        nxt[a][b] = b;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            for(int k=1; k<=n; k++)
            {
                if(arr[j][i] + arr[i][k] < arr[j][k])
                {
                    arr[j][k] = arr[j][i] + arr[i][k];
                    nxt[j][k] = nxt[j][i];
                }
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(arr[i][j] == INF) cout << '0' << ' ';
            else cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(nxt[i][j] == 0) cout << '0' << '\n';
            else
            {
                int now_end = nxt[i][j];
                q.push(now_end);
                while(now_end != j)
                {
                    now_end = nxt[now_end][j];
                    q.push(now_end);
                }

                cout << q.size()+1 << ' ';
                cout << i << ' ';
                while(!q.empty())
                {
                    cout << q.front() << ' ';
                    q.pop();
                }
                cout << '\n';
            }
        }
    }

    return 0;
}