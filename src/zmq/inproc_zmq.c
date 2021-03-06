#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

#include <zmq.h>
#include <stdio.h>
#include <signal.h>

// valgrind --tool=memcheck --leak-check=full --suppressions=valgrind.supp prog


static int s_interrupted = 0;

// change val upon signal interruption
static void s_signal_handler (int signal_value) {
    s_interrupted = 1;
}

static void s_catch_signals (void) {
    struct sigaction action;
    action.sa_handler = s_signal_handler;
    action.sa_flags = 0;
    sigemptyset (&action.sa_mask);
    sigaction (SIGINT, &action, NULL);
    sigaction (SIGTERM, &action, NULL);
}

// gcc demo_zmq.c -L/usr/local/lib -lzmq
// valgrind --tool=memcheck --leak-check=full --suppressions=valgrind.supp ./a.out

int main (void) {

    printf("START\n");
    //  Socket to talk to clients
    void *context = zmq_ctx_new ();
    void *responder = zmq_socket (context, ZMQ_REP);
    int rc = zmq_bind (responder, "tcp://*:5555");
    assert (rc == 0);


    while (1) {
        char buffer [10];
        zmq_recv (responder, buffer, 10, 0);
        printf ("Received Hello\n");

        sleep (1);          //  Do some 'work'

        zmq_send (responder, "World", 5, 0);
    }
    
    return 0;
}
