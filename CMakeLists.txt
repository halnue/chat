cmake_minimum_required(VERSION 3.17)
project(own_uchat C)

set(CMAKE_C_STANDARD 11)

add_executable(own_uchat main.c server/inc/server.h server/src/server.c client/inc/client.h client/src/client.c server/inc/api_db.h server/src/openDB.c server/src/dbRequest.c utils/api.h client/src/string_api.c client/src/command_api.c client/src/printer.c server/src/command_controler.c server/src/db.c server/src/work_struct.c)