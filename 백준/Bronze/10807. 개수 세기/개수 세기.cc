#include<iostream>

using namespace std;

int main()
{
    int n, result=0, target;
    int arr[101] = {};

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cin >> target;
    for(int i=0; i<n; i++){
        if(arr[i] == target) {result++;}
    }

    cout << result << endl;
    return 0;
}