#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

void checkWords(string words[], int wordCount)
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

    for (int i = 0; i < wordCount; i++)
    {
        bool isKeyword = false;
        bool isOperator = false;

        for (int k = 0; k < 85; k++)
        {
            if (words[i] == keyword[k])
            {
                isKeyword = true;
                break;
            }
        }

        if (!isKeyword)
        {
            for (int o = 0; o < 6; o++)
            {
                if (words[i] == opertate[o])
                {
                    isOperator = true;
                    break;
                }
            }
        }

        if (isKeyword)
            cout << "[KEYWORD]: " << words[i] << endl;
        else if (isOperator)
            cout << "[OPERATOR]: " << words[i] << endl;
        else
            cout << "[INVALID]: " << words[i] << endl;
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

    checkWords(words, tempCount);

    delete[] words;
}

string readFileContent(const string& filename)
{
    ifstream inputFile(filename);
    if (!inputFile)
    {
        cerr << "Error opening file: " << filename << endl;
        return "";
    }

    string content;
    string line;

    while (getline(inputFile, line))
    {
        content += line + '\n';
    }

    inputFile.close();
    return content;
}

void codeWritting()
{
    string filename = "test.txt";
    string code = readFileContent(filename);

    if (!code.empty())
    {
        codeDivider(code);
    }
    else
    {
        cout << "No code to process." << endl;
    }
}

int main()
{
    codeWritting();
    return 0;
}
