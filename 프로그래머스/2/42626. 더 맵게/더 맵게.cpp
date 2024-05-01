#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    int answer = 0;
    
    for(int i : scoville) pq.push(i);
    while(pq.top() < K)
    {
        if(pq.size() == 1) return -1;
        long long x = pq.top(); pq.pop();
        long long y = pq.top(); pq.pop();
        pq.push(x + y*2);
        answer++;
    }
  
    return answer;
}