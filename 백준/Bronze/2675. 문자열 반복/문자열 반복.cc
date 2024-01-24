#include<iostream>
#include<string>
using namespace std;

int main()
{
    int num;
    cin >> num;

    for(int i=0; i<num; i++){
        int cnt;
        string str, result = "";
        cin >> cnt >> str;

        for(int j=0; j<str.length(); j++)
        {
            string x(cnt, str[j]);
            result += x;
        }

        cout << result << endl;
    }

    return 0;
}