#!/usr/bin/env bash

LIBS_WE_NEED="core;s3;cloudformation;iam;ec2"

if [ ! -d aws-sdk-cpp ]; then
  echo "AWS SDK Source: Not found"
  git clone --depth 1 https://github.com/aws/aws-sdk-cpp aws-sdk-cpp
else
  echo "AWS SDK Source: Found"
fi

pushd aws-sdk-cpp

if [ ! -d build ]; then mkdir build; fi

pushd build

cmake \
  -DBUILD_ONLY="${LIBS_WE_NEED}" \
  -DCMAKE_BUILD_TYPE=Release \
  -DENABLE_TESTING=OFF \
  -DCMAKE_TOOLCHAIN_FILE=64bit.toolchain
  -Wno-dev \
  ..

make
