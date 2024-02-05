#include<bits/stdc++.h>
using namespace std;

int n, k;
int arr[20];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> arr[i];

    int cnt = 0;
    while(k>0)
    {
        cnt += (k/arr[n-1]);
        k = (k%arr[n-1]);
        n--;
    }

    cout << cnt;

    return 0;
}