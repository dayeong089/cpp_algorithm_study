#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    for(char c : s)
    {
        int idx = index;
        while(true)
        {
            if(idx == 0) break;
            c++;
            if(c > 'z') c = c-'z'+'a'-1;
            if(skip.find(c) == std::string::npos) idx--;
        }
        answer += c;
    }
    return answer;
}