#include "radix_sort.h"
#include "interactive_session.h"

int main(int argc, char *argv[]) {
    if (argc > 1 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)) {
        help();
        return 0;
    }

    interactiveSession();
    return 0;
}