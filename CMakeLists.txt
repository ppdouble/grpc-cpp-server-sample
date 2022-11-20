cmake_minimum_required(VERSION 3.20)
project(grpc_cpp_server_sample)

set(CMAKE_CXX_STANDARD 14)
#set(D_LIBRARY_PATH "/lib64:/lib:/usr/lib64:/usr/lib:/usr/local/lib64:/usr/local/lib")

#find_package(Threads)
add_executable(grpc_cpp_server_sample main.cpp service/GreeterServiceImpl.cpp service/GreeterServiceImpl.h server/GrpcServer.cpp server/GrpcServer.h)

