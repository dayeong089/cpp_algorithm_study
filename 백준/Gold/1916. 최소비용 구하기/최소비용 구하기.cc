#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 0X7FFFFFFF

using namespace std;

int n, m, st, des;
vector<pair<int, int>> adj[1005];
int dist[1005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++) dist[i] = INF;
    while(m--)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        adj[a].push_back({cost, b});
    }

    cin >> st >> des;

    dist[st] = 0;
    pq.push({0, st});

    while(!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        if(dist[cur.second] != cur.first) continue;

        for(auto nxt : adj[cur.second])
        {
            if(dist[nxt.second] > nxt.first + dist[cur.second])
            {
                dist[nxt.second] = nxt.first + dist[cur.second];
                pq.push({dist[nxt.second], nxt.second});
            }
        }
    }

    cout << dist[des];

    return 0;
}