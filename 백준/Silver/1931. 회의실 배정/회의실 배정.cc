#include<bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> v;

bool cmp(const pair<int, int> &v1, const pair<int, int> &v2)
{
    if(v1.second != v2.second) return v1.second < v2.second;
    return v1.first < v2.first;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    v.resize(n);

    for(int i=0; i<n; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), cmp);

    int now_time = v[0].second;
    int cnt = 1;

    for(int i=1; i<v.size(); i++)
    {
        if(v[i].first >= now_time)
        {
            now_time = v[i].second;
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}