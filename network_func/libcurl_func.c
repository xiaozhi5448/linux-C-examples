#include<curl/curl.h>
#include<stdio.h>
#include<stdlib.h>
FILE *fp;
size_t write_data(void* ptr, size_t size, size_t nmem, void *stream){
    size_t num = fwrite(ptr, size, nmem, fp);
    return num;
}
int main(int argc, char* argv[]){
    CURL *curl;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
    if((fp = fopen(argv[2], "w")) == NULL){
        perror("创建文件出错！");
        curl_easy_cleanup(curl);
        exit(EXIT_FAILURE);
    }
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    return 0;
}