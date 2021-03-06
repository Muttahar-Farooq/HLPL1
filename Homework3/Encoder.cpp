#include "../std_lib_facilities.h"
#include "reader.h"

string encoder(string num){
    int intNum = stoi(num);
    const char mychar = '1';
    if (intNum < 1 || intNum > 100) error("Entered number is out of range!");
    return string(intNum, mychar); 
}

bool isDecode = false;

int main(){
    try{
        cout << "Enter Your Values:\n";
        vector<vector<string>> linesVector = reader(encoder,isDecode) ;

        cout << "Output:\n";
        printOut(linesVector);  
        
        return 0;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        return 1;
    }
    
}