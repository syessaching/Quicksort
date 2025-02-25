

#pragma once
#include <string>

using namespace std;

//class definition for Employee
class Employee
{
private:
    string name;
    int id;
    string job;
    int hiredate;
    int age;

public: // constructor and function for our class
    Employee(string, int, int, string, int);
    // void printInfo();
    int getID(); //getter functions
    int getHireDate(); //getter functions
    int getAge();
    string getName();
    string getJob();

    
};
