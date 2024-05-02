#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    sort(dungeons.begin(), dungeons.end());
    
    do
    {
        int energy = k;
        int cnt = 0;
        for(int i=0; i<dungeons.size(); i++)
        {
            if(dungeons[i][0] > energy) continue;
            energy -= dungeons[i][1];
            cnt++;
        }
        answer = max(answer, cnt);
    }while(next_permutation(dungeons.begin(), dungeons.end()));
    
    return answer;
}