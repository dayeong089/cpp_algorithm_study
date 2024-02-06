#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[100005];

int binary_search(int x)
{
    int start = 0;
    int end = n-1;

    while(start <= end)
    {
        int mid = (start+end)/2;
        if(arr[mid] > x) end = mid-1;
        else if(arr[mid] < x) start = mid+1;
        else return 1;
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    cin >> m;

    while(m--)
    {
        int x;
        cin >> x;
        cout << binary_search(x) << '\n';
    }

    return 0;
}