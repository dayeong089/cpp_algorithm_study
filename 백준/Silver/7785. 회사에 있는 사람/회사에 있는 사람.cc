#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
    map<string, string, greater<>> m;
    cin >> n;

    while(n--)
    {
        string name, status;
        cin >> name >> status;
        m[name] = status;
    }
    
    for(auto x : m)
    {
        if(x.second == "enter")
        {
            cout << x.first << '\n';
        }
    }
    
    return 0;
}