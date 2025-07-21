
#include<iostream>

using namespace std;


string checkVariableName(string variableName)
{
    char firstCharacter = variableName[0];
    if(isalpha(firstCharacter))
    {
        cout<<"First Variable character is correct"<<endl;

    }
    else {
        cout<<"Variable name cannot start with number or special characters"<<endl;
    }

    int nameSize = variableName.length();
    char lastCharacter = variableName[nameSize-1];
    if(isdigit(lastCharacter) || isalpha(lastCharacter))
    {
        cout<<"Last Variable character is correct"<<endl;

    }
    else {
        cout<<"Variable name cannot end with special characters"<<endl;
    }

}

string validVariableType(string variable, string variableName)
{
    string variables[5] = {"int", "float", "double", "char", "string"};
    int check = 0;
    for(int i = 0; i < 5; i++)
    {
        if(variable == variables[i])
        {
            check = 1;
            break;
        }

    }
    if(check == 1)
    {
        cout<<"variable name is correct"<<endl;
        checkVariableName(variableName);
    }
    else
    {
        cout<<"Please assign a valid variable name"<< endl;
    }

}

string codeDivider(string code)
{
    char space = ' ';
    char semicolon = ';';
    int codeLength = code.length();
    string variable;
    string variableName;


    size_t findSpacePos = code.find(space);
    variable = code.substr(0, findSpacePos);
    variableName = code.substr(findSpacePos + 1, code.length() - 1);
    variableName.pop_back();

    cout<<"Variable Type: " <<variable<<endl;
    cout<<"Variable Name: " <<variableName<<endl;

    size_t findSemicolonPos = code.find(semicolon);
    if(findSemicolonPos != codeLength-1)
    {
        cout<<"Semicolon is missing";
    }
    else
    {
        cout<<"Semicolon found" <<endl;
        validVariableType(variable, variableName);
    }


}

void codeWritting()
{
    string code = "string name;";
    codeDivider(code);

}

int main()
{
    codeWritting();
}
