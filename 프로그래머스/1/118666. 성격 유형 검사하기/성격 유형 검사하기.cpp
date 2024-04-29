#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    unordered_map<char, int> score;
    score['R'] = 0;
    score['T'] = 0;
    score['C'] = 0;
    score['F'] = 0;
    score['J'] = 0;
    score['M'] = 0;
    score['A'] = 0;
    score['N'] = 0;
    
    for(int i=0; i<choices.size(); i++)
    {
        if(choices[i] == 4) continue;
        if(choices[i] <= 3) score[survey[i][0]] += (4-choices[i]);
        else score[survey[i][1]] += (choices[i]-4);
    }
        
    string answer = "";
    if(score['R'] >= score['T']) answer += "R";
    else answer += "T";
    if(score['C'] >= score['F']) answer += "C";
    else answer += "F";
    if(score['J'] >= score['M']) answer += "J";
    else answer += "M";
    if(score['A'] >= score['N']) answer += "A";
    else answer += "N";
    
    return answer;
}