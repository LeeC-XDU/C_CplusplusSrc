/**********************************
函数功能:二叉树的前序递归创建
参数1(Output):二叉树指针
返回值:无
说明:
作者: Lee.C
完成时间:2016-05-01
**************************************/
void CreateBiTree(BiTree *T)
{
	TElemType ch;
	scanf("%c", &ch);
	if(ch == '#')
		*T = NULL;
	//上边的一句可改为 { *T = NULL; return; } 则可以省略下面的 else 关键字
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