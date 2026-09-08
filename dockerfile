FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    software-properties-common \
    && add-apt-repository ppa:ubuntu-toolchain-r/test -y \
    && apt-get update && apt-get install -y \
    build-essential \
    g++-13 \
    make \
    gdb \
    valgrind \
    libstdc++6 \
    && rm -rf /var/lib/apt-get/lists/*

WORKDIR /app

CMD ["/bin/bash"]