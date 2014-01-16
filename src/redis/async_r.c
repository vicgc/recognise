#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/time.h>
#include <errno.h>
#include "credis.h"
#include <fcntl.h>

/* async connection with pipelining
 *
*/

int async() {
    redisAsyncContext *c = redisAsyncConnect("127.0.0.1", 6379);

    if (c->err) {
        printf("Error: %s\n", c->errstr);
        // raise handler
    }
}

int main() {

}
