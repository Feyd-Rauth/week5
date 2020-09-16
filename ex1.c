
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 

// The function to be executed by all threads 
void *ThreadFun(void *vargp) 
{ 
    int *myid = (int*)vargp; 
  
    printf("Thread ID: %d\n", *myid); 
}   
int main() 
{
    int n;
    printf("Input the number of threads:");
    scanf("%d", &n);
    pthread_t tid[n]; 
  
    for (int i = 0; i < n; i++){ 
        printf("Creation of thread number %d\n", i);
        pthread_create(&tid[i], NULL, ThreadFun, (void *)&i);
        pthread_join(tid[i], NULL);	
    }
    pthread_exit(NULL); 
    return 0; 
}; 


