#include<iostream>
using namespace std;
#include<vector>
#include<cmath>

void hanoi(int n, int x, int y, int z)
{
    if(n==1)
    {
        cout << x << " " << y << '\n';
        return;
    }

    hanoi(n-1, x, z, y);
    cout << x << " " << y << '\n';
    hanoi(n-1, z, y, x);
}


int main()
{
    int n;
    cin >> n;
    int num = pow(2, n)-1;
    cout << num << '\n';
    hanoi(n, 1, 3, 2);

    return 0;
}