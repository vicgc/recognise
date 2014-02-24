#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hiredis.h"

// gcc -Llibhiredis.so redis-conn.c -lhiredis

int main() {
    redisReply *reply;
    long int i;

    clock_t start = clock();

    //local connect
    redisContext *c = redisConnect("127.0.0.1", 6379);

    if (c->err) {
        printf("Error: %s\n", c->errstr);
    } else {
        printf("Connection Acquired! \n");
    }

    reply = redisCommand(c, "Keys %s", "*");

    if (reply -> type == REDIS_REPLY_ERROR)
        printf("Error: %s\n", reply->str);

    else if(reply->type != REDIS_REPLY_ARRAY)
        printf("Unexpected type: %d\n", reply->type);
    else {
        for (i=0;  i < reply->elements; ++i) {
            printf("Results: %lu: %s\n", i,
                    reply->element[i]->str);
        }
    }
    printf("Total Number of Results: %lu\n", i);

    //Elapsed time

    printf("%f Seconds\n", ( (double)clock() - start) /
        CLOCKS_PER_SEC);

    freeReplyObject(reply);
}
