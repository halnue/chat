cmake_minimum_required(VERSION 3.17)
project(own_uchat C)

set(CMAKE_C_STANDARD 11)

add_executable(own_uchat main.c userver/inc/server.h userver/src/server.c userver/src/get_request_SQL.c uclient/inc/client.h uclient/src/client.c userver/inc/api_db.h userver/src/openDB.c userver/src/dbRequest.c utils/mUtils/inc/api.h uclient/src/string_api.c uclient/src/command_controler.c uclient/src/printer.c userver/src/command_controler.c userver/src/db.c userver/src/work_struct.c utils/mUtils/src/command_utils.c utils/mUtils/inc/command.h utils/mUtils/inc/utils_define.h userver/src/response_server.c uclient/src/response_server.c uclient/src/create_struct.c)