#!/bin/sh

./configure --disable-munmap --disable-fill --disable-stats --enable-tls --without-export --with-jemalloc-prefix="" --disable-cache-oblivious
make
