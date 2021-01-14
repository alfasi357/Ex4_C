#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define NUM_LETTERS ((int)26)

typedef enum {FALSE=0, TRUE=1} boolean;
typedef struct node {
char letter;
char *word;
boolean flag;
long unsigned int count;
struct node* children[NUM_LETTERS];
}node;

node* init(){
    node* n = (node*) malloc(sizeof(node));
    if(n==NULL)
    exit(1);
   n->count = 0;
   for(int i=0; i<26;i++){
       n->children[i]=NULL;
   }
   n->flag = 0;
   n->word =NULL;
    return n;
}

node* newnode(char str){
    node* n = (node*) malloc(sizeof(node));
    if(n==NULL)
    exit(1);
   n->letter = str;
   n->count = 0;
      for(int i=0; i<26;i++){
       n->children[i]=NULL;
   }
   n->flag = 0;
   n->word=NULL;
    return n;
}


node* add_node(node* root, char data) {
  if(root->children[data-'a']!=NULL){
   return root->children[data-'a'];
}else{
  node* n=newnode(data);
  if(root->word==NULL){
    n->word=(char*)malloc(2);
    n->word[0]=data;
    n->word[1]='\0';
  }
else{
  n->word=(char*)malloc(strlen(root->word)+2);
  if(n->word==NULL)
  exit(1);
  for(int i=0; i<strlen(root->word);i++){
    n->word[i]=root->word[i];
  }
  n->word[strlen(root->word)]=data;
  int a = strlen(root->word)+1;
  n->word[(a)]='\0';
}
  root->children[data-'a']=n;
  return root->children[data-'a'];
}
}

node* trie(node* root){
char c;
node* temp=root;
int co;
while(scanf("%c",&c)!=EOF){
co=0;
temp=root;
while(c!=' '&&c!='\n'&&c!='\r'&&c!='\t'){
 if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
 c=tolower(c);
 temp=add_node(temp,c);
 co++;
 }
 
 scanf("%c",&c); 

}
if(co){
temp->flag=1;
temp->count++;
}
}
return  root;
}

void print(node* root){
if(root==NULL)
return;
if(root->flag)
printf("%s %ld\n",root->word,root->count);
for(int i=0;i<26;i++){
  print(root->children[i]);
  }

  free(root->word);
  free(root);
  
}   

void print_r(node* root){
if(root==NULL)
return;

for(int i=25; i>=0; i--){
  print_r(root->children[i]);
  }
  if(root->flag)
printf("%s %ld\n",root->word,root->count);

  free(root->word);
  free(root);
  
}   


int main(int argc,char* argv[]){
 node* root=init();
 root=trie(root);
 if(argc>1){
if(*argv[1]=='r')
print_r(root);
else
print(root);
 }
 else
 print(root);
    return 0;
}
