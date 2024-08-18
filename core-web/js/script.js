const boardElements = document.getElementById("board");

board = [];
turn = "";

for (let i = 0; i < boardElements.children.length; i++) {
    board[i] = boardElements.children[i];
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

function startGame() {
    // Users should be able to either:
    // 1. Select who starts explicitly
    // 2. State that each game should toggle between starting player
    // 3. State that a random player should start
    turn = "X";

    // Add cell event listeners
    for (let i = 0; i < boardElements.children.length; i++) {
        board[i].addEventListener("click", cellClick, false);
    }
}

function cellClick(e) {
    if (e.currentTarget.textContent === "") {
        e.currentTarget.textContent = turn;

        console.log(e.currentTarget.id.slice(5));
        
        // Check for win condition
        let gameOver = checkWin(turn);

        if (!gameOver) {
            if (turn === "X") {
                turn = "O"
            } else {
                turn = "X";
            }
        }
    } else {
        // Denote that the cell is currently occupied
    }
}

function checkWin() {
    
    
    return false;
}

function endGame() {
    // Denote that a particular player has won
    // Remove cell event listeners
    for (let i = 0; i < boardElements.children.length; i++) {
        board[i].removeEventListener("click", cellClick, false);
    }
    // Display next options: Play again, see stats, etc.
}
