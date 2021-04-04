all: oss user

oss:
    gcc -Wall -pthread oss.c -o oss

user:
    gcc -Wall -pthread user.c -o user

clean:
    rm user
    rm oss
    rm logfile
