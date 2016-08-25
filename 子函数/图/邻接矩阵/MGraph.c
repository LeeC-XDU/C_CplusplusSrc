#include "MGraph.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

//全局变量，节点被访问标识
Status visited[MAXVEXNUM];

static void RecurseDFS(MGraph *G, int i, void (*pfun)(VertexType *e));
static void StackDFS(MGraph *G, int startVex, void (*pfun)(VertexType *e));


/**********************************************
函数功能:创建无向图
参数1(输出参数):图指针
返回值:无
说明:用stdin的方式输入，这个函数实现本身就不定
头文件:<stdio.h>
作者: Lee.C
完成时间:2016-03-26
*************************************************/
void CreateUndirMGraph(MGraph *G)
{
	int i = 0, j = 0, k = 0, w = 0;
	
	puts("Please input the quantity of vertex and edge:(x,y)");
	scanf("%d,%d", &G->vertexesNum, &G->edgesNum);
	
	puts("Please input vertexes number:");
	for(i=0; i<G->vertexesNum; i++)
		scanf(" %c",&G->vexs[i]);

	for(i=0; i<G->vertexesNum; i++)
		for(j=0; j<G->vertexesNum; j++)
			//这个地方切不能直接用INT_MAX,因为下边有加法比较，一加就变为负数，成最小值了
			G->arc[i][j] = INT_MAX/10;

	for(k=0; k<G->edgesNum; k++)
	{
		puts("input (i,j) index-i,j and the weight w:");
		scanf("%d,%d,%d", &i, &j, &w);
		G->arc[i][j] = w;
		G->arc[j][i] = w;
	}
}


/**********************************************
函数功能:创建有向图
参数1(输出参数):图指针
返回值:无
说明:用stdin的方式输入，这个函数实现本身就不定
头文件:<stdio.h>
作者: Lee.C
完成时间:2016-03-26
*************************************************/
void CreateMGraph(MGraph *G)
{
	int i = 0, j = 0, k = 0, w = 0;
	
	puts("Please input the quantity of vertex and edge:(x,y)");
	scanf("%d,%d", &G->vertexesNum, &G->edgesNum);
	
	puts("Please input vertexes number");
	for(i=0; i<G->vertexesNum; i++)
		scanf(" %c",&G->vexs[i]);

	for(i=0; i<G->vertexesNum; i++)
		for(j=0; j<G->vertexesNum; i++)
			//这个地方切不能直接用INT_MAX,因为下边有加法比较，一加就变为负数，成最小值了
			G->arc[i][j] = INT_MAX/10;

	for(k=0; k<G->edgesNum; k++)
	{
		puts("input (i,j) index-i,j and the weight w:");
		scanf("%d,%d,%d", &i, &j, &w);
		G->arc[i][j] = w;
	}
}

/***************************************************************
函数功能:图的深度优先搜索
参数1:图指针
参数2:函数指针，指明对每个图中元素的操作
返回值:无
说明:pfun()函数可能改变图中顶点编号等信息，所以MGraph没加const
头文件:无
作者: Lee.C
完成时间:2016-07-16
*****************************************************************/
void DFSTraverse(MGraph *G, void (*pfun)(VertexType *e))
{
	int i = 0;
	
	for(i=0; i<G->vertexesNum; i++)
		visited[i] = FALSE;
	
	//如果是连通图，此循环只执行一次
	for(i=0; i<G->vertexesNum; i++)
		if(!visited[i])
			RecurseDFS(G, i, pfun);
}

/**********************************
函数功能:DFS主算法递归实现
参数1:图指针
参数2:图顶点在顶点表中的下标
参数3:函数指针，指明对顶点进行的操作
返回值:无
说明:i记录了搜索的深度
头文件:无
作者: Lee.C
完成时间:2016-07-16
**************************************/
static void RecurseDFS(MGraph *G, int i, void (*pfun)(VertexType *e))
{
	int j = 0;
	
	visited[i] = TRUE;
	
	pfun(&G->vexs[i]);
	
	for(j=0; j<G->vertexesNum; j++)
		if(G->arc[i][j] != 0 && G->arc[i][j] != INT_MAX/10 && !visited[j])
			RecurseDFS(G, j, pfun);
}


/**********************************
函数功能:DFS主算法非递归实现
参数1:图指针
参数2:从此顶点开始遍历 (此顶点在顶点表中的下标)
参数3:函数指针，指明对顶点进行的操作
返回值:无
说明:
头文件:"stack.h"
作者: Lee.C
完成时间:2016-07-16
**************************************/
static void StackDFS(MGraph *G, int startVex, void (*pfun)(VertexType *e))
{
	SqStack S;
	int i = 0, j = 0;
	InitStack(&S);
	
	visited[startVex] = TRUE;
	pfun(&G->vexs[startVex]);
	Push(&S, &startVex);
	
	while(!StackIsEmpty(&S))
	{
		GetTop(&S, &i);
		for(j = 0; j<G->vertexesNum; j++)
		{
			if(G->arc[i][j] != 0 && G->arc[i][j] != INT_MAX/10 && !visited[j])
			{
				visited[j] = TRUE;
				pfun(&G->vexs[j]);
				Push(&S, &j);
				break;
			}
		}
		if(j == G->vertexesNum)
			Pop(&S, NULL);
	}
	
	DestoryStack(&S);
}

/**********************************************
函数功能:邻接矩阵的Dijstra算法
参数1:图指针
参数2:源节点
参数3:前驱矩阵
参数4:权重矩阵
返回值:无
说明:
头文件:<stdlib.h>
       <string.h>
作者: Lee.C
完成时间:2016-03-26
修改时间:2016-03-27
*************************************************/
void Dijkstra(const MGraph *G, int srcNode, int *priorArray, int *weightArray)
{
	int min = 0, Index = 0;
	int *final = (int*)malloc(G->vertexesNum * sizeof(int));
	memset(final, 0, G->vertexesNum * sizeof(int));
//	memset(priorArray, 0, G->vertexesNum * sizeof(int));
	int i = 0, j = 0;
	
	for(i=0; i<G->vertexesNum; i++)
	{
		weightArray[i] = G->arc[srcNode][i];
		if(weightArray[i] < INT_MAX/10)
			priorArray[i] = srcNode;
		else
			priorArray[i] = -1;
	}

	weightArray[srcNode] = 0;
	final[srcNode] = 1;

	for(i=1; i<G->vertexesNum; i++)
	{
		//这个地方切不能直接用INT_MAX,因为下边有加法比较，一加就变为负数，成最小值了
		min = INT_MAX/10;
		for(j=0; j<G->vertexesNum; j++)
		{
			if(!final[j] && weightArray[j]<min)
			{
				Index = j;
				min = weightArray[j];
			}
		}
		final[Index] = 1;
		
		for(j=0; j<G->vertexesNum; j++)
		{
			//松弛操作
			if(!final[j] && (min+G->arc[Index][j]<weightArray[j]) )
			{
				weightArray[j] = min + G->arc[Index][j];
				priorArray[j] = Index;
			}
		}
	}
	free(final);
}
