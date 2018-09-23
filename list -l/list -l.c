/*
MIT License
Copyright (c) 2018 vijay madipally
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/



#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<time.h>
#include<pwd.h>

int list_dir(const char *dirname){
  struct dirent* current_directory;
  struct stat my_stat;
  struct tm lt;
  struct passwd *pwd;

  DIR* directory = opendir(dirname);

  if(directory == NULL){

    printf("list_dir ; %s : %s \n",dirname,strerror(errno));
    return 0;
  }

  printf("Directory : %s \n",dirname );
  printf("\n");

  while((current_directory = readdir(directory))){
    stat(current_directory->d_name,&my_stat);
    if((stat(current_directory->d_name,&my_stat))==0){
      pwd = getpwuid(my_stat.st_uid);
    }

    time_t t = my_stat.st_mtime;
    localtime_r(&t,&lt);
    char timebuf[80];
    strftime(timebuf, sizeof(timebuf),"%c", &lt);

    if(pwd != 0){
      printf("%s \t %ld \t %s \t %s",pwd->pw_name,(long)my_stat.st_size,timebuf,current_directory->d_name );
      printf("\n");
    }
    else{
      printf("%d \t %ld \t %s \t %s",my_stat.st_uid,(long)my_stat.st_size,timebuf,current_directory->d_name );
      printf("\n");
    }
  }
  closedir(directory);
  return 0;
}

int main(int argc, char* argv[]){
  if(argc == 1){
    return list_dir(".");
  }
  else{
    int ret = 0;
    for(int i = 1;i<argc;i++){
      if(list_dir(argv[i]) != 0){
        ret = 1;
      }
    }
    return ret;
  }
}
