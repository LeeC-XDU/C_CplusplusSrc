/**********************************
��������:��������ǰ��ݹ鴴��
����1(Output):������ָ��
����ֵ:��
˵��:
����: Lee.C
���ʱ��:2016-05-01
**************************************/
void CreateBiTree(BiTree *T)
{
	TElemType ch;
	scanf("%c", &ch);
	if(ch == '#')
		*T = NULL;
	//�ϱߵ�һ��ɸ�Ϊ { *T = NULL; return; } �����ʡ������� else �ؼ���
	else
	{
		*T = (BiTree)malloc(sizeof(BiTree));
		
		if(!*T)
			exit(EXIT_FAILURE);

		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}