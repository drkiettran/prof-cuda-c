CC = gcc
#CFLAGS = -g -Wall -Wextra -Werror -std=gnu99
CFLAGS = -g

APPS = queue ref-queue passing_args pointer_arith mem_mgmt structs macros typedefs casting cstdlib file2 static structs_2



file2: file1.c file2.c
	$(CC) -c -o file1.o file1.c
	$(CC) -c -o file2.o file2.c
	$(CC) -o file2 file1.o file2.o

static:
	$(CC) $(CFLAGS) -o static static.c
	
structs:
	$(CC) $(CFLAGS) -o structs structs.c 

structs_2:
	$(CC) $(CFLAGS) -o structs_2 structs_2.c 

macros:
	$(CC) $(CFLAGS) -o ./extras/macros ./extras/macros.c 

typedefs:
	$(CC) $(CFLAGS) -o ./extras/typedefs ./extras/typedefs.c 

casting: ./extras/casting.c
	$(CC) $(CFLAGS) -o ./extras/casting ./extras/casting.c

passing_args: ./extras/passing_args.c
	$(CC) $(CFLAGS) -o ./extras/passing_args ./extras/passing_args.c 

pointer_arith: pointer_arith.c
	$(CC) $(CFLAGS) -o pointer_arith pointer_arith.c 
	
mem_mgmt: mem_mgmt.c
	$(CC) $(CFLAGS) -o mem_mgmt mem_mgmt.c 

queue: ./extras/main.c ./extras/student-queue.c
	$(CC) $(CFLAGS) -o ./extras/student_queue_test ./extras/student-queue.c ./extras/main.c

ref-queue: ./extras/main.c ./extras/ref-queue.c
	$(CC) $(CFLAGS) -o ./extras/ref_queue_test ./extras/ref-queue.c ./extras/main.c

cstdlib: atoi.c files.c getopt.c strcat.c strlen.c strcpy.c
	$(CC) $(CFLAGS) -o atoi atoi.c
	$(CC) $(CFLAGS) -o files files.c
	$(CC) $(CFLAGS) -o getopt getopt.c
	$(CC) $(CFLAGS) -o strcat strcat.c
	$(CC) $(CFLAGS) -o strlen strlen.c
	$(CC) $(CFLAGS) -o strcpy strcpy.c

all: ${APPS}

clean:
	rm -f ${APPS}

#	rm ./extras/student_queue_test ./extras/ref_queue_test ./extras/passing_args pointer_arith mem_mgmt structs ./extras/macros ./extras/typedefs ./extras/casting atoi files getopt strcat strlen strcpy
