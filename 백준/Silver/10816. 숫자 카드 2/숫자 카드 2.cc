#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[500005];

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
        cout << upper_bound(arr,arr+n,x) - lower_bound(arr,arr+n,x) << ' ';
    }

    return 0;
}