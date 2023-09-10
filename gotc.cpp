#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include<fstream> 
using namespace std;

// Function to find the maximum consecutive extended working hours

int GoingOffTheCharts(const vector<int>& arr) {               
    int mconexhrs = 0;                                        //maximumconsecutiveextentedhours= "mconexhrs"  
    int currconexhrs = 0;                                     //currentconsecutiveextendedhours= "currconexhrs"

    for (int value : arr) {                                   //Loop through each element of vector
        if (value > 6) {
            currconexhrs++;
            mconexhrs =max(mconexhrs, currconexhrs);
        } else {
            currconexhrs = 0;
        }
    }

    return mconexhrs;
}

int main() {
    string filePath = ("C:/Users/Dell/Desktop/tc2.txt");
       ifstream fin(filePath);

    if (!fin.is_open()) {
           cout << "Error opening file: " << filePath << std::endl;
        return 1;
    }

    int size;
    fin >> size;

    vector<int> arr;
    for (int i = 0; i < size; i++) {               //Loop to read from file
        int value;
        fin >> value;
        arr.push_back(value);
    }
    fin.close(); 

    int mconexhrs = GoingOffTheCharts(arr);

          cout << "Array elements: ";
    for (int value : arr) {
           cout << value << "\t";            //Print elements of array
    }
          cout << "Highest consecutive extended working hours: " << mconexhrs << std::endl;

    return 0;
}