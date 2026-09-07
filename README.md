# COS214---Prac-4

### Docker Commands

docker build -t prac4 .
#####
docker run --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -it -v "$(pwd)":/app prac4