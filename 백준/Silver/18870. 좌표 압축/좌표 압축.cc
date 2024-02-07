#include<bits/stdc++.h>
using namespace std;

int n;
int idx = 1;
int arr[1000001];
int arr2[1000001];
int arr3[1000001];

int binary_search(int target)
{
    int st = 0;
    int end = idx-1;
    while(st <= end)
    {
        int mid = (st + end)/2;
        if(target == arr3[mid]) return mid;
        else if(target < arr3[mid]) end = mid-1;
        else st = mid + 1;
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
        arr2[i] = x;
    }

    sort(arr2, arr2+n);
    arr3[0] = arr2[0];

    for(int i=1; i<n; i++)
    {
        if(arr2[i-1] != arr2[i])
        {
            arr3[idx++] = arr2[i];
        }
    }

    for(int i=0; i<n; i++)
    {
        cout << binary_search(arr[i]) << ' ';
    }

    return 0;
}