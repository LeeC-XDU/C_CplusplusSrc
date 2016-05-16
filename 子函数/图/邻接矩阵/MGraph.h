#ifndef MGRAPH_H_
#define MGRAPH_H_

//定义节点类型
typedef char VertexType;
//定义边上的东西，可能是权重，也可以有其他，或者一个结构体，内包含很多东西
typedef int EdgeType;

//定义最大节点数
#define MAXVEXNUM 100


typedef struct
{
	VertexType vexs[MAXVEXNUM];				//顶点表
	EdgeType arc[MAXVEXNUM][MAXVEXNUM];		//邻接矩阵
	int vertexesNum, edgesNum;				//点数与边数
}MGraph;

void CreateUndirMGraph(MGraph *G);
void CreateMGraph(MGraph *G);
void Dijkstra(const MGraph *G, const int srcNode, int *priorArray, int *weightArray);



#endif
