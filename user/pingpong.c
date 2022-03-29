#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
int main(){
  int p[2];
  int p2[2];
  pipe(p);
  pipe(p2);
  char buf[10];

  int rc=fork();
 
  
  if(rc>0){
    write(p[1],"1",1);
    close(p[1]);
  }
  if(rc==0){
    sleep(10);
  
    dup(p[0]);
    // close(0);
    if(read(p[0],buf,1)){
       printf("<%d>: received ping",getpid()); 
       close(1);
       }
    write(p2[1],"1",1);
  }
  if(rc>0){
    sleep(10);
    if(read(p2[0],buf,1)){
       printf("<%d>: received pong",getpid());
      }
    
  }
  exit(1);
}
