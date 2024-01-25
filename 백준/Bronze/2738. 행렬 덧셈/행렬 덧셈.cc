#include<iostream>
using namespace std;

int main()
{
    int n, m;
    int map[101][101] = {0, };

    cin >> n >> m;
    
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<m; k++)
            {
                int x;
                cin >> x;
                map[j][k] += x;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}