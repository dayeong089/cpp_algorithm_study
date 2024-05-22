#include <iostream>

using namespace std;

int t, n;
int arr[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    while(t--)
    {
        cin >> n;
        for(int i=0; i<n; i++) cin >> arr[i];
        long long profit = 0;
        int now_max = arr[n-1];
        for(int i=n-2; i>=0; i--)
        {
            if(arr[i] < now_max) profit += (now_max - arr[i]);
            else now_max = arr[i];
        }
        cout << profit << '\n';
    }

    return 0;
}