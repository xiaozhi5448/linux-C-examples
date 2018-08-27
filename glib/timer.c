#include<glib-2.0/glib.h>
#include<stdio.h>
int main(){
    GTimer* timer;
    GRand* rand;
    timer = g_timer_new();
    rand = g_rand_new();
    gint n;
    g_timer_start(timer);
    for(n = 0; n < 100000; n++){
        printf("%d\t", g_rand_int_range(rand, 1, 100));
    }
    g_timer_stop(timer);
    g_print("\n");
    g_rand_free(rand);
    printf("执行耗时：%.2f\n", g_timer_elapsed(timer, NULL));
    return 0;
}