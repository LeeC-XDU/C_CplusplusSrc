//以此二维数组为迷宫，0表示墙壁，1表示通路
int maze[10][10] = 
{
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
	{0, 1, 1, 0, 1, 1, 1, 0, 1, 0}, 
	{0, 1, 1, 0, 1, 1, 1, 0, 1, 0},
	{0, 1, 1, 1, 1, 0, 0, 1, 1, 0}, 
	{0, 1, 0, 0, 0, 1, 1, 1, 1, 0}, 
	{0, 1, 1, 1, 0, 1, 1, 1, 1, 0}, 
	{0, 1, 0, 1, 1, 1, 0, 1, 1, 0}, 
	{0, 1, 0, 0, 0, 1, 0, 0, 1, 0}, 
	{0, 0, 1, 1, 1, 1, 1, 1, 1, 0}, 
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

/**********************************
函数功能:迷宫算法（递归版）
参数1(Output):迷宫数组
参数2:迷宫起始点x坐标（向下为x）
参数3:迷宫起始点y坐标（向右为y）
参数4:迷宫终点x坐标
参数5:迷宫终点y坐标
参数6:是否到达迷宫终点的标志位，初试默认为FALSE
返回值:无
说明:注销的语句可以将走过的坐标路径信息打印到屏幕上；
     程序的详细解析，见“递归”笔记；
	 需要 Status 的定义。
头文件:无
作者: Lee.C
完成时间:2016-07-18
**************************************/
void mazePath(int (*maze)[10], int x, int y, int endX, int endY, Status *endFlag)
{
	//用5来表示所走过的最终路径，用于迷宫的打印查看
	maze[x][y] = 5;
	
//	fprintf(stdout, "(%d, %d)-->", x, y);
	if(x == endX && y == endY)
	{
		*endFlag = TRUE;
//		fputs("over\n", stdout);
		return;
	}

	if(!*endFlag && maze[x+1][y] == 1) //下
		mazePath(maze, x+1, y, endX, endY, endFlag);
	if(!*endFlag && maze[x][y+1] == 1) //右
		mazePath(maze, x, y+1, endX, endY, endFlag);
	if(!*endFlag && maze[x-1][y] == 1) //上
		mazePath(maze, x-1, y, endX, endY, endFlag);
	if(!*endFlag && maze[x][y-1] == 1) //左
		mazePath(maze, x, y-1, endX, endY, endFlag);
	
	/**********************************************
	  将迷宫已访问且确定不是最终路径的点变回原状态，
	  由于是指针，所以必须手动变回原状态，
	  用一个标志位，可防止“反向计算”。
	  这里也可以令 maze[x][y] = 3; 来反应曾经走过的路径
	**********************************************/
	if(!*endFlag)
		maze[x][y] = 1;
}


/**********************************
函数功能:迷宫算法（栈版）
参数1(Output):迷宫数组
参数2:迷宫起点坐标
参数3:迷宫终点坐标
返回值:无
说明:栈中元素应为 mazePoint 类型，其定义为
typedef struct
{
	int x;	//纵为x
	int y;	//横为y
}mazePoint;
头文件:"stack.h"
作者: Lee.C
完成时间:2016-07-18
**************************************/
void mazePathStack(int (*maze)[10], const mazePoint *startCoord, const mazePoint *endCoord)
{
	SqStack S;
	mazePoint currentCoord;
	
	InitStack(&S);
	
	maze[startCoord->x][startCoord->y] = 5;
	Push(&S, startCoord);
	
	while(!StackIsEmpty(&S))
	{
		GetTop(&S, &currentCoord);
		
		if(currentCoord.x == endCoord->x && currentCoord.y == endCoord->y)
			break;
		
		if(maze[currentCoord.x+1][currentCoord.y] == 1)			//下
		{
			maze[++currentCoord.x][currentCoord.y] = 5;
			Push(&S, &currentCoord);
		}
		else if(maze[currentCoord.x][currentCoord.y+1] == 1)	//右
		{
			maze[currentCoord.x][++currentCoord.y] = 5;
			Push(&S, &currentCoord);
		}
		else if(maze[currentCoord.x-1][currentCoord.y] == 1)	//上
		{
			maze[--currentCoord.x][currentCoord.y] = 5;
			Push(&S, &currentCoord);
		}
		else if(maze[currentCoord.x][currentCoord.y-1] == 1)	//左
		{
			maze[currentCoord.x][--currentCoord.y] = 5;
			Push(&S, &currentCoord);
		}
		else
		{
			maze[currentCoord.x][currentCoord.y] = 3;
			Pop(&S, NULL);
		}
	}
	
	DestoryStack(&S);
}
