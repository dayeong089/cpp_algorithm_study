#include<iostream>
#include<cstdio>
#include<tuple>
#include<algorithm>
#include<vector>

using namespace std;
int v, e;
tuple<int, int, int> edge[100005];
vector<int> p(10005, -1);

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

    cin >> v >> e;

    for(int i=0; i<e; i++)
    {
        int x, y, weight;
        cin >> x >> y >> weight;
        edge[i] = {weight, x, y};
    }

    sort(edge, edge+e);

    int cnt = 1;
    int result = 0;

    for(int i=0; i<e; i++)
    {
        int weight, x, y;
        tie(weight, x, y) = edge[i];

        if(!is_diff_group(x, y)) continue;

        result += weight;
        cnt++;
        
        if(cnt == v) break;
    }

    cout << result << '\n';

    return 0;
}