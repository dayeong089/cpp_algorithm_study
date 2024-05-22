#include<iostream>
#include<algorithm>

using namespace std;

int n;
int dp[20];
int t[20];
int p[20];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=1; i<=n; i++) cin >> t[i] >> p[i];
    for(int i=n; i>=1; i--)
    {
        if(i+t[i] <= n+1)
        {
            dp[i] = max(dp[i+1], dp[i+t[i]]+p[i]);
        }
        else dp[i] = dp[i+1];
    }

    int answer = 0;
    for(int i=1; i<=n; i++) answer = max(answer, dp[i]);
    cout << answer << '\n';
    return 0;
}