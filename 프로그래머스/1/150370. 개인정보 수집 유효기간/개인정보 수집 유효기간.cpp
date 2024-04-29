#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<int> nowdate;
    unordered_map<char, int> umap;
    int x, y, m, d;
    string tmp;
    char c;
    
    stringstream ss(today);
    while(getline(ss, tmp, '.'))
    {
        nowdate.push_back(stoi(tmp));
    }
    
    for(int i=0; i<terms.size(); i++)
    {
        stringstream ss(terms[i]);
        ss >> c >> x;
        umap[c] = x;
    }
    
    for(int i=0; i<privacies.size(); i++)
    {
        y = stoi(privacies[i].substr(0, 4));
        m = stoi(privacies[i].substr(5, 2));
        d = stoi(privacies[i].substr(8, 2));
        c = privacies[i].back();
        
        m += umap[c];
        if(m > 12)
        {
            y += (m/12);
            m %= 12;
        }
        if(m == 0)
        {
            y--;
            m = 12;
        }
                    
        if(y < nowdate[0]) answer.push_back(i+1);
        else if(y == nowdate[0] && m < nowdate[1]) answer.push_back(i+1);
        else if(y == nowdate[0] && m == nowdate[1] && d <= nowdate[2]) answer.push_back(i+1);
    }
    
    return answer;
}