#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    stack<int> s;

    for(auto c : str)
    {
        if(c == '(') s.push(-1);
        else if(c == '[') s.push(-2);
        else if(c == ')')
        {
            int val = 0;
            while(true)
            {
                if(s.empty() || s.top()==-2)
                {
                    cout << '0' << '\n';
                    return 0;
                }
                else
                {
                    if(s.top() == -1)
                    {
                        s.pop();
                        if(!val) s.push(2);
                        else s.push(val*2);
                        break;
                    }
                    else
                    {
                        val += s.top();
                        s.pop();
                    }
                }
            }
        }
        else if(c == ']')
        {
            int val = 0;
            while(true)
            {
                if(s.empty() || s.top()==-1)
                {
                    cout << '0' << '\n';
                    return 0;
                }
                else
                {
                    if(s.top() == -2)
                    {
                        s.pop();
                        if(!val) s.push(3);
                        else s.push(val*3);
                        break;
                    }
                    else
                    {
                        val += s.top();
                        s.pop();
                    }
                }
            }
        }
    }

    int result = 0;
    while(!s.empty())
    {
        if(s.top() < 0)
        {
            cout << '0' << '\n';
            return 0;
        }
        result += s.top();
        s.pop();
    }

    cout << result << '\n';

    return 0;
}