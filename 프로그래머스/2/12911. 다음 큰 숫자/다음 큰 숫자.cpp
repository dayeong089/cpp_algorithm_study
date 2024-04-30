#include <string>
#include <vector>
#include <climits>

using namespace std;

int count_one(int x)
{
    int cnt = 0;
    while(x > 0)
    {
        if(x % 2 == 1) cnt++;
        x /= 2;
    }
    return cnt;
}

int solution(int n) {
    int n_one = count_one(n), new_one;
    for(int i=n+1; i<INT_MAX; i++)
    {
        new_one = count_one(i);
        if(n_one == new_one) return i;
    }
}




// 처음 풀이
// #include <string>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// #include <regex>

// using namespace std;

// int solution(int n) {
//     string s = "";
//     string news = "";
//     string regexs = "";
    
//     while(n > 0)
//     {
//         s += to_string(n % 2);
//         n /= 2;
//     }
//     reverse(s.begin(), s.end());
    
//     int idx = s.find("01");
//     if(idx == -1) 
//     {
//         s = "0" + s;
//         idx = 0;
//     }
//     news += s.substr(0, idx);
//     news += "10";
//     regexs = s.substr(idx+2, s.size()-idx-2);    
//     while(regex_search(regexs, regex("10")))
//     {
//         regexs = regex_replace(regexs, regex("10"), "01");
//     }
//     news += regexs;
//     reverse(news.begin(), news.end());
    
//     int mul = 1, answer = 0;
//     for(int i=0; i<news.size(); i++)
//     {
//         answer += ((news[i]-'0') * mul);
//         mul *= 2;
//     }
    
//     return answer;
// }