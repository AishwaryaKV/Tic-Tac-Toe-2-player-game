#include <iostream>

using namespace std;
//char num[10]={'0','1','2','3','4','5','6','7','8','9'};
static int q=0;
class game
{
public:
    int p1,p2,val1=0,val2=0;
    char board(char *a)
    {
        cout<< "    |    |    "<< "\n";
        cout<< " " << a[1]<< "  |" << " " << a[2] << "  | "<< " " << a[3]<< " " << "\n";
        cout<< "____|" << "____|" << "____ " << "\n";
        cout<< "    |    |    "<< "\n";
        cout<< " " << a[4]<< "  |" << " " << a[5] << "  | "<< " " << a[6]<< " " << "\n";
        cout<< "____|" << "____|" << "____ " << "\n";
        cout<< "    |    |    "<< "\n";
        cout<< " " << a[7]<< "  |" << " " << a[8] << "  | "<< " " << a[9]<< " " << "\n";
        cout<< "    |" << "    |" << "     " << "\n";
    }
    void player1(char *b)
    {
        cout<< "Player 1 enter your move: \t";
        cin>> p1;
        if(p1)
        {
            if(b[p1]=='X' || b[p1]=='O') {
                cout<< "Invalid move. \n";
                 }
            else {
                if (0<p1<10)
                {
                    b[p1]='X';

                }
                else
                    cout<< "Invalid move. \n";
                }
        }
        q+=1;
    }
    void player2(char *b)
    {
        cout<< "Player 2 enter your move:\t";
        cin>> p2;
        if(p2)
        {
            if (0<p2<10)
            {
                b[p2]='O';

            }
        else
            cout<< "Invalid move. \n";
        }
        q+=1;

    }
    int check(char *c)
    {
        val1=c[1]=='X' && c[2]=='X' && c[3]=='X' || c[1]=='X' && c[4]=='X' && c[7]=='X' || c[2]=='X' && c[5]=='X' && c[8]=='X' || c[3]=='X' && c[6]=='X' && c[9]=='X' || c[1]=='X' && c[5]=='X' && c[9]=='X' ||c[3]=='X' && c[5]=='X' && c[7]=='X';
        val2=c[1]=='O' && c[2]=='O' && c[3]=='O' || c[1]=='O' && c[3]=='O' && c[6]=='O' || c[2]=='O' && c[5]=='O' && c[8]=='O' || c[3]=='O' && c[6]=='O' && c[9]=='O' || c[1]=='O' && c[5]=='O' && c[9]=='O' ||c[3]=='O' && c[5]=='O' && c[7]=='O';
        if(val1==1){ cout<< "Player 1 wins! \n"; return val1; }
        else if (val2==1){
            cout<< "Player 2 wins! \n";
            return val2;
        }


    }

};

int main()
{
    char wish;
    char final;
    char num[10]={'0','1','2','3','4','5','6','7','8','9'};
    char *p;
    p=num;
    cout<< "Welcome to the TIC TAC TOE game! \n";
    cout<< "Do you want to start a new game? Type Y or N\t";
    cin>> wish;
    if (wish=='Y'){
        game g;
        g.board(p);
        while (q<9)
        {
            g.player1(p);
            g.board(p);
            if(q==9) {cout<<"Draw \n"; break;}
            if (g.check(p)==1) { cout<< "The End. \n"; break; }
            g.player2(p);
            g.board(p);
            if (q==9) {cout<<"Draw \n"; break;}
            if (g.check(p)==1){ cout<< "The End. \n"; break; }

        }

    }

    else
        cout<< "Exiting game....\n";
    return 0;
}
