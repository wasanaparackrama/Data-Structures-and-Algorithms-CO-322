

/*********************************************
 * CO322: Data structures and algorithms

 /** Testing  Hash Table**/
 /*********************************************/

/*Enumber:E/16/267
  Name:Parackrama G.T.W  */



import java.io.*;
import java.util.*;

public class HashTest extends HashTableImp{
	
	public HashTest(int size){
		super(size);
	}
	
	public static void main(String []args){
		HashTest hashMain;
		int tableSize;
		String str;
		String fileName;
		
		if(args.length==2){
			//hashtable size from commandline arugement arg[0]
			tableSize = Integer.valueOf(args[0]); 
			if(tableSize <= 0) {throw new IllegalArgumentException("Table size should be positive number");}
			
			hashMain = new HashTest(tableSize);
			
			//getting file name
			fileName = args[1]; 
			
			//file operations
			try{
				BufferedReader buffer = new BufferedReader(new FileReader(fileName));
				while((str=buffer.readLine())!=null){
					//replace alphanumeric characters from whitespaces and make all letters to lower case
					String s = str.replaceAll("\\W"," ").toLowerCase();
					//split lines
					String split[] = s.split("\\s+");
					
					
					// insert strings into hash table
					for(String string:split){
						hashMain.insert(string);
					}
					
				}
				
			}
			catch (FileNotFoundException e)
			{
				System.out.println("File does not exists");
				System.exit(0);
			}
			catch (IOException e) 
			{
				System.out.println("File reading failed");
				System.exit(0);
			}	
			//display no of elements in each bucket
			hashMain.getBucketSize(tableSize);
			
			Scanner c = new Scanner(System.in);
			String stringKey;
			
			//searching for elements in hashTable
			do{
				System.out.println("\nEnter a key string: ");
				stringKey = c.nextLine();
				System.out.println("Value = "+hashMain.search(stringKey));
			}while(!stringKey.equals("exit"));
			
		//handeling wrong arugements
		//printing message for wrong arguments	
		}else{
			System.out.println("Usage:");
			System.out.println("java HashTest <no_of_buckets> <samlpe_file_name> "); 
			System.out.println("if file was not in the same folder add the location with samlpe_file_name "); 
			System.out.println("Type <exit> to quit "); 
		}
		
	}	
}

