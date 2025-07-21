#include <iostream>
#include <string>
using namespace std;

void averageCalculate()
{
    int number=-1;
    int sum;
    int index = 0;
    cout<<"Enter numbers: " <<endl;
    while(number!=0)
    {
        number = 0;
        cin>>number;
        if(number != 0)
        {
            sum += number;
            index++;

        }

    }
    float average = sum/index;
    cout<<"Average is: " << average<<endl;
}

void stringConcate()
{
    string firstName;
    string lastName;

    cout<<"Enter First Name: "<<endl;
    cin>>firstName;

    cout<<"Enter Last Name: "<<endl;
    cin>>lastName;

    string fullname = firstName + " " + lastName;
    cout<< fullname <<endl;
}

void studentInfo()
{
    int totalStudents;
    cout<<"Total number of students: ";
    cin>>totalStudents;

    string studentName[totalStudents];
    int marks[totalStudents];

    for(int i = 0; i< totalStudents; i++)
    {
        cout<<"Student name: ";
        //getline(cin, studentName[i]);
        cin>>studentName[i];

        cout<<"Student Marks: ";
        cin>>marks[i];
    }
    for(int i = 0; i< totalStudents; i++)
    {
        cout<<studentName[i] << " " << marks[i] <<endl;
    }


}
int main()
{
    averageCalculate();
    stringConcate();
    studentInfo();
}
