#include<iostream>
#include<cstdio>
#define INF 10000

using namespace std;

int n, m, r;
int item[105];
int dist[105][105];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //입력
    cin >> n >> m >> r;
    for(int i=1; i<=n; i++) cin >> item[i];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++) {
            if(i==j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    while(r--)
    {
        int a, b, l;
        cin >> a >> b >> l;
        dist[a][b] = l;
        dist[b][a] = l;
    }

    //최단거리 계산
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    //최대 아이템 수 계산
    int max_item = 0;
    for(int i=1; i<=n; i++)
    {
        int now_item = 0;
        for(int j=1; j<=n; j++)
        {
            if(dist[i][j] <= m)
            {
                now_item += item[j];
            }
        }
        if(now_item > max_item) max_item = now_item;
    }

    //출력
    cout << max_item << '\n';
    return 0;
}