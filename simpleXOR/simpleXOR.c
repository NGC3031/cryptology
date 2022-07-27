#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Usage: crypto key input_file output_file */
void main(int argc, char *argv[])
{
    FILE *fi, *fo;
    char *cp;
    int c;
    printf("Start...");
    printf("Arguments: %i\n", argc);

    for (int i = 0; i < argc; i++)
    {
        printf("Arguments %i: %s\n", i, argv[i]);
        // argv[i] is the argument at index i
    }

    if ((cp = argv[1]) && *cp != '\0')
    {
        if ((fi = fopen(argv[2], "rb")) != NULL)
        {
            if ((fo = fopen(argv[3], "wb")) != NULL)
            {
                while ((c = getc(fi)) != EOF)
                {
                    if (!*cp)cp = argv[1];
                    c = c^*(cp++);
                    printf("OUT: %i %i XOR: %i \n", c, *(cp++), c=c^*(cp++));
                    putc(c, fo);
                }
                fclose(fo);
            }
            fclose(fi);
        }
    }
}
