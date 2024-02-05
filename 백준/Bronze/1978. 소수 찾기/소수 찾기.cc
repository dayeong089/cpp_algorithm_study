#include<bits/stdc++.h>
using namespace std;

int n;
int num[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=2; i<1001; i++)
    {
        bool check = true;
        for(int j=2; j*j<=i; j++)
        {
            if(i%j == 0)
            {
                check = false;
                break;
            }
        }
        if(check) num[i] = 1;
    }

    cin >> n;
    int cnt = 0;
    
    while(n--)
    {
        int x;
        cin >> x;
        if(num[x]) cnt++;
    }

    cout << cnt;

    return 0;
}