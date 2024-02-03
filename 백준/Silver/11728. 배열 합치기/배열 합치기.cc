#include<bits/stdc++.h>
using namespace std;

int aarr[1000001];
int barr[1000001];
int carr[2000002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    int aidx=0, bidx=0, cidx=0;
    cin >> n >> m;

    for(int i=0; i<n; i++) cin >> aarr[i];
    for(int i=0; i<m; i++) cin >> barr[i];

    while(aidx < n && bidx < m)
    {
        if(aarr[aidx] <= barr[bidx])
        {
            carr[cidx] = aarr[aidx];
            cidx++;
            aidx++;
        }
        else
        {
            carr[cidx] = barr[bidx];
            cidx++;
            bidx++;
        }
    }

    while(aidx < n)
    {
        carr[cidx] = aarr[aidx];
        cidx++;
        aidx++;
    }

    while(bidx < m)
    {
        carr[cidx] = barr[bidx];
        cidx++;
        bidx++;
    }

    for(int i=0; i<cidx; i++)
    {
        cout << carr[i] << ' ';
    }

    return 0;
}