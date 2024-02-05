#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, m, n, x, y;
    cin >> t;

    while(t--)
    {
        cin >> m >> n >> x >> y;
        if(x == m) x = 0;
        if(y == n) y = 0;
        int l = lcm(m, n);
        bool exist = false;

        for(int i=x; i<=l; i+=m)
        {
            if(i==0) continue;
            if(i%n == y)
            {
                exist = true;
                cout << i << '\n';
            }
        }

        if(!exist) cout << "-1" << '\n';
    }

    return 0;
}