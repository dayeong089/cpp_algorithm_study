#include<iostream>
#include<algorithm>

using namespace std;
int n;
int arr1[51];
int arr2[51];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) cin >> arr1[i];
    for(int i=0; i<n; i++) cin >> arr2[i];

    sort(arr1, arr1+n);
    sort(arr2, arr2+n, greater<int>());

    int answer = 0;
    for(int i=0; i<n; i++)
    {
        answer += (arr1[i] * arr2[i]);
    }

    cout << answer << '\n';
    return 0;
}