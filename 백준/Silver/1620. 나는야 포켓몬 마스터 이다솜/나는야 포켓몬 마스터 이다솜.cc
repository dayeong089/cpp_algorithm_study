#include<bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    unordered_map<string, int> book;
    unordered_map<int, string> book2;

    for(int i=1; i<n+1; i++)
    {
        string name;
        cin >> name;
        book[name] = i;
        book2[i] = name;
    }

    while(m--)
    {
        string now;
        cin >> now;
        if(isdigit(now[0]))
        {
            cout << book2[stoi(now)] << '\n';
        }
        else
        {
            cout << book[now] << '\n';
        }
    }

    return 0;
}