#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#define INF 0X7FFFFFFF

using namespace std;

int v, e, p, a, b, cost;
vector<pair<int, int>> adj[5005];
vector<int> parent[5005];
int dist[5005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e >> p;

    for(int i=0; i<e; i++)
    {
        cin >> a >> b >> cost;
        adj[a].push_back({cost, b});
        adj[b].push_back({cost, a});
    }

    for(int i=1; i<=v; i++) dist[i] = INF;

    pq.push({0, 1});
    dist[1] = 0;

    while(!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        if(cur.first != dist[cur.second]) continue;

        for(auto nxt : adj[cur.second])
        {
            if(dist[nxt.second] > dist[cur.second] + nxt.first)
            {
                dist[nxt.second] = dist[cur.second] + nxt.first;
                pq.push({dist[nxt.second], nxt.second});
                parent[nxt.second].clear();
                parent[nxt.second].push_back(cur.second);
            }
            else if(dist[nxt.second] == dist[cur.second] + nxt.first)
            {
                parent[nxt.second].push_back(cur.second);
            }
        }
    }

    queue<int> q;
    q.push(v);
    bool check = false;

    while(!q.empty())
    {
        auto cur = q.front();
        if(cur == p)
        {
            check = true;
            break;
        }
        q.pop();

        for(auto nxt : parent[cur])
        {
            q.push(nxt);
        }
    }

    if(check) cout << "SAVE HIM" << '\n';
    else cout << "GOOD BYE" << '\n';

    return 0;
}