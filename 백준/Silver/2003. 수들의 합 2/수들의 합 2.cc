#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[10005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<n; i++) cin >> arr[i];
	
	int result = 0;
	int st = 0;
	int end = 0;
	int now_sum = 0;
	
	for(int st=0; st<n; st++)
	{
		while(end<n && now_sum<m)
		{
			now_sum += arr[end];
			end++;
		}
		if(now_sum == m) result++;
		now_sum -= arr[st];
	}
	
	cout << result << '\n';
	
	return 0;
}