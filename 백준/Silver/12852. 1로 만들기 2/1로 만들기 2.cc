#include<bits/stdc++.h>
using namespace std;

int n;
int dp[1000005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    dp[1] = 0;
    for(int i=2; i<=n; i++)
    {
        dp[i] = dp[i-1] + 1;
        if(i%2 == 0) dp[i] = min(dp[i], dp[i/2]+1);
        if(i%3 == 0) dp[i] = min(dp[i], dp[i/3]+1);
    }

    cout << dp[n] << '\n';
    cout << n << ' ';
    while(n>1)
    {
        if(n%2 == 0 && dp[n] == dp[n/2]+1)
        {
            cout << n/2 << ' ';
            n = n/2;
        }
        else if(n%3 == 0 && dp[n] == dp[n/3]+1)
        {
            cout << n/3 << ' ';
            n = n/3;
        }
        else
        {
            cout << n-1 << ' ';
            n--;
        }
    }

    return 0;
}