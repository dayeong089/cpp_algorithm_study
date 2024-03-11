#include<iostream>
#include<cstdio>
#include<algorithm>
#include<tuple>
#include<vector>

using namespace std;

int n;
int arr[1005][1005];
tuple<int, int, int> edge[1000005];
vector<int> p(1005, -1);

int find(int a)
{
    if(p[a] < 0) return a;
    return p[a] = find(p[a]);
}

int is_diff_group(int a, int b)
{
    a = find(a);
    b = find(b);

    if(a == b) return 0;
    if(p[a] == p[b]) p[a]--;
    if(p[a] < p[b]) p[b] = a;
    else p[a] = b;
    return 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int idx = 0;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            edge[idx] = tie(arr[i][j], i, j);
            idx++;
        }
    }

    sort(edge, edge+idx);
    int cnt = 1;
    long long result = 0;

    for(int i=0; i<idx; i++)
    {
        int cost, a, b;
        tie(cost, a, b) = edge[i];

        if(!is_diff_group(a, b)) continue;

        result += cost;
        cnt += 1;

        if(cnt == n) break;
    }

    cout << result << '\n';

    return 0;
}