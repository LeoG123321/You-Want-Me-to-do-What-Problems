/*
    Leonardo Gonzalez   1/30/24

    Week 3              You Want Me to do What Problems
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string assign;
    char letter;
    vector<char> group1, group2;
    bool flag = true;

    cout << "Please enter the assignment: ";
    cin >> assign;

    letter = assign[0];

    for (int i = 1; i < assign.size(); i++) {
        
        if (flag) {
            if (assign[i] != '-') {
                group1.push_back(assign[i]);
            }
            else {
                flag = false;
            }
        }
        else {
            group2.push_back(assign[i]);
        }
        
    }

    cout << "\n Checkpoint 1: " << endl;
    cout << "Type: " << letter << endl;
    cout << "Group1: ";
    for (int i = 0; i < group1.size(); i++) {
        cout << group1[i];
    }
    cout << "\nGroup2: ";
    for (int i = 0; i < group2.size(); i++) {
        cout << group2[i];
    }
    cout << endl;

    vector<int> numbers1;

    for (int i = 0; i < group1.size(); i++){
        numbers1.push_back(group1[i] - 48);
    }

    cout << "\nCheckpoint 2: " << endl;
    cout << "Group1: ";
    for (int i = 0; i < group1.size(); i++) {
        cout << group1[i];
    }

    int num1{ 0 }, num2{ 0 };

    for (int i = 0; i < numbers1.size(); i++) {

    }

}

