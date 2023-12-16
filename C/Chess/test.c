#include <ncurses.h>

int main() {
    initscr();          // Initialize ncurses
    cbreak();           // Disable line buffering
    noecho();           // Don't echo characters on the screen
    keypad(stdscr, TRUE);// Enable special keys

    int rows = 8;
    int cols = 8;
    //getmaxyx(stdscr, rows, cols); // Get the number of rows and columns in the terminal

    WINDOW *win = newwin(rows - 2, cols - 2, 1, 1); // Create a window
    box(win, 0, 0); // Draw a box around the window

    // Set initial cursor position
    int cursorRow = 0;
    int cursorCol = 0;

    // Set initial text
    // char gameState[] = "rnbqkbnrpppppppp                                PPPPPPPPRNBQKBNR";
 
    const char *text = "rnbqkbnrpppppppp                                PPPPPPPPRNBQKBNR";

    // Main loop
    int ch;
    do {
        // Draw the window and text
        mvwprintw(win, 1, 1, "%s", text);

        // Move the cursor to its current position
        wmove(win, cursorRow + 1, cursorCol + 1);

        // Refresh the window
        wrefresh(win);

        // Get user input
        ch = getch();

        // Move cursor based on arrow keys
        switch (ch) {
            case KEY_UP:
                cursorRow = (cursorRow > 0) ? cursorRow - 1 : 0;
                break;
            case KEY_DOWN:
                cursorRow = (cursorRow < rows - 4) ? cursorRow + 1 : rows - 4;
                break;
            case KEY_LEFT:
                cursorCol = (cursorCol > 0) ? cursorCol - 1 : 0;
                break;
            case KEY_RIGHT:
                cursorCol = (cursorCol < cols - 4) ? cursorCol + 1 : cols - 4;
                break;
        }

    } while (ch != 'q'); // Continue until 'q' is pressed

    endwin(); // End ncurses

    return 0;
}
