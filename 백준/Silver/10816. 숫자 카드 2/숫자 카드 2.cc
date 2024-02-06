#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[500005];

int lower_idx(int x)
{
    int st = 0;
    int end = n-1;
    int idx = -1;
    while(st <= end)
    {
        int mid = (st+end)/2;
        if(arr[mid] == x)
        {
            idx = mid;
            end = mid-1;
        }
        else if(arr[mid] < x) st = mid+1;
        else end = mid-1;
    }
    
    return idx;
}

int upper_idx(int x)
{
    int st = 0;
    int end = n-1;
    int idx = -1;
    while(st <= end)
    {
        int mid = (st+end)/2;
        if(arr[mid] == x)
        {
            idx = mid;
            st = mid+1;
        }
        else if(arr[mid] < x) st = mid+1;
        else end = mid-1;
    }

    return idx;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    cin >> m;
    sort(arr, arr+n);
    
    while(m--)
    {
        int x;
        cin >> x;
        int idx1 = lower_idx(x);
        int idx2 = upper_idx(x);
        if(idx1 == -1 && idx2 == -1) cout << '0' << ' ';
        else cout << idx2-idx1+1 << ' ';
    }

    return 0;
}