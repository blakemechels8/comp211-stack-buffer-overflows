CC = gcc

all: demo_safe demo_unsafe

# Default GCC flags on most Linux systems: stack canary enabled
demo_safe: demo.c
	$(CC) -O0 demo.c -o demo_safe

# Canary disabled so you can see the raw overflow behavior
demo_unsafe: demo.c
	$(CC) -O0 -fno-stack-protector demo.c -o demo_unsafe

clean:
	rm -f demo_safe demo_unsafe
