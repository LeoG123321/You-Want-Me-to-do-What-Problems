/*
    Leonardo Gonzalez   1/30/24

    Week 3              You Want Me to do What Problems

    //To-Do:
    Wrap output
    allow for single input assignments
    impliment everything into a single function call
    move everything into functions.cpp
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

void grabSets(string, vector<string>&);
void grabNumbers(string, vector<char>&, vector<char>&);
vector<int> charToInt(vector<char>);
int vectorToInt(vector<int>);
void doProblems(int, int, vector<int>&);
void printProblems(vector<int>, char);
void sort(vector<int>&);
void clearChar(vector<char>&);
void clearDup(vector<int>&);
void clearSpace(string&);

int main()
{
    string assign, holder;  //assignments
    int loop;
    char letter;
    vector<string> sets;
    vector<char> group1{ 'a' }, group2{ 'a' };
    vector<int> problems;

    cout << "Please enter the assignment: ";
    getline(cin, assign);

    cout << "\n\nInput: " << assign << endl;

    clearSpace(assign);
    cout << "\n\nClear Space Test:" << endl;
    cout << assign << endl;

    letter = assign[0];

    grabSets(assign, sets);
   
    loop = sets.size();

    cout << "\nList of Sets: ";
    for (int i = 0; i < sets.size(); i++) {
        cout << sets[i] << " ";
    }

    for (int j = 0; j < loop; j++) {
        clearChar(group1);
        clearChar(group2);

        holder = sets[j];

        grabNumbers(holder, group1, group2);

        cout << "\n\nGrabing Numbers Test: " << endl;
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

        doProblems(small, large, problems);
    }

    clearDup(problems);
    sort(problems);

    cout << "\n\nPrinting out First set of problems: " << endl;
    printProblems(problems, letter);

}

void grabSets(string assign, vector<string> &sets) {
    bool flag = true;
    string temp = "";
    for (int i = 1; i < assign.size(); i++) {
        if (assign[i] != ' ') {
            if (assign[i] != ',') {
                temp += assign[i];
            }
            else {
                sets.push_back(temp);
                temp = "";
            }
        }
    }
    sets.push_back(temp);
}

void grabNumbers(string values, vector<char> &group1, vector<char> &group2) {
    bool flag = true;

    for (int i = 0; i < values.size(); i++) {
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

void doProblems(int small, int large, vector<int> &problems) {
    for (int i = small; i <= large; i++) {
        problems.push_back(i);
    }
}

void printProblems(vector<int> problems, char letter) {
    if (problems.size() == 1) {
        cout << "Do problem " << problems[0] << " of " << letter << "." << endl;
    }
    else {
        cout << "Do problems ";
        for (int i = 0; i < problems.size() - 1; i++) {
            cout << problems[i] << ", ";
        }
        cout << "and " << problems[problems.size() - 1] << " of " << letter << "." << endl;
    }
}

void sort(vector<int>& problems) {
    int temp;
    for (int i = 0; i < problems.size(); i++) {
        for (int j = 0; j < problems.size() - 1; j++) {
            if (problems[j] > problems[j + 1]) {
                temp = problems[j];
                problems[j] = problems[j + 1];
                problems[j + 1] = temp;
            }
        }
    }
}

void clearChar(vector<char>& clear) {
    int num = clear.size();
    for (int i = 0; i < num; i++) {
        clear.pop_back();
    }
}

void clearDup(vector<int>& problems) {
    int temp;
    for (int i = 0; i < problems.size(); i++) {
        for (int j = 0; j < problems.size(); j++) {
            if (problems[i] == problems[j] && i != j) {
                temp = problems[j];
                problems[j] = problems[problems.size() - 1];
                problems[problems.size() - 1] = temp;
                problems.pop_back();
            }
        }
    }
}

void clearSpace(string& assign) {
    string temp = "";
    for (int i = 0; i < assign.size(); i++) {
        if (assign[i] != ' ') {
            temp += assign[i];
            cout << "pass";
        }
        else {
            cout << "failed";
        }
    }
    assign = temp;
}
