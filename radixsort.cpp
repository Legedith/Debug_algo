#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int getDigit(int arr[]);
void radixsort(int arr[],int digit);
struct node* createnode(int value);

int main(){
    int arr[]={123, 45, 6, 7890, 123456};
    int digit=getDigit(arr);
    printf("the maximum digit in array is:%d",digit);
    printf("\n The sorted array is:");
    radixsort(arr,digit);
    }
    
// get max number of digit in an array
  
int getDigit(int arr[]){
    int max=arr[0];
    int count=0;
    for(int i=1;i<5;i++){
        if(arr[i]>max)
        max=arr[i];
    }
    while(max!=0){
        max=max/10;
        count++;
    }
    return count;
}


//strucure
struct node {
    int data;
    struct node* next;
};

// for creating node
struct node* createnode(int value)                                
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    return newnode;

}

//sorting function
void radixsort(int arr[],int digit)
{
    struct node poarr[10];              //initialise array of structure

    int tempArr[5];
    for(int i=0;i<5;i++){
        tempArr[i]=arr[i];
    }

    int k=10;
    for (int i=0;i<digit;i++){
        for(int j=0;j<5;j++){
        int index=tempArr[j]%k;
        //print index and element, i
        printf("\n index:%d element:%d i:%d \n",index,tempArr[j], i);
       
        if(poarr[index].next==NULL) {
            poarr[index].next=createnode(arr[j]);
            poarr[index].next->next=NULL;
           
          } 

	    else {
            struct node* temp1=poarr[index].next->next;
            struct node* temp2=poarr[index].next;
            while(temp1!=NULL) {
                temp1=temp1->next;
                temp2=temp2->next;
            }
            temp1=createnode(arr[j]);
            temp2->next=temp1;
            }
       
     
    }
            while((digit-1)){
            for(int i=0;i<10;i++){
            if(poarr[i].next!=NULL)
                free(poarr[i].next);
            }
        }
    k=k*10;
   }
     
  for(int i=0;i<10;i++){
    struct node* vartemp=poarr[i].next->next;
    while(vartemp!=NULL) {
        printf(" %d ",vartemp->data);
        vartemp=vartemp->next;
}
    }
}
    


   
