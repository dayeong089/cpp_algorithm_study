#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while(storey > 0)
    {
        int now = storey % 10;
        int choose = 0;
        if(now == 5 && storey % 100 >= 50) choose = 1;
        if(now > 5 || choose)
        {
            answer += (10 - now);
            storey += (10 - now);
        }
        else answer += now;
        storey /= 10;
    }
    
    return answer;
}