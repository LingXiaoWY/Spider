/*###################################################################
# File Name: Spider_Net_Init.c
# Author: Guo Weiye
# mail: guoweiyelai@qq.com
# Created Time: Fri 05 Aug 2022 10:50:08 AM CST
#=============================================================*/
#include<baike_spider.h>

int Spider_Net_Init()
{
	/*struct sockaddr_in myaddr;
	myaddr.sin_family = AF_INET;
	myaddr.sin_port = htons(8000);
	myaddr.sin_addr.s_addr = htonl(INADDR_ANY);*/
	int mysock;
	mysock = socket(AF_INET,SOCK_STREAM,0);
	printf("Spider Step [1] Net init Success, Sockfd %d\n",mysock);
	//bind(mysock,(struct sockaddr*)&myaddr,sizeof(myaddr));
	return mysock;
}
