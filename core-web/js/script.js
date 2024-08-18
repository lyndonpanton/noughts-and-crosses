const boardElements = document.getElementById("board");

board = [];

for (let i = 0; i < boardElements.children.length; i++) {
    board[i] = boardElements[i];
}

/* 
    Win conditions
    
    1. 0 1 2
    2. 3 4 5
    3. 6 7 8
    4. 0 3 6
    5. 1 4 7
    6. 2 5 8
    7. 0 4 8
    8. 2 4 6
*/

