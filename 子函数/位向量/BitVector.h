#ifndef _BITVECTOR__
#define _BITVECTOR__

class BitVector
{
	//位的个数
	const int N;

	//依赖机器，机器中每个int变量的位数
	static const int BITPERWORD = 32;
	// 2^5
	static const int SHIFT = 5;
	// 1111
	static const int MASK = 0x1F;

public:
	explicit BitVector(int num);
	void set(int i);
	void clr(int i);
	int test(int i);

	~BitVector();

private:
	BitVector(const BitVector &);
	BitVector &operator=(const BitVector &);

private:
	int *array;

};

#endif
