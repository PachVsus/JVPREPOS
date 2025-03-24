#include <pthread.h>
#include <time.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct my_struct_tag {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int value;
};

struct my_struct_tag data = {PTHREAD_MUTEX_INITIALIZER, PTHREAD_COND_INITIALIZER, 0};

int hibernation = 2; /* Default to 1 second */

/* Thread start routine. It will set the main thread’s predicate
   and signal the condition variable.
*/
void *wait_thread(void *arg) {
    srand(time(NULL));
    sleep(hibernation);

    /* This function is running in a separate thread. After some
       simulated work, this thread also attempts to lock the same
       mutex. However, because the mutex is already locked by the
       main thread, this function cannot immediately acquire the lock.
       It will block (wait) until the main thread unlocks the mutex.
    */
    pthread_mutex_lock(&data.mutex);
    printf("\tLock mutex inside wait_thread.\n");
    data.value = rand()%5+1; /* Set predicate */

    pthread_cond_signal(&data.cond);
    printf("\tSignaling condition.\n");

    pthread_mutex_unlock(&data.mutex);
    printf("\tUnlock mutex inside wait_thread.\n");

    return NULL;
 }

int main (int argc, char *argv[]) {
    int status;
    pthread_t wait_thread_id;
    struct timespec timeout;

    /* If an argument is specified, interpret it as the number
       of seconds for wait_thread to sleep before signaling the
       condition variable. You can play with this to see the
       condition wait below time out or wake normally.
    */
    if (argc > 1)
        hibernation = atoi(argv[1]);

    /* Create wait_thread. */
    pthread_create(&wait_thread_id, NULL, wait_thread, NULL);
    printf("Create wait thread.\n");

    /* Wait on the condition variable for 2 seconds, or until
       signaled by the wait_thread. Normally, wait_thread
       should signal. If you raise "hibernation" above 2
       seconds, it will time out.
    */
    timeout.tv_sec = time(NULL) + 3;
    timeout.tv_nsec = 0;

    /*  mutex locked before calling pthread_cond_timewait, this ensures that no other
        can modify the shared data.value variable while the main thread checks its
        condition and waits on the condition variable. The mutex remains locked while
        the main thread waits for the condition to be signaled.
    */
    pthread_mutex_lock(&data.mutex);
    printf("Lock mutex.\n");

    while(data.value == 0) {
        /* Once the main thread enters the pthread_cond_timedwait(), it performs two
           key actions: 1) the mutex is automatically unlocked by the system when the
           thread begins waiting on the condition. 2) the main thread then goes into a
           waiting state until the condition is signaled.
           This release of the mutex by the main threads allows the wait_thread() to
           proceed and acquire the lock when it tries to lock the mutex. The wait_thread()
           can the modify data.value and signal the condition.
        */
        status = pthread_cond_timedwait(&data.cond, &data.mutex, &timeout);
        if (status == ETIMEDOUT) {
            printf("Condition wait timed out.\n");
            break;
        } else if (status != 0)
            printf("Wait on condition: %d\n");
    }

    /* After the wait_thread() signals the condition and unlocks the mutex, the main thread
       resumes its execution. This happens because the condition variable was signaled while
       the main thread was in the pthread_cond_timedwait(). Once the main thread wakes up, it
       re-locks the mutex and proceeds to check the value of data.value to determine which
       condition was signaled.
    */
    if(data.value == 1)
        printf ("Condition 1 was signaled.\n");
    else if(data.value == 2)
        printf ("Condition 2 was signaled.\n");
    else if(data.value == 3)
        printf ("Condition 3 was signaled.\n");
    else if(data.value == 4)
        printf ("Condition 4 was signaled.\n");
    else if(data.value == 5)
        printf ("Condition 5 was signaled.\n");
    else
        printf ("Unrecognized condition.\n");

    pthread_mutex_unlock(&data.mutex);
    printf("Unlock mutex.\n");

    return 0;
}

