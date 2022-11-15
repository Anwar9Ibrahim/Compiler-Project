#pragma once
#include <iostream>
#include "ast.h"
#include "parser.h"
#include <cmath>
#include<cstdio>



using std::cout;
using std::endl;


extern int yylex();
extern int yyerror(const char *s);
extern int yydebug;
extern int yyparse();

Program *root;

int main()
{

	yydebug=1;
	yyparse();
	cout<<"\n\n_________________________THE PARSING DONE_________________________"<<endl;
	return 0;
}