#include <bits/stdc++.h>

using namespace std;

/*
This function simply displays the board when human is playing against computer
*/
void displayBoard(const string& board)
{
    cout<<"-------------------------------------------------------------------\n";
    cout << "      " << board[1] << " " << board[2] << " " << board[3] << '\n';
    cout << "      " << board[4] << " " << board[5] << " " << board[6] << '\n';
    cout << "      " << board[7] << " " << board[8] << " " << board[9] << '\n';
    cout<<"-------------------------------------------------------------------\n";
}

/*
opponentTurn takes input from user and makes move accordingly
*/

void opponentTurn(string &board,char opponent)
{
    cout<<"Please make a move. \nEnter a number between 1-9 such that the place is p\n";
    int i;cin>>i;
    while(i<1 || i>9 || board[i]!='_')
    {
        cout << "Please make a valid move\nEnter a number between 1-9 such that it is not filled\n" << endl;
        cin >> i;
    }
    board[i]=opponent;
    cout<<"---------------------------------\n";
    cout<<"You Played: \n";
}


/*
win checks whether player with given mark has won or not
*/

int win(const string& board,char mark)
{
    if(board[1]==mark && board[2]==mark && board[3]==mark)
        return 1;
    if(board[4]==mark && board[5]==mark && board[6]==mark)
        return 1;
    if(board[7]==mark && board[8]==mark && board[9]==mark)
        return 1;
    if(board[1]==mark && board[4]==mark && board[7]==mark)
        return 1;
    if(board[2]==mark && board[5]==mark && board[8]==mark)
        return 1;
    if(board[3]==mark && board[6]==mark && board[9]==mark)
        return 1;
    if(board[1]==mark && board[5]==mark && board[9]==mark)
        return 1;
    if(board[5]==mark && board[3]==mark && board[7]==mark)
        return 1;
    else
        return 0;
}


/*
winInAChance checks whether player can win with a mark on a specific place or not
*/

int winInAChance(string& board,char mark,int place)
{
    string boardcopy=board;
    if(boardcopy[place]=='_')
    {
        boardcopy[place]=mark;
        if(win(boardcopy,mark))
        {
            board[place]=mark;
            return place;
        }
    }
    return 0;
}


/*
winInAChance checks if the player can win with a single move
*/

int winInAChance(string& board,char mark)
{
    string boardcopy=board;
    for(int i=1;i<10;i++)
    {
        if(winInAChance(board,mark,i))
            return i;
    }
    return 0;
}


/*
defend checks whether the place if not selected can lead to immmeadiate win of other player
*/
int defend(string& board,char mark,int place)
{
    string boardcopy=board;
    char othermark;

    if(mark=='x')
        othermark='o';
    else
        othermark='x';

    if(boardcopy[place]=='_')
    {
        if(winInAChance(boardcopy,othermark,place))
        {
            board[place]=boardcopy[place]=mark;
            return place;
        }
    }
    return 0;
        
}


/*
defend checks whether there is a cell which if not selected can lead to immediate win of other player
*/
int defend(string& board,char mark)
{
    for(int i=1;i<10;i++)
    {
        if(defend(board,mark,i))
        return i;
    }
    return 0;
}
/*

winIn3 checks whether putting a mark at a particular place can lead to a definitive win
*/

int winIn3(string& board,char mark,int place)
{
    string boardcopy=board;
    char othermark;
    if(mark=='x')
        othermark='o';
    else
        othermark='x';

    int blank=0, counterable_oppositon_moves=0;
    if(boardcopy[place]=='_')
    {
        boardcopy[place]=mark;
        string copy2=boardcopy;
        for(int x=1;x<10;x++)
        {
            copy2=boardcopy;
            if(copy2[x]=='_')
            {
                blank++;
                copy2[x]=othermark;
                counterable_oppositon_moves+=(winInAChance(copy2,mark)!=0);
            }
        }
        if(blank<2)
        return 0;
        if(counterable_oppositon_moves==blank)
        {
            board[place]==mark;
            return place;
        }

    }
    return 0;
}


/*
winIn3 checks at all position whether putting a mark leads to definitve win
*/
int winIn3(string& board,char mark)
{
    for(int i=1;i<10;i++)
    {
        if(winIn3(board,mark,i))
        return i;
    }
    return 0;
}

int defendin3(string& board,char mark)
{
    string boardcopy=board;
    char othermark;
    if(mark=='x')
        othermark='o';
    else
        othermark='x';

    int count=0;

    for(int i=1;i<10;i++)
    {
        boardcopy=board;
        if(boardcopy[i]=='_')
        {
            boardcopy[i]=mark;
            if(winIn3(boardcopy,othermark))
                count++;
        }
    }
    if(count==0)
    return 0;

    int bestMove =0, cnt2=0;

    for(int i=1;i<10;i++)
    {
        boardcopy=board;
        if(boardcopy[i]=='_')
        {
            boardcopy[i] = mark;
            string copy2 = boardcopy;
            if(winInAChance(copy2, mark)==0)
                continue;

            defend(boardcopy, othermark);

            for(int j=1;j<10;j++)
            {    string copy3 = boardcopy;
                if(copy3[j]=='_')
                {
                    copy3[j]= mark;
                    if(winInAChance(copy3, othermark))
                        continue;
                    else
                    {
                        board[i]= mark;
                        return i;
                    }
                }
            }
        }
    }        
    for(int i=1; i<10; i++)
    {
        boardcopy= board;
        if(boardcopy[i] == '_')
        {
            boardcopy[i]= mark;
            if(winIn3(boardcopy, othermark)==0)
            {
                cnt2++;
                bestMove=i;
                if(winInAChance(boardcopy, mark))
                {
                    board[i]= mark;
                    return i;
                }
            }
        }
    }
    return 0;
}


/* If none works, then try randomly*/


int random(string& board, char mark)
{
    int i, cnt=0, bestMove=0;
    string boardcopy= board;
    char other;

    if(mark == 'x')
        other='o';
    else
        other='x';

    for(i=1; i<10; i++)
    {
        if(boardcopy[i] == '_')
        {
            cnt=0;
            boardcopy[i]= mark;

            if(winIn3(boardcopy, mark))
            {
                cnt++;
                bestMove=i;
            }
        }
    }
    if(bestMove!=0)
    {
        board[bestMove]= mark;
        return bestMove;
    }

    boardcopy = board;
    for(i=1; i<10; i++)
    {
        if(boardcopy[i]=='_')
        {
            cnt=0;
            boardcopy[i]= mark;
            //bestMove=i;
            if(winInAChance(boardcopy, mark))
            {
                cnt++;
                bestMove=i;
            }
        }
    }
    if(bestMove != 0)
    {
        board[bestMove]= mark;
        return bestMove;
    }
    else
    {
        for(i=1; i<10; i++)
        {
            if(board[i] == '_')
            {   board[i] = mark;
                return i;
            }
        }
    }
    return 0;
}

/*
Preference order:
1. it should mark at centre, if its 1st or 2nd move
2. winning in a chance
3. stop opponent from winning in a chance
4. try to win in 3 chances
5. stop other player to win in 3 chances
6. if none works, play randomly
*/

int autoplay(string& board, char mark)
{
    int p= 0;
    for(int i=1; i<=9; i++)
    {
        if(board[i]=='_')
            p++;
    }

    if(p>=8 && board[5]!='_' && board[1]=='_')
    {
        board[1]= mark;
        return 1;
    }
    else if(p>=8 && board[5]=='_')
    {
        board[5]= mark;
        return 5;
    }

    p--;

    int move=0;
    move = winInAChance(board, mark);
    if(move)
    {
        //cout << p << " win" << endl;
        //cout << "win in one" << endl;
        return move;
    }
    else if((move = defend(board, mark)))
    {
        //cout << "defend in one" << endl;
        return move;
    }
        else if((move = winIn3(board, mark)))
        {
            //cout << "win in three" << endl;
            return move;
        }
    else if((move = defendin3(board, mark)))
    {
        //cout << "defend in three" << endl;
        return move;
    }
    else
    {
        move = random(board, mark);
        //cout << "random" << endl;
        return move;
    }
    return 0;
}


void MANvsAI()
{
    string board(10, '_');
    char manMark, AIMark;
    int p=9;

    cout << endl << "X will play first" << endl;
    cout << "Choose: X or O" << endl;
    do
    {
        cin >> manMark;
    }
    while(manMark != 'X' && manMark!= 'O');

    cout << "Format:" << endl;
    cout << "1|2|3" << endl;
    cout << "4|5|6" << endl;
    cout << "7|8|9" << endl;


    if(manMark=='X')
    {
        AIMark = 'o';
        manMark = 'x';
        opponentTurn(board, manMark);
        displayBoard(board);
        p--;
        autoplay(board, AIMark);
        cout << "PC Played:\n";
        displayBoard(board);
        p--;
    }
    else
    {    AIMark='x';
        manMark = 'o';
        autoplay(board, AIMark);
        cout << "PC Played:\n";
        displayBoard(board);
        p--;
    }

    while(p>0)
    {
        opponentTurn(board, manMark);
        displayBoard(board);
        if(win(board, manMark))
        {
            cout << manMark << " win" << endl;
            return ;
        }
        p--;

        if(p == 0)
        {
            cout << "It's a Draw";
            return ;
        }

        autoplay(board, AIMark);
        cout << "PC played:" << endl;
        displayBoard(board);
        if(win(board, AIMark))
        {
            cout << AIMark << " win" << endl;
            return ;
        }
        p--;
    }
    cout << "It's a Draw";
}


void displayGame(const string &board, const vector<int> &humanMovementSequence)
{
    displayBoard(board);
    cout << "Played Moves: ";
    for(size_t move=0; move < humanMovementSequence.size(); move++)
        cout << humanMovementSequence[move] << " ";
    cout << '\n';
}


/*
It takes input the manmark
Returns 2 if game is left incomplete. (user or computer doesn't have any move.)
Returns 1 if computer has won.
Returns 0 if game ends in a draw.
Returns -1 if user has won.
Returns 10 if the current game has already been played once, and is redundant.

*/
int test(vector<int> &seq, char manMark, set<vector<int> > &completedSequence)
{
    string board(10, '_');
    char AIMark;
    int p=9;
    vector<int> humanMovementSequence;

    size_t k=0;

    if(manMark=='X')
    {
        AIMark = 'o';
        manMark = 'x';
        //opponentPlay(board, manMark);
        while(seq[k]<1 || seq[k]>9 || board[seq[k]]!='_')
            k++;

        humanMovementSequence.push_back(seq[k]);
        board[seq[k++]]=manMark;
        p--;

        autoplay(board, AIMark);
        p--;
    }
    else
    {
        AIMark = 'x';
        manMark = 'o';
        autoplay(board, AIMark);
        p--;
    }
    while(p>0)
    {
        while(seq[k]<1 || seq[k]>9 || board[seq[k]]!='_')
        {
            k++;
            if(k>=seq.size() && p>0)
                return 2;
        }
        humanMovementSequence.push_back(seq[k]);
        board[seq[k++]] = manMark;
        p--;

        if(p!=0)
        {
            int AIMove = autoplay(board, AIMark);
            if(AIMove == 0 && p>0)
                return 2;
            p--;
        }

        if(win(board,manMark) || win(board,AIMark) || p==0)
        {
            if(completedSequence.find(humanMovementSequence) == completedSequence.end())
            {
                completedSequence.insert(humanMovementSequence);    //This is a new move sequence.

                displayGame(board,humanMovementSequence);

                if(win(board, manMark))
                    return -1;

                else if(win(board, AIMark))
                    return 1;

                else
                    return 0;
            }
            else
                return 10;
        }
    }
    return 0;
}



void generateTests(char manMark)
{
    static const int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> seq (arr, arr + sizeof(arr) / sizeof(arr[0]) );
    int testIndex = 0, win = 0, losses = 0, draws = 0, incomplete = 0;

    set<vector<int> > completedSeq;

    do {
        testIndex++;
        int res = test(seq, manMark, completedSeq);
        
        if(res==10)
            continue;
        char AIMark;
        if(manMark=='O')
            AIMark='X';
        else
            AIMark='O';
        cout << "Test No. : " << testIndex << '\n';
        if(res == 1)
            cout << AIMark << " Win\n";
        else if(res == 0)
            cout << "It's a draw\n";
        else if(res == -1)
            cout << manMark << " Win\n";

        cout << "--------------------------------------" << '\n';
        switch(res)
        {
            case 1: win++; break;
            case 0: draws++; break;
            case -1: losses++; break;
            case 2: incomplete++; break;
        }
    } while ( next_permutation(seq.begin(), seq.end()) );

    cout << "Wins \t\t : " << win << '\n';
    cout << "Draws \t\t : " << draws << '\n';
    cout << "Losses \t\t : " << losses << '\n';
    cout << "Incomplete games : " << incomplete << '\n';

}

int main()
{
    cout << "Welcome to the TicTacToe game" << endl;
    cout << "Press 1 for playing against computer" << endl;
    cout << "Press 2 for testing the soundness and completeness of computer moves, in all 9! possible games." << endl;
    cout << "Press 3 for inputting individual, intermediate board positions from a text file and seeing the next configuration." << endl;
    int c;
    cin >> c;
    while(c!=1 && c!=2 && c!=3)
    {   cout << "Enter choice properly" << endl;
        cin >> c;
    }

    if(c == 1)
    {
        char s='Y';
        do{
        MANvsAI();        //To play against computer.
        cout<<"\nDo You want to play again?\n";
        cin>>s;
        }
        while(s=='Y');  
    }
    else if (c == 2)
    {   cin.tie(NULL);
        ios_base::sync_with_stdio(false);
        cout << "When human has mark X. i.e. It is the first player" << endl;
        generateTests('X');

        cout << endl << "When human has mark O. i.e. It is the second player" << endl;
        generateTests('O');
    }
    else
    {
        while(1)
        {
            string board;
            if (! (cin>>board))
                break;
            for(int i=0; i<9; i++)
            {
                if(board[i]=='c')
                    board[i]='_';
            }
            board = '0'+board;
            autoplay(board, 'x');
            for(int i=1; i<=9; i++)
            {
                if(board[i]=='_')
                    board[i]='c';
                cout << board[i];
            }
            cout << '\n';
        }
    }
return 0;
}




