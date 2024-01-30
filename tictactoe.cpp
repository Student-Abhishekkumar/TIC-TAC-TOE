#include<iostream>
#include<vector>
using namespace std;

vector<char> board{('1'),('2'),('3'),
                   ('4'),('5'),('6'),
                   ('7'),('8'),('9')}; 

string n1, n2;
char turn='X';
int board_row_col;
bool draw=false;

void display(){
    system("cls");
    cout<<"\n\n TIC TAC TOE GAME \n";
    cout<<"\t "<<n1<<" [x]\n \t "<<n2<<" [O] \n\n";
    cout<<"\t      |      |      \n";
    cout<<"\t   "<<board[0]<<"  |   "<<board[1]<<"  |   "<<board[2]<<"  \n";
    cout<<"\t______|______|______\n";
    cout<<"\t      |      |      \n";
    cout<<"\t   "<<board[3]<<"  |   "<<board[4]<<"  |   "<<board[5]<<"  \n";
    cout<<"\t______|______|______\n";
    cout<<"\t      |      |      \n";
    cout<<"\t   "<<board[6]<<"  |   "<<board[7]<<"  |   "<<board[8]<<"  \n";
    cout<<"\t      |      |      \n\n";
}

void player_turn(){
    int choice;

    if(turn=='X'){
    cout<<"\t "<<n1<<" [x] Turn : ";
    }

    if(turn=='O'){
    cout<<"\t "<<n2<<" [O] Turn : ";
    }
    
    cin>>choice;
    switch(choice){
        case 1:
            board_row_col=0;
            break;

        case 2:
            board_row_col=1;
            break;

        case 3:
            board_row_col=2;
            break;

        case 4:
            board_row_col=3;
            break;

        case 5:
            board_row_col=4;
            break;

        case 6:
            board_row_col=5;
            break;

        case 7:
            board_row_col=6;
            break;

        case 8:
            board_row_col=7;
            break;

        case 9:
            board_row_col=8;
            break;

        default:
            cout<<"INALID CHOICE....";
            player_turn();
    }

    if(turn=='X' && board[board_row_col]!='X' && board[board_row_col]!='O'){
        board[board_row_col]='X';
        turn='O';
    }
    else if(turn=='O' && board[board_row_col]!='X' && board[board_row_col]!='O'){
        board[board_row_col]='O';
        turn='X';
    }
    else{
        cout<<"\t Place is occupied....\n\t Please try again....\n"<<endl;
        player_turn();
    }
    display();
}

bool game_over() {

    // Check for a win
    for (int i = 0; i < 3; i++) {
        // Check rows and columns
        if ((board[i] == board[i + 3] && board[i] == board[i + 6]) ||
            (board[i * 3] == board[i * 3 + 1] && board[i * 3] == board[i * 3 + 2])){
            return true;
        }
    }

    // Check diagonals
    if ((board[0] == board[4] && board[0] == board[8]) || (board[2] == board[4] && board[2] == board[6])) {
        return true;
    }

    // Check for a draw
    draw = true;
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            draw = false;
            break;
        }
    }

    if (draw) {
        return true;
    }

    return false;
}

int main(){
    cout<<"\tEnter name of Player 1 : ";
    cin>>n1;

    cout<<"\tEnter name of Player 2 : ";
    cin>>n2;

    while (!game_over()){
        display();
        player_turn();
    }
    if(turn=='X' && !draw){
        cout << "\t " << n2 << " Wins!! Congratulations...\n";
    }
    else if(turn=='O' && !draw){
        cout << "\t " << n1 << " Wins!! Congratulations...\n";
    }else{
        cout<<"\t DRAW !!\n";
    }

    return 0;
}