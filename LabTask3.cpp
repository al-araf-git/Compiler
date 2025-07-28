#include <iostream>
#include <string>
#include <cctype> // for isspace

using namespace std;


void checkWords(string words[], int spaceCount)
{
    string keyword[85] = {
    "alignas", "alignof", "and", "and_eq", "asm", "auto",
    "bitand", "bitor", "bool", "break", "case", "catch",
    "char", "char16_t", "char32_t", "class", "compl", "const",
    "constexpr", "const_cast", "continue", "decltype", "default",
    "delete", "do", "double", "dynamic_cast", "else", "enum",
    "explicit", "export", "extern", "false", "float", "for",
    "friend", "goto", "if", "inline", "int", "long", "mutable",
    "namespace", "new", "noexcept", "not", "not_eq", "nullptr",
    "operator", "or", "or_eq", "private", "protected", "public",
    "register", "reinterpret_cast", "return", "short", "signed",
    "sizeof", "static", "static_assert", "static_cast", "struct",
    "switch", "template", "this", "thread_local", "throw", "true",
    "try", "typedef", "typeid", "typename", "union", "unsigned",
    "using", "virtual", "void", "volatile", "wchar_t", "while",
    "xor", "xor_eq", "string"
    };
    string opertate[6] = {"+", "-", "*", "/", "++", "--"};

    for(int i = 0; i < spaceCount; i++)
    {
        if(words[i] == keyword[i])
        {
            cout<<"[KEYWORD]: " << words[i]<<endl;
        }
        else if(words[i] == opertate[i])
        {
            cout<<"[OPERATOR]: " << words[i]<<endl;
        }
        else{
            cout<<"[INVALID]: " <<words[i]<<endl;
        }
    }

}


void codeDivider(const string& code)
{
    int codeLength = code.length();
    int spaceCount = 0;

    for (int i = 0; i < codeLength; i++)
    {
        if (isspace(code[i]))
        {
            spaceCount++;
        }
    }

    int wordCount = spaceCount + 1;

    // Dynamically allocate array of strings
    string* words = new string[wordCount];

    string temp = "";
    int tempCount = 0;

    for (int i = 0; i < codeLength; i++)
    {
        if (!isspace(code[i]))
        {
            temp += code[i];
        }
        else
        {
            if (!temp.empty())
            {
                words[tempCount] = temp;
                tempCount++;
                temp = "";
            }
        }
    }


    if (!temp.empty())
    {
        words[tempCount] = temp;
        tempCount++;
    }


    for (int i = 0; i < tempCount; i++)
    {
        cout << words[i] << endl;
    }

    checkWords(words, tempCount);

}

void codeWritting()
{
    string code = "string name;";
    codeDivider(code);
}

int main()
{
    codeWritting();
    return 0;
}
