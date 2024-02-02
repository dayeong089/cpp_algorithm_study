#include<bits/stdc++.h>
using namespace std;

int n, cnt=0;
bool yarr[40];
bool sumarr[40];
bool minarr[40];

void queen(int k)
{
    if(k == n)
    {
        cnt++;
        return;
    }

    for(int i=0; i<n; i++)
    {
        if(yarr[i] || sumarr[k+i] || minarr[k-i+n]) continue;
        yarr[i] = 1;
        sumarr[k+i] = 1;
        minarr[k-i+n] = 1;
        queen(k+1);
        yarr[i] = 0;
        sumarr[k+i] = 0;
        minarr[k-i+n] = 0;
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    queen(0);
    cout << cnt << '\n';

    return 0;
}