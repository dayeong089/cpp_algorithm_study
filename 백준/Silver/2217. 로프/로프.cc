#include<bits/stdc++.h>
using namespace std;

int n;
int arr[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];

    sort(arr, arr+n);

    int max_weight = 0;
    int now_num = n;

    for(int i=0; i<n; i++)
    {
        int now_weight = arr[i] * (n-i);
        if(now_weight > max_weight) max_weight = now_weight;
    }

    cout << max_weight;

    return 0;
}