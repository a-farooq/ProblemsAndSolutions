/****
A Tic-Tac-Toe board is given after some moves are played. Find out if the given board is valid, i.e., is it possible to reach this board position after some moves or not.

Note that every arbitrary filled grid of 9 spaces isn’t valid e.g. a grid filled with 3 X and 6 O isn’t valid situation because each player needs to take alternate turns.

Note :  The game starts with X




Example 1:

Input:
board[] = {'X', 'X', 'O', 
           'O', 'O', 'X',
           'X', 'O', 'X'};
Output: Valid
Explanation: This is a valid board.

Example 2:

Input:
board[] = {'O', 'X', 'X', 
           'O', 'X', 'X',
           'O', 'O', 'X'};
Output: Invalid
Explanation: Both X and O cannot win.

Your Task:
You don't need to read input or print anything. Your task is to complete the function isValid() which takes a character array of size 9 representing the board as input parameter and returns a boolean value denoting if it is valid or not.


Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)


Constraints:
Every character on the board can either be 'X' or 'O'.


  ****/

//User function template for C++

class Solution{
public:
    bool isValid(char board[9]){
        // code here
        int p1_pc, p2_pc;
        p1_pc = p2_pc = 0;

        for(int i=0; i<9; i++) {
            if(board[i]=='X')
                p1_pc++;
            else if(board[i]=='O')
                p2_pc++;
        }
        //p1 is first player with X always
        //O (p2_pc) cannot be more than X anytime
        if(p1_pc-p2_pc>1 || p2_pc-p1_pc>0)
            return false;

        int p1_wins, p2_wins;
        p1_wins = p2_wins = 0;

        //check first row, first col, first diag
        if((board[0]==board[1] && board[0]==board[2]) ||
            (board[0]==board[3] && board[0]==board[6]) ||
            (board[0]==board[4] && board[0]==board[8])) {

            if(board[0]=='X') p1_wins++;
            else if(board[0]=='O') p2_wins++;
        }
        //check middle col
        if((board[1]==board[4] && board[1]==board[7])) {
            if(board[1]=='X') p1_wins++;
            else if(board[1]=='O') p2_wins++;
        }
        //check last diag, last col
        if((board[2]==board[4] && board[2]==board[6]) ||
            (board[2]==board[5] && board[2]==board[8])) {
            if(board[2]=='X') p1_wins++;
            else if(board[2]=='O') p2_wins++;
        }
        //check middle row
        if((board[3]==board[4] && board[3]==board[5])) {
            if(board[3]=='X') p1_wins++;
            else if(board[3]=='O') p2_wins++;
        }
        //check last row
        if((board[6]==board[7] && board[6]==board[8])) {
            if(board[6]=='X') p1_wins++;
            else if(board[6]=='O') p2_wins++;
        }
        //cout << p1_cnt << ", " << p2_cnt << endl;
        //if(p1_wins>1 || p2_wins>1)
        //    return false;
        //else
        //both X and O cannot be winner
        if(p1_wins>0 && p2_wins>0)
            return false;
        //if O wins, X must not be more than O bcox X was first piece
        else if(p2_wins && p1_pc>p2_pc)
            return false;
        return true;
    }
};
