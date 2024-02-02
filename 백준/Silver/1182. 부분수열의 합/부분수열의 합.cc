#include<bits/stdc++.h>
using namespace std;

int n, s, cnt=0;
int arr[21];

void func(int m, int total)
{
    if(m == n)
    {
        if(total == s) cnt++;
        return;
    }

    func(m+1, total);
    func(m+1, total+arr[m]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for(int i=0; i<n; i++) cin >> arr[i];
    func(0, 0);
    if(s == 0) cnt--;
    cout << cnt;

    return 0;
}