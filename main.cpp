//Hazem Abdel Hamied Mohamed Hassan
//20191525958
#include <iostream>
#include<stdlib.h>
typedef struct node{
int data;
node *left;
node *right;
};
using namespace std;
int main(void)
{
int **X;
int i,j,rows,cols,counter=0;
//insertion of the number of rows
cout<<"Enter number of rows:";
cin>>rows;
//insertion of the number of coloumns
cout<<"Enter number of columns:";
cin>>cols;
cout<<"Enter the matrix components"<<endl;
//Adjacency matrix should be a square matrix
if (rows==cols){
//Allocation of adjacency matrix
X=(int **)malloc(rows*sizeof(int*));
if(X==NULL){
   cout<<"Out of memory";
   return 1;}
for (i=0;i<rows;i++){
X[i]=(int *)malloc(cols*sizeof(int));
if(X[i]==NULL){
   cout<<"Out of memory";
   return 1;}
}
//insertion of the matrix
for(i=0;i<rows;i++){
  for(j=0;j<cols;j++){
     cin>>X[i][j];
     //checking input of unrooted graph
     if (X[i][j]<0){
        cout<<"invalid input ";
        return 1;}
     //checking the loops
     if (i==j && X[i][j]>0){
        cout<<"can't contain loops";
        return 1;}
     //checking the multiple edges
     if (X[i][j]>1){
        cout<<"can't contain multiple edges ";
        return 1;}
     if(X[i][j]==1)
         counter++;}
}
     //checking cycles
     if (counter/2>=cols || counter/2>=rows){
         cout<<"can't contatin cycles";
         return 1;}
}
     else
         cout<<"It's not an adjacency matrix because it is not square matrix";
     //to free memory
     for(i=0;i<rows;i++)
       free(X[i]);
free(X);
return 0;
}
