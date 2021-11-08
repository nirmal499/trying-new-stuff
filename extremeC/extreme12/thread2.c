#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

/* This function contains the logic which should be run as
    the body of a separate thread
*/
void *thread_body(void *arg)
{
    printf("Hello from first thread!\n");
    return NULL;
}

int main(int argc, char const *argv[])
{
    //The thread handler
    pthread_t thread;

    //Create a new thread
    int result = pthread_create(&thread, NULL, thread_body, NULL);
    // If the thread creation did not succeed
    if (result)
    {
        printf("Thread could not be created. Error number %d\n", result);
        exit(1);
    }

    //Detach the thread
    result = pthread_detach(thread);
    //If detaching the thread did not succeed
    if (result)
    {
        printf("The thread could not be joined. Error number: %d\n",
               result);
        exit(2);
    }
    //Exit the main thread
    pthread_exit(NULL);
    /* Right after the creation of the new thread, the main thread has detached it. Then
        following that, the main thread exits. The instruction pthread_exit(NULL) was
        necessary in order to let the process know that it should wait for other detached
        threads to be finished. If the threads were not detached, the process would get
        terminated upon the exit of the main thread. 
    */
    return 0;
}
