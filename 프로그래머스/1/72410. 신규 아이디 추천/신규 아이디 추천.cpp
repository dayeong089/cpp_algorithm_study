#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    for(int i=0; i<new_id.size(); i++)
    {
        if(new_id[i] >= 'A' && new_id[i] <= 'Z') answer += (new_id[i] - 'A' + 'a');
        else if(new_id[i] >= 'a' && new_id[i] <= 'z') answer += new_id[i];
        else if(new_id[i] >= '0' && new_id[i] <= '9') answer += new_id[i];
        else if(new_id[i] == '-' || new_id[i] == '_') answer += new_id[i];
        else if(new_id[i] == '.' && answer == "") continue;
        else if(new_id[i] == '.' && answer.back() == '.') continue;
        else if(new_id[i] == '.') answer += new_id[i];
    }
    
    if(answer == "") answer = "a";
    if(answer.size() >= 16) answer = answer.substr(0, 15);
    if(answer.back() == '.') answer = answer.substr(0, answer.size()-1);
    if(answer.size() == 1) answer += (answer + answer);
    if(answer.size() == 2) answer += answer[answer.size()-1];
    
    return answer;
}