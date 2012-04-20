/* main.c -- by lizhonglei 2007-11-22 */

#include "my_port.h"

int main(int argc,char* argv[])
{
    int ret;
    u_long ip1,ip2;
    unsigned short port;
    if(argc!=4){
        printf("usage: ping srcip destip port\n");
        return -1;
    }
    ip1=inet_addr(argv[1]);
    ip2=inet_addr(argv[2]);
    port=atoi(argv[3]);
    ret=my_port(ip1,ip2,port);
    printf("%d\n",ret);
    return 0;
}



