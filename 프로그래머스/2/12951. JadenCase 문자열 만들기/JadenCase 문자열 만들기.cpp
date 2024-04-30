#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool first = true;
    for(char& c : s)
    {
        if(first)
        {
            if(c >= 'a' && c <= 'z') c = c - 'a' + 'A';
            if(c != ' ') first = false;
        }
        else if(c == ' ') first = true;
        else if(c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
    }
    
    return s;
}