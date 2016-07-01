#ifndef _BITVECTOR__
#define _BITVECTOR__

class BitVector
{
	//位的个数
	static const int N = 100;
	//依赖机器，机器中每个int变量的位数
	static const int BITPERWORD = 32;
	
	//2^5
	static const int SHIFT = 5;
	// 1111
	static const int MASK = 0x1F;

public:
	BitVector();
	void set(int i);
	void clr(int i);
	int test(int i);


private:
	/***********************************************************
	 * 存储N个位的数组，
	 * 《编程珠玑》原书中是N/BITPERWORD + 1，
	 * 如果N恰为BITPERWORD的倍数，那么又要浪费一个int的空间了，
	 * N取0时，仍会浪费一个int的空间，
	 * N非0非BITPERWORD的倍数时，最多是最后一个int不完全利用而已
	***********************************************************/
	int array[(N-1)/BITPERWORD + 1];
	
};

#endif
