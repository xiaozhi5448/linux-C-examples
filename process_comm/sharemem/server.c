#include"common.h"
int main(){
    int running = 1;
    void *share_mem;
    struct share_mem_st *data;
    int shmid;
    char buf[50];

    shmid = shmget((key_t)1234, sizeof(struct share_mem_st), 0666 | IPC_CREAT);
    if(shmid == -1){
        perror("create share_memory failed");
        exit(EXIT_FAILURE);
    }

    share_mem = shmat(shmid, (void*)0, 0);
    if(share_mem == (void*)-1){
        perror("attach the mem failed");
        exit(EXIT_FAILURE);
    }
    printf("share memory attached at %X\n", share_mem);
    
    data = (struct share_mem_st*)share_mem;
    data->controller = 0;
    while(running){
        while(data->controller == 1){
            printf("wait for client...\n");
            sleep(1);
        }
        puts("type the message:");
        //fgets(buf, 50, stdin);
        memset(buf, '\0', 50);
        scanf("%s", buf);
        memset(data->message, '\0', TEXT_SIZE);
        strncpy(data->message, buf, strlen(buf));
        data->controller = 1;
        if(strncmp(buf, "end", 3) == 0){
            running = 0;
        }
        
    }

    printf("exiting...\n");
    if(shmdt(share_mem) == -1){
        perror("error between unttach the share_meme");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
