#include<bits/stdc++.h>
using namespace std;

int n, s;
int min_len = 0x7fffffff;
int arr[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for(int i=0; i<n; i++) cin >> arr[i];
    
    int now_sum=arr[0], end=0;

    for(int st=0; st<n; st++)
    {
        while(end<n && now_sum<s)
        {
            end++;
            now_sum += arr[end];
        }
        if(end >= n) break;
        min_len = min(min_len, end-st+1);
        now_sum -= arr[st];
    }

    if(min_len != 0x7fffffff) cout << min_len;
    else cout << '0';

    return 0;
}