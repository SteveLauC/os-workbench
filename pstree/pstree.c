#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <getopt.h>

typedef int bool;
typedef struct {
    bool show_pid;
    bool numeric_sort;
    bool version; 
}options;

void show_options(options * opt) {
    printf("show pid: %d\nnumeric sort: %d\nversion: %d\n", opt->show_pid, opt->numeric_sort, opt->version);
}
options get_options(int ac, char *av[]) {
    options opt = {
        0,
        0,
        0,
    };
    int option = -1;

    const char * short_option = ":pnv";
    const struct option long_opton[4] = {
        {"show-pids", 0, NULL, 'p'},
        {"numeric-sort", 0, NULL, 'n'},
        {"version", 0, NULL, 'v'},
        {NULL, 0, NULL, 0},
    };

    while (-1 != (option = getopt_long(ac, av, short_option, &long_opton[0], NULL))) {
        switch (option){
            case 'p':
                opt.show_pid = 1;
                break;
            case 'n':
                opt.numeric_sort = 1;
                break;
            case 'v':
                opt.version = 1;
                break;
            case ':':
                fprintf(stderr, "%c needs an additional argument\n", optopt);
                exit(EXIT_FAILURE);
                break;
            case '?':
                fprintf(stderr, "%c: invalid option\n", optopt);
                exit(EXIT_FAILURE);
                break;
        }
    }
    return opt;
}
int main(int ac, char *av[]) {
    options opt = get_options(ac, av);
    show_options(&opt);
}