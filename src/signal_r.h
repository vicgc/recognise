#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/signalfd.h>
#include <signal.h>
#include "ansi_colors.h"
#include "gcc_attributes.h"
#include <linux/prctl.h>
#include <sys/prctl.h>


//signal handlers def
static void __pure __noreturn sig_handler(int signum, 
        siginfo_t *siginfo, void *context) {

    printf("%s\nBye :) --> \n", KYEL);
    printf("%sSignal %d Received\n", KRED, signum);
    printf("Exiting process %lu\n", (unsigned long) siginfo->si_pid);
    
    printf("\n%sExiting ...\n", KGRN);
    exit(0);
}


// Main --Call
static int __inline setsigHl() {

    
    // notify me if my Parent is dead :(
    // using prctl to notify of parents death --then clean up resources
    prctl(PR_SET_PDEATHSIG, SIGHUP);
    if (getppid() == 1) // Dead parent
        kill(getpid(), SIGHUP);

    
    struct sigaction act;
    memset(&act, 0, sizeof(act));

    //act.sa_handler = sig_handler;

    // sigset_t mask; // dereferenced pointer = NULL // -type void *

    //memset(&act, '\0', sizeof(act));

    sigemptyset(&act.sa_mask); // (&act.sa_mask);
    sigaddset(&act.sa_mask, SIGINT);
    sigaddset(&act.sa_mask, SIGTERM); // (&mask.sa_mask, SIGTREM);
 

    act.sa_sigaction = &sig_handler;
    act.sa_flags = SA_SIGINFO;

    if (sigaction(SIGINT, &act, NULL) <0) {
        perror("\nsigaction -> ERROR on signal Handler\n");
        return -1;
    }

    return 0;

}
