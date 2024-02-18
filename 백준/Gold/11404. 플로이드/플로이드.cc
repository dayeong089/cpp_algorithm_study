#include<iostream>
#include<cstdio>
#define INF 10000005

using namespace std;

int n, m;
int arr[101][101];

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
        }
    }

    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if(arr[a][b] > c) arr[a][b] = c;
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

    return 0;
}