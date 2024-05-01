#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0, max_ele = 0, index = 0, order = 0;
    vector<int> loc(priorities.size(), 0);
    while(true)
    {
        if(order == priorities.size()) break;
        max_ele = *max_element(priorities.begin(), priorities.end());
        for(int i=0; i<priorities.size(); i++)
        {
            if(priorities[(i+index) % priorities.size()] == max_ele)
            {
                priorities[(i+index) % priorities.size()] = 0;
                loc[(i+index) % priorities.size()] = ++order;
                index = (i+index+1) % priorities.size();
                break;
            }
        }
    }
    return loc[location];
}