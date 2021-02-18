#include "std_lib_facilities.h"

class Derivative_lessThan0{};

vector<double> quadratic(double a, double b, double c){

    double derivate = pow(b,2) - 4*a*c;
    
    if (derivate < 0) throw Derivative_lessThan0{};

    vector<double> x;
    x.push_back((-(b) + sqrt(derivate)) / (2*a));
    x.push_back((-(b) - sqrt(derivate)) / (2*a));

    return x;
}

int main()
    try{
        double a, b, c;
        cout << "Enter the value of a,b,c of your quadratic equation\n";
        cin >> a >> b >> c;
        cout << "roots of (" << a << ")x^2 + (" << b << ")x + (" << c << ") are as follows:\n";
        
        for(double ans : quadratic(a,b,c)){
            cout << ans << "\n";
        }
        
        return 0;
    } catch(Derivative_lessThan0){
        cout << "The equation has no real roots.";
        return 1;
    }
