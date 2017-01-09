/*Authors: Saikrishna Vasudevan; Saurabh Nair*/
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdbool.h>
typedef struct Vertices
{
    bool flag;
    int* edges;
    int16_t edges_size;


}Vertex;
typedef struct Vertices1
{
    bool flag;
    int* edges;
    int16_t headcount;
    int16_t last_index;

}Vertex1;
void dfs_rev(int node,Vertex1 * reverse_graph);
int* temp;
int j;
int last_vertex;
int forward_graph_run[875715] = {0};
int sum_of_headcounts=0;
int running_count = 1;
int current_leaders=0;


void bubble_sort(int* array){
int c,d,swap,f;
f =0 ;
  for (c = 0 ; c <5; c++)
  {
    for (d = 0 ; d < 5 - c - 1; d++)
    {
      if (array[d] > array[d+1]) /* For decreasing order use < */
      {
        swap       = array[d];
        array[d]   = array[d+1];
        array[d+1] = swap;
      }
    }
  }
}
int main(void)
    {
        Vertex* forward_graph=malloc(875715*sizeof(Vertex));
        Vertex1* reverse_graph=malloc(875715*sizeof(Vertex1));


        int y;
        for(y=0;y<875715;y++)
        {
            reverse_graph[y].headcount=0;
            //printf("hi\n");
            reverse_graph[y].last_index=0;
        }
//************************ FORWARD GRAPH ********************************
        printf("Loading the forward graph ....\n");
        int* buffer=malloc(1000*sizeof(int));
        int a;//Create a buffer of size 1000
        FILE* fp;
        fp=fopen("test.txt","r");
        int prev_tail,tail,head;
        a=fscanf(fp,"%i %i",&prev_tail,&head);
        int count=0;
        int size_count;
        int i;
        while(!feof(fp)&&a!=0)
        {
        buffer[0]=prev_tail;
        buffer[1]=head;
        count++;
        size_count=1;
        for(i=2;i<1000&&(a!=0);i++)
            {
                a=fscanf(fp,"%i %i",&tail,&head);                 //now read each rail-head pair using scanf..the first index of the buffer is the tail.
                if(prev_tail==tail&&a!=-1){             //printf("a: %d tail: %d head: %d\n",a,tail,head);
                         count++;
                         buffer[i]=head;
                         size_count++;
                         prev_tail=tail;
                }
                else{

                        prev_tail=tail;
                    break;
                }
            }
        forward_graph[buffer[0]].edges=malloc((size_count+1)*sizeof(int));
        forward_graph[buffer[0]].edges_size=size_count;
        last_vertex=buffer[0];
        temp=forward_graph[buffer[0]].edges;//alias for the edges pointer
        int j;
        for( j=1;j<size_count+1;j++)//copy the buffer to the edges pointer in the respected vertex of the forward graph as well as print it.
          {
            temp[j]=buffer[j];
                sum_of_headcounts++;     //increase the headcount
                reverse_graph[buffer[j]].headcount++;  //              printf("headcount of %d is %d\n",buffer[j],reverse_graph[buffer[j]].headcount);



        }
         }
        free(buffer);
        printf("Forward graph is Loaded\n");
        printf("\n\n\n\n");
        printf("The number of Edges in total is : %d and the total number of vertices are : %d and the total headcounts is : %d \n",count,last_vertex,sum_of_headcounts);
        //*************************************************************************


// **************** REVERSE GRAPH ************************
        fseek(fp,0,SEEK_SET);         //free all the edges in the forward graph

        printf("loading the reverse graph...\n");
        int o;
        for(o=0;o<875715;o++)//mallocing the edges array with size headcount..
        {
            reverse_graph[o].edges=malloc((reverse_graph[o].headcount+1)*sizeof(int));
            }
        while(!feof(fp)&&a!=0)
        {
                a=fscanf(fp,"%i %i ",&head,&tail);
                reverse_graph[tail].edges[reverse_graph[tail].last_index+1]=head;
                reverse_graph[tail].last_index++;

        }
  int p,re;
for (p=1;p<last_vertex+1;p++)
        {
            if(reverse_graph[p].headcount==0)
            {
                reverse_graph[p].edges[0]=0;
            }

        }



printf("Reverse Graph loaded...");
fclose(fp);
//*********************************
int wer;
printf("\n");
int node;
for (node= 1;node<=last_vertex;node++){
	if(reverse_graph[node].flag==0)
	{
	    reverse_graph[node].flag=1;
        dfs_rev(node,reverse_graph);
    }
}
int c;
int  leaders[5]={0};
for (c=last_vertex;c>=1;c--)
  {
        current_leaders=0;

          if(forward_graph[forward_graph_run[c]].flag==0)
          {
            forward_graph[forward_graph_run[c]].flag =1;
            current_leaders++;
            dfs_for(forward_graph_run[c],forward_graph);
          }
          if (leaders[0]<current_leaders)
          {
            leaders[0]=current_leaders;
            bubble_sort(leaders);
             }
  }
    int k;
  printf("Leaders array is : ");
  	for(k=0;k<5;k++)
    {
      printf("%d ",leaders[k]);
    }
    printf("\n");
    printf("Finisher array is : ");
    for(k=1;k<=9;k++)
    {
        printf("%d ",forward_graph_run[k]);
    }
    printf("\n");
    for (k=0;k<875715;k++)
    {
        free(forward_graph[k].edges);
        free(reverse_graph[k].edges);
    }
    free(forward_graph);
    free(reverse_graph);

    return 0;
    }
void dfs_rev(int node,Vertex1 * reverse_graph){
    int16_t saurabh;
    for (saurabh = 1; (saurabh <=reverse_graph[node].headcount); saurabh++ ){

            if (reverse_graph[reverse_graph[node].edges[saurabh]].flag ==0)
                {
            reverse_graph[reverse_graph[node].edges[saurabh]].flag = 1;
            dfs_rev(reverse_graph[node].edges[saurabh],reverse_graph);

            }
    }
    forward_graph_run[running_count] = node;
    running_count++;
  }
  int leaders[5]={0};


void dfs_for(int node,Vertex * forward_graph){
     int16_t sai ;
     for (sai = 1; sai <= forward_graph[node].edges_size; sai++ ){

            if (forward_graph[forward_graph[node].edges[sai]].flag ==0)
                {
            forward_graph[forward_graph[node].edges[sai]].flag = 1;
            current_leaders++;
            dfs_for(forward_graph[node].edges[sai],forward_graph);

            }
    }
}
