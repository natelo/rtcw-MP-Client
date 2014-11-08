/*
---------------------------
Nate 'L0 - http.h
Created: 8.11/14

Hold declarations and structures of all the HTTP related functionality..
---------------------------
*/
#ifndef _S_HTTP
#define _S_HTTP

#include "../game/q_shared.h"
#include "qcommon.h"

// So if it's ported it can be set here..
#define STATS_VERSION Q3_VERSION " auth"

// Upload is capped at 10mb..anything more @ your own risk.
#define UFILE_SIZELIMIT 10000000

// So it's little easier..
#define _CMD(x, y) !Q_stricmp(x, y)

/*
============
Prototypes
============
*/
//
// g_http.c
//
void HTTP_SubmitData(char *url, char *data);
void HTTP_SubmitFile(char *url, char *file, qboolean wipe);
char *HTTP_QueryAddres(char *url, char *data);

#endif // _S_HTTP
