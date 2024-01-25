#include<iostream>
using namespace std;

int main()
{
    int p[101][101] = {0, };
    int num, x, y;
    cin >> num;

    for(int i=0; i<num; i++)
    {
        cin >> x >> y;
        for(int j=x; j<x+10; j++)
        {
            for(int k=y; k<y+10; k++)
            {
                p[j][k] = 1;
            }
        }
    }

    int cnt = 0;
    for(int i=0; i<101; i++)
    {
        for(int j=0; j<101; j++)
        {
            if(p[i][j] == 1)
            {
                cnt += 1;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}