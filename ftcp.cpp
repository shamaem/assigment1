#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

int FixingCodeInProduction(int target, int size, int* arr) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;                                          // When Number not found
}

int main() {
    int target, size;                       //Reading contents from file
    ifstream fin;
    fin.open("C:/Users/Dell/Desktop/tc3.txt");

    fin >> target;
    fin >> size;
    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        fin >> arr[i];
        fin.get();
    }
    fin.close(); 

    int index = FixingCodeInProduction(target, size, arr);
    cout << "Sorted Array: ";
    for (int x = 0; x < size; x++) {
        cout << arr[x] << "\t";
    }
    cout << "\nIndex of " << target << " in the array: " << index <<endl;

    delete[] arr; // Free dynamically allocated memory
 return 0;
}