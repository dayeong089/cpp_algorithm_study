#include<iostream>
using namespace std;

#include<vector>
#include<string>

int main()
{
    vector<vector<char>> v(5, vector<char>(15, ' '));
    int max_len = 0;

    for(int i=0; i<5; i++)
    {
        string str;
        cin >> str;

        if(str.length() > max_len) max_len = str.length();

        for(int j=0; j<str.length(); j++)
        {
            v[i][j] = str[j];
        }
    }

    string result = "";
    for(int i=0; i<max_len; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(v[j][i] != ' ')
            {
                result += v[j][i];
            }
        }
    }

    cout << result << endl;
    return 0;
}