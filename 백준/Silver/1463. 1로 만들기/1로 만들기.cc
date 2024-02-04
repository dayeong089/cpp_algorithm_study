#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[1000005];
    int n;
    cin >> n;

    arr[1] = 0;
    int div2, div3;

    for(int i=2; i<=n; i++)
    {
        div2 = i;
        div3 = i;
        if(i%2 == 0) div2 = arr[i/2]+1;
        if(i%3 == 0) div3 = arr[i/3]+1;
        arr[i] = min({arr[i-1]+1, div2, div3});
    }

    cout << arr[n];

    return 0;
}