#include<iostream>
#include<string>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row, col;
char token = 'x';

string player1 = "";
string player2 = "";

void displayBoard()
{
    cout << "    |    |   \n";
    cout << " " << space[0][0] << "  |  " << space[0][1] << " |  " << space[0][2] << "  \n";
    cout << "____|____|____\n";
    cout << "    |    |   \n";
    cout << " " << space[1][0] << "  |  " << space[1][1] << " |  " << space[1][2] << "  \n";
    cout << "____|____|____\n";
    cout << "    |    |   \n";
    cout << " " << space[2][0] << "  |  " << space[2][1] << " |  " << space[2][2] << "  \n";
    cout << "    |    |   \n";
}

void getPlayerMove()
{
    int digit;
    cout << (token == 'x' ? player1 : player2) << " Enter a number (1-9): ";
    cin >> digit;

    if (digit < 1 || digit > 9)
    {
        cout << "INVALID INPUT!!" << endl;
        return;
    }

    row = (digit - 1) / 3;
    col = (digit - 1) % 3;

    if (space[row][col] != 'x' && space[row][col] != '0')
    {
        space[row][col] = token;
        token = (token == 'x') ? '0' : 'x';
    }
    else
    {
        cout << "Cell already taken! Try again." << endl;
        getPlayerMove();
    }
}

bool checkWin()
{
    for (int i = 0; i < 3; i++)
    {
        if ((space[i][0] == space[i][1] && space[i][0] == space[i][2]) ||
            (space[0][i] == space[1][i] && space[0][i] == space[2][i]))
        {
            return true;
        }
    }

    if ((space[0][0] == space[1][1] && space[1][1] == space[2][2]) ||
        (space[0][2] == space[1][1] && space[1][1] == space[2][0]))
    {
        return true;
    }

    return false;
}

bool checkTie()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (space[i][j] != 'x' && space[i][j] != '0')
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    cout << "Enter the name of the first player: ";
    getline(cin, player1);
    cout << "Enter the name of the second player: ";
    getline(cin, player2);

    cout << "X----for " << player1 << endl;
    cout << "O----for " << player2 << endl;

    while (!checkWin() && !checkTie())
    {
        displayBoard();
        getPlayerMove();
    }

    displayBoard();

    if (checkWin())
    {
        cout << (token == '0' ? player1 : player2) << " wins!" << endl;
    }
    else
    {
        cout << "It's a tie!" << endl;
    }

    return 0;
}