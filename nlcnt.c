/************             N L C N T            ***********/
/************ Example of dynamic linking       ***********/
/************ Laura Toro July 2021       ***********/

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>


void show_usage(char *name)
{
  printf("USAGE: %s reading|mapping filename\n",name);
  exit(1);
}

int main(int argc, char **argv){

  int i;
  char *s;
  char *librarySelected;
  void *handle;
  int (*my_cnt)(char *);

  //check for valid amount of args
  if (argc!=3){
    show_usage(argv[0]);
  }

  //set args
  librarySelected = argv[1];
  s = argv[2];
  //printf("string %s\n", s);
  char filename[strlen(s)];
  strcpy(filename, s);

  //printf("you chose: %s\n", librarySelected);

  //appending and prepending file suffix/prefix
  char fullLibraryPath[50] = "./";
  char extension[] = ".so";
  strcat(librarySelected, extension);
  strcat(fullLibraryPath, librarySelected);

  //printf("filename: %s\n", fullLibraryPath);

  handle = dlopen(fullLibraryPath, RTLD_LAZY);
  if (handle == NULL){
    printf("error opening library\n");
    return 1;
  }

  //opening the function
  my_cnt = dlsym(handle, "my_cnt");
  if (my_cnt == NULL){
    printf("error opening function my_cnt\n");
    return 1;
  }

  //printf("string %s\n", filename);

  printf("Total number of (non new line): %d\n", my_cnt(filename));

  dlclose(handle);

}
