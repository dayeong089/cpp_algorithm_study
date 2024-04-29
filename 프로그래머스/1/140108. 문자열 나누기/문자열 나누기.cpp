#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    char first = 'N';
    int same_cnt = 0, diff_cnt = 0;
    for (char c : s)
    {
        if(first == 'N')
        {
            first = c;
            same_cnt++;
        }
        else
        {
            if(c == first) same_cnt++;
            else diff_cnt++;
            if(same_cnt == diff_cnt)
            {
                first = 'N';
                same_cnt = 0;
                diff_cnt = 0;
                answer++;
            }
        }
    }
    if(first != 'N') answer++;
    return answer;
}