#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

#define INF 0x7fffffff

using namespace std;

vector<pair<int, int>> adj[20005]; // 거리, 간선
bool isvisited[20005];
int dist[20005];

int v, e, start; 


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> v >> e >> start;
	
	for(int i=0; i<e; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		adj[a].push_back({cost, b});
	}
	
	for(int i=1; i<=v; i++)
	{
		isvisited[i] = false;
		dist[i] = INF;
	}
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	pq.push({0, start});
	isvisited[start] = true;
	dist[start] = 0;
	
	while(!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		if(cur.first != dist[cur.second]) continue;
		isvisited[cur.second] = true;
 		
		for(auto nxt : adj[cur.second])
		{
			if(isvisited[nxt.second]) continue;
			if(dist[nxt.second] > cur.first + nxt.first)
			{
				dist[nxt.second] = cur.first + nxt.first;
				pq.push({dist[nxt.second], nxt.second});
			}
		}
	}	
	
	for(int i=1; i<=v; i++)
	{
		if(dist[i] != INF) cout << dist[i] << '\n';
		else cout << "INF" << '\n';
	}
	
	return 0;
}