#include<stdio.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
int main(){
    int server_fd, client_fd;
    int server_addr_len, client_addr_len;
    struct sockaddr_in server_addr, client_addr;
    server_addr_len = sizeof(server_addr);
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = 8000;
    bind(server_fd, (struct sockaddr *)&server_addr, server_addr_len);
    listen(server_fd, 5);
    while(1){
        printf("服务器等待消息！\n");
        char ch;
        client_addr_len = sizeof(client_addr);
        client_fd = accept(server_fd, 
            (struct sockaddr *) &client_addr, 
            (socklen_t *)&client_addr_len);
        read(client_fd, &ch, 1);
        ch++;
        write(client_fd, &ch, 1);
        close(client_fd);
    }
    return 0;
}