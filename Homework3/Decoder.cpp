#include "../std_lib_facilities.h"
#include "reader.h"

string decoder(string num){
    const char mychar = '1';
    int output = num.length();
    string reverse = string(output, mychar);
    if (output < 1 || output > 100) error("Entered number is out of range!");
    if (num != reverse) error("Entered number is not of correct format!");
    return to_string(output);
}

int main(){
    try{       
    cout << "Enter Your Values:\n";
    vector<vector<string>> linesVector = reader(decoder);

    cout << "Output:\n";
    printOut(linesVector);  
      
    return 0;
    }
    catch(const std::exception& e){
        cout << e.what() << '\n';
        return 1;
    }
    

}