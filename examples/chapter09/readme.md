# Instruction on running MPI app.
First make sure to install openlib library:

```
sudo apt install libopenmpi-dev
```

to run: 
```
mpirun -np 2 --allow-run-as-root simpleC2C
```

Set up MPI_HOME:
export MPI_HOME=/usr/include/x86_64-linux-gnu/openmpi

