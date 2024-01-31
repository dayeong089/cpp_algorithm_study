#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    
    stack<char> s;
    int num = 0;
    char before = ' ';

    for(auto c : str)
    {
        if(c == '(') s.push(c);
        else
        {
            s.pop();
            if(before == '(')
            {
                num += s.size();
            }
            else
            {
                num += 1;
            }
        }
        
        before = c;
    }

    cout << num << '\n';

    return 0;
}