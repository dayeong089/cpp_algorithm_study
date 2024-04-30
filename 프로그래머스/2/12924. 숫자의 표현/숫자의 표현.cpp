#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    for(int i=1; i<n; i++)
    {
        int num = 0;
        int prev = i;
        while(num < n)
        {
            num += prev;
            prev++;
        }
        if(num == n) answer++;
    }
    return answer;
}