#ifndef READER_H
#define READER_H
#include "../std_lib_facilities.h"

vector<vector<string>> reader(string(*encoder)(string)){
    vector<vector<string>> linesVector; // Vector to store single line vectors
    int lines;
    cin >> lines; // Reads initial number of lines to be entered
    if (lines < 1) error("Please enter a valid value!");

    for (int i = 0; i < lines; i++){
        
        vector<string> lenghtVector; // vector to store each line as string
        int length;
        cin >> length; // Reads length of each line
        if (length < 1 || length > 10) error("Length should be >=1 and <=10!");

        for (int j = 0; j < length; j++){
            string num;
            cin >> num; //Reads single number to be encoded
            
            lenghtVector.push_back(encoder(num)); 
        }
        sort(lenghtVector.begin(), lenghtVector.end()); // Sorts each line in ascending order
        linesVector.push_back(lenghtVector);
    }
    return linesVector;
}

void printOut(vector<vector<string>> linesVector){
    for (auto i : linesVector){
            for (auto j: i){
                cout << j << "-";
            }
            cout << "\b \n";
        }
}

#endif