Tic-Tac-Toe

1.Introduction:

    Two players, Cross and Nought, take turns to place crosses (X) and noughts (O) in empty cells of a 3X3 array.
    
    The player who succeeds in placing three of their marks in a horizontal row, vertical column, or diagonal wins
    
    the game. If this doesn't happen, the game ends in a draw. The simplicity of the 3X3 game ensures that best
    
    play from both the players ensures a draw.
    
2.Strategy
    
    List of priorities:
    
    1)Win: If the player has two in a row (here, row represents horizontal row or vertical
    
     column or diagonal), they can place a third (if empty) to get three in a row.
    
    2)Block: If the opponent has two in a row, the player must play the third themselves to
    
    block the opponent's win.
    
    3)Opportunity move: Create an opportunity where the player has two ways to win (two non-blocked lines of 2).
    
    It is a move which creates an opportunity for the player to definitely win in the next move.
    
    4)Blocking an opponent's opportunity move (in priority order):
    
        Option 1: The player should create two in a row to force the opponent into
    
              defending, as long as it doesn't result in them creating an opportunity move. For example, if
    
              "X" has two opposite corners and "O" has the center, "O" must not play a
    
              corner in order to win. (Playing a corner in this scenario creates an opportunity move for "X"
    
               to win.)
    
        Option 2: If there is a configuration where the opponent can have an opportunity move, the player
    
               should block that move.
    
    5)If none of the above moves exist, the following strategy should be used in the same priority order:
    
        i)The player should play a move which can lead to an opportunity move if the opponent doesn't play the next
    
         move optimally.
    
        ii)The player should play a move which can lead to win in next move, given that the
    
         opponent doesn't play optimally.
    
        iii)Otherwise any random move can be played.
    
    To play optimally, O should adopt the following strategies:
    
    i)    If X plays corner opening move (best move for them), O should take center in the next move. This
    
        will ensure that X has no move to play that will give an opportunity move. Then follow the list of priorities.
    
    ii)    If X plays edge opening move, O should take center, and then follow the given list of priorities.
    
    iii)If X plays center opening move, O should take corner, and then follow the above list of priorities.
    
    To play optimally, X should adopt the following strategies:
    
    i)    X should play the centre as the opening move and then follow the list of priorities.

