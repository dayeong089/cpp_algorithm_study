#include <iostream>

using namespace std;
int n, m;
int arr[10];
bool isvisit[10];

void func(int x)
{
    if(x == m)
    {
        for(int i=0; i<m; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i=1; i<=n; i++)
    {
        if(isvisit[i]) continue;
        arr[x] = i;
        isvisit[i] = true;
        func(x+1);
        isvisit[i] = false;
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