#include <iostream>
#include <stdlib.h>
#include <stdio.h>


/*RECURSIVE ORNEK  
void yaz(int test) {
    if (test < 1)  
	      return;
	 else    { 
	 printf("%d ",test);       
	  yaz(test-1);        
	  printf("%d ",test);        
	  return;    
	  } 
	  } 
	  int main() 
	  {    
	  int test = 3;    
	  yaz(test);
}

int kackisi( int n ){
   if ( n <= 1 ){       
   printf("Sadece ben");      
    return 1;   
	}else{       
	printf("Ben ve sonraki, ");       
	kackisi(n-1);       
	return 1;   } 
	}
int main() {   
kackisi(3); 
}*/ 

//dugum ekleme 

struct agacdugum{
	struct agacdugum *soldal;
	int data;
	struct agacdugum *sagdal;
};

struct agacdugum * dugumekle(struct agacdugum* agacptr, int veri) 
{ 
  if(agacptr==NULL){ 
  agacptr = malloc(sizeof (*agacdugum)); 
   if (agacptr!=NULL){
   agacptr->data = veri;
   agacptr->soldal = NULL; 
   agacptr->sagdal= NULL; 
   }  else 
   printf("%d eklenemedi. Bellek yetersiz.\n",veri); 
  }else
   { if(veri < agacptr->data){
        printf("Aðaçýn soluna veri eklendi\n ");     
        agacptr->soldal = dugumekle(agacptr->soldal,veri); }
	else{
	    if(veri > agacptr->data){
	       printf("Aðaçýn saðýna veri eklendi\n ");
	       agacptr->sagdal = dugumekle(agacptr->sagdal,veri); 
	    }
		else
	    printf("Eþit olduðu için alýnmadý\n "); 
		} 
		} 
		return agacptr; 
		}
		
void inorder(struct agacdugum * agacptr) {
 if (agacptr != NULL) { inorder(agacptr->soldal); 
 printf("%3d",agacptr->data); 
 inorder(agacptr->sagdal); 
 } 
 } 
 void preorder(struct agacdugum * agacptr)  { 
 if (agacptr != NULL) {
  printf("%3d",agacptr->data); 
  preorder(agacptr->soldal);
   preorder(agacptr->sagdal); 
   } 
   } 
   void postorder(struct agacdugum * agacptr) { 
   if (agacptr != NULL) {       
    postorder(agacptr->soldal);        
	postorder(agacptr->sagdal);       
	 printf("%3d",agacptr->data);   
	 }}

int main(){ 
int i, dugum;
struct agacdugum * agacptr = NULL; 
for(i=0; i<12; ++i){ 
scanf("%d",&dugum); printf("\n"); 
agacptr = dugumekle(agacptr, dugum); 
} 
printf("\n");
printf("Aðacýn preorder dolaþýlmasý :\n"); 
preorder(agacptr); printf("\n");
printf("Aðacýn inorder dolaþýlmasý :\n");
 inorder(agacptr); printf("\n");
printf("Aðacýn postorder dolaþýlmasý :\n"); 
postorder(agacptr); printf("\n");
return 0;

}






