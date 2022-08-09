/*###################################################################
# File Name: Spider_Conainter_add.c
# Author: Guo Weiye
# mail: guoweiyelai@qq.com
# Created Time: Mon 08 Aug 2022 10:49:46 AM CST
#=============================================================*/
#include<baike_spider.h>

int Spider_Container_add(container_t *ct,url_t node)
{
	if(ct->cur==ct->max)return -1;
	ct->url_list[ct->front] = node;
	ct->front = (ct->front + 1) % ct->max;
	++ct->cur;
	return 0;
}
