#include"client.h"
#include<ctype.h>
int main(){
    struct data_to_pass_st data;
    char buf[BUF_SIZE];
    char cli_fifo_name[50];
    int serv_fifo_fd, cli_fifo_fd;


    serv_fifo_fd = open(SERVER_FIFO_NAME, O_WRONLY);
    puts("client : open server fifo");
    if(serv_fifo_fd == -1){
        perror("open server fifo failed");
        exit(EXIT_FAILURE);
    }

    data.pid = getpid();
    sprintf(cli_fifo_name, CLIENT_FIFO_NAME, data.pid);
    mkfifo(cli_fifo_name, 0777);
    puts("client : create client fifo");

    int read_bytes;

    sprintf(data.some_data, "data from %d", data.pid);
    printf("%d sent: %s, ", data.pid, data.some_data);
    write(serv_fifo_fd, &data, sizeof(data));

    cli_fifo_fd = open(cli_fifo_name, O_RDONLY);
    if(cli_fifo_fd == -1){
        perror("open client fifo failed");
        exit(EXIT_FAILURE);
    }
    if(cli_fifo_fd != -1){
        read_bytes = read(cli_fifo_fd, &data, sizeof(data));
        printf("received:%s\n", data.some_data);
    }else{
        perror("open client fifo to read failed");
        exit(EXIT_FAILURE);
    }

    close(cli_fifo_fd);
    close(serv_fifo_fd);
    exit(EXIT_SUCCESS);
}
