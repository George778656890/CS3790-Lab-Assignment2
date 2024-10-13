CS3790 Lab Assignment2 : boss-worker computing model

Zhihong Liu(5088806)

12/Oct/2024


[worker.cpp] could compute all the primes within the range given by the command-line arguments.

[boss.cpp] could invoke the "worker" to create many processes to compute  all the primes from 1 to designated bound,and write all the results
into corresponding files.

File name: boss.cpp    worker.cpp

Compilation Command : g++ boss.cpp -o boss      g++ worker.cpp -o worker

Execution Command:       ./boss 4 300    (Create 4 processes to compute primes from 1 to 300,and write results to 4 files)                 

                          ./worker 1 10   (Compute all the primes from 1 to 10,and write the results to one file)



