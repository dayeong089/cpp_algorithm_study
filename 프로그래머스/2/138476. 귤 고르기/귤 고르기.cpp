#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10000001];

int solution(int k, vector<int> tangerine) {
    vector<int> cnt;
    
    for(int i=0; i<10000001; i++) arr[i] = 0;
    for(int i=0; i<tangerine.size(); i++)
    {
        arr[tangerine[i]]++;
    }
    for(int i=0; i<10000001; i++) 
    {
        if(arr[i]) cnt.push_back(arr[i]);
    }
    
    sort(cnt.begin(), cnt.end(), greater<int>());
    
    int idx = 0;
    while(k > 0)
    {
        k -= cnt[idx];
        idx++;
    }
    return idx;
}