#include"common.h"
int main(){
    int shmid;
    struct share_mem_st* data;
    void* share_mem;
    int running = 1;
    char buf[50];

    if((shmid = shmget((key_t)1234, sizeof(struct share_mem_st), 0666 | IPC_CREAT)) == -1){
        perror("create share mem failed");
        exit(EXIT_FAILURE);
    }

    if((share_mem = shmat(shmid, (void*)0, 0)) == (void*)-1){
        perror("attach the share mem failed");
        exit(EXIT_FAILURE);
    }
    printf("share mem attach at %X\n", share_mem);
    data = (struct share_mem_st*)share_mem;
    data->controller = 1;
    while(running){
        if(data->controller == 1){
            strncpy(buf, data->message, strlen(data->message));
            printf("message:%s\n", buf);
            sleep(2);
            data->controller = 0;
            if(strncmp(buf, "end", 3) == 0){
                running = 0;
            }
        }else{
            printf("waiting for server...\n");
            sleep(1);
        }
    }
    if(shmdt(share_mem) == -1){
        perror("unattach the share mem failed");
        exit(EXIT_FAILURE);
    }
    if(shmctl(shmid, IPC_RMID, 0) == -1){
        perror("error with release the share mem");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);

}
