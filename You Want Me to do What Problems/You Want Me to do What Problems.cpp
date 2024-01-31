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
    string num1{ "" }, num2{ "" };
    bool flag = true;

    cout << "Please enter the assignment: ";
    cin >> assign;

    letter = assign[0];

    for (int i = 1; i < assign.size(); i++) {
        
        if (flag) {
            if (assign[i] != '-') {
                num1 += assign[i];
            }
            else {
                flag = false;
            }
        }
        else {
            num2 += assign[i];
        }
        
    }

    cout << "Type: " << letter << endl;
    cout << "Num1: " << num1 << endl;
    cout << "Num2: " << num2 << endl;



}

