#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int GB_TO_ALLOCATE = 10;
    int delay = 0;
    if (argc < 2)
    {
        printf("argument(s) missing:\n\n%s AMOUNT_OF_RAM_IN_GB [DELAY]\n\nif DELAY is provided, it will wait DELAY seconds or infinity if omitted or equal 0\n", argv[0]);
        return 1;
    }

    printf("will allocate %d GB\n", GB_TO_ALLOCATE);

    long long int allocated = 0LL;
    int inc = 1024 * 1024 * sizeof(char);
    int *p;

    // Fill a block with random value
    int *random_values_filled = (int *)calloc(1, inc);
    int rnd = open("/dev/urandom", O_RDONLY);
    read(rnd, p, inc);
    close(rnd);

    for (int i = 0; i < GB_TO_ALLOCATE * 1024; i++)
    {
        p = (int *)calloc(1, inc);
        // Copy the random values to force allocation
        memcpy(p, random_values_filled, inc);
        if (!p)
        {
            printf("calloc failed!\n");
            break;
        }
    }

    printf("allocation done: %d GB.\n", GB_TO_ALLOCATE);
    // Wait until killed
    if (delay != 0)
    {
        printf("now wait for %d seconds\n", delay);
        sleep(delay);
    }
    else
    {
        printf("now wait until killed\n");
        select(0, NULL, NULL, NULL, 0);
    }
}
