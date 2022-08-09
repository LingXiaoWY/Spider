/*###################################################################
# File Name: Spider_Remove_Duplication.c
# Author: Guo Weiye
# mail: guoweiyelai@qq.com
# Created Time: Mon 08 Aug 2022 10:56:29 AM CST
#=============================================================*/
#include<baike_spider.h>

int Spider_Remove_Duplication(container_t *E_ct,container_t *P_ct, const char *url){
	int flag;
	flag = E_ct->rear;
	while(flag%E_ct->max != E_ct->front){
		if((strncmp(E_ct->url_list[flag].origin_url,url,strlen(url)))==0)return 0;
		flag++;
	}
	flag = P_ct->rear;
	while(flag % P_ct->max != P_ct->front){
		if((strncmp(P_ct->url_list[flag].origin_url,url,strlen(url)))==0)return 0;
		flag++;
	}
	return 1;
}
