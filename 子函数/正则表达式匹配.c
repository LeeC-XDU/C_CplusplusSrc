/**********************************
函数功能:正则表达式匹配
参数1:待匹配字符串
参数2:模式串
返回值:匹配返回TRUE，不匹配返回FALSE
说明:该程序只能用于 . 和 * 的情况；
. 指任意一个字符，*指前边一个字符出现任意次（包括0次）
头文件:无
作者: Lee.C
完成时间:2016-08-20
**************************************/
Status match(char *str, char *pattern)
{
	if(!str || !pattern)
		return FALSE;

	return match_aux(str, pattern);
}

/**********************************
函数功能:正则表达式匹配主函数，递归版
参数1:待匹配字符串
参数2:模式串
返回值:匹配返回TRUE，不匹配返回FALSE
说明:该程序只能用于 . 和 * 的情况；
. 指任意一个字符，*指前边一个字符出现任意次（包括0次）
头文件:无
作者: Lee.C
完成时间:2016-08-20
**************************************/
Status match_aux(char *str, char *pattern)
{
	if(*str == '\0' && *pattern == '\0')
		return TRUE;

	if(*str != '\0' && *pattern == '\0')
		return FALSE;

	if(*(pattern+1) == '*')
	{
		if(*pattern == *str || (*pattern == '.' && *str != '\0'))
			return match_aux(str+1, pattern+2) || match_aux(str+1, pattern) || match_aux(str, pattern+2);
		else
			return match_aux(str, pattern+2);
	}

	if(*str == *pattern || (*pattern == '.' && *str != '\0'))
		return match_aux(str+1, pattern+1);

	return FALSE;
}