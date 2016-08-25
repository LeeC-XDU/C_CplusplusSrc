/*********************************************
函数功能:计算后缀表达式的值，并仍以字符串输出
参数1(Output):结果字符串
参数2:后缀表达式(字符串数组的形式)
返回值:结果字符串
说明:之所以使用字符串数组的形式保存后缀表达式，
     因为每个数字可能多位，也可能是小数。
	 返回的是第一个形参的常引用，为的是形成链式操作
头文件:<stack>
       <string>
	   <vector>
	   <cstdlib>
作者: Lee.C
完成时间:2016-07-10
**************************************************/
const std::string &calcValue(std::string &dstString, const std::vector<std::string> &express)
{
	using std::stack;
	using std::vector;
	using std::string;

	double num = 0.0;
	int i = 2;
	char numStr[100];
	memset(numStr, 0, sizeof(numStr));

	stack<string> st;
	
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
			num = atof(st.top().c_str()) - num;
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
			num = atof(st.top().c_str())/num;
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