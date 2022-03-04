#include <stdio.h>
#include <assert.h>
#include <getopt.h>

typedef int bool;
typedef struct {
    bool show_pid;
    bool numeric_sort;
    bool version; 
}options;

options get_options(int ac, char *av[]) {
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
                break;
            case 'p':
                break;
            case 'p':
                break;
            case 'p':
                break;
            case 'p':
                break;
        }
    }
}
int main(int ac, char *av[]) {

}