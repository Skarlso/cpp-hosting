# C++ Hosting solution

Build status: [![Build Status](https://travis-ci.org/Skarlso/furnace.svg?branch=master)](https://travis-ci.org/Skarlso/furnace)

# Compile

```bash
$ git submodule init
$ git submodule update
$ cmake . && make furnace
```

# Testing

```bash
$ cmake . && cmake --build . && ctest
```

If you'd like to see log messages for individual test cases, logging has to be enabled and
the test has to be executed alone in it's own executable like this:

```bash
export BOOST_TEST_LOG_LEVEL=message
$ ./bin/test/test_executable
```
