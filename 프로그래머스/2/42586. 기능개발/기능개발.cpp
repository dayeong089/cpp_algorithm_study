#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int idx = 0, day = 0, prev_idx = 0;
    while(idx < progresses.size())
    {
        day = ((100 - progresses[idx]) / speeds[idx]);
        if((100 - progresses[idx]) % speeds[idx] != 0) day++;
        while(idx < progresses.size())
        {
            idx++;
            if(progresses[idx] + speeds[idx] * day < 100) break;
        }
        cout << idx << ' ';
        answer.push_back(idx - prev_idx);
        prev_idx = idx;
    }
    
    return answer;
}