#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "md5.h"

int main(int argc, char *argv[])
{
    //Check how many filename user supplied.
    //If not enough, erro message and exit/
    if(argc < 3)
    {
        printf("You need to supply two filenames\n");
        exit(1);
    }
    
    //Check if output file is the same as input file
    if(strcmp(argv[1], argv[2]) == 0)
    {
        printf("Output file is same as input file\n");
        exit(1);
    }
    
    //Open first file for reading
    FILE *in = fopen(argv[1], "r");
    if (!in)
    {
        printf("Can't open %s for reading\n", argv[1]);
        exit(1);
    }
    
    //Open second file for writing
    FILE *out = fopen(argv[2], "w");
    if(!out)
    {
        printf("Can't open %s for writing\n", argv[2]);
        exit(1);
    }
    
    char line[100];
    int count = 0;
    while(fgets(line, 100, in) != NULL)
    {
        count++;
        char *hash = md5(line, strlen(line));
        
        fprintf(out, "%d %s\n", count, hash);
        free(hash);
    }
    
    
    //close both file
    fclose(in);
    fclose(out);
      
}