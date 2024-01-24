#include<iostream>

using namespace std;

#include<string>

int main()
{
    string croatia[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    string str;
    cin >> str;

    for(int i=0; i<8; i++)
    {
        while(1)
        {
            int idx = str.find(croatia[i]);
            if(idx == std::string::npos) break;
            str.replace(idx, croatia[i].length(), "*");
        }
    }

    cout << str.length() << endl;
    
    return 0;
}