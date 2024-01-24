#include<iostream>

using namespace std;

int main()
{
    int total, count;
    int result = 0;
    cin >> total >> count;

    for(int i=0; i<count; i++){
        int price, num;
        cin >> price >> num;
        result += (price * num);
    }

    if (total == result) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}