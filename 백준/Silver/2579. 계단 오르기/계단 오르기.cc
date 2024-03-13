#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int n;
int arr[305];
int dp[305];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		cin >> arr[i];
	}
	
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[1], arr[2]) + arr[3];
	
	for(int i=4; i<=n; i++)
	{
		dp[i] = max(dp[i-2], dp[i-3] + arr[i-1]) + arr[i];
	}
	
	cout << dp[n];
	
	return 0;
}