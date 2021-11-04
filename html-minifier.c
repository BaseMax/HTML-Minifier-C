// 
// 
// ███╗░░░███╗░█████╗░██╗░░██╗    ██████╗░░█████╗░░██████╗███████╗
// ████╗░████║██╔══██╗╚██╗██╔╝    ██╔══██╗██╔══██╗██╔════╝██╔════╝
// ██╔████╔██║███████║░╚███╔╝░    ██████╦╝███████║╚█████╗░█████╗░░
// ██║╚██╔╝██║██╔══██║░██╔██╗░    ██╔══██╗██╔══██║░╚═══██╗██╔══╝░░
// ██║░╚═╝░██║██║░░██║██╔╝╚██╗    ██████╦╝██║░░██║██████╔╝███████╗
// ╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝    ╚═════╝░╚═╝░░╚═╝╚═════╝░╚══════╝
// 
// 
// Date: 2021/11/04
// Source: https://github.com/BaseMax/HTML-Minifier-C
// Purpose: International obfuscated contest
// Description: Just a small C program to minify HTML sources and generate a minified HTML output.
// © Copyright 2021, Max Base
// 
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
                                 char*R(const char*
                            p){FILE*f=fopen(p,"r");if(f==
                        NULL){return NULL;}fseek(f,0,SEEK_END
                       );long j=ftell(f);fseek(f,0,SEEK_SET)
                     ;char*content=malloc(j+1);if(content==NULL
                     ){fclose(f);return NULL;}fread(content,1,j
                   ,f);content[j]='\0';fclose(f);return content;}
                   bool D(const char*p){struct stat st;if(stat(p,
                   &st)==0){if(S_ISDIR(st.st_mode)){return 2;}else
                    if(S_ISREG(st.st_mode)){return 1;}}return-1;}
                  char*E(const char*p){char*e=strrchr(p,'.');if(e
                   ==NULL){return NULL;}return e+1;}char*RA(char*I
                  ,char*S,char*R){static char B[1024];int i=0;char
                   *_str;if(!(_str=strstr(I+i,S))){return I;}while
                   (I[i]){if (!(_str=strstr(I+i,S))){strcat(B,I+i
                    );break;} strncpy(B+strlen(B),I+i,(_str-I)-i)
                    ;B[_str-I]='\0'; strcat(B,R);i=(_str-I)+strlen
                     (S);} return B;}char*M(const char*I){char*
                   O=malloc(strlen(I)+1);if(O==NULL){return NULL;}
                    char*p= O;bool      it=0;      for(const char
                     *q=I;*q!='\0'     ;q++){       if(*q=='<'){
                      it=true;}else   if (*q=='>') {it=false;}
                       else if(!it){if(*q=='\r'||*q=='\n'||*q
                      =='\t'){continue;}if(*q==' '){if(p>O&&*(
                       p-1)==' '){continue;}}}*p++=*q;}*p='\0'
                       ;O=RA(O,"><","><");return O;}int main
                       (  ){printf("Enter the name of a file "
                       "path: ");char*p=malloc(256);if(p==NULL){
                         return 1; }            scanf("%s",p);
                        if(D (p)==1){         char*e=E(p);if(e
                        ==NULL){printf("Error: invalid p\n");
                          return 1;}if(strcmp(e,"html")==0){
                            printf("Minifying %s\n",p);char*
                            content=R(p);if(content==NULL){
                             printf("Error:invalid path\n"
                            );return 1;}char*O=M(content
                               );if(O==NULL){printf
                              ("Error:invalid p\n");
                             return 1;}FILE*f=fopen(p,
                     "w");if(f==NULL){printf("Error: invali"
                   "d path\n"); return 1;}fprintf(f,"% s",O);fclose
               (f);printf("Mi"   "nified%s\n",p);}   else{printf("Error: "
    "invalid p\n");return     1;}}else{printf     ("Error:invalid p\n");return 1;}}
