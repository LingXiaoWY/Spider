/*###################################################################
# File Name: Spider_Connect_Web.c
# Author: Guo Weiye
# mail: guoweiyelai@qq.com
# Created Time: Sat 06 Aug 2022 09:15:03 AM CST
#=============================================================*/
#include<baike_spider.h>

int Spider_Connect_Web(int sockfd,url_t *node)
{
	struct sockaddr_in webAddr;
	bzero(&webAddr,sizeof(webAddr));
	webAddr.sin_family = AF_INET;
	webAddr.sin_port = htons(node->port);
	inet_pton(AF_INET,node->ip,&webAddr.sin_addr.s_addr);
	if((connect(sockfd,(struct sockaddr*)&webAddr,sizeof(webAddr)))==-1){
		perror("Spider_Connect_Web >> Connect Call Failed");
		return -1;
	}
	printf("Spider Step [3] Connection Web Success...\n");
	return 0;
}
