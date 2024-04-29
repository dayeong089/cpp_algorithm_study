#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string, int> getReport;
    unordered_map<string, vector<string>> doReport;
    
    for(int i=0; i<id_list.size(); i++) getReport[id_list[i]] = 0;
    
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    
    for(int i=0; i<report.size(); i++)
    {
        string s1, s2;
        stringstream ss(report[i]);
        ss >> s1 >> s2;
        getReport[s2]++;
        doReport[s1].push_back(s2);
    }
    
    for(int i=0; i<id_list.size(); i++)
    {
        int cnt = 0;
        for(int j=0; j<doReport[id_list[i]].size(); j++)
        {
            if(getReport[doReport[id_list[i]][j]] >= k) cnt++;
        }
        answer.push_back(cnt);
    }
    
    return answer;
}