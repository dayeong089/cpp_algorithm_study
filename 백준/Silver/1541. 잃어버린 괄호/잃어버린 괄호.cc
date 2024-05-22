#include <iostream>
#include <string>

using namespace std;

string str, now_num = "";
int answer = 0, pm = 1;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> str;

    for(auto s : str)
    {
        if(s == '+' || s == '-')
        {
            answer += (stoi(now_num) * pm);
            now_num = "";
            if(s == '-') pm = -1;
        }
        else now_num += s;
    }
    
    answer += (stoi(now_num) * pm);
    cout << answer << '\n';
    return 0;
}