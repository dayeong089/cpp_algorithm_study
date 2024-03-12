#include<iostream>
#include<cstdio>
#include<algorithm>
#include<tuple>
#include<vector>

using namespace std;

int n, m;
tuple<int, int, int> edge[1000005];
vector<int> p(100005, -1);

int find(int a)
{
    if(p[a] < 0) return a;
    return p[a] = find(p[a]);
}

int is_diff_group(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a==b) return 0;
    if(p[a] == p[b]) p[a]--;
    if(p[a] < p[b]) p[b] = a;
    else p[a] = b;
    return 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = tie(cost, a, b);
    }

    sort(edge, edge+m);
    int cnt = 1;
    int result = 0;
    int max_cost = 0;

    for(int i=0; i<m; i++)
    {
        int a, b, cost;
        tie(cost, a, b) = edge[i];

        if(!is_diff_group(a, b)) continue;

        cnt++;
        result += cost;
        if(cost > max_cost) max_cost = cost;

        if(cnt == n) break;
    }

    cout << result - max_cost << '\n';
    return 0;
}