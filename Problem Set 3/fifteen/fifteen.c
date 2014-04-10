/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements the Game of Fifteen (generalized to d x d).
 *
 * Usage: ./fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [MIN,MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

// board's minimal dimension
#define MIN 3

// board's maximal dimension
#define MAX 9

// board, whereby board[i][j] represents row i and column j
int board[MAX][MAX];
char myBoard[MAX][MAX];

// board's dimension
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void save(void);

int main(int argc, string argv[])
{
    // greet player
    greet();

    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < MIN || d > MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            MIN, MIN, MAX, MAX);
        return 2;
    }

    // initialize the board
    init();
    usleep(10000);

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();
        printf("Draw function\n");
        usleep(1000000);

        // saves the current state of the board (for testing)
        save();

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }
          //  break
        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep for animation's sake
        usleep(5000);
    }

    // that's all folks
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1,
 * (i.e., fills board with values but does not actually print them),
 * whereby board[i][j] represents row i and column j.
 */
void init(void)
{  
    board[d-1][d-1] = 95;
   
    int p = (d*d)-1;
    

    
    if(d==3)
    {
     
        // Initialize row 1*/
        for(int r=0; r<d; r++)
        {
             
            if(r!=d-1)
            {
                for(int i=0; i<d; i++)
                {
                    board[r][i]=p;
                    printf("   %i", board[r][i]);
                    p--;
                }
                printf("\n");
            }
            else
            {
                for(int i=0; i<d-1; i++)
                {
                    board[r][i]=p;
                    printf("   %i", board[r][i]);
                    p--;
                }
                printf("   %c\n", (char)(board[d-1][d-1]));
            } 
        }
        
        return;
    }
    
    
    
 
    //Switch places of 1 and 2 if board dimensions are even*/
    if (d%2==0)
    {   
        //Initialize row 1*/
        for(int r=0; r<d; r++)
        {
            if(r!=d-1)
            {
                for(int i=0; i<d; i++)
                {
                    board[r][i]=p;
                    if(p<10)
                    { 
                        printf("   %i", board[r][i]);
                    } 
                    else
                    {
                        printf("  %i", board[r][i]);
                    }
                    p--;
                }
                printf("\n");
            }
            
            else
            {
                
                
                for(int i=0; i<d-3; i++)
                {
                    board[r][i]=p;
                    
                    //This determines the spacing if the numbers are two digit to keep everything in line
                    if(p<10)
                    {
                        printf("   %i", board[r][i]);
                    }
                    else
                    {
                        printf("  %i", board[r][i]);
                    }
                    p--;
                }
                board[r][d-3] = 1;
                board[r][d-2] = 2;
                board[r][d-1] = 95;
                
                if(p<10)
                {
                    printf("   %i", board[r][d-3]);
                    printf("   %i", board[r][d-2]);
                    printf("   %c\n", (char)board[r][d-1]);
                }
                
                else
                {
                    printf("  %i", board[r][d-3]);
                    printf("  %i", board[r][d-2]);
                    printf("  %c\n", (char)board[r][d-1]);
                }
                
            }      
        }
    }
  
  
    //If board dimensions are odd (number of tiles even) do this:*/
    else
    {
        for(int r=0; r<d; r++)
        {
            if(r!=d-1)
            {
                for(int i=0; i<d; i++)
                {
                    board[r][i]=p;
                    if(p<10)
                    {
                        printf("   %i", board[r][i]);
                    } 
                    else
                    {
                        printf("  %i", board[r][i]);
                    }
                    p--;
                  
                }
                printf("\n");
            }
            
            else
            {
                for(int i=0; i<d-1; i++)
                {
                    board[r][i]=p;
                    if(p<10)
                    {
                        printf("   %i", board[r][i]);
                    }
                    else
                    {
                        printf("  %i", board[r][i]);
                    }
                     p--;
                }
                
                board[r][d-1] = 95;
                
                if(p<10)
                {
                    printf("   %c\n", (char)board[r][d-1]);
                }
                
                else
                {
                    printf("  %c\n", (char)board[r][d-1]);
                }
            }      
        }
    } 
}  






/**
 * Prints the board in its current state.
 */
void draw(void)
{
    int p = (d*d)-1;
    
    for(int r=0; r<d; r++)
    {
        for(int i=0; i<d;i++)
        {
            if(p<10)
            {
                if(board[r][i]==95)
                {
                    printf("   %c", (char)board[r][i]);
                    
                }
                else
                {
                    printf("   %i", board[r][i]);
                }
                p--;
            }
            else
            {
                if(board[r][i]==95)
                {
                    printf("  %c", (char)board[r][i]);
                }
                else
                {
                    printf("  %i", board[r][i]);
                }
                p--;
            }   
        }
        printf("\n");
    } 
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    
    int tileRow = 0;
    int tileCol = 0;
    int spaceRow = 0;
    int spaceCol = 0;
    
    
    //Search the array 
    for(int r=0; r<d; r++)
    {
        for(int i=0; i<d; i++)
        {
            //Search for tile that user gave, store the position 
            if(board[r][i]==tile)
            {
                tileRow = r;
                tileCol = i;
            }
        
            //Search for "_" and store the position
            if(board[r][i]==95)
            {
                spaceRow = r;
                spaceCol = i;
            }
        }
    }
    
    
    //If tiles are beside each other, switch their positions
    if((abs(tileRow-spaceRow)<=1) && (abs(spaceCol-tileCol)<=1))
    {
        board[spaceRow][spaceCol] = board[tileRow][tileCol];
        board[tileRow][tileCol] = 95;

        return true;
    }
    
    
    //If tiles are not adjacent, return false
    else
    {
        return false;
    }
    
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    
    
    //Create a "winning" array
    int p = 1;
    //int boardWon[][] = [d][d];
    int boardWon[d][d];
    
    for(int r=0; r<d; r++)
    {
        for(int i=0; i<d; i++)
        {
            boardWon[r][i] = p;
            p++;
        }
    }
    boardWon[d-1][d-1] = 95;
    
    
    //Compare board array to boardWon array
    int badTile = 0;
    
    for(int r=0; r<d; r++)
    {
        for(int i=0; i<d; i++)
        {
            if(board[r][i] != boardWon[r][i])
            {
                badTile +=1;
                printf("BAD TILE!!!!\n");
            }
        }
    }
    
    
    if(badTile==0)
    {
        return true;
    }
    
    else
    {
        return false;
    }


    

}

/**
 * Saves the current state of the board to disk (for testing).
 */
void save(void)
{
    // log
    const string log = "log.txt";

    // delete existing log, if any, before first save
    static bool saved = false;
    if (!saved)
    {
        unlink(log);
        saved = true;
    }

    // open log
    FILE* p = fopen(log, "a");
    if (p == NULL)
    {
        return;
    }

    // log board
    fprintf(p, "{");
    for (int i = 0; i < d; i++)
    {
        fprintf(p, "{");
        for (int j = 0; j < d; j++)
        {
            fprintf(p, "%i", board[i][j]);
            if (j < d - 1)
            {
                fprintf(p, ",");
            }
        }
        fprintf(p, "}");
        if (i < d - 1)
        {
            fprintf(p, ",");
        }
    }
    fprintf(p, "}\n");

    // close log
    fclose(p);
}
