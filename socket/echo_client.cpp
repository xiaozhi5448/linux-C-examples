#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
int main(){
    struct sockaddr_in server_addr;
    int server_addr_len = sizeof(sockaddr_in);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = 8000;
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    char ch = 'A';
    int res;
    
   
    if((res = connect(socket_fd, (sockaddr*) &server_addr, (socklen_t) server_addr_len)) == -1){
        perror("连接目的地址出错！");
        exit(1);
    }
    printf("请输入字符：\n");
    scanf("%c", &ch);
    
    write(socket_fd, &ch, 1);
    read(socket_fd, &ch, 1);
    printf("%c\n", ch);
    close(socket_fd);
    return 0;
}