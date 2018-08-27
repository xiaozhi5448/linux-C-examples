#include"common.h"
int main(){
    int running = 1;
    struct msg_st msg_data;
    int msg_id;
    long int msg_type_receive = 1;

    if((msg_id = msgget((key_t)1234, 0666| IPC_CREAT)) == -1){
        perror("server:can't create message queue");
        exit(EXIT_FAILURE);
    }
    printf("get message queue with id:%d\n", msg_id);

    while(running){
        if(msgrcv(msg_id, (void*)&msg_data, BUF_SIZE, msg_type_receive, 0) == -1){
            perror("recv data from queue failed");
            exit(EXIT_FAILURE);
        }
        printf("you wrote:%s\n", msg_data.data);
        if(strncmp(msg_data.data, "end", 3) == 0){
            printf("exiting...\n");
            running = 0;

        }
    }
    msgctl(msg_id, IPC_RMID, 0);
    exit(EXIT_SUCCESS);
}
