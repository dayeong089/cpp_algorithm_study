#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll div(ll a, ll b, ll c)
{
    if(b == 1) return a%c;
    if(b%2==0) return (div(a, b/2, c) * div(a, b/2, c)) % c;
    else return ((div(a, b/2, c) * div(a, b/2, c) % c) * (a%c)) % c;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c;
    cin >> a >> b >> c;

    cout << div(a, b, c) << '\n';

    return 0;
}