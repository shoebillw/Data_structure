#include <stdio.h>
#include <stdlib.h>
#define MAXSTACK 200  //定義最大堆疊容量
int stackY[MAXSTACK];  //堆疊的陣列宣告 
int stackX[MAXSTACK];
int top = -1;		  //堆疊的頂端

					  /*判斷是否為空堆疊*/
int isEmpty() {
	if (top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}
/*將指定的資料存入堆疊*/
void push(int Y, int X) {
	if (top >= MAXSTACK) {
		printf("堆疊已滿,無法再加入\n");
	}
	else {
		top++;
		stackY[top] = Y;
		stackX[top] = X;
	}

}
/*從堆疊取出資料*/
int popY() {
	int data;
	if (isEmpty()) {
		printf("堆疊已空\n");
	}
	else {
		data = stackY[top];
		return data;
	}
}
int popX() {
	int data;
	if (isEmpty()) {
		printf("堆疊已空\n");
	}
	else {
		data = stackX[top];
		top--;
		return data;
	}
}


int main(void)
{
	int maze[14][15] = {{ 0,0,0,0,0,0,0,0,0,0,1,0,0,0,0 } ,
						{ 0,1,0,0,1,1,1,1,1,1,0,0,0,0,0 } ,
						{ 0,1,0,1,1,0,0,0,0,0,0,0,0,0,0 },
						{ 0,1,1,1,0,0,0,0,0,0,0,0,0,0,0 },
						{ 0,0,0,0,1,0,0,0,1,1,1,1,1,0,0 },
						{ 0,1,1,1,0,0,0,0,0,0,0,0,1,0,0 },
						{ 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0 },
						{ 0,1,1,0,0,0,0,1,0,1,0,1,0,1,1 },
						{ 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0 },
						{ 0,1,1,0,0,0,1,0,0,0,0,0,0,0,0 },
						{ 0,1,1,0,0,1,1,0,0,0,0,1,0,0,0 },
						{ 0,1,1,0,0,0,1,1,1,1,1,1,0,0,0 },
						{ 0,1,1,0,0,0,0,0,0,0,0,1,0,0,0 },
						{ 0,0,1,0,0,0,0,0,0,0,0,0,1,0,0 } };
	
	push(0, 0);
	while (1)
	{
		/*把走過的路徑標記*/
		maze[stackY[top]][stackX[top]] = -1;
		/*判斷走到底了沒*/
		if (stackY[top] == 13 && stackX[top] == 14)
		{
			break;
		}
		else if (top == -1)
		{
			printf("沒路了");
			break;
		}
		else if (top == 199)
		{
			printf("爆了");
			break;
		}
		/*看哪些路可以走*/
		if (maze[stackY[top]][stackX[top] + 1] == 0 && stackX[top] + 1 < 15)
		{
			push(stackY[top], stackX[top] + 1);
		}
		else if (maze[stackY[top] + 1][stackX[top]] == 0 && stackY[top] + 1 < 14)
		{
			push(stackY[top] + 1, stackX[top]);
		}
		else if (maze[stackY[top]][stackX[top] - 1] == 0 && stackX[top] - 1 >= -1)
		{
			push(stackY[top], stackX[top] - 1);
		}
		else if (maze[stackY[top] - 1][stackX[top]] == 0 && stackY[top] - 1 >= -1)
		{
			push(stackY[top] - 1, stackX[top]);
		}
		/*沒路可以走了就倒退*/
		else
		{
			maze[popY()][popX()] = 2;
		}
	}
	/*印出迷宮和路徑*/
	int i = 0, j = 0;
	for (i = 0;i < 14;i++)
	{
		for (j = 0;j < 15;j++)
		{
			if (maze[i][j] == 0 || maze[i][j] == 2)
			{
				printf("0\t");
			}
			else if (maze[i][j] == 1)
			{
				printf("1\t");
			}
			else if (maze[i][j] == -1)
			{
				printf("X\t");
			}
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

