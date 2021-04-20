#include "../std_lib_facilities.h"

void print_array10(ostream& os, int* a){
    for (int i=0; i<10; i++) os << a[i] << ",";
    cout << endl;
}

void print_array(ostream& os, int* a, int n){
    for (int i=0; i<n; i++) os << a[i] << ",";
    cout << endl;
}

void vecPrint(ostream& os,vector<int> vec){
    for (auto e:vec) os << e << ",";
    cout << endl;
}


int main(){

    int* arr10 = new int[10];
    for (int i=0; i<10; i++) arr10[i] = 100+i;
    print_array10(cout, arr10);
    delete[] arr10;

    int* arr11 = new int[11];
    for (int i=0; i<11; i++) arr11[i] = 100+i;
    print_array(cout, arr11, 11);
    delete[] arr11;

    int* arr20 = new int[20];
    for (int i=0; i<20; i++) arr20[i] = 100+i;
    print_array(cout, arr20, 20);
    delete[] arr20;

    vector<int> vec10;
    for (int i=0; i<10; i++) vec10.push_back(100+i);
    vecPrint(cout,vec10);

    vector<int> vec11;
    for (int i=0; i<11; i++) vec11.push_back(100+i);
    vecPrint(cout,vec11);

    vector<int> vec20;
    for (int i=0; i<20; i++) vec20.push_back(100+i);
    vecPrint(cout,vec20);


    int seven = 7;
    int* p1 = &seven;
    cout << "P1 Adress = " << p1 << " and the value = " << *p1 << endl;  
   
    int arr7[7];
    for (int i=0; i<7; i++) arr7[i] = pow(2,i);
    int* p2 = arr7;
    cout << "P2 Adress = " << p2 << " and the value = " ;
    print_array(cout,p2,7);

    int* p3 = p2;
    p2 = p1;
    p2 = p3;
    cout << "P1 Adress = " << p1 << " and the value = " << *p1 << endl;
    cout << "P2 Adress = " << p2 << " and the value = " << *p2 << endl;

    p1 = nullptr; p2=nullptr; p3=nullptr; 
//  
    int arr10_2[10];
    for (int i=0; i<10; i++) arr10_2[i] = pow(2,i);
    p1 = arr10_2;

    int arr10_3[10];    
    p2 = arr10_3;

    for (int i=0; i<10; i++) p2[i] = p1[i];

    vector<int> vec10_2;
    for (int i=0; i<10; i++) vec10_2.push_back(pow(2,i));
    vector<int>* P1 = &vec10_2;

    vector<int> vec10_3;
    vector<int>* P2 = &vec10_3;
    for (int i=0; i<P1->size(); i++) P2->push_back((*P1)[i]);

    cout << "\nP2 output:\n";
    for (int i=0; i<P2->size(); i++) cout << (*P2)[i] << " ";

    return 0;
}