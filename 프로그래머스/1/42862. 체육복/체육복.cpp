#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    int more[31];
    int need[31];
    
    sort(lost.begin(), lost.end());
    
    for(int i=0; i<=n; i++) more[i] = 0;
    for(int i=0; i<reserve.size(); i++) more[reserve[i]]++;
    
    // 도난 + 여벌
    for(int i=0; i<lost.size(); i++)
    {
        if(more[lost[i]])
        {
            more[lost[i]] = 0;
            lost.erase(lost.begin()+i);
            i--;
        }
    }
    
    cout << more[4] << ' ' << lost.size() << ' ';
    for(int i=0; i<lost.size(); i++) cout << lost[i] << ' ';
    
    // 도난 + 여벌x
    for(int i=0; i<lost.size(); i++)
    {
        if(lost[i]-1 > 0 && more[lost[i]-1]) more[lost[i]-1] = 0;
        else if(lost[i]+1 <= n && more[lost[i]+1]) more[lost[i]+1] = 0;
        else answer--;
    }
        
    return answer;
}