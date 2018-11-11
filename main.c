
#include <stdbool.h>
#include <stdio.h>
#include <zconf.h>
#include <stdlib.h>
#include <pthread.h>

bool running = 1;
int var1 = 0;
int var2 = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *myThreadFun1(void *vargp)
{


    while(running) {
        pthread_mutex_lock(&mutex);
        var1 = var1 + 1;
        var2 = var1;
        pthread_mutex_unlock(&mutex);
    }
    exit(0);
}

void *myThreadFun2(void *vargp)
{

    int i;
        for (i = 1; i < 21; i++) {
            printf("Number 1 is %i, number 2 is %i\n", var1,var2);
            usleep(100000);
        }
        running = 0;
        exit(0);
}

int main()
{
    pthread_t thread_id;
    printf("Comparing variables var 1 and 2:\n");
    sleep(3);
    pthread_create(&thread_id, NULL, myThreadFun1, NULL);
    pthread_create(&thread_id, NULL, myThreadFun2, NULL);
    pthread_join(thread_id, NULL);
    sleep(2);
    printf("\nExiting program..\n");
    exit(0);
}
