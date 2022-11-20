cmake_minimum_required(VERSION 3.20)
project(grpc_cpp_server_sample)

set(CMAKE_CXX_STANDARD 14)
#set(D_LIBRARY_PATH "/lib64:/lib:/usr/lib64:/usr/lib:/usr/local/lib64:/usr/local/lib")

include_directories(/usr/local/include/google/protobuf)
include_directories(/usr/local/include/grpcpp)

link_directories(/usr/local/lib)
link_directories(/usr/local/lib64)
link_directories(/usr/lib)
link_directories(/usr/lib64)
link_directories(/lib)
link_directories(/lib64)

add_executable(grpc_cpp_server_sample main.cpp service/GreeterServiceImpl.cpp service/GreeterServiceImpl.h server/GrpcServer.cpp server/GrpcServer.h)

