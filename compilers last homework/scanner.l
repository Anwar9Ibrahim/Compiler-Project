%{
		#include "ast.h"
		#include<iostream>
		#include "parser.h"
		
		using std::cout;
		using std::endl;
		
		int line=1;
		int col=1;
		int errorno=0;
%}

%x comment

%%

"/*"								{BEGIN(comment); col += yyleng;}
<comment>"*/"						{BEGIN(0); col += yyleng;}
<comment>[^\n\t]?					{col+=yyleng;}
<comment>\n							{line++; col = 1;}
<comment>\t							{col+=4*yyleng;}

[/][/][^\n]*\n {
						line++;
						col = 1;
						} 

"--"		{
						col += yyleng;
						return MINUS1;
						}

"++"		{
						col += yyleng;
						return PLUS1;
						}

"&&"		{
						col += yyleng;
						return AND;
						}

"||"		{
						col += yyleng;
						return OR;
						}

"!="		{
						col += yyleng;
						return NOTEQ;
						}

"=="		{
						col += yyleng;
						return EQ;
						}

"<="		{
						col += yyleng;
						return INF;
						}

">="		{
						col += yyleng;
						return SUP;
						}
"Class"	{
						col += yyleng;
						return CLASS;
						}
"int"		{
						col += yyleng;
						return INT;
						}
"string" {
						col += yyleng;
						return STRING_TYPE;
						}
"double"	{
						col += yyleng;
						return DOUBLE;
						}
"boolean"	{
						col += yyleng;
						return BOOLEAN;
						}
"void"		{
						col += yyleng;
						return VOID;
						}

"for"		{
						col += yyleng;
						return FOR;
						}
"while"		{
						col += yyleng;
						return WHILE;
						}
"if"		{
						col += yyleng;
						return IF;
						}
"else"		{
						col += yyleng;
						return ELSE;
						}
"true"		{
						col += yyleng;
						return TRUE;
						}
"false"		{
						col += yyleng;
						return FALSE;
						}
"return"	{
						col += yyleng;
						return RETURN;
						}
"new"		{
						col += yyleng;
						return NEW;
						}

"null"		{
						col += yyleng;
						return NUL;
						}


[a-zA-Z_][a-zA-Z_0-9]* {
						col += yyleng;
						yylval.tIdentifier=new Identifier(strdup(yytext), line, col);
						return ID;
						}

0|([1-9][0-9]*) {
						col += yyleng;
						yylval.tInteger_value = new Integer_value(atoi(yytext), line, col);
						return INTEGER;
						}
([0-9]+[\.][0-9]*([eE][+-]?[0-9]+)?)|([\.][0-9]+([eE][+-]?[0-9]+)?)|([0-9]+([eE][+-]?[0-9]+)?) {
						col += yyleng;
						yylval.tReal_value = new Real_value(atof(yytext), line, col);
						return REAL;
						}

[-+=<>*/%!;:,\[\]\.\(\){}] {
						col += yyleng;
						return *yytext;
						}

[\t]*	{
						col += 4*yyleng;
						}
[ ]*	{
						col += yyleng;
						}
[\n]	{
						col =1;
						line++;
						}
["][^\n"\t]*["] {
						col += yyleng;
						return STRING;
						}
.		{
						col += yyleng;
						errorno++;
						cout<<"\n\n_________________________Parser Error_________________________"<<endl;
						cout<<"Error Number: " <<errorno<<" "<<*yytext<<endl;
						cout<<"input.txt, Line: "<<line <<" , col: "<<col<<endl;
						cout<<"Lexical Error"<<endl;
						}
%%
int yywrap(){
	return 1;
}