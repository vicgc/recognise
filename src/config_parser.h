#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "ini.h"
#include "ini.c"

typedef struct {
    int version;
    const char* name;
    const char* email;
    int term;
    int threads;
    const char* model;

} configuration;


static int handler(void* user, const char* section, const char* name,
                   const char* value)
{
    configuration* pconfig = (configuration*)user;

    #define MATCH(s, n) strcmp(section, s) == 0 && strcmp(name, n) == 0
    if (MATCH("protocol", "version")) {
        pconfig->version = atoi(value);
    } else if(MATCH("config", "term")) {
    	pconfig->term = atoi(value);
    } else if(MATCH("config", "threads")) {
    	pconfig->threads = atoi(value);
    } else if(MATCH("config", "model")) {
    	pconfig->model = strdup(value);
    }
    else if (MATCH("user", "name")) {
        pconfig->name = strdup(value);
    } else if (MATCH("user", "email")) {
        pconfig->email = strdup(value);
    } else {
        return 0;  /* unknown section/name, error */
    }
    return 1;
}
