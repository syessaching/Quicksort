#include<iostream>
#include <fstream>
#include "Employee.h"




using namespace std;

bool printIt = false;

// Function to print the list of employees
void printList (Employee** employees, int n){
    for (int i = 0; i < n; i++) {
        cout << employees[i]->getID() << " ";
    }
    cout << endl;
}
int partition(Employee** employees, int low, int high, int &comparison, int n){
    int x = employees[high]->getID(); //set the pivot to the last element
    int i = low - 1; //set the index of the smaller element to -1

    for (int j = low; j <= high - 1; j++) {
        comparison++;
        if (employees[j]->getID() < x) {
            i++;
            Employee* temp = employees[i];
            employees[i] = employees[j];
            employees[j] = temp;

             // Print array after each swap
             if(printIt){
                printList(employees, n);
        }
    }
    }
    Employee* temp = employees[i + 1];
    employees[i + 1] = employees[high];
    employees[high] = temp;

    // Print array after each swap
    if(printIt){
        printList(employees, n);
    }


    return i + 1;
}
void quickSort(Employee** employees, int low, int high, int &comparison, int n){
    if (low < high) {
        int a = partition(employees, low, high, comparison, n);
        quickSort(employees, low, a - 1, comparison, n);
        quickSort(employees, a + 1, high, comparison, n);
    }
    
}


int randomizedPartition(Employee** employees, int low, int high, int &comparison, int n){
    int random = low + rand() % (high - low);
    Employee* temp = employees[random];
    employees[random] = employees[high];
    employees[high] = temp;
    return partition(employees, low, high, comparison, n);
}


void randomizedQuickSort(Employee** employees, int low, int high, int &comparison, int n){
    if (low < high) {
        int a = randomizedPartition(employees, low, high, comparison, n);
        quickSort(employees, low, a - 1, comparison, n);
        quickSort(employees, a + 1, high, comparison, n);
    }
    
}
int TREPartition(Employee** employees, int low, int high, int &comparison, int n) {
    int mid = low + (high - low) / 2;
    int pivotIndex = low;
    if (employees[mid]->getID() < employees[low]->getID()) {
        pivotIndex = mid;
    }
    if (employees[high]->getID() < employees[pivotIndex]->getID()) {
        pivotIndex = high;
    }
    Employee* temp = employees[pivotIndex];
    employees[pivotIndex] = employees[high];
    employees[high] = temp;
    return partition(employees, low, high, comparison, n);
}

void treQuickSort(Employee** employees, int low, int high, int &comparison, int n){
    if (low < high) {
        int a = partition(employees, low, high, comparison, n);
        quickSort(employees, low, a - 1, comparison, n);
        quickSort(employees, a + 1, high, comparison, n);
    }
    
}
void makeOutputFile(Employee** employees, int n, const string& filename, int comparison) {
    ofstream ofs(filename);
    for (int i = 0; i < n; i++) {
        ofs << employees[i]->getName() << "|" << employees[i]->getID() << "|" 
            << employees[i]->getJob() << "|" << employees[i]->getAge() << "|" 
            << employees[i]->getHireDate() << endl;
    }
    ofs << "Number of comparisons: " << comparison << endl;
    ofs.close();
}


int main(int argc, char**  argv){

        ofstream ofs;
        // checks if a command line is provided
        if (argc<2)
        {
            cout<<"Please include a command line parameter"<<endl;
            exit(1); //exit the program if no parameter
        }
        

        ifstream ifs;
        //Open the file specified in the command line
        ifs.open(argv[1], ios::in);


        // error if file is not found
        if(!ifs){
            cout<<"File not found"<<endl;
            exit(1);
        }

        
        string tmp;
        //read the first line to determine the number of records
        getline(ifs, tmp);
        int n = stoi(tmp);//convert string to integer
        


        Employee** employees = new Employee*[n];//create an array of pointers to Employee objects
        
        //read the records from the file and create Employee objects
        for (int i = 0; i < n; i++) {
            string name, job;
            int id, age, year;

                
            getline(ifs, name, '|');
            getline(ifs, tmp, '|');
            id = stoi(tmp);
            getline(ifs, tmp, '|');
            age = stoi(tmp);
            getline(ifs, job, '|');
            getline(ifs, tmp);
            year = stoi(tmp);
                
            employees[i] = new Employee(name, id, age, job, year);
        }
        
    
    //QuickSort call
    int comparison =0;
    printIt = true;
    quickSort(employees, 0, n - 1, comparison, n);  //sort the records
    cout<<"Number of comparisons (QuickSort): " << comparison << endl;  //print the number of comparisons
    makeOutputFile(employees, n, "sorted_quicksort.txt", comparison); //write the sorted records to a file

    //RandomizedQuickSort call
    comparison = 0;
    printIt = false;
    randomizedQuickSort(employees, 0, n - 1, comparison, n);  //sort the records
    cout<<"Number of comparisons(Randomized QuickSort): " << comparison << endl;  //print the number of comparisons
    makeOutputFile(employees, n, "sorted_randomizedquicksort.txt", comparison); //write the sorted records to a file


    //TREQuickSort call
    comparison = 0;
    printIt = false;
    treQuickSort(employees, 0, n - 1, comparison, n);  //sort the records
    cout<<"Number of comparisons(TRE QuickSort): " << comparison << endl;  //print the number of comparisons
    makeOutputFile(employees, n, "sorted_trequicksort.txt", comparison); //write the sorted records to a file


    //close the files
    ifs.close();
    return 0;
} 
