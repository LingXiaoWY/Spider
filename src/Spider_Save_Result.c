/*###################################################################
# File Name: Spider_Save_Result.c
# Author: Guo Weiye
# mail: guoweiyelai@qq.com
# Created Time: Mon 08 Aug 2022 11:20:07 AM CST
#=============================================================*/
#include<baike_spider.h>

int Spider_Save_Result(const char* h1,const char *description,const char *link)
{
	char result[20000];
	bzero(result,sizeof(result));

	//头部信息，创建文件后写入一次，html语言头
	const char *start = "<html>\r\n<head>\r\n<meta http-equiv=\"Content-Type\" content=\"text/html;charset=utf-8\">\r\n<head>\r\n<table border=\"1\" cellspacing=\"0\" cellpadding=\"0\" width=\"1920\">\r\n<caption>词条抓取数据集</caption>\r\n<tr><th>百科词条标题</th><th>百科词条描述</th><th>百科词条超链接</th></tr>\r\n";

	const char *end = "</table></html>\r\n";

	if(result_num == 0){
		write(result_fd,start,strlen(start));//第一次写入html头部信息，仅写一次
		return 0;
	}
	//将抓取的数据写入到文件中
<<<<<<< HEAD
	sprintf(result,"<tr id=%d><td name=\"h1\">%s<td name=\"description\">%s</td><td name=\"link\"><a href=\"%s\">%s</a></td></tr>\r\n",result_num,h1,description,link,link);
=======
	sprintf(result,"<tr id=%d><td name=\"h1\">%s<td name=\"description\"%s</td><td name=\"link\"><a href=\"%s\">%s</a></td></tr>\r\n",result_num,h1,description,link,link);
>>>>>>> first commit
	write(result_fd,result,strlen(result));
	if(result_num == RESULT_MAX){
		write(result_fd,end,strlen(end));
		close(result_fd);
	}
	return 0;
}
