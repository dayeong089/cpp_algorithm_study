#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str;
vector<int> num;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> str;
    
    string now_num = "";
    bool minus = false;
    for(auto s : str)
    {
        if(s == '+' || s == '-')
        {
            if(minus) num.push_back(-stoi(now_num));
            else num.push_back(stoi(now_num));
            now_num = "";
            if(s == '-' && !minus) minus = true;
        }
        else now_num += s;
    }
    if(minus) num.push_back(-stoi(now_num));
    else num.push_back(stoi(now_num));

    int answer = 0;
    for(auto x : num) answer += x;
    cout << answer << '\n';
    return 0;
}