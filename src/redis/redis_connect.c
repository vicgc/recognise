#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/time.h>
#include <errno.h>
#include "credis.h"
#include <fcntl.h>


int main(int argc, char *argv[]) {
    REDIS rh;
    char *val;

    rh = credis_connect(NULL, 6789, 2000);
    credis_ping(rh);

    credis_set(rh, "kale", "kula");
    credis_get(rh, "kale", &val);

    printf("get kale returned: %s\n", val);

    credis_close(rh);

    return 0;
}
