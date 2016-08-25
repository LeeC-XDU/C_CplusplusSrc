#include "GraphAdjList.h"
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include "stack.h"


//全局变量，节点被访问标识
Status visited[MAXVEXNUM];

static void RecurseDFS(GraphAdjList *G, int i, void (*pfun)(VertexType *v));
static void StackDFS(GraphAdjList *G, int i, void (*pfun)(VertexType *v));

/**********************************************
函数功能:创建邻接表无向图
参数1(output):图指针
返回值:无
说明:用stdin的方式输入，这个函数实现本身就不定
头文件:<stdio.h>
       <stdlib.h>
作者: Lee.C
完成时间:2016-03-27
*************************************************/
void CreateUndirALGraph(GraphAdjList *G)
{
	int i = 0, j = 0, k = 0, w = 0;
	EdgeNode *e = NULL;
	
	puts("Please input the quantity of vertex and edge:(x,y)");
	scanf("%d,%d", &G->vertexesNum, &G->edgesNum);

	puts("Please input vertexes number:");
	for(i=0; i<G->vertexesNum; i++)
	{
		scanf(" %c", &G->adjList[i].data);
		G->adjList[i].firstedge = NULL;
	}

	for(k=0, i=0, j=0, w=0; k<G->edgesNum; k++)
	{
		puts("Please input the index of node on edge and the weight");
		scanf("%d,%d,%d", &i, &j, &w);
		e = (EdgeNode *)malloc(sizeof(EdgeNode));

		e->adjvex = j;
		e->weight = w;
		e->next = G->adjList[i].firstedge;
		G->adjList[i].firstedge = e;

		e = (EdgeNode *)malloc(sizeof(EdgeNode));

		e->adjvex = i;
		e->weight = w;
		e->next = G->adjList[j].firstedge;
		G->adjList[j].firstedge = e;
	}
}


/***************************************************************
函数功能:图的深度优先搜索
参数1:图指针
参数2:函数指针，指明对每个图中元素的操作
返回值:无
说明:pfun()函数可能改变图中顶点编号等信息，所以GraphAdjList没加const
头文件:无
作者: Lee.C
完成时间:2016-07-16
*****************************************************************/
void DFSTraverse(GraphAdjList *G, void (*pfun)(VertexType *vex))
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
完成时间:2016-07-18
**************************************/
static void RecurseDFS(GraphAdjList *G, int i, void (*pfun)(VertexType *v))
{
	EdgeNode *e = NULL;
	
	visited[i] = TRUE;
	
	pfun(&G->adjList[i].data);
	
	e = G->adjList[i].firstedge;
	while(e)
	{
		if(!visited[e->adjvex])
			RecurseDFS(G, e->adjvex, pfun);
		
		e = e->next;
	}
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
static void StackDFS(GraphAdjList *G, int startVex, void (*pfun)(VertexType *v))
{
	SqStack S;
	EdgeNode *e = NULL;
	int index = 0;
	
	InitStack(&S);
	
	visited[startVex] = TRUE;
	pfun(&G->adjList[startVex].data);
	Push(&S, &startVex);
	
	while(!StackIsEmpty(&S))
	{
		GetTop(&S, &index);
		e = G->adjList[index].firstedge;
		while(e)
		{
			if(!visited[e->adjvex])
			{
				visited[e->adjvex] = TRUE;
				pfun(&G->adjList[e->adjvex].data);
				Push(&S, &e->adjvex);
				break;
			}
			e = e->next;
		}
		if(!e)
			Pop(&S, NULL);
	}
	
	DestoryStack(&S);
}

/**********************************************
函数功能:邻接表的Dijstra算法
参数1:图指针
参数2:源节点
参数3:前驱矩阵
参数4:权重矩阵
返回值:无
说明:
头文件:<stdlib.h>
       <limits.h>
	   <string.h>
作者: Lee.C
完成时间:2016-03-27
*************************************************/
void Dijkstra(const GraphAdjList *G, int srcNode, int *priorArray, int *weightArray)
{
	EdgeNode *e = NULL;
	int min = 0, Index = 0;
	int i = 0, j = 0;
	int *final = (int *)malloc(G->vertexesNum * sizeof(int));
	memset(final, 0, G->vertexesNum * sizeof(int));
//	memset(priorArray, 0, G->vertexesNum * sizeof(int));

	for(i=0; i<G->vertexesNum; i++)
	{
		weightArray[i] = INT_MAX/10;
		priorArray[i] = -1;
	}
	
	weightArray[srcNode] = 0;
	e = G->adjList[srcNode].firstedge;
	while(e)
	{
		weightArray[e->adjvex] = e->weight;
		priorArray[e->adjvex] = srcNode;
		e = e->next;
	}

	final[srcNode] = 1;

	for(i=0; i<G->vertexesNum; i++)
	{
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
		e = G->adjList[Index].firstedge;

		//不用遍历 vertexesNum 遍了，直接找当前节点的出度节点就行
		while( e )
		{
			//松弛操作
			if(!final[e->adjvex] && (min+e->weight<weightArray[e->adjvex]))
			{
				weightArray[e->adjvex] = min + e->weight;
				priorArray[e->adjvex] = Index;
			}
			e = e->next;
		}
	}
}

/**********************************
函数功能:释放图空间
参数1(Output):图指针
返回值:无
说明:
头文件:<stdlib.h>
作者: Lee.C
完成时间:2016-03-27
**************************************/
void DestoryALGraph(GraphAdjList *G)
{
	int i = 0;
	EdgeNode *p = NULL, *q = NULL;
	
	for(i=0; i<G->vertexesNum; i++)
	{
		p = G->adjList[i].firstedge;
		while(p)
		{
			q = p->next;
			free(p);
			p = q;
		}
	}
	
}