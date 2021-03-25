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

    vector<position> nextPositionW;
    vector<position> nextPositionB;


    void nextPositionsCalc(vector<position>& nextPos, position P){
        nextPos.clear();
        int nextRow = 0;
        int nextCol = 0;
        for (int i=-1; i<=1; i=i+2){
            for (int j=-2; j<=2; j=j+4){
                nextRow = P.row+i;
                nextCol = P.column+j;
                if (nextRow >= 0 && nextCol >= 0 && nextRow <= 7 && nextCol <= 7)
                    if (isEmpty(nextRow,nextCol)) nextPos.push_back({nextRow,nextCol});
                nextRow = P.row+j;
                nextCol = P.column+i;
                if (nextRow >= 0 && nextCol >= 0 && nextRow <= 7 && nextCol <= 7)
                    if (isEmpty(nextRow,nextCol)) nextPos.push_back({nextRow,nextCol});
            }
        }
    }
    void updateNextPositions(){
        nextPositionsCalc(nextPositionW, W);
        nextPositionsCalc(nextPositionB, B);
    }    
    
public:
    
    Grid(){
        for (int i = 0; i < 8; i++) line.push_back("*");
        for (int i = 0; i < 8; i++) grid.push_back(line);
        W.row = 0; W.column = 0;
        B.row = 7; B.column = 7;
        grid[W.row][W.column] = "W";
        grid[B.row][B.column] = "B";
        updateNextPositions();
    }
    
    void moveW(int r, int c){
        grid[W.row][W.column] = "-";
        W.row = r;
        W.column = c;
        grid[W.row][W.column] = "W";
        updateNextPositions();
    }
    void moveB(int r, int c){
        grid[B.row][B.column] = "-";
        B.row = r;
        B.column = c;
        grid[B.row][B.column] = "B";
        updateNextPositions();
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

    vector<position> getNextPositionW(){
        return nextPositionW;
    }
    vector<position> getNextPositionB(){
        return nextPositionB;
    }

    bool isGameEnd(){
        if (nextPositionW.empty() || nextPositionB.empty()) return true;
        else return false;
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

    myGrid.moveW(6,5);  //updates the postion of W
    myGrid.printOut();
    cout << twoLineSpace;

    cout <<"Row  of W:"<< myGrid.positionW().row+1;          //outputs the row position of W
    cout << "\nColumn of B:" << myGrid.positionB().column+1; //outputs the column position of W
    
    cout << "\n\n";
    for (auto e: myGrid.getNextPositionW()){
        cout << "| row = "<< e.row << " Col = " << e.column << "\n";
    }

    return 0;
}