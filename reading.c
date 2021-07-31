/***********************************************************************/
/********** Author: Laura Toro                                **********/
/********** Description: A character count using read         **********/
/********** July 2021                                         **********/
/***********************************************************************/
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <fcntl.h>

int my_cnt(char *f){

    int size;

    //get page size
    size = sysconf(_SC_PAGE_SIZE);

    char buffer[size]; 
    FILE * stream;
    int count;
    unsigned long long newlineCount = 0;
    size_t i;

    //printf("%s\n", f);


    //printf("%d\n", size);

    //open file
    stream = fopen(f, "r");
    if (stream == NULL){
        printf("error opening library\n");
        return -1;
    }

    //read file and save to buffer
    count = fread(&buffer, sizeof(char),  size, stream);

    //using loop to count the newlines
    for (i=0; i<count; i++) {
    //printf("%c\n", buffer[i]);
    if (buffer[i] == '\n') newlineCount++;
    }

    //printf("linecount %llu count %d\n", newlineCount, count); 
    fclose(stream);

    return count - newlineCount; 

}
