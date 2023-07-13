#include "types.h"
#include "user.h"
#include "syscall.h"

int main(int argc, char *argv[]){
    int rc;
    printf(1, "hello world\n");
    rc = getcount(SYS_write);
    printf(1, "%d\n", rc);
    exit();
}