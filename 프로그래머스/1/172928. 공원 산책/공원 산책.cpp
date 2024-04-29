#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    unordered_map<char, pair<int, int>> umap;
    int nowx = 0, nowy = 0, dist, dirx, diry, movx, movy;
    char dir;
    
    umap['E'] = {0, 1};
    umap['W'] = {0, -1};
    umap['S'] = {1, 0};
    umap['N'] = {-1, 0};
    
    for(int i=0; i<park.size(); i++)
    {
        if(park[i].find('S') == std::string::npos) continue;
        nowx = i;
        nowy = park[i].find('S');
    }
    
    cout << nowx << ' ' << nowy << '\n';
    
    for(int i=0; i<routes.size(); i++)
    {
        dir = routes[i][0];
        dist = routes[i][2] - '0';
        
        dirx = umap[dir].first;
        diry = umap[dir].second;
        movx = nowx;
        movy = nowy;
        bool move = true;
        
        while(dist > 0)
        {
            movx += dirx;
            movy += diry;
            if(movx < 0 || movx >= park.size() || movy < 0 || movy >= park[0].size()) 
            {
                move = false;
                break;
            }
            if(park[movx][movy] == 'X')
            {
                move = false;
                break;
            }
            dist--;
        }
        
        if(move)
        {
            nowx = movx;
            nowy = movy;
        }
    }
    answer.push_back(nowx);
    answer.push_back(nowy);
    return answer;
}