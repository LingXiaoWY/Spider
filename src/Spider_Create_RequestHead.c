/*###################################################################
# File Name: Spider_Create_RequestHead.c
# Author: Guo Weiye
# mail: guoweiyelai@qq.com
# Created Time: Sat 06 Aug 2022 11:26:57 AM CST
#=============================================================*/
#include<baike_spider.h>

int Spider_Create_RequestHead(url_t* node, char* Request)
{
	bzero(Request,sizeof(4096));
	sprintf(Request,"GET %s HTTP/1.1\r\n"\
					"Accept:text/html,application/xhtml+xml;q=0.9,image/webp;q=0.8\r\n"\
					"User-Agent:Mozilla/5.0 (X11;linux x86_64)\r\n"\
					"Host:%s\r\n"\
					"Connection:close\r\n\r\n",node->origin_url,node->domain);
	printf("Spider Step[4] Create RequestHead Success:\n%s",Request);
	return 0;
}
