#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int num[10];
int arr[10];
bool visited[10];

void func(int k)
{
    if(k == m)
    {
        for(int i=0; i<m; i++) cout << num[arr[i]] << ' ';
        cout << '\n';
        return;
    }

    int tmp = 0;
    int start = 0;
    if(k != 0) start = arr[k-1]+1;
    for(int i=start; i<n; i++)
    {
        if(visited[i] || tmp == num[i]) continue;
        arr[k] = i;
        tmp = num[i];
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
    return 0;
}