#include "../std_lib_facilities.h"


struct nameAge
{
    string name;
    int age;
};

bool myCompfunc(nameAge& a, nameAge& b) {
    return a.name < b.name; 
}

void myPrint(const vector<string>& names,const vector<int>& ages){
    vector<nameAge> people;
    for (int i = 0; i < names.size(); i++ ){
            people.push_back({names[i],ages[i]});
        }

        sort(people.begin(),people.end(), myCompfunc);

        cout << "\n\n--------------------Sorted--------------------\n";

        for (const auto& e:people){
            cout << "Name = " << e.name << "    Age = " << e.age << "\n";
        }
        cout << "\n\n";
}

int main(){
    vector<string> names ;
    vector<int> ages ;
    
    int input;

    int tempAge;
    string tempName;

    cout << "Enter the data of five people: \n";
    for(int i; i<5 ; i++){
                    
        cout << "\nEnter the name "<< i+1 << " : ";
        cin >> tempName;
        names.push_back(tempName);  

        while (true){
            cout << "\nEnter the age " << i+1 << " : ";
            cin >> tempAge;
            if (cin.fail() || tempAge > 150 || tempAge <= 0){
                cin.clear();
                cin.ignore( 512, '\n' ); 
                cout << "Invalid or out of range age value!";
            } 
            else break;                 
        }
            ages.push_back(tempAge);
        
    }
    cout << "\n";        
    myPrint(names, ages);
            
    return 0;
}