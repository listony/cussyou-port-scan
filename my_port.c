/* my_port.c -- by lizhonglei 2007-11-22 */

#include "my_port.h"

int my_port(u_long src_ip,u_long dest_ip,unsigned short port)
{
    int ret,i;
    int sock;
    char send_buf[256];
    char recv_buf[256];
    struct sockaddr_in from,dest;
    u_long argp;
    struct timeval timeout;
    fd_set fd;
    char output[32];// MS is so stupid
    int exin;
#ifdef WINDOWS
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2,2),&wsaData) != 0){
        printf("wsastartup error\n");
        return -5;
    }
#endif
    /* test args */
    if(src_ip==0||dest_ip==0) return -9;
    if(port==0) return -7;
    /* address */
    memset(&dest,0,sizeof(dest));
    memset(&from,0,sizeof(from));
    dest.sin_family = AF_INET;
    dest.sin_port=htons(port);
    dest.sin_addr.s_addr = dest_ip;
    from.sin_family= AF_INET;
    from.sin_addr.s_addr=src_ip;

    sock=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(sock<=0){
        printf("socket() error\n");
        return -4;
    }
    /* non block */
#ifdef WINDOWS
    argp=1;
    ret=WSAIoctl(sock,FIONBIO,&argp,sizeof(argp),output,32,&exin,NULL,NULL);
    if(ret==-1) return -3;
#endif
    ret=bind(sock,(struct sockaddr*)&from,sizeof(from));
    if(ret==-1){
        printf("bind() error\n");
        return -2;
    }
    ret=connect(sock,(struct sockaddr*)&dest,sizeof(dest));
    /* set time out */
    timeout.tv_sec=5;
    timeout.tv_usec=5000;    
    FD_ZERO(&fd);
    FD_SET(sock,&fd);
    /* select */
    ret=select(0,NULL,&fd,NULL,&timeout);
    if(ret==0) {
        return -1; //time out
        close(sock);
    }
    else {
        close(sock);
    }
    return 0;
}


