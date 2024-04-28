#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    int idx = 0;
    while(true)
    {
        if(idx == completion.size()) return participant[idx];
        if(participant[idx] == completion[idx]) idx++;
        else return participant[idx];
    }
}