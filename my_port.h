/* my_port.h -- by lizhonglei 2007-11-22 */

#ifndef _MY_PORT_H_1361955_
#define _MY_PORT_H_1361955_

#include <stdio.h>
#include <string.h>
#include "sock_conf.h"
#include "ip_tcp.h"

int my_port(u_long src_ip,u_long dest_ip,unsigned short port); //port is host byte order and don't forget to convert

#endif
