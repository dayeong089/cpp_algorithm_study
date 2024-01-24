#include<iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int arr[101] = {};
    for(int i=1; i<n+1; i++){
        arr[i] = i;
    }

    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        
        int tmp = arr[x];
        arr[x] = arr[y];
        arr[y] = tmp;
    }

    for(int i=1; i<n+1; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}