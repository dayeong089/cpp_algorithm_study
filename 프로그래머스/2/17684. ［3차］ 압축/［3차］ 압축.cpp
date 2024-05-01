#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> dict;
    
    for(char c='A'; c<='Z'; c++)
    {
        dict[string(1, c)] = c-'A'+1;
    }
        
    int idx = 0;
    int cnt = 26;
    while(idx < msg.size())
    {
        int now_len = 1;
        while(idx + now_len <= msg.size())
        {
            if(dict.find(msg.substr(idx, now_len)) == dict.end()) break;
            now_len++;
        }
        answer.push_back(dict[msg.substr(idx, now_len-1)]);
        if(idx+now_len <= msg.size()) dict[msg.substr(idx, now_len)] = ++cnt;
        idx += (now_len-1);
    }
    
    return answer;
}