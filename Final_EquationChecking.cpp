#include<iostream>
using namespace std;

bool checkVaraible(string eqn) {
    for(int i = 0; i < eqn.length(); i++) {
        if(isalpha(eqn[i])) {
            if(isalpha(eqn[i+1]))
            {
                cout<<"Two Alphabet cannot be beside one another"<<endl;
                return false;
            } else if(eqn[i-1] == ')') {
                cout<<"Alphabet cannot be placed after end bracket"<<endl;
                return false;
            }
        }
    }
    cout<<"Equation is correct"<<endl;
    return true;

}

bool checkOperatorPlacement (string eqn) {
    char operators[4] = {'+', '-', '*', '/'};
    int total = eqn.length();
    for(int i = 0; i < eqn.length(); i++) {
        for(int j = 0; j < 4; j++) {
            if(eqn[0] == operators[j]) {
                cout<<"Equation cannot start with operator"<<endl;
                return false;

            } else if(eqn[total-1] == operators[j]) {
                cout<<"Equation cannot end with operator" << endl;
                return false;
            }else if(eqn[i] == '(') {
                if(eqn[i+1] == operators[j])
                {
                    cout<<"Operator cannot be after first bracket"<<endl;
                    return false;
                }
            }else if(eqn[i] == ')') {
                if(eqn[i-1] == operators[j])
                {
                    cout<<"Operator cannot be before end bracket"<<endl;
                    return false;

                }
            } else if(eqn[i] == operators[j]) {
                if(eqn[i+1] == operators[j])
                {
                    cout<<"Two operator can not be beside one another"<<endl;
                    return false;
                }
            }
        }
    }
    checkVaraible(eqn);
    return true;

}

bool checkBracket(string eqn) {
    int open = 0;
    int close = 0;
    for(int i = 0; i < eqn.length(); i++) {
        if(eqn[i] == '(') {
            open++;
        } else if(eqn[i] == ')') {
            close++;
        }
    }
    if(open == close) {
        checkOperatorPlacement(eqn);
        return true;

    } else {
        cout<< "Bracket missing" <<endl;
        return false;

    }

}

bool check(string eqn) {
    char operators[4] = {'+', '-', '*', '/'};
    for(int i = 0; i < eqn.length(); i++) {
        if(!isalpha(eqn[i]) || eqn[i] == '+' || eqn[i] == '-' ||eqn[i] == '*' || eqn[i] == '/' || eqn[i] == '(' || eqn[i] == ')') {
            cout<<"Invalid character"<<endl;
            return false;
        }
    }
    checkBracket(eqn);

}

int main() {
    string eqn = "(a+c)=c";

    check(eqn);
}
