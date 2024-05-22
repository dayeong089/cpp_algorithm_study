#include<iostream>

using namespace std;

int n, t;
long long dp[101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;
    for(int i=6; i<=100; i++) dp[i] = dp[i-1] + dp[i-5];

    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}