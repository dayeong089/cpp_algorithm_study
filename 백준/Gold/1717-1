#include<iostream>
#include<vector>

using namespace std;

int n, m;
int p[1000005];

int find(int a)
{
	if(p[a] == a) return a;
	return p[a] = find(p[a]);
}

void _union(int a, int b)
{
	a = find(a);
	b = find(b);
	
	if(a > b) p[a] = b;
	else p[b] = a;
}

void check(int a, int b)
{
	a = find(a);
	b = find(b);
	
	if(a==b) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	
	for(int i=0; i<=n; i++) p[i] = i;
	
	while(m--)
	{
		int op, a, b;
		cin >> op >> a >> b;
		
		if(op == 0)
		{
			if(a!=b) _union(a, b);
		}
		else
		{
			check(a, b);
		}
	}
	
	return 0;
}
