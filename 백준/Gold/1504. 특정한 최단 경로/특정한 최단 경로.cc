#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 0X7FFFFFF

using namespace std;

int n, e, x, y;
int dist[805];
vector<pair<int, int>> adj[805];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int dijkstra(int x, int y)
{
    // 초기화
    for(int i=1; i<=n; i++) dist[i] = INF;
    while(!pq.empty()) pq.pop();

    // 시작점
    dist[x] = 0;
    pq.push({0, x});

    // 거리 계산
    while(!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        if(dist[cur.second] != cur.first) continue;

        for(auto nxt : adj[cur.second])
        {
            if(dist[nxt.second] > dist[cur.second] + nxt.first)
            {
                dist[nxt.second] = dist[cur.second] + nxt.first;
                pq.push({dist[nxt.second], nxt.second});
            }
        }
    }

    return dist[y];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> e;

    while(e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    cin >> x >> y;
    int dist1 = dijkstra(1, x) + dijkstra(x, y) + dijkstra(y, n);
    int dist2 = dijkstra(1, y) + dijkstra(y, x) + dijkstra(x, n);

    if(dist1 >= INF && dist2 >= INF) cout << "-1";
    else cout << min(dist1, dist2);

    return 0;
}