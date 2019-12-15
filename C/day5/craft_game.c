#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(void), stopOrContGame(void);

void main()
{
    enum Status
    {
        COUNTINUE,
        WON,
        LOSE,
        QUIT
    };
    int playerPoint, sum;

    printf("Welcome to craft game\n");

    enum Status gameStatus;
    srand(time(NULL));
    printf("Rolling dice ..\n");
    sum = rollDice();

    switch (sum)
    {
    case 7:
    case 11:
        gameStatus = WON;
        break;
    case 2:
    case 3:
    case 12:
        gameStatus = LOSE;
        break;
    default:
        playerPoint = sum;
        printf("player point is : %d\n", playerPoint);
        gameStatus = stopOrContGame();
        break;
    }

    while (gameStatus == COUNTINUE)
    {
        printf("Rolling dice ..\n");
        sum = rollDice();
        if (sum == playerPoint)
        {
            gameStatus = WON;
        }
        if (sum == 7)
        {
            gameStatus = LOSE;
        } 
        if (sum != playerPoint && sum!=7) {
            gameStatus = stopOrContGame();
        }
    }
    if (gameStatus == WON)
    {
        printf("YOU WON");
    }
    else if (gameStatus == LOSE)
    {
        printf("YOU LOSE");
    } else
    {
        printf("GAME QUIT");
    }
    
}

int rollDice(void)
{
    int sum, dice1, dice2;
    dice1 = 1 + (rand() % 6);
    dice2 = 1 + (rand() % 6);
    sum = dice1 + dice2;
    printf("Player rolled: %d + %d = %d\n", dice1, dice2, sum);
    return sum;
}

int stopOrContGame(void) {
    printf("Enter to continue drawing or crl z to end\n");
    int choice = getchar(); // using getchar to pause for input
    switch (choice)
    {
    case EOF:
        return 3; //gameStatus = QUIT
        break;
    
    default:
        return 0; // gameStatus = CONTINUE
        break;
    }
}
