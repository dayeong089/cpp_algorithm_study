#include<iostream>
using namespace std;

int main()
{
    int max_x=1, max_y=1, max_val=0;
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            int x;
            cin >> x;
            if(x > max_val)
            {
                max_x = i+1;
                max_y = j+1;
                max_val = x;
            }
        }
    }

    cout << max_val << endl;
    cout << max_x << " " << max_y << endl;

    return 0;
}