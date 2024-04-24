#include<iostream>
#include<algorithm>

using namespace std;

int n;
int arr[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];

    sort(arr, arr+n);

    long long max_weight = 0; 
    for(int i=0; i<n; i++)
    {
        int now = arr[i] * (n-i);
        if(now > max_weight) max_weight = now;
    }

    cout << max_weight << '\n';
    return 0;
}