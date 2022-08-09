/*###################################################################
# File Name: Spider_Openssl_Create.c
# Author: Guo Weiye
# mail: guoweiyelai@qq.com
# Created Time: Sat 06 Aug 2022 10:18:38 AM CST
#=============================================================*/
#include<baike_spider.h>

ssl_t *Spider_Openssl_Create(int webfd)
{
	ssl_t *ssl = NULL;
	if((ssl = (ssl_t*)malloc(sizeof(ssl_t)))==NULL){
		perror("Spider_Openssl_Create >> malloc ssl Failed");
		exit(0);
	}
	SSL_load_error_strings();//加载openssl库中的错误处理函数和信息
	SSL_library_init();//初始化openssl库函数
	OpenSSL_add_ssl_algorithms();//初始化加密散列
	ssl->ssl_ctx = SSL_CTX_new(SSLv23_method());//选择对应的SSL版本信息，产生CTX上下文信息
	ssl->ssl_socket = SSL_new(ssl->ssl_ctx);//使用上下文生成安全套接字
	SSL_set_fd(ssl->ssl_socket,webfd);//使用webfd对ssl_socket进行通信设置，后续使用ssl_socket与服务器进行https认证
	SSL_connect(ssl->ssl_socket);//完成认证过程
	//SSL_read 读取并解密，SSL_write(ssl_socket,buffer,strlen(buffer))加密并发送
	printf("Spider Step [*] Openssl Create Success...\n");
	
	//安装库文件和说明文档
	//sudo apt-get install libssl-dev
	//sudo apt-get install libssl-doc
	return ssl;
}
