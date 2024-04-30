#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int i;
    sort(citations.rbegin(), citations.rend());
    
    for(i=citations[0]; i>=0; i--)
    {
        int cnt = 0;
        for(int j=0; j<citations.size(); j++)
        {
            if(citations[j] >= i) cnt++;
            else break;
        }
        if(cnt >= i) break;
    }
    
    return i;
}