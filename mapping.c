

/***********************************************************************/
/********** Author: Laura Toro                                **********/
/********** Description: A simple example of mmap usage       **********/
/********** for counting newlines in a file                   **********/
/********** July 2021                                         **********/
/***********************************************************************/

#include <sys/mman.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <stdarg.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


int my_cnt(char *f){

int fd;
struct stat s;
int status;
size_t size;
const char * mapped_file;

int count = 0;

//opening file
fd = open (f, O_RDONLY);
if(fd == -1 ){
    printf("error opening file\n");
    return -1;
}

//getting stats for size
status = fstat (fd, &s);
if(status > 0 ){
    printf("error checking stats\n");
    return -1;
}

size = s.st_size;

//printf("file size is %ld\n", size);

//mapping to buffer
mapped_file = mmap (0, size, PROT_READ, MAP_PRIVATE, fd, 0);

int i;
for(i = 0; i < size; i++){
    if(mapped_file[i] == '\n'){
        continue; 
    } else {
        count++;
    }
}

return count;


}
