# C++ Hosting solution

# Compile

Thanks to cmake's out-of-source builds, this way, every build information will be under
the build directory and make will also work from there.
```
$ git submodule init
$ git submodule update
$ cd build && cmake ..
$ make
```

Notes:
- CloudFormation
- Code Deploy
- Tar gzf the whole thing
