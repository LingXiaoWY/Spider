/*###################################################################
# File Name: Spider_Download_HTML.c
# Author: Guo Weiye
# mail: guoweiyelai@qq.com
# Created Time: Mon 08 Aug 2022 09:11:52 AM CST
#=============================================================*/
#include<baike_spider.h>

int Spider_Download_HTML(int webfd,char *Request,url_t node,ssl_t *ssl)
{
	int statcode;
	char buffer[8192];
	char Response[4096];
	int recvlen;
	char *pos = NULL;
	int fd;
	bzero(Response,sizeof(Response));
	bzero(buffer,sizeof(buffer));
	SSL_write(ssl->ssl_socket,Request,strlen(Request));//发送请求
	printf("Spider Step [5] Send Resquest Success...\n");
	recvlen = SSL_read(ssl->ssl_socket,buffer,sizeof(buffer));
	if((pos = strstr(buffer,"\r\n\r\n"))==NULL){
		printf("strstr Call Failed,not Find Response Head!\n");
		exit(0);
	}
	snprintf(Response, pos - buffer + 4,"%s",buffer);//将响应头写入到Response
	printf("Spider step [6] Response Head:\n%s",Response);
	//创建文件保存网页源码
	if((fd = open(node.file_name,O_RDWR|O_CREAT,0664))==-1){
		perror("Spider_Download_HTML, Create HTML Call Failed\n");
		exit(0);
	}
	if((statcode = Spider_Get_StateCode(Response))==200){
		printf("Spider Step [*] Response Code %d\n",statcode);
		//将第一次读取的部分响应体，写入到文件
		write(fd,pos+4,recvlen - (pos - buffer + 4));
		//循环读写剩余内容
		while((recvlen = SSL_read(ssl->ssl_socket,buffer,sizeof(buffer)))>0){
			write(fd,buffer,recvlen);
			bzero(buffer,sizeof(buffer));
		}
		close(fd);
		close(webfd);
		printf("Spider_Step [7] Download HTML Success...\n");
		free(ssl);
		ssl = NULL;
		return 0;
	}
	else{
		printf("Spider step [*] Download Failed Statcode %d\n",statcode);
		close(webfd);
		free(ssl);
		ssl = NULL;
		return -1;
	}
}
