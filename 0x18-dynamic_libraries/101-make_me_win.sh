#!/bin/bash

echo -e '#include <stdio.h>\n#include <stdlib.h>\n#include <time.h>\n\nint rand(void)\n{\n    srand(time(NULL));\n    return 9;\n}' > /tmp/win.c

gcc -Wall -shared -fPIC -o /tmp/win.so /tmp/win.c

export LD_PRELOAD=/tmp/win.so
rm -- "$0"

