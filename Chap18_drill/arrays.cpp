#include "../std_lib_facilities.h"

int fac(int n){
    int factorial = 1;
    for(int i = 1; i <=n; ++i) {
            factorial *= i;
        }
    return factorial;
}

int ga[10]={1,2,4,8,16,32,64,128,256,512};

void f(int* arr, int n){
    int la[10];
    for (int i=0; i<10; i++) la[i] = ga[i];

    cout << "\nElements of la are:\n";
    for (int i=0; i<10; i++) cout << la[i] << endl;

    int* p = new int[n];
    for (int* i=p; i<p+n; i++) *i = arr[i-p];
    cout << "\nElements of free store array are:\n";
    for (int* i=p; i<p+n; i++) cout << *i << endl;
    delete[] p;
}

int main(){
    cout << "<-----------f(ga,10)----------->";
    f(ga,10);

    int aa[10];
    for (int i=0; i<10; i++) aa[i] = fac(i+1);

    cout << "<-----------f(aa,10)----------->";
    f(aa,10);
        
    return 0;
}