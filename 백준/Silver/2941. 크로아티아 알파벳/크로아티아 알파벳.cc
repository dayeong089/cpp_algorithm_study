#include<iostream>
using namespace std;

#include<string>

int main()
{
    string str;
    cin >> str;
    int cnt=0, i=0;

    while(i < str.length())
    {
        cnt++;
        if(i+2 < str.length() && str[i] == 'd' && str[i+1] == 'z' && str[i+2] == '=') { i+=3; }
        else if(i+1 < str.length())
        {
            if(str[i] == 'c' && (str[i+1] == '=' || str[i+1] == '-')){ i+=2; }
            else if(str[i] == 'd' && str[i+1] == '-') { i+=2; }
            else if(str[i] == 'l' && str[i+1] == 'j') { i+=2; }
            else if(str[i] == 'n' && str[i+1] == 'j') { i+=2; }
            else if(str[i] == 's' && str[i+1] == '=') { i+=2; }
            else if(str[i] == 'z' && str[i+1] == '=') { i+=2; }
            else { i+=1; }
        }
        else{ i+=1; }
    }

    cout << cnt << endl;

    return 0;
}