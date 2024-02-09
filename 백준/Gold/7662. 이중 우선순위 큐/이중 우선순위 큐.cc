#include<bits/stdc++.h>
using namespace std;

int t;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--)
    {
        int k;
        cin >> k;
        multiset<int> s;
        while(k--)
        {
            char op;
            int num;
            cin >> op >> num;

            if(op == 'I') s.insert(num);
            else
            {
                if(s.empty()) continue;
                if(num == 1) s.erase(prev(s.end()));
                else s.erase(s.begin());
            }
        }

        if(s.empty()) cout << "EMPTY" << '\n';
        else cout << *(prev(s.end())) << ' ' << *(s.begin()) << '\n';
    }

    return 0;
}