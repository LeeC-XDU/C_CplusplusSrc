#ifndef GRAPHADJLIST__
#define GRAPHADJLIST__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _STATUS__
#define _STATUS__
typedef enum { FALSE, TRUE } Status;
#endif

//定义最大节点数
#define MAXVEXNUM 100

//定义节点类型
typedef char VertexType;
//定义边上的东西，可能是权重，也可以有其他，或者一个结构体，内包含很多东西
typedef int EdgeType;


//边表结点
typedef struct EdgeNode
{
	int adjvex;					//邻接点域，存储该点在顶点表数组中的下标
	EdgeType weight;			//用于存储边信息，可以是一个结构体，保存边的权重，编号等
	struct EdgeNode *next;
}EdgeNode;


//顶点表节点
typedef struct VertexNode
{
	VertexType data;			//顶点域，存储顶点信息，编号，是否访问标识等
	EdgeNode *firstedge;
}VertexNode, AdjList[MAXVEXNUM];

typedef struct
{
	AdjList adjList;
	int vertexesNum, edgesNum;
}GraphAdjList;

void CreateUndirALGraph(GraphAdjList *G);
void CreateALGraph(GraphAdjList *G);
void DFSTraverse(GraphAdjList *G, void (*pfun)(VertexType *vex));
void Dijkstra(const GraphAdjList *G, int srcNode, int *priorArray, int *weightArray);
void DestoryALGraph(GraphAdjList *G);

#ifdef __cplusplus
}
#endif


#endif
