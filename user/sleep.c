#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
int main(int argc,char* argv[]){
    if(argc<2){
    printf("error sleep systemcall");
    exit(1);
    }
    int n=atoi(argv[1]);
    sleep(n);
    exit(1);
    
}
