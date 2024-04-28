#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int unknown = 0;
    int same = 0;
    int min_rank, max_rank;
    
    for(int i=0; i<6; i++)
    {
        if(lottos[i] == 0)
        {
            unknown++;
            continue;
        }
        for(int j=0; j<6; j++)
        {
            if(lottos[i] == win_nums[j]) same++;
        } 
    }
    
    min_rank = 7-(same+unknown);
    max_rank = 7-(same);
    if(min_rank >= 6) min_rank = 6;
    if(max_rank >= 6) max_rank = 6;
    
    answer.push_back(min_rank);
    answer.push_back(max_rank);
    return answer;
}