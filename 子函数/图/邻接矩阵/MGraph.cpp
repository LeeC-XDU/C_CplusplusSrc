#include "MGraph.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>


/**********************************************
函数功能:创建无向图
参数1(输出参数):图指针
返回值:无
说明:用stdin的方式输入，这个函数实现本身就不定
所需标准库文件:stdio.h
作者: Lee.C
完成时间:2016-03-26
修改时间:
*************************************************/
void CreateUndirMGraph(MGraph *G)
{
	printf("Please input the number of vertex and edge:(x,x)\n");
	scanf("%d,%d", &G->vertexesNum, &G->edgesNum);
	
	for(int i=0; i<G->vertexesNum; i++)
		scanf(" %c",&G->vexs[i]);

	for(int i=0; i<G->vertexesNum; i++)
		for(int j=0; j<G->vertexesNum; j++)
			//这个地方切不能直接用INT_MAX,因为下边有加法比较，一加就变为负数，成最小值了
			G->arc[i][j] = INT_MAX/10;

	for(int k=0; k<G->edgesNum; k++)
	{
		int i, j, w;
		printf("input (i,j) index-i,j and the weight w:\n");
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
所需标准库文件:stdio.h
作者: Lee.C
完成时间:2016-03-26
修改时间:
*************************************************/
void CreateMGraph(MGraph *G)
{
	printf("Please input the number of vertex and edge:\n");
	scanf("%d,%d", &G->vertexesNum, &G->edgesNum);
	
	printf("Please input vertexes number\n");
	for(int i=0; i<G->vertexesNum; i++)
		scanf(" %c",&G->vexs[i]);

	for(int i=0; i<G->vertexesNum; i++)
		for(int j=0; j<G->vertexesNum; i++)
			//这个地方切不能直接用INT_MAX,因为下边有加法比较，一加就变为负数，成最小值了
			G->arc[i][j] = INT_MAX/10;

	for(int k=0; k<G->edgesNum; k++)
	{
		int i, j, w;
		printf("input (i,j) index-i,j and the weight w:\n");
		scanf("%d,%d,%d", &i, &j, &w);
		G->arc[i][j] = w;
	}
}


/**********************************************
函数功能:邻接矩阵的Dijstra算法
参数1:图指针
参数2:源节点
参数3:前驱矩阵
参数4:权重矩阵
返回值:无
说明:
所需标准库文件:
作者: Lee.C
完成时间:2016-03-26
修改时间:2016-03-27
*************************************************/
void Dijkstra(const MGraph *G, const int srcNode, int *priorArray, int *weightArray)
{
	int min = 0, Index = 0;
	int *final = (int*)malloc(G->vertexesNum * sizeof(int));
	memset(final, 0, G->vertexesNum * sizeof(int));
//	memset(priorArray, 0, G->vertexesNum * sizeof(int));
	for(int i=0; i<G->vertexesNum; i++)
	{
		weightArray[i] = G->arc[srcNode][i];
		if(weightArray[i] < INT_MAX/10)
			priorArray[i] = srcNode;
		else
			priorArray[i] = -1;
	}

	weightArray[srcNode] = 0;
	final[srcNode] = 1;

	for(int i=1; i<G->vertexesNum; i++)
	{
		//这个地方切不能直接用INT_MAX,因为下边有加法比较，一加就变为负数，成最小值了
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
		
		for(int j=0; j<G->vertexesNum; j++)
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
