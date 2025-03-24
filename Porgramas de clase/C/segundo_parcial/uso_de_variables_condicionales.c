#include <pthread.h>    // For pthread_create, pthread_cond_timedwait, pthread_mutex_lock, pthread_mutex_unlock, pthread_cond_signal, pthread_t, pthread_mutex_t, pthread_cond_t
#include <time.h>   // For time
#include <errno.h>  // For ETIMEDOUT
#include <stdio.h>  // For printf
#include <stdlib.h> // For atoi
#include <unistd.h> // For sleep

struct my_struct_tag {      // Structure to store the mutex, condition variable, and value
    pthread_mutex_t mutex;  // Mutex to protect the shared data
    pthread_cond_t cond;    // Condition variable to signal the main thread
    int value;              // Value to store the predicate
};

struct my_struct_tag data = {PTHREAD_MUTEX_INITIALIZER, PTHREAD_COND_INITIALIZER, 0};   // Initialize the structure with default values

int hibernation = 2; /* Default to 1 second */

/* Thread start routine. It will set the main thread’s predicate
   and signal the condition variable.
*/
void *wait_thread(void *arg) {  // Function to be executed by the wait_thread
    srand(time(NULL));          // Seed the random number generator
    sleep(hibernation);         // Sleep for the specified number of seconds

    /* This function is running in a separate thread. After some
       simulated work, this thread also attempts to lock the same
       mutex. However, because the mutex is already locked by the
       main thread, this function cannot immediately acquire the lock.
       It will block (wait) until the main thread unlocks the mutex.
    */
    pthread_mutex_lock(&data.mutex);    // Lock the mutex
    printf("\tLock mutex inside wait_thread.\n");   // Print a message to indicate that the mutex has been locked
    data.value = rand()%5+1; // Set predicate to a random number between 1 and 5

    pthread_cond_signal(&data.cond);    // Signal the condition variable
    printf("\tSignaling condition.\n"); // Print a message to indicate that the condition has been signaled

    pthread_mutex_unlock(&data.mutex); // Unlock the mutex
    printf("\tUnlock mutex inside wait_thread.\n"); // Print a message to indicate that the mutex has been unlocked

    return NULL;    // Return NULL to indicate that the thread has finished
 }

int main (int argc, char *argv[]) { // Main function with command line arguments
    int status;                     // Variable to store the status of the condition wait
    pthread_t wait_thread_id;       // Variable to store the ID of the wait_thread
    struct timespec timeout;        // Variable to store the timeout value

    /* If an argument is specified, interpret it as the number
       of seconds for wait_thread to sleep before signaling the
       condition variable. You can play with this to see the
       condition wait below time out or wake normally.
    */
    if (argc > 1)   // Check if an argument was provided
        hibernation = atoi(argv[1]);    // Convert the argument to an integer and store it in hibernation

    /* Create wait_thread. */
    pthread_create(&wait_thread_id, NULL, wait_thread, NULL);   // Create a new thread and store its ID in wait_thread_id
    printf("Create wait thread.\n");

    /* Wait on the condition variable for 2 seconds, or until
       signaled by the wait_thread. Normally, wait_thread
       should signal. If you raise "hibernation" above 2
       seconds, it will time out.
    */
    timeout.tv_sec = time(NULL) + 3;    // Set the timeout to 3 seconds
    timeout.tv_nsec = 0;                // Set the nanoseconds to 0

    /*  mutex locked before calling pthread_cond_timewait, this ensures that no other
        can modify the shared data.value variable while the main thread checks its
        condition and waits on the condition variable. The mutex remains locked while
        the main thread waits for the condition to be signaled.
    */
    pthread_mutex_lock(&data.mutex);    // Lock the mutex
    printf("Lock mutex.\n");        // Print a message to indicate that the mutex has been locked

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
        if (status == ETIMEDOUT) {                  // Check if the condition wait timed out
            printf("Condition wait timed out.\n");  // Print a message to indicate that the condition wait timed out
            break;
        } else if (status != 0)                     // Check if the condition wait failed
            printf("Wait on condition: %d\n");     // Print a message to indicate that the condition wait failed
            perror("pthread_cond_timedwait");   // Print an error message if the condition wait fails
            exit(1);    // Exit the program with an error code

    }

    /* After the wait_thread() signals the condition and unlocks the mutex, the main thread
       resumes its execution. This happens because the condition variable was signaled while
       the main thread was in the pthread_cond_timedwait(). Once the main thread wakes up, it
       re-locks the mutex and proceeds to check the value of data.value to determine which
       condition was signaled.
    */

    if(data.value == 1) // Check if the value of data is 1
        printf ("Condition 1 was signaled.\n"); // Print a message to indicate that condition 1 was signaled
    else if(data.value == 2)    // Check if the value of data is 2
        printf ("Condition 2 was signaled.\n"); // Print a message to indicate that condition 2 was signaled
    else if(data.value == 3)    // Check if the value of data is 3
        printf ("Condition 3 was signaled.\n"); // Print a message to indicate that condition 3 was signaled
    else if(data.value == 4)    // Check if the value of data is 4
        printf ("Condition 4 was signaled.\n"); // Print a message to indicate that condition 4 was signaled
    else if(data.value == 5)    // Check if the value of data is 5
        printf ("Condition 5 was signaled.\n"); // Print a message to indicate that condition 5 was signaled
    else                  // If the value of data is not recognized
        printf ("Unrecognized condition.\n");   // Print a message to indicate that the condition is not recognized

    pthread_mutex_unlock(&data.mutex);  // Unlock the mutex
    printf("Unlock mutex.\n");    // Print a message to indicate that the mutex has been unlocked

    return 0;
}
