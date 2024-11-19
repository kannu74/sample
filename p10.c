#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct records
{
    int flag, usn;
    char name[20];
} rec[15];

int hash(int m)
{
    return m % 15;
}

int main()
{
    int m, k, usn, loc, i, j, n;
    char name[20];
    FILE *in, *outp;

    printf("Enter the number of records to read from file: ");
    scanf("%d", &n);
    if (n > 15)
    {
        printf("Provide less than 15 records\n");
        return 1;
    }

    in = fopen("input.txt", "r");
    if (!in)
    {
        printf("Error opening input file\n");
        return 1;
    }

    for (k = 0; k < 15; k++)
        rec[k].flag = 0;

    for (i = 0; i < n; i++)
    {
        fscanf(in, "%s%d", name, &usn);
        loc = hash(usn);
        if (rec[loc].flag == 0)
        {
            strcpy(rec[loc].name, name);
            rec[loc].usn = usn;
            rec[loc].flag = 1;
        }
        else
        {
            for (j = loc + 1; j % 15 != loc; j++)
            {
                if (rec[j % 15].flag == 0)
                {
                    strcpy(rec[j % 15].name, name);
                    rec[j % 15].usn = usn;
                    rec[j % 15].flag = 1;
                    break;
                }
            }
        }
    }
    fclose(in);

    printf("\nHash Table Content:\n");
    for (i = 0; i < 15; i++)
    {
        if (rec[i].flag == 1)
            printf("%s %d\n", rec[i].name, rec[i].usn);
        else
            printf("##\n");
    }

    outp = fopen("output.txt", "w");
    if (!outp)
    {
        printf("Error opening output file\n");
        return 1;
    }

    for (i = 0; i < 15; i++)
    {
        if (rec[i].flag == 0)
            fprintf(outp, "\n# | #");
        else
            fprintf(outp, "\n%s | %d ", rec[i].name, rec[i].usn);
    }
    fclose(outp);

    return 0;
}
