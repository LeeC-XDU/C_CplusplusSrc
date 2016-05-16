#include "GraphAdjList.h"
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>


/**********************************************
函数功能:创建邻接表无向图
参数1(输出参数):图指针
返回值:无
说明:用stdin的方式输入，这个函数实现本身就不定
所需标准库文件:stdio.h
作者: Lee.C
完成时间:2016-03-27
修改时间:
*************************************************/
void CreateUndirALGraph(GraphAdjList *G)
{
	EdgeNode *e;
	puts("Please input the number of vertexes and edges");
	scanf("%d,%d", &G->vertexesNum, &G->edgesNum);

	for(int i=0; i<G->vertexesNum; i++)
	{
		scanf(" %c", &G->adjList[i].data);
		G->adjList[i].firstedge = NULL;
	}

	for(int k=0, i=0, j=0, w=0; k<G->edgesNum; k++)
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


/**********************************************
函数功能:邻接表的Dijstra算法
参数1:图指针
参数2:源节点
参数3:前驱矩阵
参数4:权重矩阵
返回值:无
说明:
所需标准库文件:stdlib.h
作者: Lee.C
完成时间:2016-03-27
修改时间:
*************************************************/
void Dijkstra(const GraphAdjList *G, const int srcNode, int *priorArray, int *weightArray)
{
	EdgeNode *e = NULL;
	int min = 0, Index = 0;
	int *final = (int *)malloc(G->vertexesNum * sizeof(int));
	memset(final, 0, G->vertexesNum * sizeof(int));
//	memset(priorArray, 0, G->vertexesNum * sizeof(int));

	for(int i=0; i<G->vertexesNum; i++)
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

	for(int i=0; i<G->vertexesNum; i++)
	{
		min = INT_MAX/10;
		for(int j=0; j<G->vertexesNum; j++)
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