CU_APPS=simple2DFD simpleMultiGPU simpleP2P_PingPong
C_APPS=simpleC2C simpleP2P simpleP2P_CUDA_Aware
C_OBJS=simpleP2P.o simpleP2P_CUDA_Aware.o

all: ${C_APPS} ${CU_APPS}

simpleC2C: simpleC2C.c
	mpicc -g -o simpleC2C simpleC2C.c

simpleP2P.o: simpleP2P.c
	nvcc -g -c -o simpleP2P.o -I/usr/include/x86_64-linux-gnu/openmpi/ ./simpleP2P.c
simpleP2P: simpleP2P.o	
	nvcc -lm -lcudart -lcublas -L-I/usr/include/x86_64-linux-gnu/openmpi/lib -lmpi_cxx \
	-lmpi -lopen-rte -lopen-pal -ldl -lnsl -lutil -lm  simpleP2P.o -o simpleP2P

simpleP2P_CUDA_Aware.o: simpleP2P_CUDA_Aware.c
	nvcc -g -c -o simpleP2P_CUDA_Aware.o -I/usr/include/x86_64-linux-gnu/openmpi/ ./simpleP2P_CUDA_Aware.c
simpleP2P_CUDA_Aware: simpleP2P_CUDA_Aware.o
	nvcc -lm -lcudart -lcublas -L-I/usr/include/x86_64-linux-gnu/openmpi/lib -lmpi_cxx \
	-lmpi -lopen-rte -lopen-pal -ldl -lnsl -lutil -lm  simpleP2P_CUDA_Aware.o -o simpleP2P_CUDA_Aware

%: %.cu
#	nvcc -O2 -arch=sm_20 -I${MPI_HOME}/include -o $@ $<
	nvcc -g -G -arch=sm_80 -I${MPI_HOME}/include -o $@ $<
%: %.c
#	gcc -O2 -std=c99 -I${MPI_HOME}/include -o $@ $<
	gcc -g -std=c99 -I${MPI_HOME}/include -o $@ $<
	
clean:
	rm -f ${CU_APPS} ${C_APPS} ${C_OBJS}
