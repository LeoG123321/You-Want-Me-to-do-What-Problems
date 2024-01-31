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

    vector<int> numbers1 = charToInt(group1);

    cout << "\nCheckpoint 2: " << endl;
    cout << "Group1: ";
    for (int i = 0; i < group1.size(); i++) {
        cout << group1[i];
    }

    int num1{vectorToInt(numbers1)}, num2{0};

    cout << "\nCheckpoint 3: " << endl;
    cout << "Num1: ";
    cout << num1;
    
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
