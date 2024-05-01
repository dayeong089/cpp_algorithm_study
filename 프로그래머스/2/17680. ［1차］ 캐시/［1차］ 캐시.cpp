#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0, time = 0;;
    vector<string> cache;
    unordered_map<string, int> recent;
    
    if(cacheSize == 0) return cities.size() * 5;
    
    for(int i=0; i<cities.size(); i++)
    {
        string now_city = "";
        for(int j=0; j<cities[i].size(); j++) now_city += tolower(cities[i][j]);
        recent[now_city] = time;
        if(find(cache.begin(), cache.end(), now_city) == cache.end())
        {
            if(cache.size() >= cacheSize) 
            {
                int min_recent = 0;
                for(int j=1; j<cache.size(); j++)
                {
                    if(recent[cache[j]] < recent[cache[min_recent]]) min_recent = j;
                }
                cache.erase(cache.begin() + min_recent);
            }
            cache.push_back(now_city);
            answer += 5;
        }
        else answer += 1;
        time++;
    }
    return answer;
}