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
                if(!s.empty())
                {
                    if(num == 1)
                    {
                        auto it = s.end();
                        it--;
                        s.erase(s.find(*it));
                    }
                    else
                    {
                        auto it = s.begin();
                        s.erase(s.find(*it));
                    }
                }
            }
        }

        if(s.empty()) cout << "EMPTY" << '\n';
        else{
            auto it = s.end();
            it--;
            auto it2 = s.begin();
            cout << *it << ' ' << *it2 << '\n';
        }
    }

    return 0;
}