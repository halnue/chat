//
// Created by Mykhailo Burenko on 03/02/2021.
//

#ifndef OWN_UCHAT_CLIENT_H
#define OWN_UCHAT_CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include "../../utils/libmx/inc/libmx.h"
#include "../../utils/api.h"

#define LENGTH 2048

char *rm_first_spas(char *string);

#endif //OWN_UCHAT_CLIENT_H
