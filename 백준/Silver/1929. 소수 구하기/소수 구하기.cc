#include<bits/stdc++.h>
using namespace std;

int m, n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    vector<bool> num(n+1, true);

    num[1] = false;
    for(int i=2; i*i<=n; i++)
    {
        if(!num[i]) continue;
        for(int j=i*i; j<=n; j+=i)
        {
            num[j] = false;
        }
    }

    for(int i=m; i<=n; i++)
    {
        if(num[i]) cout << i << '\n';
    }

    return 0;
}