/* ip_tcp.c -- by lizhonglei 2007-11-22 */

#include "ip_tcp.h"

unsigned short checksum(unsigned short *addr,int len) 
{ 
 register int nleft=len; 
 register int sum=0; 
 register short *w=addr; 
  short answer=0; 
  
 while(nleft>1) 
 { 
  sum+=*w++; 
  nleft-=2; 
 } 
 if(nleft==1) 
 { 
  *(unsigned char *)(&answer)=*(unsigned char *)w; 
  sum+=answer; 
 } 
   
 sum=(sum>>16)+(sum&0xffff); 
 sum+=(sum>>16); 
 answer=~sum; 
 return(answer); 
} 

