

//Name:G.T.W. Parackrama
//E number:E/16/267

//(d) Use dynamic programming to improve the runtime.

import java.util.Map;
import java.util.HashMap;
class task4 {
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

    
    
    static Map<String,Integer> costMap = null;
    static int comp =0;
    
    

    public static String indexToKey(int i, int j) {	
	return Integer.toString(i) + Integer.toString(j);
    }

    public static Map<String, Integer> initHashMap() {
	Map<String,Integer> costs = new HashMap<String, Integer>();
	for(int i=0; i < jMax-1; i++) {
	    String s = indexToKey(i, i+1); 
	    costs.put(s, cost[i][i+1]);
	}
	return costs; 
    }
    
    public static int minCostDynamicPro(int i, int j) {
    	
    comp ++; 
	if(costMap == null) costMap = initHashMap();
	if(costMap.containsKey(indexToKey(i,j))) 	
	    return costMap.get(indexToKey(i,j));
	

	int min = cost[i][j];
	for(int k = i+1; k < j; k++) {
	    int tmp = minCostDynamicPro(i, k) + minCostDynamicPro(k, j);
	    if(min > tmp) min = tmp; 	    
	}
	costMap.put(indexToKey(i,j), min); 
	return min;
    }
	
    
    public static void main(String [] args) {
    	
	for(int l=1; l<jMax; l++) {
		comp=0	 ;   
	    int r =minCostDynamicPro(0,l);
		// System.out.println("Minimum cost="+ r);
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
    
