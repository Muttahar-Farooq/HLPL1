#include "../std_lib_facilities.h"

int encoder(int num){
    return pow(10,num)/9; 
}

vector<vector<int>> reader(){
    vector<vector<int>> linesVector; // Vector to store single line vectors
    int lines;
    cin >> lines; // Reads initial number of lines to be entered
    if (lines < 1) error("Please enter a valid value!");

    for (int i = 0; i < lines; i++){
        
        vector<int> lenghtVector; // vector to store each line as string
        int length;
        cin >> length; // Reads length of each line
        if (length < 1 || length > 10) error("Length should be >=1 and <=10!");

        for (int j = 0; j < length; j++){
            int num;
            cin >> num; //Reads single number to be encoded
            if (num < 1 || num > 100) error("Number should be >=1 and <=100");
            
            lenghtVector.push_back(encoder(num)); 
        }
        sort(lenghtVector.begin(), lenghtVector.end()); // Sorts each line in ascending order
        linesVector.push_back(lenghtVector);
    }
    return linesVector;
}

void printOut(vector<vector<int>> linesVector){
    for (auto i : linesVector){
            for (auto j: i){
                cout << j << "-";
            }
            cout << "\b \n";
        }
}

int main(){
    try{
        
    cout << "Enter Your Values:\n";
    vector<vector<int>> linesVector = reader();

    cout << "Output:\n";
    printOut(linesVector);  
      
    return 0;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        return 1;
    }
    
}