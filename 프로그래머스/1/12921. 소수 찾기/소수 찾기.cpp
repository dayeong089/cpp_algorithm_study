#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<bool> num(n+1, true);
    num[1] = false;
    for(int i=2; i*i<=n; i++)
    {
        if(!num[i]) continue;
        for(int j=i*i; j<=n; j+=i) num[j] = false;
    }
    int answer = 0;
    for(int i=2; i<=n; i++) if(num[i]) answer++;
    return answer;
}