#include<iostream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;



void checkVariableName(string variableName[], int count)
{
    for (int i = 0; i < count; i++)
    {
        string varName = variableName[i];

        char firstCharacter = varName[0];
        if (isalpha(firstCharacter))
        {
            cout << "Variable starts with a correct character." << endl;
        }
        else
        {
            cout << "Variable " << varName << " cannot start with a number or special characters." << endl;
        }

        int nameSize = varName.length();
        char lastCharacter = varName[nameSize - 1];
        if (isalpha(lastCharacter) || isdigit(lastCharacter))
        {
            cout << "Variable " << varName << " ends with a correct character." << endl;
        }
        else
        {
            cout << "Variable " << varName << " cannot end with special characters." << endl;
        }
    }
}


string validVariableType(string variable[], string variableName[], int count)
{
    string variables[5] = {"int", "float", "double", "char", "string"};
    int check = 0;
    for(int i = 0; i < count; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(variable[i] == variables[j])
            {
                check++;
                cout << variable[i] << endl;
            }
        }
    }
    cout << "Count: " << check << endl;
    if(check == count)
    {
        cout << "Parameter variable type is correct" << endl;
        checkVariableName(variableName, count);
    }
    else
    {
        cout << "Please assign a valid parameter variable type" << endl;
    }
}

void checkParameters(string parameters)
{
    int count = 0;

    for (char ch : parameters) {
        if (ch == ',') {
            count++;
        }
    }

    count++;  // Add 1 because the number of parameters is one more than the commas

    string variable[count];
    string variableName[count];

    stringstream ss(parameters);
    string param;
    int idx = 0;

    while (getline(ss, param, ','))
    {
        size_t first = param.find_first_not_of(" \t");
        size_t last = param.find_last_not_of(" \t");
        param = param.substr(first, (last - first + 1));

        size_t spacePos = param.find(' ');

        if (spacePos != string::npos)
        {
            string type = param.substr(0, spacePos);
            string name = param.substr(spacePos + 1);

            variable[idx] = type;
            variableName[idx] = name;
        }

        idx++;
    }

    cout << "Total Parameters: " << count << endl;
    cout << "Types: ";
    for (int i = 0; i < count; i++) {
        cout << variable[i] << " ";
    }
    cout << endl;

    cout << "Names: ";
    for (int i = 0; i < count; i++) {
        cout << variableName[i] << " ";
    }
    cout << endl;

    validVariableType(variable, variableName, count);
}

string checkFunctionName(string functionName)
{
    char firstCharacter = functionName[0];
    if(isalpha(firstCharacter) && !isupper(firstCharacter))
    {
        cout << "First Variable character is correct" << endl;
    }
    else {
        cout << "Variable name cannot start with number or special characters or upperCase" << endl;
    }

    int nameSize = functionName.length();
    char lastCharacter = functionName[nameSize-1];
    if(isdigit(lastCharacter) || isalpha(lastCharacter))
    {
        cout << "Last Function character is correct" << endl;
    }
    else {
        cout << "Function name cannot end with special characters" << endl;
    }

    int count = 0;

    for(int i = 1; i < nameSize; i++)
    {
        if(functionName[i] == toupper(functionName[i]))
        {
            count = 1;
            break;
        }
    }

    if(count == 1)
    {
        cout << "The function name is camel case" << endl;
    }
    else {
        cout << "The function name is not camel case" << endl;
    }
}

string validFunctionType(string functionType, string functionName)
{
    string functionTypes[6] = {"void", "int", "float", "double", "char", "string"};
    int check = 0;
    for(int i = 0; i < 6; i++)
    {
        if(functionType == functionTypes[i])
        {
            check = 1;
            break;
        }
    }
    if(check == 1)
    {
        cout << "Function type is correct" << endl;
        checkFunctionName(functionName);
    }
    else
    {
        cout << "Please assign a valid function name" << endl;
    }
}

string codeDivider(string code)
{
    char space = ' ';
    char semicolon = ';';
    char startParenthesis = '(';
    char endParenthesis = ')';
    int codeLength = code.length();
    string functionType;
    string functionName;
    string parameters;

    size_t findSpacePos = code.find(space);
    functionType = code.substr(0, findSpacePos);

    size_t findStartParenthesis = code.find(startParenthesis);
    size_t findEndParenthesis = code.find(endParenthesis);

    functionName = code.substr(findSpacePos + 1, findStartParenthesis - (findSpacePos + 1));

    parameters = code.substr(findStartParenthesis + 1, findEndParenthesis - findStartParenthesis - 1);

    checkParameters(parameters);

    size_t findSemicolonPos = code.find(semicolon);
    if (findSemicolonPos != string::npos && findSemicolonPos != codeLength - 2) {
        cout << "Semicolon is missing at the end of function declaration." << endl;
    } else {
        cout << "Semicolon found" << endl;
        validFunctionType(functionType, functionName);
    }
}

void codeWritting()
{
    string code = "void HelloWorld(string a, int b) {return 0;}";
    codeDivider(code);
}

int main()
{
    codeWritting();
    return 0;
}
