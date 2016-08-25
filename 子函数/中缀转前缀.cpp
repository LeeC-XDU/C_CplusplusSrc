/*************************************************************
函数功能:中缀表达式转前缀表达式
参数1(Output):前缀缀表达式的字符串数组的形式
参数2:字符串形式的中缀表达式
返回值:无
说明:详细说明参加笔记
     必须将结果放到另一个栈中，不断出栈，出入字符串数组中；
	 由于是从右向左读，所以i是--操作，且循环结束条件又有等于0，
	 i一定会减到-1的，所以请使用int类型!!!
	 由于是从右向左读，字符串最初拼接好是逆序的，调用函数改变次序。
头文件:<vector>
       <stack>
	   <string>
	   <algorithm>
作者: Lee.C
完成时间:2016-07-12
*****************************************************************/
const bool Priority[][6] = 
{   //表达式中符号
	//  +      -      *      /     )     (      //栈顶元素符号
	{ true,  true,  true,  true, true, false }, // +
	{ true,  true,  true,  true, true, false }, // -
	{ false, false, true,  true, true, false }, // *
	{ false, false, true,  true, true, false }, // /
	{ true,  true,  true,  true, true, false }, // )
};   //右下角的情况是不可能存在的

void nifix2Prefix(std::vector<std::string> &prefixExpress, const std::string &nifixExpress)
{
	using std::string;
	using std::vector;
	using std::stack;

	stack<char> OPTR;
	stack<string> OPND;
	string numString;
	int i=nifixExpress.length()-1;

	//i又是--操作，且这里又是等于0，i一定会小于0的
	while(i>=0)
	{
		if(IsOperator(nifixExpress[i]))
		{
			if(OPTR.empty() || IsPriorStackTop(nifixExpress[i], OPTR.top()))
			{
				OPTR.push(nifixExpress[i]);
			}
			else
			{
				//表达式中运算符比栈顶元素优先级低，可分为两种出栈情况
				//第一是表达式中运算符确实低或同级情况下的低
				if(nifixExpress[i] != '(')
				{
					OPND.push(string(1, OPTR.top()));
					OPTR.pop();
					continue;
				}
				//第二是表达式中运算符是 ")"
				else
				{
					while(OPTR.top() != ')')
					{
						OPND.push(string(1, OPTR.top()));
						OPTR.pop();
					}
					OPTR.pop();
				}
			}
			i--;
		}
		else
		{
			while(!IsOperator(nifixExpress[i]) && i>0)
				numString += nifixExpress[i--];

			reverse(numString.begin(), numString.end());
			OPND.push(numString);
			numString.clear();
		}
	}

	//将OPTP中剩余的元素出栈
	while(!OPTR.empty())
	{
		OPND.push(string(1, OPTR.top()));
		OPTR.pop();
	}

	//循环弹出放入
	while(!OPND.empty())
	{
		prefixExpress.push_back(OPND.top());
		OPND.pop();
	}
}

/**********************************
函数功能:判断符号是否是运算符
参数1:待判断符号
返回值:是运算符返回真，否则返回假
说明:
头文件:无
作者: Lee.C
完成时间:2016-07-12
**************************************/
static bool IsOperator(char c)
{
	if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')')
		return true;
	else
		return false;
}

/**********************************
函数功能:查表判断此时是压栈还是出栈
参数1:表达式中符号
参数2:栈顶元素符号
返回值:需要入栈返回真，否则返回假
说明:第一个元素与第二个元素的实参以及
     函数体的实现要与查询表一致
头文件:无
作者: Lee.C
完成时间:2016-07-12
**************************************/
static bool IsPriorStackTop(char exOper, char StackTopOper)
{
	return Priority[Convert(StackTopOper)][Convert(exOper)];
}

/**********************************
函数功能:将符号转为查询表下标
参数1:待转换符号
返回值:某符号对应的查询表的下标
说明:由于查询表变了，这里也与中缀转后缀发生了一定变化
头文件:无
作者: Lee.C
完成时间:2016-07-12
**************************************/
static int Convert(char sign)
{
	if(sign=='+')
		return 0;
	else if(sign=='-')
		return 1;
	else if(sign=='*')
		return 2;
	else if(sign=='/')
		return 3;
	else if(sign=='(')
		return 4;
	else
		return 5;
}