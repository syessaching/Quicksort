#include<iostream>

#include "Employee.h"

//constructor to initialize the employee fields
Employee::Employee(string n, int i, int a,string j, int y){
    name=n;
    id=i;
    age=a;
    job=j;
    hiredate=y;
}

//function to print the details of the employee
// void Employee::printInfo(){
//     cout <<"Found: " "Name: "<< name << ", ID:  "<< id<< ", Age:   "<< age  << ", Job:  "<< job  << ", Hire year:  "<< hiredate << endl;
    
// }

//getters to get the employee fields
int Employee::getID(){
    return id;
}

int Employee::getHireDate(){
    return hiredate;
}
int Employee::getAge(){
    return age;
}
string Employee::getName(){
    return name;
}
string Employee::getJob(){
    return job;
}
