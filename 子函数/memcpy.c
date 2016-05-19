/**********************************
函数功能:内存拷贝函数
参数(Output)1:目标地址
参数2:原地址
参数3:拷贝字节数
返回值:目标地址
说明:本函数与C库中的函数一样，没有考虑内存重叠问题
作者: Lee.C
完成时间:2016-05-19
**************************************/
void *memcpy(void *dst, const void *src, size_t count)
{
	assert(dst && src);

	void *ret = dst;

	while(count--)
	{
		*(char *)dst = *(char *)src;
		dst = (char *)dst + 1;
		src = (char *)src + 1;
	}

	return ret;
}

