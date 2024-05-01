#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    for(int i=0; i<discount.size()-9; i++)
    {
        bool check = true;
        for(int j=0; j<want.size(); j++)
        {
            if(count(discount.begin()+i, discount.begin()+i+10, want[j]) < number[j])
            {
                check = false;
                break;
            }
        }
        if(check) answer++;
    }
    return answer;
}