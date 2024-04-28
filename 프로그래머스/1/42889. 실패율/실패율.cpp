#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
pair<double, int> fail[501];
vector<int> failp(501, 0);

bool cmp(pair<double, int>& p1, pair<double, int>& p2)
{
    if(p1.first == p2.first) return p1.second < p2.second;
    else return p1.first > p2.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    for(int i=0; i<N; i++)
    {
        fail[i].first = 0;
        fail[i].second = i+1;
    }
    
    for(int i=0; i<stages.size(); i++)
    {
        failp[stages[i]-1]++;
        for(int j=0; j<stages[i]; j++)
        {
            fail[j].first++;
        }
    }
    
    for(int i=0; i<N; i++) 
    {
        if(fail[i].first != 0) fail[i].first = failp[i] / fail[i].first;
    }
    sort(fail, fail+N, cmp);
    for(int i=0; i<N; i++) answer.push_back(fail[i].second);
    
    return answer;
}