#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<vector>

using namespace std;

/*
8 8 1
1 5
1 2
2 3
3 4
5 4
4 6
6 7
6 8
6
*/

int n, m, q;
pair<int, int> edge[100005];
int p[100005];
int height[100005];
int check[100005];
stack<int> s;

int find(int a)
{
	if(p[a] == a) return a;
	return p[a] = find(p[a]);
}

long long _union(int a, int b)
{
	long long result;
	a = find(a);
	b = find(b);
	
	if(a==b) {
		result = 0;
		return 0;
	}
	else result = (long long)height[a] * (long long)height[b];

	if(a > b){
		p[a] = b;
		height[b] += height[a];
	}
	else{
		p[b] = a;
		height[a] += height[b];
	}
	return result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> q;
	
	for(int i=0; i<=n; i++)
	{
		p[i] = i;
		height[i] = 1;
	}
	
	for(int i=1; i<=m; i++)
	{
		int x, y;
		cin >> x >> y;
		edge[i] = {x, y};
		check[i] = 1;
	}
	
	while(q--)
	{
		int a;
		cin >> a;
		s.push(a);
		check[a] = 0;
	}
	
	for(int i=1; i<=m; i++)
	{
		if(check[i]) _union(edge[i].first, edge[i].second);
	}
	
	long long result = 0;
	while(!s.empty())
	{
		int now = s.top();
		s.pop();
		
		int x = edge[now].first;
		int y = edge[now].second;
		
		result += (_union(x, y));
	}
	
	cout << result << '\n';
	
	return 0;
}