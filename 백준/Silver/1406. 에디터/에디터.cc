#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    list<char> li;
    list<char>::iterator it;

    for(char c : str) li.push_back(c);
    it = li.end();

    int m;
    cin >> m;

    for(int i=0; i<m; i++)
    {
        char op;
        cin >> op;
        if(op == 'L')
        {
            if(it != li.begin()) it--;
        }
        else if(op == 'D')
        {
            if(it != li.end()) it++;
        }
        else if(op == 'B')
        {
            if(it != li.begin())
            {
                it--;
                it = li.erase(it);
            }
        }
        else if(op == 'P')
        {
            char c;
            cin >> c;
            li.insert(it, c);
        }
    }

    for(auto c : li) cout << c;

    return 0;
}