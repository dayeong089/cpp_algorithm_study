#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int solution(int n, int k) {
    string s = "";
    while(n > 0)
    {
        s += to_string(n % k);
        n /= k;
    }
    reverse(s.begin(), s.end());
    
    stringstream ss(s);
    string str;
    int answer = 0;
    while(getline(ss, str, '0'))
    {
        if(str == "" || str == "1") continue;
        long long x = stol(str);
        
        bool check = true;
        for(long long i=2; i*i<=x; i++)
        {
            if(x % i == 0)
            {
                check = false;
                break;
            }
        }
        if(check) answer++;
    }
    
    return answer;
}