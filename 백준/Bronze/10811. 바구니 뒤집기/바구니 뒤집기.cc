#include<iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int arr[101];
    int arr2[101];
    
    for(int i=1; i<n+1; i++){
        arr[i] = i;
    }

    for(int i=0; i<m; i++){
        int start, end;
        cin >> start >> end;

        for(int i=start; i<end+1; i++){
            arr2[i] = arr[i];
        }

        for(int i=start; i<end+1; i++){
            arr[i] = arr2[start+end-i];
        }
    }

    for(int i=1; i<n+1; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}