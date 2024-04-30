#include<iostream>
#include<vector>

using namespace std;

int n;
int arr[4000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // initalize
    cin >> n;
    for(int i=2; i<=n; i++) arr[i] = 1;

    // check prime
    for(int i=2; i*i<=n; i++)
    {
        if(!arr[i]) continue;
        for(int j=i*i; j<=n; j+=i)
        {
            arr[j] = 0;
        }
    }
    vector<int> prime;
    for(int i=2; i<=n; i++)
    {
        if(arr[i]) prime.push_back(i);
    }

    // check sum
    int idx1 = 0, idx2 = 0, now_sum = 0;
    int answer = 0;
    for(; idx1<prime.size(); idx1++)
    {
        while(idx2<prime.size() && now_sum<n)
        {
            now_sum += prime[idx2];
            idx2++;
        }
        if(now_sum == n) answer++;
        now_sum -= prime[idx1];
    }

    cout << answer << '\n';

    return 0;
}