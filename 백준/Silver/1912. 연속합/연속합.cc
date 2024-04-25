#include<iostream>
#include<algorithm>

using namespace std;

int n;
int arr[100001];
int dp[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];

    dp[0] = arr[0];
    for(int i=1; i<n; i++)
    {
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
    }

    cout << *max_element(dp, dp+n);

    return 0;
}