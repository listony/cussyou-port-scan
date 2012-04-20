/* ip_tcp.h -- by lizhonglei 2007-11-16 */

#ifndef _IP_TCP_H_1361955_
#define _IP_TCP_H_1361955_

/* The IP header */
typedef struct _iphdr {
	unsigned char v_len;          // version and length 
	unsigned char tos;             // Type of service
	unsigned short total_len;      // total length of the packet
	unsigned short ident;          // unique identifier
	unsigned short frag_and_flags; // flags
	unsigned char  ttl; 
	unsigned char proto;           // protocol (TCP, UDP etc)
	unsigned short cksum;       // IP checksum

	unsigned int srcIP;
	unsigned int destIP;

}iphead;

// ICMP header
//
typedef struct _ihdr {
  unsigned char type;
  unsigned char code; /* type sub code */
  unsigned short cksum;
  unsigned short id;
  unsigned short seq;
}icmphead;

// udp header
typedef struct _udphdr { 
  u_short    source; 
  u_short    dest; 
  u_short    len; 
  u_short     check; 
}udphead; 

// tcp head
typedef struct _tcphdr{
    unsigned short source;
    unsigned short dest;
    unsigned int seq;
    unsigned int ack_seq;
    /* I don't use bit fields,because I can't know the order...in book C Reference..*/
    unsigned char len_4;
    unsigned char flag;
    unsigned short window;
    unsigned short cksum;
    unsigned short urg_ptr;    
}tcphead;

/* */
unsigned short checksum(unsigned short *addr,int len);
/* we */

#endif
