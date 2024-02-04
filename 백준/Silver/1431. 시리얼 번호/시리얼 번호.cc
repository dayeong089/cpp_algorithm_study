#include<bits/stdc++.h>
using namespace std;

bool cmp(string a, string b)
{
    // 조건 1
    if(a.length() != b.length()) return a.length() < b.length();

    // 조건 2
    int a_add=0, b_add=0;
    for(auto c : a)
    {
        if(c >= '0' && c <= '9') a_add += (c - '0');
    }
    for(auto c : b)
    {
        if(c >= '0' && c <= '9') b_add += (c - '0');
    }
    if(a_add != b_add) return a_add < b_add;

    // 조건 3
    return a < b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string arr[51];
    for(int i=0; i<n; i++) cin >> arr[i];

    sort(arr, arr+n, cmp);
    for(int i=0; i<n; i++) cout << arr[i] << '\n';

    return 0;
}