#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // declarations
    FILE *cbs;
    int i;
    int lines;
    char *names = (char *)malloc(100);
    char *data1 = (char *)malloc(4);
    char *data2 = (char *)malloc(4);
    char *temp = (char *)malloc(1);
    char *temp2 = (char *)malloc(1);

    // open database
    cbs = fopen("database.cbs", "r");

    // check if database opened
    if(!cbs)
    {
        printf("Error loading database.cbs\n");
        exit(1);
    }

    // get lines
    fscanf(cbs, "%[^,] %s %i", temp, temp2, &lines);

    // print table
    printf("%s %20s %20s", "Data 1", "Data 2", "Data 3");

    // read and print customer names
    for(i = 0; i < lines; i++)
    {
        // store data2
        fscanf(cbs, "%[^,] %s %[^,] %s %s", names, temp, data1, temp2, data2);

        // print data 1 and data 2
        printf("%s %20s %20s", names, data1, data2);
    }

    // close cbs file
    fclose(cbs);

    // new line
    printf("\n");

    // pause
    printf("Press any key to continue\n");
    getchar();

    return 0;
}
