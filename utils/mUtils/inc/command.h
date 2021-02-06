//
// Created by Mykhailo Burenko on 2/6/21.
//

#ifndef OWN_UCHAT_COMMAND_H
#define OWN_UCHAT_COMMAND_H

#include <stdbool.h>
#include "../../libmx/inc/libmx.h"
#include "utils_define.h"
#include <string.h>

bool isCommand(char *string);
char **toCommandWithArg(char *command);

#endif //OWN_UCHAT_COMMAND_H
