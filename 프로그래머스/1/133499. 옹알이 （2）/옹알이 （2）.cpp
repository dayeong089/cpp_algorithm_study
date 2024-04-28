#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    for (string w : babbling)
    {
        int idx = 0;
        string before = "";
        while(true)
        {
            if(w.substr(idx, 3) == "aya" && before != "aya") 
            {
                before = "aya";
                idx += 3;
            }
            else if(w.substr(idx, 2) == "ye" && before != "ye")
            {
                before = "ye";
                idx += 2;
            }
            else if(w.substr(idx, 3) == "woo" && before != "woo")
            {
                before = "woo";
                idx += 3;
            }
            else if(w.substr(idx, 2) == "ma" && before != "ma")
            {
                before = "ma";
                idx += 2;
            }
            else break;
        }
        if(idx == w.size()) answer++;
    }
    return answer;
}