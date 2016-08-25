/**********************************
函数功能:求一个滑动窗口中的最大值
参数1:数组
参数2:滑动窗口的大小
返回值:滑动窗口中的最大值组成数组
说明:《剑指offer》P294中题目
作者: Lee.C
完成时间:2016-08-21
**************************************/
vector<int> maxInWindow(const vector<int>& num, unsigned int size)
{
	vector<int> maxValue;

	if(num.size() < size && size < 1)
		throw new std::exception("Data error");

	deque<int> indexDeq;

	for(unsigned int i=0; i<size; i++)
	{
		while(!indexDeq.empty() && num[i] >= num[indexDeq.back()])
			indexDeq.pop_back();

		indexDeq.push_back(i);
	}

	for(unsigned int i=size; i<num.size(); i++)
	{
		maxValue.push_back(num[indexDeq.front()]);

		while(!indexDeq.empty() && num[i]>=num[indexDeq.back()])
			indexDeq.pop_back();
		//队首元素若在窗口中，则加上窗口长度应该大于i，小于等于就说明已经不在窗口中了
		if(!indexDeq.empty() && indexDeq.front()+size <= i)
			indexDeq.pop_front();

		indexDeq.push_back(i);
	}

	maxValue.push_back((num[indexDeq.front()]));

	return maxValue;
}