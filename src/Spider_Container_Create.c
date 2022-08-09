/*###################################################################
# File Name: Spider_Container_Create.c
# Author: Guo Weiye
# mail: guoweiyelai@qq.com
# Created Time: Mon 08 Aug 2022 10:45:33 AM CST
#=============================================================*/
#include<baike_spider.h>

container_t *Spider_Container_Create(int tmax)
{
	container_t *ct = (container_t*)malloc(sizeof(container_t));
	if(ct == NULL){
		perror("Spider_Container_Create, Malloc Container Failed");
		exit(0);
	}
	if((ct->url_list = (url_t *)malloc(sizeof(url_t)*tmax))==NULL){
		perror("Spider_Container_Create, Malloc URL_LIST Failed");
		exit(0);
	}
	ct->front = 0;
	ct->rear = 0;
	ct->max = tmax;
	ct->cur = 0;
	return ct;
}
