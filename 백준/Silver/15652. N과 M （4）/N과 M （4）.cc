#include <iostream>

using namespace std;

int n, m;
int arr[10];

void func(int x)
{
    if(x == m)
    {
        for(int i=0; i<m; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    int st = 1;
    if(x != 0) st = arr[x-1];

    for(int i=st; i<=n; i++)
    {
        arr[x] = i;
        func(x+1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0);
    return 0;
}