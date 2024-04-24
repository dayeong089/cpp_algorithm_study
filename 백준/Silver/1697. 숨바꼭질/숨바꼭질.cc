#include<bits/stdc++.h>
using namespace std;
int n, k;
int arr[100005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	
	queue<int> q;
	q.push(n);
	arr[n] = 1;
	
	while(!q.empty())
	{
		int pos = q.front();
		if(pos == k)
		{
			cout << arr[pos]-1 << '\n';
		}
		q.pop();
		if(pos-1 >= 0 && !arr[pos-1])
		{
			q.push(pos-1);
			arr[pos-1] = arr[pos]+1;
		}
		if(pos+1 <= 100000 && !arr[pos+1])
		{
			q.push(pos+1);
			arr[pos+1] = arr[pos]+1;
		}
		if(pos*2 <= 100000 && !arr[pos*2])
		{
			q.push(pos*2);
			arr[pos*2] = arr[pos]+1;
		}
	}
	
	return 0;
}