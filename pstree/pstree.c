#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <getopt.h>
#include <sys/types.h>

#define MAX_PROC 20000

// type of cli options
typedef int bool;
typedef struct {
    bool show_pid;
    bool numeric_sort;
    bool version; 
}options;

// void show_options(options * opt) {
//     printf("show pid: %d\nnumeric sort: %d\nversion: %d\n", opt->show_pid, opt->numeric_sort, opt->version);
// }

// parse the cli options
options get_options(int ac, char *av[]) {
    options opt = {
        0,
        0,
        0,
    };

    const char * short_option = ":pnv";
    const struct option long_opton[4] = {
        {"show-pids", 0, NULL, 'p'},
        {"numeric-sort", 0, NULL, 'n'},
        {"version", 0, NULL, 'v'},
        {NULL, 0, NULL, 0},
    };

    int option = -1;
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

// definition of the process
typedef struct {
    char * cmd[256];
    pid_t pid;
    int parent_index;
} process;

// definition of the list of processes
typedef struct {
    process p_array[MAX_PROC];
    int p_num;
} processes;

/*
  read subdirectories of `/proc` and file `/proc[pid]/stat` to get the processes info
  format of `/proc/[pid]/stat`: pid comm state ppid ... (other irrelevant fields are omitted)
*/
int get_process(processes * p) {

}

int main(int ac, char *av[]) {
    options opt = get_options(ac, av);
    show_options(&opt);

    return 0;
}