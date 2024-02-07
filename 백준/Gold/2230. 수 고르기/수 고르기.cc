#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);

    int min_diff=0x7fffffff, idx1=0, idx2=1;
    while(idx1<n && idx2<n)
    {
        int now_diff = arr[idx2]-arr[idx1];
        if(now_diff < m) idx2++;
        else if(now_diff == m) 
        {
            min_diff = now_diff;
            break;
        }
        else
        {
            min_diff = min(min_diff, now_diff);
            idx1++;
        }
    }

    cout << min_diff << '\n';

    return 0;
}