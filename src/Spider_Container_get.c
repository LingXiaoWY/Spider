/*###################################################################
# File Name: Spider_Conainter_add.c
# Author: Guo Weiye
# mail: guoweiyelai@qq.com
# Created Time: Mon 08 Aug 2022 10:49:46 AM CST
#=============================================================*/
#include<baike_spider.h>

int Spider_Container_get(container_t *ct,url_t* node)
{
	if(ct->cur==0)return -1;
	*node = ct->url_list[ct->rear];
	ct->rear = (ct->rear + 1) % ct->max;
	--ct->cur;
	return 0;
}
