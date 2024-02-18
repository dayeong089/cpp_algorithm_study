#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int indegree[32005];
    vector<int> arr[32005];

    memset(indegree, 0, n+1);

    while(m--)
    {
        int x, y;
        cin >> x >> y;

        indegree[y]++;
        arr[x].push_back(y);
    }

    queue<int> q;

    for(int i=1; i<=n; i++)
    {
        if(!indegree[i]) q.push(i);
    }

    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        cout << now << ' ';

        for(int x : arr[now])
        {
            indegree[x]--;
            if(!indegree[x]) q.push(x);
        }
    }

    return 0;
}