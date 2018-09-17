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

#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>

int main(int argc, char* argv[]){

int src;
int n;
int count = 0;
char buf[1];

if(argc != 2){
printf("usage ./a.out fileName\n");
exit(1);
}

src = open(argv[1],O_RDONLY);

if(src == -1){
perror("unable to open file ");
exit(1);
}

while((n=read(src,buf,1))>0 && buf[0] != EOF){

if(buf[0] == ' '){
count = count +1;
 }

}
count = count +1;
close(src);
printf("your file has %d words\n",count);
return 0;

}
