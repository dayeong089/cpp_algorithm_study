#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<vector>

using namespace std;

int n, m, q;
pair<int, int> edge[100005];
vector<int> p(100005, -1);
int check[100005];
stack<int> s;

int find(int a)
{
	if(p[a] < 0) return a;
	return p[a] = find(p[a]);
}

long long _union(int a, int b)
{
	long long result;
	a = find(a);
	b = find(b);

	if(a==b) return 0;
	else result = (long long)p[a] * (long long)p[b];

	if(p[a] <= p[b]){
        p[a] += p[b];
        p[b] = a;
    }
	else{
        p[b] += p[a];
        p[a] = b;
    }

	return result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> q;
	
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