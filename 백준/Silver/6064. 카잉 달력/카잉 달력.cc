#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, m, n, x, y;
    cin >> t;

    while(t--)
    {
        bool check = false;
        cin >> m >> n >> x >> y;
        if(x == m) x = 0;
        if(y == n) y = 0;
        for(int i=x; i<=n*m; i+=m)
        {
            if(i==0) continue;
            if(i%n == y)
            {
                cout << i << '\n';
                check = true;
                break;
            }
        }
        if(!check) cout << "-1" << '\n';
    }

    return 0;
}