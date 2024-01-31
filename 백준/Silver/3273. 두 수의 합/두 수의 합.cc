#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[100001];
    bool num[2000001] = {false, };
    int n, x, y, result=0;

    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    cin >> x;

    for(int i=0; i<n; i++)
    {
        if(x-arr[i]>0 && num[x-arr[i]]) result++;
        num[arr[i]] = true;
    }

    cout << result << '\n';

    return 0;
}