//E/16/267

class Fib {

    public static int fib_r(int x) {
	if(x <= 2) return 1;
	return fib_r(x-1) + fib_r(x-2);
    }

    public static int fib_i(int x) {
	int a=1, b=1, fib=1, i=2;
	while(i<x) {
	    fib = a + b;
	    a = b;
	    b = fib;
	    i+=1;
	}
	return fib;
    }


    public static void main(String [] args) {
    	
	for(int x=0;x<=40;x++) {
	//recursive method	
	final long startTime_r = System.nanoTime();
	fib_r(x);
	System.out.println("Fib of recursive " + x + " = " + fib_r(x));
	final long endTime_r = System.nanoTime();  
    final long duration_r =  endTime_r - startTime_r;
    System.out.println("Time taken recursive "+duration_r/1000000+" nanoseconds.\n");
   
    //iterative method
    final long startTime_i = System.nanoTime();
    fib_i(x);
	System.out.println("Fib of iter" + x + " = " + fib_i(x));
	final long endTime_i = System.nanoTime();  
    final long duration_i =  endTime_i - startTime_i;
    System.out.println("Time taken to iterative "+duration_i/1000000+" nanoseconds.\n");
	}
    }
}