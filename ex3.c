#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
int ConsumerSleep, ProducerSleep, position = 0;
long int t;
char buffer[20];

void* Consumer(void *vargp){
    while(1){
        if (ConsumerSleep == 1){
            continue;
        }
        if (position == 0){
            ProducerSleep = 0;
            ConsumerSleep = 1;
            printf("Done consumption with time: %ld\n", t++);
            continue;
        }
        buffer[position] = '\0';
        position--;
    }
    pthread_exit(NULL);
    return NULL;
}

void* Producer(void *vargp){
    while(1){
        if(ProducerSleep == 1){
            continue;
        }
        if (position == 20){
            ProducerSleep = 1;
            ConsumerSleep = 0;
            printf("Done production with time: %ld\n", t++);
            continue;
        }
        buffer[position] = 'a' + position;
        position++;
    }
    pthread_exit(NULL);
    return NULL;
}

int main(int argc, char const *argv[])
{
    ProducerSleep = 0;
    ConsumerSleep = 1;

    pthread_t tprod, tcons;

    pthread_create(&tprod, NULL, Producer, NULL);
    pthread_create(&tcons, NULL, Consumer, NULL);

    while(1);
//first time stopped at 561805
    return 0;
}
