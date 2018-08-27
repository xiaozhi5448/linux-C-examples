#include"common.h"
int main(){
    int running = 1;
    struct msg_st msg_data;
    long int msg_type_receive = 0;
    char buf[BUF_SIZE];
    int msg_id;

    if((msg_id = msgget((key_t)1234, 0666 | IPC_CREAT)) == -1){
        perror("client:get message queue failed");
        exit(EXIT_FAILURE);
    }
    printf("get message queue with id:%d\n", msg_id);
    int length = 0;
    while(running){
        memset(msg_data.data, '\0', BUF_SIZE);
        printf("input some text:");
        fgets(buf, BUFSIZ, stdin);
        length = strlen(buf);
        msg_data.msg_type = 1;
        strncpy(msg_data.data, buf, length -1);
        msg_data.data[length] = '\0';
        if(msgsnd(msg_id, (void*)&msg_data, BUF_SIZE, 0) == -1){
            perror("error with send data");
            exit(EXIT_FAILURE);
        }
        printf("you send:%s\n", msg_data.data);
        if(strncmp(buf, "end", 3) == 0){
            printf("exiting...\n");
            running = 0;
        }
    }

    exit(EXIT_SUCCESS);

}
