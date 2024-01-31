/*
    Leonardo Gonzalez   1/30/24

    Week 3              You Want Me to do What Problems
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void grabNumbers(string, vector<char>&, vector<char>&);
vector<int> charToInt(vector<char>);
int vectorToInt(vector<int>);

int main()
{
    string assign;
    char letter;
    vector<char> group1, group2;
    bool flag = true;

    cout << "Please enter the assignment: ";
    cin >> assign;

    letter = assign[0];

    grabNumbers(assign, group1, group2);

    cout << "\nGrabing Numbers Test: " << endl;
    cout << "Letter: " << letter << endl;
    cout << "Group1: ";
    for (int i = 0; i < group1.size(); i++) {
        cout << group1[i];
    }
    cout << "\nGroup2: ";
    for (int i = 0; i < group2.size(); i++) {
        cout << group2[i];
    }
    cout << endl;

    vector<int> numbers1 = charToInt(group1);
    vector<int> numbers2 = charToInt(group2);

    cout << "\nVector Characters To Vector Integers Test: " << endl;
    cout << "Numbers1: ";
    for (int i = 0; i < numbers1.size(); i++) {
        cout << numbers1[i];
    }
    cout << "\nNumbers2: ";
    for (int i = 0; i < numbers2.size(); i++) {
        cout << numbers2[i];
    }

    int small = vectorToInt(numbers1);
    int large = vectorToInt(numbers2);

    cout << "\n\nVector Integers to Integer Test: " << endl;
    cout << "Num1: ";
    cout << small << endl;
    cout << "Num2: ";
    cout << large << endl;
    
}

void grabNumbers(string values, vector<char> &group1, vector<char> &group2) {
    bool flag = true;
    for (int i = 1; i < values.size(); i++) {
        if (flag) {
            if (values[i] != '-') {
                group1.push_back(values[i]);
            }
            else {
                flag = false;
            }
        }
        else {
            group2.push_back(values[i]);
        }

    }
}

vector<int> charToInt(vector<char> group) {
    vector<int> holder;
    for (int i = 0; i < group.size(); i++) {
        holder.push_back(group[i] - 48);
    }
    return holder;
}

int vectorToInt(vector<int> numbers) {
    int num{ 0 };
    for (int i = 0; i < numbers.size(); i++) {
        num += numbers[i] * pow(10, numbers.size() - i - 1);
    }
    return num;
}
