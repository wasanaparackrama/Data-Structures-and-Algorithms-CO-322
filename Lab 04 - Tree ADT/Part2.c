/****Radix Tree (Trie) Structure for Text Auto-complete
Part 2-Come up with a way to reduce the space usage
of your Trie structure by removing unnecessary nodes without losing any information.
E/16/267
Parackrama G.T.W.
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include<ctype.h>


//maximum childnode size(alphabet size)
#define SIZE 26

//for count nodes
int count=0;

//structure for linking the string
typedef struct linkedString
{
	char letter;
	struct linkedString *next;
}linkedString;


//function for creating linked string
linkedString* createString(char newLetter)
{
    linkedString* temp = (linkedString*) malloc(sizeof(linkedString));
    temp -> letter = newLetter;
    temp -> next = NULL;
    return temp;
}

//structure for a node
typedef struct  radixNode
{
    struct  radixNode* child[SIZE];
    linkedString* linkedString;
	//represent end of the word
    bool endOfWord;
} radixNode;

//function to string to char
int stringToChar(linkedString* begin,char* str,int initial)
{
    int newSize = initial;
    linkedString* currentLetter = begin;

    while (currentLetter != NULL)
    {
        str[newSize] = currentLetter->letter;
        newSize++;
        currentLetter = currentLetter->next;
    }
    str[newSize] = '\0';
    return newSize-1;
}

//to generate the position of the character
int getPosition(char character)
{ 
   int position;
	if(character>64 && character<91){
			//if capital convert it into simple and generate index
			position = 32 +(int)character - (int)'a';
	return position;
	
	}else if(character>96 && character<123){
			//generate index for simple letters
			position = (int)character - (int)'a';
	return position;
	}
	else
     return -1;
}




//function for create a new node
 radixNode* createNode()
{
    radixNode* newradixNode = ( radixNode*)malloc(sizeof( radixNode));
    newradixNode->linkedString = NULL;
	//initializing elements in the node
    newradixNode->endOfWord = false;
    int i;
    for (i=0;i<26;i++)
    {
    	newradixNode->child[i] = NULL;
    }
    return newradixNode;
}

//append letters to a linkedstring
linkedString* AppendStr(char* str,int inital,int end)
{
    
    linkedString* curr= createString(str[inital]);
    linkedString* temp = NULL;
    linkedString* nwStr = curr;

    for(int i=inital+1;i<end;i++)
    {
        temp = createString(str[i]);
        curr->next = temp;
        curr = curr->next;
    }
    curr = NULL;
    return nwStr;
}

//divide the string among previous and current node depend on the breakpoint
 radixNode* divideLinkedStr( radixNode* prevNode, radixNode* node,linkedString* breakPoint)
{
    radixNode* tempNode = createNode();
    linkedString* temp = breakPoint->next;
    breakPoint->next = NULL;
    int position1 = getPosition(temp->letter);

    tempNode->linkedString = node->linkedString;
    node->linkedString = temp;
    tempNode->child[position1] = node;

    int position2 = getPosition(tempNode->linkedString->letter);
    prevNode->child[position2] = tempNode;

    return tempNode;
}

//function to insert words in to radix tree
void insertWord( radixNode* root,char* word)
{
    
    int position;

    radixNode* currentNode = root, 
	*prevNode = NULL;
    radixNode* newNode = NULL;
    linkedString* currentLetter, *previousLetter = NULL;
	currentLetter = currentNode->linkedString;
	
	//go through all the letters of the word
    for(int i = 0 ; i < strlen(word) ; i ++)
    {
    	position = getPosition(word[i]);
        if(position >= 0){
    	    if(currentLetter == NULL)
            {
    		if(currentNode->child[position] == NULL)
    		{
    			newNode = createNode();
    			newNode->linkedString = AppendStr(word,i,(strlen(word)-1));
                        newNode->endOfWord = true;
    			currentNode->child[position] = newNode;
    			count = count+1;
    			break;
    		}else
                {
                        prevNode = currentNode;
                        currentNode = currentNode->child[position];
                        previousLetter = currentNode->linkedString;
						currentLetter = currentNode->linkedString->next;
    		}
    	    }else
            {
    		if (currentLetter->letter != word[i])
    		{
    			currentNode = divideLinkedStr(prevNode,currentNode,previousLetter);
    			newNode = createNode();
    			newNode->linkedString = AppendStr(word,i,(strlen(word)-1));
                newNode->endOfWord = true;
    			currentNode->child[position] = newNode;
    			break;
    		}else
                {
                previousLetter = currentLetter;
    			currentLetter = currentLetter->next;
    		}
    	    }
        }
    
    }
}
//function to search a word in the tree
 radixNode* searchWord( radixNode* root,char* word)
{
   
    radixNode* tempstr = root;
    linkedString* curr = tempstr->linkedString;
	
	 int length = strlen(word);
    int i=0,position,check=1;

    while(i<length)
    {
    	position = getPosition(word[i]);
    	if(curr == NULL && check)
        {
            tempstr = tempstr->child[position];
            if(tempstr != NULL){
    	       curr = tempstr->linkedString->next;
            }
            else{
               check=0;
            }
    	}
        else if(check && curr != NULL)
        {    
    	    curr = curr->next;
    	}
        i++;
    }

    while(curr != NULL)
    {
    	word[length] = curr->letter;
    	curr = curr->next;
    	length++;
    }
    word[length] = '\0';

    return tempstr;
}




//function to give set of words start with given word
void printSuggetions( radixNode* suggestedNode,char wordBuffer[],int bufferSize)
{
    radixNode* root = suggestedNode;
    
	//print the word when meet the end
    if(root->endOfWord)
    {
        for (int j=0;j<bufferSize;j++)
        {
            printf("%c",wordBuffer[j]);
        }
        printf("\n");
    }

    for (int i=0;i<26;i++)
    {
        if(root->child[i]!=NULL)
        {    
			////assigning next letter to word to the next charIndex
            int newSize = stringToChar(root->child[i]->linkedString,wordBuffer,bufferSize);
            printSuggetions(root->child[i],wordBuffer,newSize+1);
        }
    }
}




//main function
int main(int argc,char *argv[]){

    
  	radixNode* root = createNode();//create the root node
	clock_t begin, time;
	
	
	int len;
	char str[100];
	char s[50];
	
	if(argc==1){
    printf("Usage: ./<excutable_file> <filename.txt>\n");
    exit(1);
  }
	FILE *fp=fopen(argv[1],"r");; //poniter for reading the file
	
	

	 //Check the existence of the file
	if(fp==NULL){
	    printf("Cannot open the file...");
	    exit(1);
	 }
	
	  
	  //read until meet the end of file and insertWord it into trie structure
	  begin=clock();
	  while(!feof(fp)){
				//read the word
				fgets(str,100,fp); 
				char c[50];
				len = strlen(str);
				str[len-1]='\0';
				strcpy(c,str);
				insertWord(root,c);

	  }
	  time=clock()-begin;
	  
	  //close  file
	  fclose(fp);
	  
	  //getting the single node size
	  int nodeSize=sizeof(*root); 

	  //display time taken to store
	  printf("\nTime taken to store the list %f sec\n", ((double)time)/CLOCKS_PER_SEC);
	  //node count
	  printf("no of nodes %d\n",count); 
	  //size of a one node size
	  printf("Size of a node %d\n",nodeSize);
	  //used total memory
	  printf("Memory need to store the list=%d Bytes\n",count*nodeSize); 

	  
	  
    while(1){

			printf("\nEnter a prefix...\n");
			//get user input
			scanf("%s",s); 
			printf("\n---------Word Suggestions----------\n");
			
			begin = clock();
			//find the last node for the given prefix
			radixNode* suggestedNode =  searchWord(root,s);
			//set of suggested words
			printSuggetions(suggestedNode,s,strlen(s)); 
			
			time = clock()-begin;
			double time_spent=((double)time)/CLOCKS_PER_SEC;
			
			 //display time taken to print suggestions list
			printf("\nTime taken to insert and print a suggestions list%f sec\n", time_spent); 
			printf("------------------------------\n");
    }
    return 0;
}
