/*###################################################################
# File Name: main.c
# Author: Guo Weiye
# mail: guoweiyelai@qq.com
# Created Time: Fri 05 Aug 2022 11:35:46 AM CST
#=============================================================*/
#include<baike_spider.h>

int main(void)
{
	//种子
	char* tmp = "https://baike.baidu.com/item/%E5%8E%9F%E7%A5%9E/23583622?fr=aladdin";
	Spider_StartUp(tmp);
	return 0;
}
