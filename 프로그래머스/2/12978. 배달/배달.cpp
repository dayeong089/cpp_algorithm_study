#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> adj[55];
int dist[55];

int solution(int N, vector<vector<int> > road, int K) {
    for(int i=0; i<road.size(); i++)
    {
        adj[road[i][0]].push_back({road[i][2], road[i][1]});
        adj[road[i][1]].push_back({road[i][2], road[i][0]});
    }
    for(int i=1; i<=N; i++) dist[i] = INT_MAX;
    
    dist[1] = 0;
    pq.push({0, 1});
    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if(cur.first != dist[cur.second]) continue;
        for(auto nxt : adj[cur.second])
        {
            if(dist[nxt.second] > cur.first + nxt.first)
            {
                dist[nxt.second] = cur.first + nxt.first;
                pq.push({dist[nxt.second], nxt.second});
            }
        }
    }
    
    int answer = 0;
    for(int i=1; i<=N; i++)
    {
        if(dist[i] <= K) answer++;
    }
    return answer;
}