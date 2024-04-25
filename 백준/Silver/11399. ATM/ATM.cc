#include<iostream>
#include<algorithm>

using namespace std;

int n, total_time = 0;
int dur_time[1001];
int wait_time[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) cin >> dur_time[i];
    sort(dur_time, dur_time+n);

    wait_time[0] = dur_time[0];
    for(int i=1; i<n; i++)
    {
        wait_time[i] = wait_time[i-1] + dur_time[i]; 
    }

    for(int i=0; i<n; i++) total_time += wait_time[i];

    cout << total_time << '\n';
    return 0;
}