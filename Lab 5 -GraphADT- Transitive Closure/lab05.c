/*CO 322-LAB 05
E/16/267
Parackrama G.T.W.*/


// Program for transitive closure
// using Floyd Warshall Algorithm

#include<stdio.h> 
  
// define no of nodes in the graph
#define VERTEX 7
 void printSolution(int reach[][VERTEX]) 
{ 
    printf ("\nFollowing matrix is Transitive closure of the given graph\n\n"); 
    for (int j = 0; j < VERTEX; j++) 
    { 
        for (int i = 0; i < VERTEX; i++) 
            printf ("%d ", reach[j][i]); 
        printf("\n"); 
    } 
    printf("\n");
}  
   


  
void transitive_Closure(int Graph[][VERTEX]) 
{ 
    int reach[VERTEX][VERTEX], i, j, k; 
  
    for (i = 0; i < VERTEX; i++) 
        for (j = 0; j < VERTEX; j++) 
            reach[i][j] = Graph[i][j]; 
  
    for (k = 0; k < VERTEX; k++) 
    { 
        for (i = 0; i < VERTEX; i++) 
        { 
            for (j = 0; j < VERTEX; j++) 
            { 
                if(i==j){
                   reach[i][j] = 1;
                }else{
                   reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]); 
                }
            } 
        } 
    } 
  
    printSolution(reach); 
}


int main() 
{ 
    // Insert adjacency matrix of the given graph
   int Graph[VERTEX][VERTEX] = { {0, 1, 1, 0, 0, 0, 0}, 
                        {0, 0, 0, 0, 1, 0, 0}, 
                        {0, 0, 0, 0, 0, 1, 0}, 
                        {0, 1, 0, 0, 1, 0, 1},
                        {0, 0, 0, 0, 0, 0, 1},
                        {0, 0, 0, 1, 0, 0, 0},
                        {0, 1, 0, 0, 0, 0, 0}
                      }; 
	//if assuming has self loops
	/*int Graph[VERTEX][VERTEX] = { {1, 1, 1, 0, 0, 0, 0}, 
                        {0, 1, 0, 0, 1, 0, 0}, 
                        {0, 0, 1, 0, 0, 1, 0}, 
                        {0, 1, 0, 1, 1, 0, 1},
                        {0, 0, 0, 0, 1, 0, 1},
                        {0, 0, 0, 1, 0, 1, 0},
                        {0, 1, 0, 0, 0, 0, 1}
                      }; */
	
  /*int graph[VERTEX][VERTEX]={ {0,1,1,0},
                        {0,0,0,0},
                        {0,0,0,1},
                        {0,1,0,0}};*/
  
    // Printing the solution 
    transitive_Closure(Graph); 
    return 0; 
} 
