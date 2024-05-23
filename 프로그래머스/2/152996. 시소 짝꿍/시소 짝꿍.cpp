#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
unordered_map<int, long long> umap;

long long solution(vector<int> weights) {
    long long answer = 0;
    sort(weights.begin(), weights.end());
    for(int i=0; i<weights.size(); i++) umap[weights[i]] += 1;
    weights.erase(unique(weights.begin(), weights.end()), weights.end());
    
    for(int i=0; i<weights.size(); i++)
    {
        int now = weights[i];
        if(umap[now] >= 2) answer += (umap[now] * (umap[now]-1) / 2);
        if(umap.find(now*2) != umap.end()) answer += (umap[now] * umap[now*2]);
        if(now % 2 == 0 && umap.find(now*1.5) != umap.end()) answer += (umap[now] * umap[now*1.5]);
        if(now % 3 == 0 && umap.find(now/3*4) != umap.end()) answer += (umap[now] * umap[now/3*4]);
    }
    
    return answer;
}