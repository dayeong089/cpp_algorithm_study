#include<iostream>
#include<cstdio>
#include<algorithm>
#define INF 0X7FFFFFFF

using namespace std;

int n, m;
int arr[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> arr[i];

    sort(arr, arr+n);
    int p2 = 0;
    int min_diff = INF;

    for(int p=0; p<n; p++)
    {
        while(arr[p2] - arr[p] < m && p2 < n) p2++;
        if(p2 == n) break;
        if(arr[p2] - arr[p] < min_diff) min_diff = arr[p2] - arr[p];
    }

    cout << min_diff;

    return 0;
}