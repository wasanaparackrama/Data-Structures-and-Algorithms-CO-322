/**** Tree (Trie) Structure for Text Auto-complete
Part 1-Design and implement a Trie node structure and associated operations and algorithms to store and retrieve
a collection of English words.
E/16/267
Parackrama G.T.W.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>


//maximum childnode size(alphabet size)
#define SIZE 26 
//for count nodes
int count=0;

// basic stucture for trie node
typedef struct trieNode{
	struct trieNode *child[SIZE];
	bool EndOfWord;
	
}TrieNode;

TrieNode *newtrieNode;

//function to initialze newnode and create newnode
TrieNode *createNode(){
	TrieNode *newtrieNode = NULL;
	newtrieNode = (TrieNode *)malloc(sizeof(TrieNode));
	
	newtrieNode->EndOfWord = false;
	
	for (int i = 0; i < SIZE; i++){
    		newtrieNode->child[i] = NULL;
  }
	count++;
	return newtrieNode;
}

//function to insert a word into TrieNode
void insertWord(TrieNode *root, const char *word){
	int i,charIndex;

	TrieNode *newtrieNode = root;

	for (i = 0; i < strlen(word); i++){
    //checking  capital ,simple letters and other characters
		if(word[i]>64 && word[i]<91){
			//convert capital to simple and generate index
			charIndex = 32 +(int)word[i] - (int)'a'; 
		}else if(word[i]>96 && word[i]<123){
			//to generate index for simple letters
			charIndex = (int)word[i] - (int)'a'; 
		}else{
			
			continue;
		}

    //to represent the letter
		if (!newtrieNode->child[charIndex])
			newtrieNode->child[charIndex] = createNode();

		newtrieNode = newtrieNode->child[charIndex];
	}
	// end of the word
	newtrieNode->EndOfWord = true; 
}

//funtion to search a word in trie
bool searchNode(TrieNode *root, const char *word){
	int i,charIndex;
	newtrieNode = NULL;
	newtrieNode = root;


	for (i = 0; i < strlen(word); i++){
    //checking  capital ,simple letters and other characters
    if(word[i]>64 && word[i]<91){
			//convert capital to simple and generate index
  			charIndex = 32 +(int)word[i] - (int)'a';
  		}else if(word[i]>96 && word[i]<123){
			//generate index
  			charIndex = (int)word[i] - (int)'a';
  		}else{
  			continue;
  		}

		if (!newtrieNode->child[charIndex]){
      newtrieNode = NULL;
	  //if word does not exists return false
      return false; 
    }

		newtrieNode = newtrieNode->child[charIndex];
	}
	//return true or false depending on existance of index 
	return (newtrieNode != NULL && newtrieNode->EndOfWord);
}

//function to read the file
double fileRead(char *fileName,TrieNode *root){
  
  char str[100];
  FILE *fp = fopen(fileName,"r"); //poniter for reading the file
  int len;
  
  //Check the existence of the file
  if(fp==NULL){
    printf("Unable to open the file...");
    exit(1);
  }

  //read unitl meet the end of file and insertNode into trie structure
  clock_t begin=clock();
  while(!feof(fp)){
      fgets(str,100,fp);
      len = strlen(str);
      char c[50];
      insertWord(root, str);
      
  }
   clock_t time=clock()-begin;

  fclose(fp);//close the opened file
  int oneNodeSize=sizeof(*root); //getting the single node size

  printf("no of nodes %d\n",count); //node count
  printf("Size of a node %d\n",oneNodeSize); //size of a one node size
  printf("Memory need to store the list=%d Bytes\n",count*oneNodeSize); //used total memory
  
  double time_spent=((double)time)/CLOCKS_PER_SEC;

  return time_spent;
}

//function to give set of words begin with given word
void printSuggestions(TrieNode *root, char wordBuffer[],int size){
	
	 //when meet the end print the word 
	 if (root->EndOfWord) { 
     for(int i=0;i<size;i++){
            printf("%c",wordBuffer[i]);
      }
        printf("\n");
    }

    for(int i=0;i<26;i++){
        if(root->child[i]!=NULL) {
           wordBuffer[size] = i+97; //assigning next letter to word to the next charIndex
           printSuggestions(root->child[i],wordBuffer,size+1);
        }
    }
}


//main function
int main(int argc, char *argv[]){
	
  TrieNode *root = createNode();
  clock_t begin, time;
  bool check;
  //how to excute the code
  if(argc==1){
    printf("Usage: ./<excutable_file> <filename.txt>\n");
    exit(1);
  }
  
  //to read the file
  double timeTaken=fileRead(argv[1],root);
  //to display time taken to store
  printf("\nTime taken to store the list %f sec\n",timeTaken);

 

  while(1){
	printf("\nEnter a prefix...\n");
    char text[100];
	//getting input prefix
	scanf("%s",text); 

    printf("\n---------Word Suggestions----------\n");
    begin = clock();
	
	//execute to detect the end node of prefix
	check = searchNode(root,text);
	
	//check whether prefix does not exists or not
	if(check==false && newtrieNode==NULL){ 
			printf("No Matching Suggestions\n");
	}else{
		  printSuggestions(newtrieNode,text,strlen(text)); //find word suggestions and print
		  time = clock()-begin;
		  
		  //display time taken to print suggestions list
    	  printf("\nTime taken to insert and print a suggestions list %f sec\n",((double)time)/CLOCKS_PER_SEC); 
	}
		printf("------------------------------\n");

	}
	return 0;
}
