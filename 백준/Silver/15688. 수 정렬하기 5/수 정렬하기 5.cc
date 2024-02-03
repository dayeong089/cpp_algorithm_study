#include<bits/stdc++.h>
using namespace std;

int num[2000005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> x;
        num[x+1000000]++;
    }

    for(int i=0; i<2000005; i++)
    {
        while(num[i]--)
        {
            cout << i-1000000 << '\n';
        }
    }

    return 0;
}