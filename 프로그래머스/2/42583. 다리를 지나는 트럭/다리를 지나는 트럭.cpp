#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, now_weight = 0, idx = 0, time = 0;
    
    queue<pair<int, int>> q;
    
    while(true)
    {
        if(time && q.empty()) break;
        if(!q.empty())
        {
            if(q.front().second + bridge_length == time) 
            {
                now_weight -= q.front().first;
                q.pop();
            }
        }
        if(idx < truck_weights.size() && now_weight + truck_weights[idx] <= weight)
        {
            q.push({truck_weights[idx], time});
            now_weight += truck_weights[idx];
            idx++;
        }
        time++;
    }
    
    return time;
}