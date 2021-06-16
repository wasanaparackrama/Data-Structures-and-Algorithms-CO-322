#E/16/267


import matplotlib.pyplot as plt
import time


def fib_r(x):
    if (x <= 2):
        return 1
    return fib_r(x - 1) + fib_r(x - 2)


def fib_i(x):
    a = 1
    b = 1
    fib = 1
    i = 2
    while i < x:
        fib = a + b
        a = b
        b = fib
        i += 1

    return fib


length = [x for x in range(41)]

iter_time = []
recur_time = []

for i in length:
    # iterative execution time
    #start time
    ts_i = time.time() * 1000
    fib_i(i)
    print("Fib of iterative " + str(i) + " = " + str(fib_i(i)))
    #end time
    te_i = time.time() * 1000
    iter_time.append(te_i - ts_i)

    # recursive execution time
    # start time
    ts_r = time.time() * 1000
    fib_r(i)
    print("Fib of recursive " + str(i) + " = " + str(fib_r(i)))
    # end time
    te_r = time.time() * 1000
    recur_time.append(te_r - ts_r)

plt.plot(length, recur_time, "r", label='recursive')
plt.plot(length, iter_time, 'b', label='iterative')
plt.xlabel('Problem size')
plt.ylabel('time/ms')
plt.title("Run time for recursive and iterative method")
plt.grid()
plt.legend()
plt.show()
