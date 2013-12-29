#include <stdio.h>
#include <stdlib.h>

int CalculateSize(int CellSize, int FrameSize, int GridSize)
{
	int result;
	result = CellSize * GridSize + (GridSize + 1) * FrameSize;
	return result;
}

void PrintFrameLine(int n)
{
	int i;
	for (i = 0; i < n; ++i) putchar('*');
	putchar('\n');
}

void PrintFrame(int CellSize, int FrameSize, int GridSize)
{
	int i;
	for (i = 0; i < FrameSize; ++i) 
		PrintFrameLine(CalculateSize(CellSize,FrameSize,GridSize));
}

void PrintCellLine(int CellSize, int FrameSize, int GridSize)
{
	int i, j;
	for (i = 0; i < FrameSize; ++i) putchar('*');
	for (i = 0; i < GridSize; ++i)
	{
		for (j = 0; j < CellSize; ++j) putchar('.');
		for (j = 0; j < FrameSize; ++j) putchar('*');
	}
	putchar('\n');
}

void PrintCell(int CellSize, int FrameSize, int GridSize)
{
	int i;
	for (i = 0; i < CellSize; ++i) 
		PrintCellLine(CellSize,FrameSize,GridSize);
}

void PrintOutput(int CellSize, int FrameSize, int GridSize)
{
	int i;
	PrintFrame(CellSize,FrameSize,GridSize);
	for (i = 0; i < GridSize; ++i)
	{
		PrintCell(CellSize,FrameSize,GridSize);
		PrintFrame(CellSize,FrameSize,GridSize);
	}
	putchar('\n');
}

int main()
{
	int CellSize, FrameSize, GridSize, TestCase = 1;
	scanf("%d %d %d",&CellSize,&FrameSize,&GridSize);
	while(CellSize || FrameSize || GridSize)
	{
		printf("Case %d:\n",TestCase++);
		PrintOutput(CellSize,FrameSize,GridSize);
		scanf("%d %d %d",&CellSize,&FrameSize,&GridSize);
	}
	return 0;
}