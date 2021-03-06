/*
 * The main part for execution
 * Create by Tingsheng Lai (tingshengl, 781319)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <signal.h>

#include "core/default.h"
#include "core/server.h"

int main(int argc, char *argv[]) {
    int port = PORT;
    char *path = PATH;

    if(argc == 2 && !strcmp(argv[1], "-h")) {
        printf("Usage: %s [port [default: %d]] [path [default: %s]]\n", argv[0],
            PORT, PATH
        );
        return 0;
    }

    if(argc > 1)
        port = atoi(argv[1]);

    if(argc > 2)
        path = argv[2];

    /* ignore the broken pipe signal */
    signal(SIGPIPE, SIG_IGN);

    /* start server */
    serve(port, path);

    return 0;
}
