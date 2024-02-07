#include<bits/stdc++.h>
using namespace std;

int n;
int arr[1000001];
vector<int> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        v.push_back(arr[i]);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i=0; i<n; i++)
    {
        cout << lower_bound(v.begin(), v.end(), arr[i]) - v.begin() << ' ';
    }

    return 0;
}