#ifndef MGRAPH_H_
#define MGRAPH_H_

//����ڵ�����
typedef char VertexType;
//������ϵĶ�����������Ȩ�أ�Ҳ����������������һ���ṹ�壬�ڰ����ܶණ��
typedef int EdgeType;

//�������ڵ���
#define MAXVEXNUM 100


typedef struct
{
	VertexType vexs[MAXVEXNUM];				//�����
	EdgeType arc[MAXVEXNUM][MAXVEXNUM];		//�ڽӾ���
	int vertexesNum, edgesNum;				//���������
}MGraph;

void CreateUndirMGraph(MGraph *G);
void CreateMGraph(MGraph *G);
void Dijkstra(const MGraph *G, const int srcNode, int *priorArray, int *weightArray);



#endif
