#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

             //For Calculating The Number Of Bribes

int BribedQueue(int bribes, vector<int>& array) {

  for (int i = 1; i < array.size(); i++) {
    if (array[i] < array[i - 1]) {
      bribes += (array[i - 1] - array[i]);
    }
  }

  return bribes;                                      //Return Bribed Queue 
}
   //For Opening And Reading File          
 int main() {
    ifstream file("C:/Users/Dell/Desktop/tc1/tc1_2.txt");
     if (file.is_open()) {                             //To Check If The File Opened Successfully
        int size;
            file >> size;
            vector<int> array(size);
            string line;
            getline(file, line);
            getline(file, line);
            stringstream ss(line);

     for (int i = 0; i < size; i++) {                  //For Reading Array From File
            string value;
            getline(ss, value, ',');
            stringstream ss2(value);
                ss2 >> array[i];
    }
    file.close();       
    
    int Bribes = 0;                                    //To Declare A Variable For Storing Number Of Bribes
        Bribes = BribedQueue(Bribes, array);          //To Call The Function
        cout << "Bribes: " << Bribes << endl;        //For Printing The NUmbers Of Bribes

  } else {
            cout << "Error Opening File" << endl;                       //If the file is not opened
  }

  return 0;
}