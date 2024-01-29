#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void replaceCoins(int size, int arr[size][size], int coinNumber);
void printBoard(int size, int arr[size][size]);
void playGame(int size, int coinBoard[size][size],int coinNumber);
int findDistance(int *posX, int *posY,int size, int arr[size][size]);
int distance(int posX, int posY, int x, int y);

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
        findDistance(&playerPosX,&playerPosY,8,arr);
        coinNumber--;
    }    
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
                    printf("%d %d",i ,j);
			}
		}
	}
    *posX = closestX;
    *posY = closestY;

    return currentDistance;
}

int distance(int posX, int posY, int x, int y)
{
    return (x-posX) + (y- posY);
}
