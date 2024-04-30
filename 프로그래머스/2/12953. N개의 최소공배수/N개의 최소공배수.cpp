#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int solution(vector<int> arr) {
    sort(arr.begin(), arr.end(), greater<int>());
    int prev_lcm = arr[0], now_lcm;
    
    for(int i=1; i<arr.size(); i++)
    {
        now_lcm = lcm(prev_lcm, arr[i]);
        prev_lcm = now_lcm;
    }
    
    return now_lcm;
}