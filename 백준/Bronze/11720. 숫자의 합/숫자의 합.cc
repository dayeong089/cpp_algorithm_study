#include<iostream>

using namespace std;

int main()
{
    int n, result=0;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        char m;
        cin >> m;
        result += (int(m)-48);
    }

    cout << result << endl;
    return 0;
}