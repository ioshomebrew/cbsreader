#include <stdio.h>
#include <stdlib.h>

int main()
{
    // declarations
    FILE *cbs;
    int i;
    char str1[100];
    char str2[100];
    char str3[100];
    char *names = {str1};
    char *product = {str2};
    char *temp = {str3};

    // open database
    cbs = fopen("database.cbs", "r");

    // check if database opened
    if(!cbs)
    {
        printf("Error loading database.cbs\n");
        exit(1);
    }

    // print table
    printf("%s %20s\n", "Data 1", "Data 2");

    // read and print customer names
    for(i = 0; i < 5; i++)
    {
        // store array
        fscanf(cbs, "%[^,] %s %s", names, temp, product);

        // print data 1 and data 2
        printf("%s %20s", names, product);
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
