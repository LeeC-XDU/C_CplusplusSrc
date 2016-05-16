/**********************************
模块功能:使用main函数参数，并提示用法
说明:
作者: Lee.C
完成时间:2016-03-22
修改时间:
**************************************/
int main(int argc, char *argv[])
{
	if(argc < 4)
	{
		printf("Usage: %s fileName1 fileName2 fileName3\n", argv[0]);
	}
}