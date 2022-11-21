

## 1. Install grpc
`set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")` in `CMakeLists.txt`

**fatal error: google/protobuf/compiler/csharp/csharp_names.h: No such file or directory**

**error**
```shell
cpp/grpc/src/compiler/config_protobuf.h:53:10: fatal error: google/protobuf/compiler/csharp/csharp_names.h: No such file or directory
 #include <google/protobuf/compiler/csharp/csharp_names.h>
          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
compilation terminated.
make[2]: *** [CMakeFiles/grpc_plugin_support.dir/build.make:63: CMakeFiles/grpc_plugin_support.dir/src/compiler/cpp_generator.cc.o] Error 1
make[1]: *** [CMakeFiles/Makefile2:1742: CMakeFiles/grpc_plugin_support.dir/all] Error 2
make: *** [Makefile:152: all] Error 2

```

**solution**

```shell
git clone -b v1.49.1 git@github.com:grpc/grpc.git
```

**CMake Error at cmake/abseil-cpp.cmake:38 (find_package)**

**error**
```shell
CMake Error at cmake/abseil-cpp.cmake:38 (find_package):
  Could not find a package configuration file provided by "absl" with any of
  the following names:

    abslConfig.cmake
    absl-config.cmake

  Add the installation prefix of "absl" to CMAKE_PREFIX_PATH or set
  "absl_DIR" to a directory containing one of the above files.  If "absl"
  provides a separate development package or SDK, be sure it has been
  installed.
Call Stack (most recent call first):
  CMakeLists.txt:318 (include)


-- Configuring incomplete, errors occurred!
See also "/home/user/works/cpp/grpc/cmake/build/CMakeFiles/CMakeOutput.log".
See also "/home/user/works/cpp/grpc/cmake/build/CMakeFiles/CMakeError.log".

```

```shell
CMake Error at third_party/protobuf/cmake/utf8_range.cmake:4 (message):
  Cannot find third_party/utf8_range directory that's needed to build
  conformance tests.  If you use git, make sure you have cloned submodules:

    git submodule update --init --recursive

Call Stack (most recent call first):
  third_party/protobuf/CMakeLists.txt:346 (include)
  third_party/protobuf/cmake/CMakeLists.txt:9 (include)


-- Configuring incomplete, errors occurred!
See also "/home/user/works/cpp/grpc/CMakeFiles/CMakeOutput.log".
See also "/home/user/works/cpp/grpc/CMakeFiles/CMakeError.log".

```

**solution**

Add `set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")` to `CMakeLists.txt`

Using `git submodule update --init --recursive` to download submodule to `third_party` folder,
or using `git` command to download those submodules following [.gitmodules] (https://github.com/grpc/grpc/blob/v1.49.1/.gitmodules) manually.

Finally the folders are looks like below:

```shell
[user@localhost grpc]$ pwd
/home/user/works/cpp/grpc
[user@localhost grpc]$ ls third_party/
abseil-cpp        bloaty                cython.BUILD   googletest                 objective_c       protoc-gen-validate        README.md           upb         zlib
ABSEIL_MANUAL.md  boringssl-with-bazel  enum34.BUILD   incremental.BUILD          opencensus-protos  protoc-gen-validate.patch  rules_python.patch  utf8_range  zlib.BUILD
address_sorting   BUILD                 envoy-api      libprotobuf_mutator.BUILD  opentelemetry     py                         six.BUILD           xds         zope_interface.BUILD
android           cares                 futures.BUILD  libuv                      protobuf          rake-compiler-dock         toolchains          xxhash
benchmark         constantly.BUILD      googleapis     libuv.BUILD                protobuf.patch    re2                        twisted.BUILD       yaml.BUILD
[user@localhost grpc]$ ls third_party/protobuf/third_party/
abseil-cpp  benchmark  BUILD.bazel  googletest  utf8_range  zlib.BUILD

```

**unrecognized import path "golang.org/x/net"**

**error**
```shell
[ 27%] Generating err_data.c
go: golang.org/x/net@v0.0.0-20210614182718-04defd469f4e: unrecognized import path "golang.org/x/net" (https fetch: Get https://golang.org/x/net?go-get=1: dial tcp 142.251.43.17:443: i/o timeout)
go: golang.org/x/crypto@v0.0.0-20210513164829-c07d793c2f9a: unrecognized import path "golang.org/x/crypto" (https fetch: Get https://golang.org/x/crypto?go-get=1: dial tcp 142.251.43.17:443: i/o timeout)
go: error loading module requirements
make[2]: *** [third_party/boringssl-with-bazel/crypto/CMakeFiles/crypto.dir/build.make:85: third_party/boringssl-with-bazel/crypto/err_data.c] Error 1
make[2]: *** Deleting file 'third_party/boringssl-with-bazel/crypto/err_data.c'
make[1]: *** [CMakeFiles/Makefile2:8613: third_party/boringssl-with-bazel/crypto/CMakeFiles/crypto.dir/all] Error 2
make: *** [Makefile:152: all] Error 2

```

**solution**:
```shell
export PATH=$PATH:$(go env GOPATH)/bin
export GOPATH=$(go env GOPATH)
export GO111MODULE=on
export GOPROXY=https://goproxy.cn

```
**undefined reference to `SSL_CTX_ctrl'**
```shell
[ 70%] Linking CXX executable gen_hpack_tables
/usr/bin/ld: libgrpc.so.27.0.0: undefined reference to `SSL_CTX_ctrl'
/usr/bin/ld: libgrpc.so.27.0.0: undefined reference to `ENGINE_init'
/usr/bin/ld: libgrpc.so.27.0.0: undefined reference to `OPENSSL_sk_push'
/usr/bin/ld: libgrpc.so.27.0.0: undefined reference to `ENGINE_load_private_key'
/usr/bin/ld: libgrpc.so.27.0.0: undefined reference to `OPENSSL_sk_new_null'
/usr/bin/ld: libgrpc.so.27.0.0: undefined reference to `ENGINE_ctrl_cmd_string'
/usr/bin/ld: libgrpc.so.27.0.0: undefined reference to `ENGINE_set_default'
/usr/bin/ld: libgrpc.so.27.0.0: undefined reference to `ENGINE_by_id'
/usr/bin/ld: libgrpc.so.27.0.0: undefined reference to `SSL_ctrl'
/usr/bin/ld: libgrpc.so.27.0.0: undefined reference to `OPENSSL_sk_num'
/usr/bin/ld: libgrpc.so.27.0.0: undefined reference to `OPENSSL_sk_pop_free'
/usr/bin/ld: libgrpc.so.27.0.0: undefined reference to `OPENSSL_sk_value'
/usr/bin/ld: libgrpc.so.27.0.0: undefined reference to `SSL_CTX_callback_ctrl'
collect2: error: ld returned 1 exit status
make[2]: *** [CMakeFiles/gen_hpack_tables.dir/build.make:139: gen_hpack_tables] Error 1
make[1]: *** [CMakeFiles/Makefile2:639: CMakeFiles/gen_hpack_tables.dir/all] Error 2
make: *** [Makefile:152: all] Error 2

```
**solution**:
Using openssl.[how-to-build-grpc-with-openssl-instead-of-boringssl](https://stackoverflow.com/questions/63523196/how-to-build-grpc-with-openssl-instead-of-boringssl)

`-DgRPC_SSL_PROVIDER=package` 

```shell
cmake -DCMAKE_INSTALL_PREFIX=/usr/local/ -DgRPC_SSL_PROVIDER=package ../..
```

## 2. Generated api source file

**error**
```shell
/usr/local/bin/grpc_cpp_plugin: error while loading shared libraries: libgrpc_plugin_support.so.1.49: cannot open shared object file: No such file or directory
--grpc_out: protoc-gen-grpc: Plugin failed with status code 127.
make: *** [Makefile:33: helloworld.grpc.pb.cc] Error 1
```

**solution1**

Add `export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/lib64:/lib:/usr/lib64:/usr/lib:/usr/local/lib64:/usr/local/lib`
to `~/.bash_profile` and run `source ~/.bash_profle` in bash

**solution2**

Modify `/etc/ld.so.conf`

```shell
include ld.so.conf.d/*.conf
/lib64
/lib
/usr/lib64
/usr/lib
/usr/local/lib64
/usr/local/lib
```

And run `sudo ldconfig`

### 2.1 The protocol buffer compiler

```shell
[user@localhost grpc-cpp-server-sample]$ protoc -I ./protos --grpc_out=./api --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` ./protos/helloworld.proto
[user@localhost grpc-cpp-server-sample]$ ls api/
helloworld.grpc.pb.cc  helloworld.grpc.pb.h

```

```shell
[user@localhost grpc-cpp-server-sample]$ protoc -I ./protos --cpp_out=./api/ ./protos/helloworld.proto
[user@localhost grpc-cpp-server-sample]$ ls api/
helloworld.grpc.pb.cc  helloworld.grpc.pb.h  helloworld.pb.cc  helloworld.pb.h

```

> The generated code contains both stub code for clients to use and 
an abstract interface for servers to implement, both with the 
method defined in our Greeting service.

The code in those files are defined in namespace `helloword`.


## Ref

[cpp quickstart](https://grpc.io/docs/languages/cpp/quickstart/)

[cpp basic tutorial](https://grpc.io/docs/languages/cpp/basics/)

[gRPC C++ Hello World Tutorial](https://chromium.googlesource.com/external/github.com/grpc/grpc/+/chromium-deps/2016-07-19/examples/cpp/helloworld/README.md)

[grpc INSTALL](https://chromium.googlesource.com/external/github.com/grpc/grpc/+/chromium-deps/2016-07-19/INSTALL.md)

[grpc server cpp demo](https://github.com/ppdouble/grpc-cpp-server-sample)

[grpc client cpp demo](https://github.com/ppdouble/grpc-cpp-client-sample)

[grpc client with springboot demo](https://github.com/ppdouble/springboot-grpc-client-sample)

[grpc server with springboot demo](https://github.com/ppdouble/springboot-grpc-server-sample)

[grpc client java demo](https://github.com/ppdouble/grpc-service-sample-client)

[grpc server java demo](https://github.com/ppdouble/grpc-service-pemo)

[sprintboot with grpc server. Fork from nils](https://github.com/ppdouble/city-score)

[gRPC Java Client App Implementation](https://www.youtube.com/watch?v=J0AMX9YpdLk)

[grpc sample on github](https://github.com/techtter/grpc)


