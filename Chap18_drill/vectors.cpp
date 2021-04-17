#include "../std_lib_facilities.h"

int fac(int n){
    int factorial = 1;
    for(int i = 1; i <=n; ++i) {
            factorial *= i;
        }
    return factorial;
}

vector<int> gv = {1,2,4,8,16,32,64,128,256,512};

void f(vector<int> vec){
    vector<int> lv;
    lv.reserve(vec.size());
    for (auto e:gv) lv.push_back(e);

    cout << "\nElements of lv are:\n";
    for (auto e:lv) cout << e << endl;

    vector<int> lv2 = vec;
    cout << "\nElements of lv2 are:\n";
    for (auto e:lv2) cout << e << endl;
}

int main(){
    cout << "<-----------f(gv)----------->";
    f(gv);

    vector<int> vv;
    for (int i=0; i<10; i++) vv.push_back(fac(i+1));

    cout << "<-----------f(vv)----------->";
    f(vv);

    return 0;
}