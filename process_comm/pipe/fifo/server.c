#include"client.h"
#include<ctype.h>
int main(){
    int serv_fifo_fd, cli_fifo_fd;
    struct data_to_pass_st data;
    char buf[BUF_SIZE];
    char cli_fifo_name[50];
    int mode_serv;
    int mode_cli;
    serv_fifo_fd = mkfifo(SERVER_FIFO_NAME, 0777);
    if(serv_fifo_fd == -1){
        perror("create server fifo failed!");
        exit(EXIT_FAILURE);
    }
    puts("create server fifo");

    mode_serv = O_RDONLY;
    serv_fifo_fd = open(SERVER_FIFO_NAME, mode_serv);
    if(serv_fifo_fd == -1){
        perror("open server fifo failed!");
        exit(EXIT_FAILURE);
    }
    puts("open server fifo");

    sleep(1);

    printf("read to receive data!\n");
    int read_bytes;
    char* tmp_ptr;
    do{
        read_bytes = read(serv_fifo_fd, &data, sizeof(data));
        if(read_bytes > 0){
            tmp_ptr = data.some_data;
            while(*tmp_ptr){
                *tmp_ptr = toupper(*tmp_ptr);
                tmp_ptr++;
            }
            sprintf(cli_fifo_name, CLIENT_FIFO_NAME, data.pid);
            cli_fifo_fd = open(cli_fifo_name, O_WRONLY);
            if(cli_fifo_fd != -1){
                write(cli_fifo_fd, &data, sizeof(data));
                close(cli_fifo_fd);
            }
        }
    }while(read_bytes > 0);
    close(serv_fifo_fd);
    unlink(SERVER_FIFO_NAME);
    exit(EXIT_SUCCESS);
}
