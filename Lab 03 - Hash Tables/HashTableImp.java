/*********************************************
 * CO322: Data structures and algorithms

 * Implementation of the hashTable
 *********************************************/

/*Enumber:E/16/267
  Name:Parackrama G.T.W  */




class HashTableImp implements HashTable {

	//to count the no of key/value pairs
	private int n;
	
    private static class Node {
      String key;
      int value=0;
      //pointer to next node in the list;
      Node next; 
    }
    //hash table
 	public Node[] hashTable;
 
    public HashTableImp(int buckets) {
    	//create the hashTable
		hashTable = new Node[buckets];
    }


	/** function for inserting the key/value **/
	public void insert(String key){
		//get the bucket index from hash function
		int bucketNo =hashfunction(key);
		Node newNode = null; 
		
		try{
			
			//get reference to the corresponding node
			newNode = hashTable[bucketNo]; 
			
			//go through the list to check whether key exists or not
			while(newNode!=null){ 
				if(newNode.key.equals(key)){
					break;
				}
				newNode = newNode.next;
			}
				
			if(newNode !=null){
				 //if key exists increment the value 
				newNode.value++;
			}else{
			    //if not create new node and add to end of the list of the bucket
				Node newNode1 = new Node();  
				newNode1.key = key;
				newNode1.value++;                                          
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
				newNode1.next = hashTable[bucketNo];
				hashTable[bucketNo] = newNode1;
				n++;
			}
			
		}catch(Exception e){
			System.out.println(e);
		}
		
		
		
	}
	/** function for searching the value **/
	public int search(String key){
		int bucketNo = hashfunction(key);//get the bucket number
		Node newNode = hashTable[bucketNo];//get the list to a node
		
		//go through list and check for the key
		while(newNode!=null){
			if(newNode.key.equals(key)){
				return newNode.value;
			}
			newNode = newNode.next;
		}
		//key not found
		return 0;
	} 
	 
	/**function to check the existance of key/value **/
	public boolean isContain(String key){
		int bucketNo = hashfunction(key);//get bucket number
		Node newNode = hashTable[bucketNo]; //get corresponding list
		
		//go through list and check for the key
		while(newNode!=null){
			if(newNode.key.equals(key)){
				return true;
			}
			newNode = newNode.next;
		}
		//if key not found
		return false;
	}
	

	/** function to get the hash table size**/
	public int getTableSize(){
		return n;
	}
	
	
	/* here i have implemented 3 hash functions 
	 * division method and two multiplication methods
	 */
	
	
	
	//hashfunction division method
	public int hashfunctionDivision(String key){
		
		
		int h=0;
		//sum up the ascci value of the word
		for(int i=0;i<key.length();i++){
		 h=h+(int)key.charAt(i);
		}
		//return modulus of sum of ascii values
		return h%hashTable.length;
	}
	
	
	//hashfunction multiplication method
		public int hashfunctionMultiplication(String key){
			//can chage the A value;
			double A=0.61;
			int h;
			long sum=0;
			//sum up the ascci value of the word
			for(int i=0;i<key.length();i++){
				sum=sum+(int)key.charAt(i);
				
			}
			//return modulus of sum of ascii values
			h=(int)Math.floor(((hashTable.length)*((A*sum)%1)));
			return h;
		}
		
	
	
	
	
	/**hash function another multiplcation method(good function)**/
	public int hashfunction(String key){
		//set the multiplier
		int mul=43;
		int h=0;
		
		//sum up the ascci value of the word
		for(int i=0;i<key.length();i++){
			h=(h*mul+key.charAt(i))%hashTable.length;
		}
		//return modulus of sum of ascii values
		return h%hashTable.length;
	}  
	
	/**function to each bucket size, minimum and maximum no of entries, average and standard deviation**/
	public void getBucketSize(int size){
		
		float d=0;
		int j=0,max=0,min=100000;
		float average =(float) n/size;
		
		
		for(int i=0;i<size;i++){
			Node newNode = hashTable[i];
			while(newNode != null){
				j++;
				newNode = newNode.next;
			}
			if(max<j){max=j;}//find maximum no of entries
			if(min>j){min=j;}//find minimum no of entries
			System.out.println("Bucket "+(i+1)+" -> no of elements : "+j); //display no of entries in the bucket
			d += Math.pow((j-average),2);
			j=0;
		}
		
		System.out.println("\nThe minimum no of entries : "+min);
		System.out.println("The maximum no of entries : "+max);
		
		double deviation = Math.sqrt(d/size);//calculate standard deviation
		
		System.out.println("Total elements : "+getTableSize()); //total no of entries in hash table
		System.out.println("Average no of elements per bucket : "+average);//average no of entries in a bucket
		System.out.println("Standard deviation : "+deviation);//display the standard deviation
		
	}
	
	
	
	  

}// end HashTableImp 
