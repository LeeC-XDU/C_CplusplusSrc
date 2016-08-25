/**********************************
函数功能:二叉树层序遍历
参数1:待遍历二叉树
返回值:无
说明:利用了STL中的队列
头文件:<queue>
作者: Lee.C
完成时间:2016-08-21
**************************************/
void LevelOrder(BiTree pRoot)
{
    std::queue<BiTNode*> nodes;
    BiTNode *curNode = NULL;

    nodes.push(pRoot);
    while(!nodes.empty())
    {
        curNode = nodes.front();

        //do something
        std::cout << curNode->data << std::endl;

        if(curNode->lchild)
            nodes.push(curNode->lchild);
        if(curNode->rchild)
            nodes.push(curNode->rchild);

        nodes.pop();
    }
}