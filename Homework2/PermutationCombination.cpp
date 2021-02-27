#include "../std_lib_facilities.h"
class A_smaller_than_B{};
class Negative_Inputs{};

double factorial(int num){
    double out = 1;
    for(int i = 2; i <= num; i++){
        out *= i;
    }
    return out;
}

double permutation(int a, int b){
    if (a<0 || b<0) throw Negative_Inputs{};
    if (a < b) throw A_smaller_than_B{};
    
    double out = 1;        
    for(int i = (a-b+1); i <= a; i++){
        out *= i;
    }
        
    return out;
}

double combination(int a, int b){
    return permutation(a,b)/factorial(b);
}

int main()
try{
    cout << "Enter 2 numbers a and b (a>b):\n";
    int a, b;
    cin >> a >> b;
    cout  << "Enter 1 for Permutation and 2 for Combination:\n";
    int selection;
    cin >> selection;

    if (selection == 1) cout << permutation(a,b) << "\n";
    else if (selection == 2) cout << combination(a,b) << "\n";
    else {cout << "Please Enter correct selection value!\n"; main();}
    
    return 0;
}
catch(const std::exception& e){
    std::cerr << e.what() << '\n';
    return 1;
}

    