#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 0X7FFFFFFF;

using namespace std;

int n, m, x;
vector<pair<int, int>> adj1[1005];
vector<pair<int, int>> adj2[1005];
int dist1[1005];
int dist2[1005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x;

    for(int i=1; i<=n; i++){
        dist1[i] = INF;
        dist2[i] = INF;
    }

    while(m--)
    {
        int a, b, t;
        cin >> a >> b >> t;
        adj1[a].push_back({t, b});
        adj2[b].push_back({t, a});
    }

    dist1[x] = 0;
    pq.push({0, x});
    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();

        if(dist1[cur.second] != cur.first) continue;

        for(auto nxt : adj1[cur.second])
        {
            if(dist1[nxt.second] > dist1[cur.second] + nxt.first)
            {
                dist1[nxt.second] = dist1[cur.second] + nxt.first;
                pq.push({dist1[nxt.second], nxt.second});
            }
        }
    }

    dist2[x] = 0;
    pq.push({0, x});
    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();

        if(dist2[cur.second] != cur.first) continue;

        for(auto nxt : adj2[cur.second])
        {
            if(dist2[nxt.second] > dist2[cur.second] + nxt.first)
            {
                dist2[nxt.second] = dist2[cur.second] + nxt.first;
                pq.push({dist2[nxt.second], nxt.second});
            }
        }
    }

    int max_time = -1;
    for(int i=1; i<=n; i++)
    {
        if(dist1[i] + dist2[i] > max_time) max_time = dist1[i] + dist2[i];
    }

    cout << max_time << '\n';

    return 0;
}