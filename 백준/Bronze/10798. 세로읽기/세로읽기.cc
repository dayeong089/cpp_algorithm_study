#include<iostream>
using namespace std;

#include<vector>
#include<string>

int main()
{
    vector<string> v;
    int max_len = 0;
    string str;

    for(int i=0; i<5; i++)
    {
        cin >> str;
        if(str.length() > max_len) max_len = str.length();
        v.push_back(str);
    }

    string result = "";
    for(int i=0; i<max_len; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(v[j].length() > i)
            {
                result += v[j][i];
            }
        }
    }

    cout << result << endl; 
    return 0;
}