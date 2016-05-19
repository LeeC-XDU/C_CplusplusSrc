/**********************************
函数功能:内存拷贝函数
参数1(Output):目标地址
参数2:原地址
参数3:拷贝字节数
返回值:目标地址
说明:与C库一样，本函数考虑了内存重叠问题，
     当内存有重叠时，从高地址开始复制
作者: Lee.C
完成时间:
修改时间:
修改说明:
**************************************/
void *memmove(void *dst, const void *src, size_t count)
{
	assert(dst && src);

	void *ret = dst;

	//这里右操作数类型转换了，所以左操作数也应做类型转换
	if(dst <= src || (char *)dst >= (char *)src + count)
	{
		//内存无重叠，从低地址开始复制
		while(count--)
		{
			*(char *)dst = *(char *)src;
			dst = (char *)dst + 1;
			src = (char *)src + 1;
		}
	}
	else
	{
		//内存有重叠，从高地址开始复制
		src = (char *)src + count - 1;
		dst = (char *)dst + count - 1;

		while(count--)
		{
			*(char *)dst = *(char *)src;
			dst = (char *)dst - 1;
			src = (char *)src - 1;
		}
	}

	return ret;
}
