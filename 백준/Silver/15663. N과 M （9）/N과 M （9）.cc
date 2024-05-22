#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int n, m;
int num[10];
int arr[10];
bool visited[10];
set<vector<int>> s;

void func(int k)
{
    if(k == m)
    {
        vector<int> now;
        for(int i=0; i<m; i++) now.push_back(arr[i]);
        s.insert(now);
        return;
    }

    for(int i=0; i<n; i++)
    {
        if(visited[i]) continue;
        arr[k] = num[i];
        visited[i] = true;
        func(k+1);
        visited[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> num[i];
    sort(num, num+n);
    func(0);
    for(auto v : s)
    {
        for(auto x : v) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}