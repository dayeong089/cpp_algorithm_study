#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string op;
    cin >> n;

    queue<int> q;

    while(n--)
    {
        cin >> op;
        if(op == "push")
        {
            int x;
            cin >> x;
            q.push(x);
        }
        else if(op == "pop")
        {
            if(!q.empty()){
                cout << q.front() << '\n';
                q.pop();
            }
            else cout << "-1" << '\n';
        }
        else if(op == "size")
        {
            cout << q.size() << '\n';
        }
        else if(op == "empty")
        {
            cout << (int)q.empty() << '\n';
        }
        else if(op == "front")
        {
            if(!q.empty()) cout << q.front() << '\n';
            else cout << "-1" << '\n';
        }
        else
        {
            if(!q.empty()) cout << q.back() << '\n';
            else cout << "-1" << '\n';
        }
    }

    return 0;
}