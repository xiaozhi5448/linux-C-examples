#include<stdio.h>
#include<glib-2.0/glib.h>
int main(){
	GMemChunk* chunk;
    gchar *mem[10];
    chunk = g_mem_chunk_new("test", 5, 50, G_ALLOC_AND_FREE);
    for( int i = 0; i < 10; i++){
        mem[i] = g_mem_chunk_alloc(chunk);
        for( int j = 0; j < 5; j++){
            mem[i][j] = 'A' + j;
        }
    }
    g_mem_chunk_print(chunk);
    for(int i = 0; i < 10; i++){
        printf("%s\n", mem[i]);
    }
    for(int j = 0; j < 10; j++){
        g_mem_chunk_free(chunk, mem[j]);
    }
    return 0;
}
