#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i=0; i<skill_trees.size(); i++)
    {
        int order = 0;
        bool check = true;
        for(int j=0; j<skill_trees[i].size(); j++)
        {
            if(skill.find(skill_trees[i][j]) != std::string::npos)
            {
                int now_order = find(skill.begin(), skill.end(), skill_trees[i][j]) - skill.begin();
                if(now_order > order) 
                {
                    check = false;
                    break;
                }
                else order++;
            }
        }
        if(check) answer++;
    }
    return answer;
}