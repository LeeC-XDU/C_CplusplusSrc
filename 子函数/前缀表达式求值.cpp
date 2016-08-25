/*********************************************
函数功能:计算前缀表达式的值，并仍以字符串输出
参数1(Output):结果字符串
参数2:前缀表达式(字符串数组的形式)
返回值:结果字符串
说明:以后缀表达式求值为基础，部分注意事项参见后缀表达式求值，
     反转了字符串，把减和除的程序稍作了改动
头文件:<stack>
       <string>
	   <vector>
	   <cstdlib>
	   <algorithm>
作者: Lee.C
完成时间:2016-07-10
**************************************************/
const std::string &calcValue2(std::string &dstString, std::vector<std::string> &express)
{
	using std::stack;
	using std::vector;
	using std::string;

	double num = 0.0;
	int i = 2;
	char numStr[100];
	memset(numStr, 0, sizeof(numStr));
	stack<string> st;

	reverse(express.begin(), express.end());
	
	st.push(express[0]);
	st.push(express[1]);

	while(!st.empty())
	{
		switch(express[i][0])
		{
		case '+':
			num = atof(st.top().c_str());
			st.pop();
			num += atof(st.top().c_str());
			st.pop();
			sprintf(numStr, "%f", num);
			st.push(string(numStr));
			break;
		case '-':
			num = atof(st.top().c_str());
			st.pop();
			num -= atof(st.top().c_str());
			st.pop();
			sprintf(numStr, "%f", num);
			st.push(string(numStr));
			break;
		case '*':
			num = atof(st.top().c_str());
			st.pop();
			num *= atof(st.top().c_str());
			st.pop();
			sprintf(numStr, "%f", num);
			st.push(string(numStr));
			break;
		case '/':
			num = atof(st.top().c_str());
			st.pop();
			num /= atof(st.top().c_str());
			st.pop();
			sprintf(numStr, "%f", num);
			st.push(string(numStr));
			break;
		default:
			st.push(express[i]);
			break;
		}
		if(++i == express.size())
		{
			dstString = st.top();
			st.pop();
		}
	}

	return dstString;
}