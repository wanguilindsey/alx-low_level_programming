#!/bin/bash
echo -e "#include <stdlib.h>\n#include <time.h>\nvoid srand(unsigned int seed) {}\nint rand() { return 6; }" > /tmp/rand_override.c
gcc -shared -o /tmp/rand_override.so /tmp/rand_override.c -nostartfiles
LD_PRELOAD=/tmp/rand_override.so "$(dirname "$0")/gm" 9 8 10 24 75 9
