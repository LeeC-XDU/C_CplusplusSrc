/**********************************
函数功能:若迷宫 maze 中存在从入口 start 到出口 end 的通路,
		 则求得一条通路存放在栈中
参数1:
参数2:
参数3:
返回值:
说明:
作者: Lee.C
完成时间:
**************************************/
typedef struct
{
	int     ord;	//记录通道块在路径上的“序号”
	PosType seat;	//通道块在迷宫中的“坐标位置”
	int     di;		//从此通道块走向下一个通道块的“方向”
}SElemType			//栈的元素类型

bool MazePath(MazeTpye maze,PosType start,PosType end)
{
	SqStack S;
	PosType curpos;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
	InitStack(&S);
}

