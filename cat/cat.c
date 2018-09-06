#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>

int main(int argc, char* argv[]){
  int src; //source file
  int n; // tracking variable
  char buf[1];
  if(argc != 2){
    printf("usage ./a.out fileName\n");
    exit(1);
  }

  src = open(argv[1],O_RDONLY);
  if(src == -1){
    perror("can't find the source file");
    exit(1);
  }

  while((n=read(src,buf,1))>0){
    write(1,buf,1);
  }
  close(src);
  return 0;
}
