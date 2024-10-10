#include <iostream>

using namespace std;
char char_turn='X', board[3][3]={ {'1','2','3'},
                                  {'4','5','6'},
                                  {'7','8','9'},};
int pos_choice, row, col, draw=0;
void display()
{

    cout<<"    " <<"     |     |     "<<endl;
    cout<<"    " <<"  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  "<<endl;
    cout<<"    " <<"     |     |     "<<endl;

    cout<<"    "<<"----------------"<<endl;

    cout<<"    " <<"     |     |     "<<endl;
    cout<<"    " <<"  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  "<<endl;
    cout<<"    " <<"     |     |     "<<endl;

    cout<<"    " <<"-----------------"<<endl;

    cout<<"    " <<"     |     |     "<<endl;
    cout<<"    " <<"  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  "<<endl;
    cout<<"    " <<"     |     |     "<<endl;

}
void turn()
{
    if(char_turn=='X')
        cout<<"player I's turn - you're X:";
    else cout<<"player II's turn - you're O:";

    cin>>pos_choice;
    switch(pos_choice){
        case 1: row=0; col=0; break;
        case 2: row=0; col=1; break;
        case 3: row=0; col=2; break;
        case 4: row=1; col=0; break;
        case 5: row=1; col=1; break;
        case 6: row=1; col=2; break;
        case 7: row=2; col=0; break;
        case 8: row=2; col=1; break;
        case 9: row=2; col=2; break;
        default:
            cout<<"Invalid Move: Try Again", turn();
    }
    if(char_turn=='X' && board[row][col]!='X' && board[row][col]!='O')
        board[row][col]='X', char_turn='O';
    else if(char_turn=='O' && board[row][col]!='X' && board[row][col]!='O')
        board[row][col]='O', char_turn='X';
    else cout<<"box already used: try again", turn();
    display();
}
int gameover()
{
    int i,j;
    ///rows & columns wins
    for(i=0; i<3; i++)
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] ||
           board[0][i] == board[1][i] && board[0][i] == board[2][i])
           return 0;

    ///diagonal win
    if(board[0][0]==board[1][1] && board[0][0]==board[2][2] ||
       board[0][2]==board[1][1] && board[0][2]==board[2][0])
       return 0;

    ///there are still numbered boxes
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return 1;

    ///all boxes are filled but nobody won
    draw=1;
    return 0;
}
int main()
{
    cout<<"      T I C -- T A C -- T O E -- G A M E            \n";
    cout<<"               FOR 2 PLAYERS               \n";
    cout<<endl<<endl<<"Choose your player: I - X or II - O before you start."<<endl<<"Tutorial: when your turn comes, simply choose the number of the box you want to mark\nand it will fill automatically after you press Enter."<<endl<<endl;

    display();
    while(gameover()!=0){
        turn();
        gameover();
    }

    if(draw==0)
    {
        if(char_turn=='O')
            cout<<"\n         Congratulations! Player I has won the game";
        else cout<<"\n        Congratulations! Player II has won the game";
    }

    else
    cout<<"\n            GAME DRAW!!!            ";
}
