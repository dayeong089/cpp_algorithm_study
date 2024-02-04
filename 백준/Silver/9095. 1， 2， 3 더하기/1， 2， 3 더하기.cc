#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[12];
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    int t, n;
    cin >> t;

    for(int i=4; i<12; i++)
    {
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }

    for(int i=0; i<t; i++)
    {
        cin >> n;
        cout << arr[n] << '\n';
    }

    return 0;
}