cmake_minimum_required(VERSION 3.17)
project(own_uchat C)

set(CMAKE_C_STANDARD 11)

add_executable(own_uchat server/src/main.c server/inc/server.h server.c client/inc/client.h client/src/client.c server/inc/api_db.h server/src/openDB.c server/src/dbRequest.c utils/api.h server/src/get_request_SQL.c server/src/create_struct.c)