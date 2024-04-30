#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    int count_remove = count(s.begin(), s.end(), '0');
    int num = s.size() - count_remove;
    int count_change = 1;
    
    while(true)
    {
        if(num == 1) break;
        
        int count_zero = 0;
        int count_one = 0;
        
        while(num > 0)
        {
            if(num % 2 == 0) count_zero++;
            else count_one++;
            num /= 2;
        }
                
        count_change++;
        count_remove += count_zero;
        num = count_one;
    }
    
    return {count_change, count_remove};
}