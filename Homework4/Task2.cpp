#include "../std_lib_facilities.h"

vector<int> strLenght(const vector<string>& inputString){
    vector<int> outputInt;
    for (auto i:inputString){
        outputInt.push_back(i.length());
    }
    return outputInt;
}

void minMax(const vector<string>& s,vector<string>& minVec, vector<string>& maxVec){
    vector<int> intVec = strLenght(s);
    sort(intVec.begin(), intVec.end());
    for (auto e:s){
        if (intVec[0] == e.length()) minVec.push_back(e);
        if (intVec[intVec.size()-1] == e.length()) maxVec.push_back(e);
    }   
}



vector<string> sortLexi(vector<string> s){
    sort(s.begin(),s.end());
    return s;
}

int main(){
     
    //_____________________TEST STRING VECTOR_____________________
    vector<string> myStr = {"My", "name", "is", "Mr.Bean", "and", "I", "do", "comedy", "shows", "my", "show", "is", "no.", "1", "comedy", "show", "Worlwide"};
    //____________________________________________________________
    
    cout << "\n___________________LENGTH OF STRINGS_________________\n";
    vector<int> tempintVec = strLenght(myStr);
    for (int i = 0; i < myStr.size(); i++){
        cout << myStr[i] << "   ---Lenght = " << tempintVec[i] << "\n";
    }


    cout << "\n\n____________________LEXICAL ORDER_____________________\n";
    vector<string> tempVec = sortLexi(myStr);
    for (auto e:tempVec) cout << e << "\n";

    cout << "\n\n______________SHORTEST AND LONGEST STRING_____________\n";
    vector<string> minVec;
    vector<string> maxVec;
    minMax(myStr, minVec, maxVec);
    cout << "shortest string(s):\n";
    for (auto e:minVec) cout<< "  - " << e << "\n";
    cout << "longest string(s):\n";
    for (auto e:maxVec) cout<< "  - " << e << "\n";
    cout<< "\n";

    return 0;
}
