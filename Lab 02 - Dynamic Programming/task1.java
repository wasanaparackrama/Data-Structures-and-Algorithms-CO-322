

//Name:G.T.W. Parackrama
//E number:E/16/267

//Using recursion (or otherwise) implement the minCost function.

class task1 {
    static int [][] cost = {{0, 3, 12, 23, 41, 6, 211, 4}, // cost from 0 
			    {0, 0,  2,  4, 34, 4, 12, 43}, // cost from 1 
			    {0, 0,  0,  12, 3, 5, 2,  4}, // cost from 2 
			    {0, 0,  0,  0, 12, 4, 32, 3}, // cost from 3 
			    {0, 0,  0,  0,  0, 4, 3, 12},  // cost from 4
			    {0, 0,  0,  0,  0, 0, 3, 234},  // cost from 5
			    {0, 0,  0,  0,  0, 0, 0, 12},  // cost from 6
			    {0, 0,  0,  0,  0, 0, 0, 0}  // cost from 7 
    };
    static int iMax = 7;
    static int jMax = 7;

    // Just for testing, min cost from 0 to 4 should be 8.
    static int answer = 8;
    static int comp =0;
    
    

    static int minCost(int i, int j) {
	comp ++; 
	//System.out.printf("i=%d j=%d\n",i,j);
	if(j == i+1) return cost[i][j];
	
	int min = cost[i][j];
	for(int k = i+1; k < j; k++) {
	    int tmp = minCost(i, k) + minCost(k, j);
	    if(min > tmp) min = tmp; 	    
	}
	return min; 
    }
    
    

   
	
    
    public static void main(String [] args) {
	for(int l=1; l<jMax; l++) {
	    comp = 0;	    
	    int r =minCost(0,l);
	  //System.out.println("Minimum cost="+ r);
	    System.out.println("Complexity=" + comp);
	}
	/*
	if(r == answer)
	    System.out.println("Your implementation might be correct");
	else
	    System.out.println("Too bad. Try again (" + r + ")");

	System.out.println("Complexity=" + comp); 
	*/

    }
}
    
