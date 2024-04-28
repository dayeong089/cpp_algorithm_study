// #include <string>
// #include <vector>
// #include <algorithm>

// using namespace std;

// string solution(vector<string> participant, vector<string> completion) {
//     sort(participant.begin(), participant.end());
//     sort(completion.begin(), completion.end());
    
//     int i = 0;
//     for(; i<completion.size(); i++)
//     {
//         if(participant[i] != completion[i]) return participant[i];
//     }
    
//     return participant[i];
// }


#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> hmap;
    
    for(auto ele : completion)
    {
        if(hmap.find(ele) == hmap.end()) hmap.insert({ele, 1});
        else hmap[ele]++;
    }
    
    for(auto ele : participant)
    {
        if(hmap.find(ele) == hmap.end()) return ele;
        else 
        {
            hmap[ele]--;
            if(hmap[ele] < 0) return ele;
        }
    }
}