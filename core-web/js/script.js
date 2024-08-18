const boardElements = document.getElementById("board");

let board = [];
let winningCells = [];
let turn = "";

for (let i = 0; i < boardElements.children.length; i++) {
    board[i] = boardElements.children[i];
}

startGame();

function startGame() {
    // Clear previous cell styling
    
    // Users should be able to either:
    // 1. Select who starts explicitly
    // 2. State that each game should toggle between starting player
    // 3. State that a random player should start
    turn = "X";
    winningCells = [];

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
        } else {
            endGame();
        }
    } else {
        // Denote that the cell is currently occupied
    }
}

function checkWin() {
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
    
    if (board[0].textContent !== ""
        && board[0].textContent === board[1].textContent
        && board[1].textContent === board[2].textContent
    ) {
        winningCells = [0, 1, 2];
        return true;
    } else if (board[3].textContent !== ""
        && board[3].textContent === board[4].textContent
        && board[4].textContent === board[5].textContent
    ) {
        winningCells = [3, 4, 5];
        return true;
    } else if (board[6].textContent !== ""
        && board[6].textContent === board[7].textContent
        && board[7].textContent === board[8].textContent
    ) {
        winningCells = [6, 7, 8];
        return true;
    } else if (board[0].textContent !== ""
        && board[0].textContent === board[3].textContent
        && board[3].textContent === board[6].textContent
    ) {
        winningCells = [0, 3, 6];
        return true;
    } else if (board[1].textContent !== ""
        && board[1].textContent === board[4].textContent
        && board[4].textContent === board[7].textContent
    ) {
        winningCells = [1, 4, 7];
        return true;
    } else if (board[2].textContent !== ""
        && board[2].textContent === board[5].textContent
        && board[5].textContent === board[8].textContent
    ) {
        winningCells = [2, 5, 8];
        return true;
    } else if (board[0].textContent !== ""
        && board[0].textContent === board[4].textContent
        && board[4].textContent === board[8].textContent
    ) {
        winningCells = [0, 4, 8];
        return true;
    } else if (board[2].textContent !== ""
        && board[2].textContent === board[4].textContent
        && board[4].textContent === board[6].textContent
    ) {
        winningCells = [2, 4, 6];
        return true;
    }
    
    return false;
}

function endGame() {
    console.log(turn + " wins! ("
        + winningCells[0] + ", " + winningCells[1] + ", " + winningCells[2]
        + ")"
    );
    // Denote that a particular player has won via text
    for (let i = 0; i < winningCells.length; i++) {
        // board[winningCells[i]].className
    }
    
    // Highlight winning cells
    
    // Remove cell event listeners / Disable cells
    for (let i = 0; i < boardElements.children.length; i++) {
        board[i].removeEventListener("click", cellClick, false);
    }
    
    // Display next options: Play again, see stats, etc.
}
