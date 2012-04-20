/* config.h -- by lizhonglei 2007-11-16 */

#ifndef _CONFIG_H__160730450_
#define _CONFIG_H__160730450_


/* defines */
#define MY_DEBUG
/* I hope my code can run both on windows and linux */
#define WINDOWS

/* include different head file and function */
#ifdef LINUX
#include <sys/socket.h>
#endif

#ifdef WINDOWS
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <Winsock2.h>
#include <ws2tcpip.h>
#define close closesocket
#endif


#endif
