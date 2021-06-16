/********************************************

* CO322: Data structures and algorithms

* Interface for the HashTable

********************************************
*
*
/*Enumber:E/16/267
  Name:Parackrama G.T.W */


interface HashTable {

/* insert the given key to a open hash tabled.
 
 * With each key you have a count of how many times it 

 * was inserted 
 
 */


public void insert(String key);


/* given the key return the number of times it was inserted 
 
 * to the table 
 
*/


public int search(String key);

}


