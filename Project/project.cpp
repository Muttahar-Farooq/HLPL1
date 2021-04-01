#include "../std_lib_facilities.h"

struct position
    {
        int row;
        int column;
    }; 

class Grid{
private:
    char spaceChar = 177;
    char lineChar = 186;
    struct position
    {
        int row;
        int column;
    }; 
    vector<char> line;
    vector<vector<char>> grid;
       
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

        for (int i = 0; i < 8; i++) line.push_back(spaceChar);
        for (int i = 0; i < 8; i++) grid.push_back(line);
        W.row = 0; W.column = 0;
        B.row = 7; B.column = 7;
        grid[W.row][W.column] = 'W';
        grid[B.row][B.column] = 'B';
        updateNextPositions();
    }
    
    void move(char turn, int r, int c){
        if (turn == 'W'){
            grid[W.row][W.column] = '-';
            W.row = r;
            W.column = c;
            grid[W.row][W.column] = 'W';
        } else
        {
           grid[B.row][B.column] = '-';
            B.row = r;
            B.column = c;
            grid[B.row][B.column] = 'B';
        }
         updateNextPositions();
        
       
    }

    bool isEmpty(int r, int c) {
        if (grid[r][c] == spaceChar) return true;
        else return false;        
    }

    position positionW(){
        return W;
    }

    position positionB(){
        return B;
    }

    vector<position> getNextPosition(char turn){
        if (turn == 'W'){
            return nextPositionW;
        } else
        {
            return nextPositionB;
        }
        
        
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
            for (auto h: v) cout << lineChar << " " <<  h << " ";
            cout << lineChar <<"\n";
        }
        cout << "\n";
    }

    
};

int main(){
    string twoLineSpace = "\n\n";
    position currentMove;
    int option;
    char alphaChar = 'a';
    char turn = 'W';


    Grid myGrid;       //creates an instance of Grid class
    
    while(!myGrid.isGameEnd()){
        system("cls");
        myGrid.printOut();
        
        int i=0;
        
        if (turn == 'W') cout << "It is White Horse's turn!\n";
        else cout << "It is Black Horse's turn!\n";
        cout << twoLineSpace << "Possible values for to move:\n";
        cout << "(Option 0): Skip turn!\n";
        for (auto e:myGrid.getNextPosition(turn)){
            i=i+1;
            cout <<"(Option "<<i<<"): Row = "<< char(alphaChar+e.row)<<e.column+1<<endl; 
        }
        cout << "Select an option from above: ";

        while (true){
            cin >> option;
            if (option > 0 and option <= myGrid.getNextPosition(turn).size()){ myGrid.move(turn,myGrid.getNextPosition(turn)[option-1].row,myGrid.getNextPosition(turn)[option-1].column);break;}
            else if (option == 0) {break;}
            else cout << "Please Enter a valid value: ";
        }

        if (turn == 'W') turn = 'B';
        else turn = 'W';
                
    }


    cout << "\n\n++++++++++++++++++CONGRATS++++++++++++++++++++\n";
    if (myGrid.getNextPosition('W').empty()) cout << "      WINNER OF THIS GAME IS BLACK HORSE\n";
    else cout << "      WINNER OF THIS GAME IS WHITE HORSE\n";
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++";


    return 0;
}