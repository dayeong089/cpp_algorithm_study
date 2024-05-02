#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> s;
    int now = 1;
    
    for(int i=0; i<order.size(); i++)
    {
        while(now < order[i])
        {
            s.push(now++);
        }
        if(now == order[i])
        {
            answer++;
            now++;
        }
        else
        {
            if(s.empty()) break;
            if(s.top() != order[i]) break;
            s.pop();
            answer++;
        }
    }
    
    return answer;
}