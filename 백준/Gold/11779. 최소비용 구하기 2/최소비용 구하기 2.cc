#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>

#define INF 0x7fffffff

using namespace std;

vector<pair<int, int>> adj[1005]; // 거리, 간선
bool isvisited[1005];
int dist[1005];
int prev_node[1005];

int v, e, start, finish;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> v >> e;
	
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
		prev_node[i] = i;
	}
	
	cin >> start >> finish;
	
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
				prev_node[nxt.second] = cur.second;
			}
		}
	}	
	
	cout << dist[finish] << '\n';
	
	stack<int> route;
	int now = finish;
		
	while(now != start)
	{
		route.push(now);
		now = prev_node[now];
	}
	
	cout << route.size()+1 << '\n';
	cout << start << ' ';
	while(!route.empty())
	{
		int cur = route.top();
		cout << cur << ' ';
		route.pop();
	}
	
	return 0;
}