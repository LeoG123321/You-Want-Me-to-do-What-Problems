/*
    Leonardo Gonzalez   1/30/24

    Week 3              You Want Me to do What Problems
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

void problems();    //Prompts user to input assignments, outputs the list of assignemnts
void problemsTest(string);  //Outputs the list of assignments called from the parameters
void grabSets(string, vector<string>&); //Grabs the groups of numbers from the input and keeps them in sets
void grabNumbers(string, vector<char>&, vector<char>&); //From a set, grab the first and second number into vector<char> variables
vector<int> charToInt(vector<char>);    //Converts the numbers from vector<char> variables into vector<int> variables
int vectorToInt(vector<int>);           //Converts the numbers from vector<int> variables into int variables
void doProblems(int, int, vector<int>&);    //Creates the list of problems from the input
void printProblems(vector<int>, char);  //Prints the problems the user needs to complete
void sort(vector<int>&);        //Organizes numbers in ascending order
void clearChar(vector<char>&);  //Clears the variables for a new set
void clearDup(vector<int>&);    //Removes any duplicate numbers
void clearSpace(string&);   //Clears any spaces in the input
    
int main()
{
    string input;

    tests:
    cout << "Run Tests? y/n" << endl;
    cin >> input;
    if (input == "y") {
        problemsTest("L6");
        problemsTest(" M 1 - 3 ");
        problemsTest("N1,2,5");
        problemsTest("P1-3,5");
        problemsTest("Q1-3,5-7");
        problemsTest("R1-1,3-3,5-8");
        problemsTest("S4-5,1-3,7-10");
        problemsTest("T4-5,1-3,7-10,8-12");
    }
    else if (input != "n") {
        cout << "Invalid Input\n" << endl;
        goto tests;
    }

    do {
        problems();
        problems:
        cout << "\nEnter more Assignments? y/n" << endl;
        cin >> input;
        if (input != "n" && input != "y") {
            cout << "Invalid Input\n" << endl;
            goto problems;
        }
    } while (input == "y");

    return 0;
}

void problemsTest(string assign) {
    string holder;  //assignments
    int loop;
    char letter;
    vector<string> sets;
    vector<char> group1{ 'a' }, group2{ 'a' };
    vector<int> problems;

    cout << "\nInput: " << assign << endl;

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

        if (large == 0)
            large = small;

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

void problems() {
    string assign, holder;  //assignments
    int loop;
    char letter;
    vector<string> sets;
    vector<char> group1{ 'a' }, group2{ 'a' };
    vector<int> problems;

    cout << "\nPlease enter the assignment: ";
    
    getline(cin, assign);
    getline(cin, assign);


    clearSpace(assign);

    letter = assign[0];

    grabSets(assign, sets);

    loop = sets.size();

    for (int j = 0; j < loop; j++) {
        clearChar(group1);
        clearChar(group2);

        holder = sets[j];

        grabNumbers(holder, group1, group2);

        vector<int> numbers1 = charToInt(group1);
        vector<int> numbers2 = charToInt(group2);

        int small = vectorToInt(numbers1);
        int large = vectorToInt(numbers2);

        if (large == 0)
            large = small;

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
            if (i % 14 == 0 && i != 0) {
                cout << endl;
            }
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
        }
    }
    assign = temp;
}
