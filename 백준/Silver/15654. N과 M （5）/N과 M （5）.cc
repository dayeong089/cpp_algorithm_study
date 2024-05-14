#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
int num[10];
int arr[10];
bool visited[10];

void func(int x)
{
    if(x == m)
    {
        for(int i=0; i<m; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i=0; i<n; i++)
    {
        if(visited[i]) continue;
        arr[x] = num[i];
        visited[i] = true;
        func(x+1);
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