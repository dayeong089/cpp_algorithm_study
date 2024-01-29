#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string op;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    stack<int> stack;

    while(n--)
    {
        cin >> op;
        if(op == "push")
        {
            int x;
            cin >> x;
            stack.push(x);
        }
        else if(op == "pop")
        {
            if(!stack.empty()){
                cout << stack.top() << '\n';
                stack.pop();
            }
            else cout << "-1" << '\n';
        }
        else if(op == "top")
        {
            if(!stack.empty()) cout << stack.top() << '\n';
            else cout << "-1" << '\n';
        }
        else if(op == "size")
        {
            cout << stack.size() << '\n';
        }
        else{
            if(stack.empty()) cout << '1' << '\n';
            else cout << '0' << '\n';
        }
    }

    return 0;
}