# C++ Hosting solution

# Compile

Thanks to cmake's out-of-source builds, this way, every build information will be under
the build directory and make will also work from there.

```bash
$ git submodule init
$ git submodule update
$ cd build && cmake .. && cmake --build .
```

# Testing

```bash
$ cd build && cmake .. && cmake --build . && ctest
```

If you'd like to see log messages for individual test cases, logging has to be enabled and
the test has to be executed alone in it's own executable like this:

```bash
export BOOST_TEST_LOG_LEVEL=message
$ cd build && ./testBin/test_executable
```
