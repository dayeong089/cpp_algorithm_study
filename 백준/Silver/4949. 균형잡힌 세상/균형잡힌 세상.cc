#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    getline(cin, str);

    while(str != ".")
    {
        stack<char> s;
        int check = 1;
        for(auto c : str)
        {
            if(c == '(' || c == '[')
            {
                s.push(c);
            }
            else if(c == ')')
            {
                if(!s.empty() && s.top() == '(')
                {
                    s.pop();
                }
                else
                {
                    check = 0;
                    break;
                }
            }
            else if(c == ']')
            {
                if(!s.empty() && s.top() == '[')
                {
                    s.pop();
                }
                else
                {
                    check = 0;
                    break;
                }
            }
        }
        if(check && s.empty())
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
        getline(cin, str);
    }

    return 0;
}