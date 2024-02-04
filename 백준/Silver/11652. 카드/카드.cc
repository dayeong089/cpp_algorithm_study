#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt=0, mxcnt=0, n;
    long long mxval = -(2<<62)-1;
    long long arr[100001];

    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];

    sort(arr, arr+n);

    for(int i=0; i<n; i++)
    {
        if(i==0 || arr[i-1]==arr[i])
        {
            cnt++;
        }
        else
        {
            if(cnt > mxcnt)
            {
                mxval = arr[i-1];
                mxcnt = cnt;
            }
            cnt = 1;
        }
    }
    if(cnt > mxcnt) mxval = arr[n-1];
    cout << mxval;

    return 0;
}