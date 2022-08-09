/*###################################################################
# File Name: Spider_Get_StatCode.c
# Author: Guo Weiye
# mail: guoweiyelai@qq.com
# Created Time: Mon 08 Aug 2022 10:07:24 AM CST
#=============================================================*/
#include<baike_spider.h>

int Spider_Get_StateCode(const char* Response)
{
	int statcode;
	char Strcode[128];
	bzero(Strcode,128);
	regex_t reg;
	regmatch_t match[2];
	regcomp(&reg,"HTTP/1.1 \\([^\r\n]\\+\\?\\)\r\n",0);
	if((regexec(&reg,Response,2,match,0))==0){
		snprintf(Strcode, match[1].rm_eo - match[1].rm_so + 1,"%s",Response+match[1].rm_so);
		sscanf(Strcode,"%d ",&statcode);
		regfree(&reg);
		return statcode;
	}
	regfree(&reg);
	return statcode;
}
