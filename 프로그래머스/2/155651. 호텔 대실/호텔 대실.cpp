#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<string> &v1, vector<string> &v2)
{
    return v1[1] < v2[1];
}

bool cmp2(pair<int, int> &p1, pair<int, int> &p2)
{
    if(p1.first == p2.first) return p1.second > p2.second;
    else return p1.first > p2.first;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<pair<int, int>> end_time;
    sort(book_time.begin(), book_time.end(), cmp);
    for(int i=0; i<book_time.size(); i++)
    {
        int s_h = stoi(book_time[i][0].substr(0, 2));
        int s_m = stoi(book_time[i][0].substr(3, 2));
        int e_h = stoi(book_time[i][1].substr(0, 2));
        int e_m = stoi(book_time[i][1].substr(3, 2));
        int next_h = e_h + ((e_m+10) / 60);
        int next_m = (e_m+10) % 60;
        
        if(end_time.size() == 0) end_time.push_back({next_h, next_m});
        else
        {
            bool check = false;
            for(int j=0; j<end_time.size(); j++)
            {
                if(end_time[j].first < s_h) check = true;
                else if(end_time[j].first == s_h && end_time[j].second <= s_m) check = true;

                if(check) 
                {
                    end_time[j] = {next_h, next_m};
                    break;
                }
            }
            if(!check) end_time.push_back({next_h, next_m});
        } 
        sort(end_time.begin(), end_time.end(), cmp2);
    }
    
    return end_time.size();
}