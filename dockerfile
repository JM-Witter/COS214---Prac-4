FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    g++ \
    make \
    gdb \
    valgrind \
    && rm -rf /var/lib/apt-get/lists/*

WORKDIR /app

CMD ["/bin/bash"]