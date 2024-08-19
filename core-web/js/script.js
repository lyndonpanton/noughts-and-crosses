const boardElements = document.getElementById("board");

let board = [];
let winningCells = [];
let winningText = document.getElementById("winning-text");
let turn = "";

for (let i = 0; i < boardElements.children.length; i++) {
    board[i] = boardElements.children[i];
}

let restartButton =
    document.getElementById("button-restart");

restartButton.addEventListener("click", startGame);

startGame();

function startGame() {
    // Users should be able to either (these options should be displayed once
    // a move has been played):
    // 1. Select who starts explicitly
    // 2. State that each game should toggle between starting player
    // 3. State that a random player should start
    turn = "X";
    winningCells = [];
    winningText.textContent = "Game in progress...";
    
    // Clear previous cell content
    // Clear previous cell styling
    // Add cell event listeners
    
    for (let i = 0; i < board.length; i++) {
        board[i].textContent = "";
        board[i].classList.remove("winning-cell");
        board[i].addEventListener("click", cellClick, false);
    }
}

function cellClick(e) {
    if (e.currentTarget.textContent === "") {
        e.currentTarget.textContent = turn;
        
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
        // Denote that the cell is currently occupied (temporarily)
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
    // Denote that a particular player has won via text
    winningText.textContent = (turn + " wins!").toUpperCase();
    
    // Denote that a particular player has won via highlighting winning cells
    for (let i = 0; i < winningCells.length; i++) {
        board[winningCells[i]].classList.add("winning-cell");
    }
    
    // Remove cell event listeners / Disable cells
    for (let i = 0; i < boardElements.children.length; i++) {
        board[i].removeEventListener("click", cellClick, false);
    }
    
    // Display next options: Play again, see stats, etc.
}
