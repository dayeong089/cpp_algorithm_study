#include<iostream>
using namespace std;

#include<string>
#include<unordered_map>

int main()
{
    double total_score = 0;
    double total_num = 0;

    unordered_map<string, double> hash;
    hash.insert({"A+", 4.5});
    hash.insert({"A0", 4.0});
    hash.insert({"B+", 3.5});
    hash.insert({"B0", 3.0});
    hash.insert({"C+", 2.5});
    hash.insert({"C0", 2.0});
    hash.insert({"D+", 1.5});
    hash.insert({"D0", 1.0});
    hash.insert({"F", 0.0});

    for(int i=0; i<20; i++)
    {
        string name, score;
        double num;

        cin >> name >> num >> score;

        if(score != "P")
        {
            total_score += (hash[score] * num);
            total_num += num;
        }
    }

    cout << total_score/total_num << endl;
    return 0;
}