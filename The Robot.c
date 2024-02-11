#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void replaceCoins(int size, int arr[size][size], int coinNumber);
void printBoard(int size, int arr[size][size]);
void playGame(int size, int coinBoard[size][size],int coinNumber);
int findDistance(int *posX, int *posY,int size, int arr[size][size]);

int main() {
    srand(time(NULL));
    int coinBoard[8][8];
    int coinNumber = 7;
    replaceCoins(8,coinBoard,coinNumber);
    playGame(8,coinBoard,coinNumber);
    return 0;
}

void replaceCoins(int size, int arr[size][size], int coinNumber) {
    while (coinNumber != 0) 
    {
        int randomPosX = rand() % 8;
        int randomPosY = rand() % 8;

        if ((randomPosX != 0 && randomPosY != 0) && arr[randomPosX][randomPosY] != 1) 
        {
            arr[randomPosX][randomPosY] = 1;
            coinNumber--;
        }
    }
}

void printBoard(int size, int arr[size][size]) {
    for (int i = 0; i < size; i++) {
        printf("\n");
        for (int j = 0; j < size; j++) {
            if (arr[i][j] == 2) {
                printf("P ");
            } else if (arr[i][j] == 1) {
                printf("0 ");
            } else {
                printf("_ ");
            }
        }
    }
}

void playGame(int size, int arr[size][size],int coinNumber)
{
    int playerPosX = 0;
    int playerPosY = 0;
    arr[playerPosX][playerPosY] = 2;
    int turnCount = 0;
    
    while(coinNumber != 0)
    {
        turnCount++;
        printf("\n\n%d. turn the board : \n",turnCount);
        printBoard(8, arr);
        
        while(playerPosX < size -1 || playerPosY < size -1)
        {
        arr[playerPosX][playerPosY] = 0;
        findDistance(&playerPosX,&playerPosY,8,arr);
        if(arr[playerPosX][playerPosY]== 1)
        {
        arr[playerPosX][playerPosY] = 2;
        coinNumber--;
        }
        }
        printf("\n\nAfter turn board state: \n");
        arr[size-1][size-1] = 2;
        printBoard(8,arr);
        arr[size-1][size-1] = 0;
        arr[0][0] = 2;
        playerPosX = 0;
        playerPosY = 0;
    }
      
    printf("\nYou collect all coin in %d. turn",turnCount);
}

int findDistance(int *posX, int *posY,int size, int arr[size][size])
{
    int minDistance = 8 * 2;
    int closestX = 8;
    int closestY = 8;
    int currentDistance;
    
    for(int i = *posX; i< size; i++)
	{
		for(int j = *posY; j < size; j++)
		{
			if(arr[i][j] == 1) 
			{
				currentDistance = (i - *posX) + (j - *posY);
				if(currentDistance < minDistance)
				{
					closestX = i;
					closestY = j;
					minDistance = currentDistance;
				}
			}
		}
	}
    *posX = closestX;
    *posY = closestY;
    return currentDistance;
}
