#include<stdio.h>
int X_squareBracket=0;
int X_roundBracket=0;
int X_curlyBracket=0;

//this functions takes a string of braces, and determines if ther order of the braces is valid. it returns true if valid and false otherwise
void braces_matching(char *s){
char *temp=s;
while(*s!='\0'){
  if(*s=='(')
  //increase the number of roundBrackets expected
    X_roundBracket++;
  else if(*s=='{')
    X_curlyBracket++;
 else if(*s=='[')
    X_squareBracket++;
 else if(*s==']'){
    //if no squareBracket is expected
    if(X_squareBracket==0){
       printf("%s==>False\n",temp);
       return;
   }
   else
      X_squareBracket--;
 }
 else if(*s=='}'){
    if(X_curlyBracket==0){
       printf("%s==>False\n",temp);
       return;
   }
   else
      X_curlyBracket--;
 }
 else if(*s==')'){
    if(X_roundBracket==0){
       printf("%s==>False\n",temp);
       return;
   }
   else
      X_roundBracket--;
 }
 s++;
}
//if no closingBracket is expected
if(X_squareBracket==0 && X_roundBracket==0 && X_curlyBracket==0){
   printf("%s==>True\n",temp);
   return;
}
else{
   printf("%s==>False\n",temp);
   return;
 }
}

int main(){
 char characters[300];
 scanf("%s",characters);
 braces_matching(characters);
}
