#include<iostream>
#include<algorithm>

using namespace std;

int n;
int arr[1001];
int dp[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) 
    {
        cin >> arr[i];
        dp[i] = 1;
    }

    for(int i=1; i<n; i++)
    {
        int max_now = 0;
        for(int j=i-1; j>=0; j--)
        {
            if(arr[j] < arr[i] && dp[j] > max_now)
            {
                dp[i] = dp[j] + 1;
                max_now = dp[j];
            }
        }
    }

    cout << *max_element(dp, dp+n) << '\n';

    return 0;
}