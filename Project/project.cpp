#include "../std_lib_facilities.h"

class Grid{
private:
    
    vector<string> line;
    vector<vector<string>> grid;
    struct position
    {
        int row;
        int column;
    };    
    position W;
    position B;
    
public:
    
    Grid(){
        for (int i = 0; i < 8; i++) line.push_back("*");
        for (int i = 0; i < 8; i++) grid.push_back(line);
        W.row = 0; W.column = 0;
        B.row = 7; B.column = 7;
        grid[W.row][W.column] = "W";
        grid[B.row][B.column] = "B";
    }
    
    void updateW(int r, int c){
        grid[W.row][W.column] = "-";
        W.row = r;
        W.column = c;
        grid[W.row][W.column] = "W";
    }
    void updateB(int r, int c){
        grid[B.row][B.column] = "-";
        B.row = r;
        B.column = c;
        grid[B.row][B.column] = "B";
    }

    bool isEmpty(int r, int c) {
        if (grid[r][c] == "*") return true;
        else return false;        
    }

    position positionW(){
        return W;
    }

    position positionB(){
        return B;
    }

    void printOut(){
        cout << "___";
        for (int i = 1; i <= 8; i++) cout << "|_"<< i << "_";
        cout << "|\n";
        char myChar = 'a';
        for (auto v: grid){
            cout << myChar << "  ";  myChar++;
            for (auto h: v) cout << "| "<< h << " ";
            cout << "|\n";
        }
    }


};

int main(){
    string twoLineSpace = "\n\n";


    Grid myGrid;       //creates an instance of Grid class
    cout << twoLineSpace;
    myGrid.printOut();
    cout << twoLineSpace;

    myGrid.updateW(3,4);  //updates the postion of W
    myGrid.printOut();
    cout << twoLineSpace;

    cout <<"Row  of W:"<< myGrid.positionW().row+1;          //outputs the row position of W
    cout << "\nColumn of B:" << myGrid.positionB().column+1; //outputs the column position of W

    return 0;
}