#include<iostream>
#include<cstdio>

using namespace std;
int n, m;
int arr[100005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	arr[0] = 0;
	cin >> n >> m;
	cin >> arr[1];

	for (int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		arr[i] = x + arr[i - 1];
	}

	while (m--)
	{
		int i, j;
		cin >> i >> j;
		cout << arr[j] - arr[i - 1] << '\n';
	}

	return 0;
}