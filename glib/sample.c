#include<stdio.h>
#include<glib-2.0/glib.h>
typedef struct{
    GMainLoop* loop;
    gint max;
} Arg;
GMutex *mutex = NULL;
static gboolean t1_end = FALSE;
static gboolean t2_end = FALSE;

void thread_func1(Arg* arg){
    for(int i = 0; i < arg->max; i++){
        if(g_mutex_trylock(mutex) == FALSE){
            printf("%d:线程2锁定了互斥对象！\n", i);
            g_mutex_unlock(mutex);
        }else{
            g_usleep(2);
        }
    }
}

void thread_func2(Arg* arg){
    for(int i = 0; i < arg->max; i++){
        if(g_mutex_trylock(mutex) == FALSE){
            printf("%d，线程1锁定了互斥对象！\n", i);
            g_mutex_unlock(mutex);
        }else{
            g_usleep(2);
        }
    }
}

void thread_func3(Arg* arg){
    while(1){
        if(t1_end && t2_end){
            g_main_loop_quit(arg->loop);
            break;
        }
    }
}

int main(){
    if(g_thread_supported()){
        g_thread_init(NULL);
        printf("线程初始化成功！");
    }

    GMainLoop* loop;
    g_main_loop_new(NULL, FALSE);

    Arg* arg;
    arg = g_new(Arg, 1);
    arg->loop = loop;
    arg->max = 10;

    mutex = g_mutex_new();

    g_thread_create((GThreadFunc)thread_func1, arg, FALSE, NULL);
    g_thread_create((GThreadFunc)thread_func2, arg, FALSE, NULL);
    g_thread_create((GThreadFunc)thread_func3, arg, FALSE, NULL);

    g_main_loop_run(loop);

    printf("线程3退出\n");
    g_mutex_free(mutex);
    printf("释放锁对象\n");
    g_free(arg);
    printf("释放内存空间\n");
    return 0;
}