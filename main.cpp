#include<iostream>

using namespace std;

string checkDays(string day)
{
    string days[7]= {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
    int x = 0;

    for(int i = 0; i< 7; i++)
    {
        if(day == days[i])
        {
            x = 1;
            break;
        }
    }

    if(x == 0)
    {
        cout<<"Not FOund" <<endl;
    } else
    {
        cout << "Found: " + day << endl;
    }

}

int main() {
    string day;
    cout << "Enter Your Day: ";
    cin >> day;
    cout<< endl;

    checkDays(day);
}
