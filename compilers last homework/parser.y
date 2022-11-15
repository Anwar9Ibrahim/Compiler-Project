%{
	#include<iostream>
	#include "ast.h"
	using std::cout;
	using std::endl;
	#define YYDEBUG 1;
	Class * root;
	extern int yylex();
	extern int yyerror(const char *);
	extern int yydebug;
	extern int line;
	extern int col;
	extern char* yytext;
	extern int errorno;
	extern int yyleng;
	extern int yywrap();
	extern Deffered *deffered;
	extern SymbolTable *symtab;



	int whileLabel = 0;
	int ifLabel = 0;
	int ifElseLabel = 0;
	int forLabel=0;
%}

%union
{
	Node *Node;
	int tint;
	Identifier* tIdentifier;
	Integer_value *tInteger_value;
	Real_value *tReal_value;
	True_value *tTrue_value;
	False_value *tFalse_value;
	NullExpr * tNullExpr;
	Parameter *tParameter;
	Params *tParams;
	Expr *tExpr;
	Expr_List *tExpr_List;
	May_EXP *tMay_EXP;
	Inst *tInst;
	Instructions *tInstructions;
	Function *tFunction;
	Global *tGlobal;
	Identifier_Global *tIdentifier_Global;
	Identifier_Expr_Global *tIdentifier_Expr_Global;
	Body *tBody;
	Func_Body *tFunc_Body;
	Global_Body *tGlobal_Body;
	Class *tClass;
	SymbolTable * tSymbolTable;
}

//%type <tIdentifier>  ID
%type <tInteger_value>  INTEGER
%type <tReal_value>  REAL
%type <tTrue_value>  TRUE
%type <tSTRING> STRING
%type <tFalse_value>  FALSE
%type <tNullExpr>  NUL
%type <tReal_value> DOUBLE
%type <tint> Data_Type
%type <tParameter> parameter
%type <tParams> Params
%type <tParams> Params_empty
%type <tExpr> Expr
%type <tMay_EXP> May_EXP
%type <tExpr_List>  Expr_List 
%type <tInst> instruction
%type <tInstructions> instructions
%type <tFunction> Function
%type <tGlobal> Global
%type <tBody> Body
%type <tClass> class



%debug
%token MINUS1 
%token PLUS1 
%token AND 
%token OR 
%token NOTEQ
%token EQ
%token INF
%token SUP
%token MINUS1
%token PLUS1
%token AND
%token OR
%token NOTEQ
%token EQ
%token INT
%token SUP
%token CLASS
%token DOUBLE
%token BOOLEAN
%token NUL
%token FOR
%token WHILE
%token IF
%token ELSE
%token TRUE
%token FALSE
%token VOID
%token RETURN
%token NEW
%token <tIdentifier> ID
%token INTEGER
%token REAL
%token STRING
%token STRING_TYPE


%nonassoc THEN 
%nonassoc ELSE
%right '='
%left OR
%left AND
%nonassoc  EQ  NOTEQ
%nonassoc '<' '>'  INF SUP
%left '-' '+'
%left '*' '/' '%'
%left UNARYOPERATOR


%start class
%%

class :  {symtab->OpenScope();Initializer::initialize(); } CLASS ID '{' Body '}'
							{
								$$ = new Class ( $3 , $5 , line , col );
								root=$$;
							}
;
Body :	/*empty*/
							{
								$$ = new Body ( line , col );	
							}
		|Body Function
							{
								$$ = new Func_Body ( $1 , $2 , line , col );								
							}
		|Body Global
							{
								$$ = new Global_Body ( $1 , $2 , line , col );
							}
;
Global : Data_Type ID ';'
							{
								$$ = new Identifier_Global ( $1 , $2 , line , col );
								symtab -> AddSymbol ($2,1,$1);
							}
		|Data_Type ID '=' Expr';'	
							{
								$$ = new Identifier_Expr_Global ( $1 , $2 , $4 , line , col );
								symtab -> AddSymbol ($2,1,$1);
							}
;
Function :	  Data_Type ID {symtab->OpenScope(); }  '(' Params_empty ')' '{' instructions '}'
							{
								$$ = new Type_Param_Fun ( $1 , $2 , $5 , $8 , line , col );
								symtab->CloseScope();
								symtab -> AddSymbol( $2 , 3 , $1 , $5 , $$);
							}
			| VOID ID {symtab->OpenScope(); } '(' Params_empty ')' '{' instructions '}'
							{
								$$ = new Void_Param_Fun ( $2 , $5 , $8 , line , col );
								symtab->CloseScope();
								symtab -> AddSymbol($2, 3, 4,$5,$$);
							}
;
parameter:	Data_Type ID
							{
								$$ = new Parameter($1, $2, line, col);
								symtab -> AddSymbol ($2,2,$1);
							}
;

Params:	    parameter
							{
								$$ = new Params($1, line, col);
							}
			| Params  ',' parameter
							{
								$$ = $1; 
								$$->addParameter($3);
							}
;

Params_empty: /*empty*/ 
							{
								$$ = NULL;
							}
			| Params
							{
								$$ = $1;
							}
;
Data_Type :  BOOLEAN
							{
								$$ = 3;
							}
			|DOUBLE
							{
								$$ = 2;
							}
			|INT
							{
								$$ = 1;
							}
			|STRING_TYPE
							{
								$$ = 5;
							}
;
Expr :	 '!'Expr	%prec UNARYOPERATOR
							{
								$$ = new NegativeExpr ($2 , line , col);
							}
		|'-' Expr	%prec UNARYOPERATOR
							{
								$$ = new MinusExpr ($2 , line , col);
							}
		|'+' Expr	%prec UNARYOPERATOR
							{
								$$ = new PlusExpr ($2 , line , col);
							}
		| '(' Expr ')'
							{
								$$ = new ParenthesesExpr ($2 , line , col);
							}
		| ID
							{
								$$ = new IdentifierExpr ($1 , line , col);
								symtab->IsDeclared($1,deffered);
							}

		| ID '[' Expr ']'
							{
								$$= new VariableArrayElenment($1, $3, line, col);
								symtab->IsDeclared($1,deffered);
							}
		| ID '=' Expr
							{
								$$ = new Identifier_Eq_Expr ($1 , $3 , line , col);
								symtab->IsDeclared($1,deffered);
							}
		| ID '[' Expr ']' '=' Expr
							{
								$$= new VariableArrayElenment_Eq_Expr($1, $3, $6 , line, col);
								symtab->IsDeclared($1,deffered);
							}
		| ID '('Expr_List')'
							{
								$$ = new Identifier_Expr_list ($1 , $3 , line , col);
								// we need type checking before check for declaration.
								//symtab->IsDeclared($1, $3,deffered);
							}
		| ID '(' ')'
							{
								$$ = new Identifier_Expr_list ($1 , NULL , line , col);
							}
		| Expr '+' Expr
							{
								$$ = new Expr_Plus_Expr ($1 , $3 , line , col);
							}
		| Expr '-' Expr
							{
								$$ = new Expr_Minus_Expr ($1 , $3 , line , col);
							}
		| Expr '*' Expr
							{
								$$ = new Expr_Multiply_Expr ($1 , $3 , line , col);
							}
		| Expr '/' Expr
							{
								$$ = new Expr_Div_Expr ($1 , $3 , line , col);
							}
		| Expr '%' Expr
							{
								$$ = new Expr_Modulo_Expr ($1 , $3 , line , col);
							}
		| Expr OR Expr
							{
								$$ = new Expr_Or_Expr ($1 , $3 , line , col);
							}
		| Expr AND Expr
							{
								$$ = new Expr_And_Expr ($1 , $3 , line , col);
							}
		| Expr EQ Expr 
							{
								$$ = new Expr_Equal_Expr ($1 , $3 , line , col);
							}
		| Expr NOTEQ Expr
							{
								$$ = new Expr_NotEqual_Expr ($1 , $3 , line , col);
							}
		| Expr '<' Expr
							{
								$$ = new Expr_Less_Expr ($1 , $3 , line , col);
							}
		| Expr '>' Expr
							{
								$$ = new  Expr_Geater_Expr ($1 , $3 , line , col);
							}
		| Expr INF Expr
							{
								$$ = new Expr_Inf_Expr ($1 , $3 , line , col);
							}
		| Expr SUP Expr
							{
								$$ = new Expr_Sup_Expr ($1 , $3 , line , col);
							}
		| INTEGER
							{
								$$ = new IntegerExpr ($1 , line , col);
							}
		| REAL
							{
								$$ = new RealExpr ($1 , line , col);
							}
		|STRING 
							{
								$$= new StringExpr(strdup(yytext), line, col);
							}
		| TRUE
							{
								$$ = new TrueExpr ($1 , line , col);
							}
		| FALSE
							{
								$$ = new FalseExpr ($1 , line , col);
							}
		| NUL
							{
								$$ = new NullExpr ( line , col);
							}
;
Expr_List :  Expr
							{
								$$ = new Expr_List ($1  , line , col);
							}	
			|Expr_List ',' Expr 
							{
								$1->addExpression($3);
								$$ = $1;
							}
;
instructions :	 /*empty*/
							{
								$$ = new Instructions(line , col);
								// we can put $$ = NULL;
							}
				| instructions instruction
							{
								$1->addInstruction($2);
								$$ = $1;
							}
;
instruction :	  WHILE { symtab->OpenScope(); } '(' Expr ')' instruction
							{
								$$ = new While ( $4 , $6 , line , col);
								symtab->CloseScope();
							}
				| FOR '(' Data_Type ID  ';' { symtab->OpenScope();  symtab -> AddSymbol ($4,1,$3);} May_EXP ';' May_EXP  ')' instruction
							{
								$$ = new For ( $3 , $4 , $7 , $9 , $11 , line , col);
								symtab->CloseScope();
							}
				| FOR '(' Data_Type ID '=' Expr ';' {symtab->OpenScope();  symtab -> AddSymbol ($4,1,$3);} May_EXP ';' May_EXP  ')' instruction
							{
								$$ = new For_Expr ( $3 , $4 , $6 , $9 , $11 , $13 , line , col);
								symtab->CloseScope();
							}
				| IF '(' Expr ')' instruction					%prec THEN
							{
								$$ = new If ( $3 , $5 , line , col);
							}
				| IF '(' Expr ')' instruction ELSE instruction
							{
								$$ = new If_Else( $3 , $5 , $7 , line , col);
							}
				| Expr ';'
							{
								$$ = new ExprInstruction( $1 , line , col);
							}
				| Data_Type ID '=' Expr ';'
							{
								$$ = new Identifier_Eq_Expr_Inst ( $1 , $2 , $4 , line , col);
								symtab->AddSymbol( $2 , 2 , $1 );
							}
				| Data_Type ID ';'
							{
								$$ = new Identifier_Declaration ( $1 , $2 , line , col);
								symtab->AddSymbol( $2 , 2 , $1 );
							}

				| Data_Type ID '[' INTEGER ']' ';'
							{
								$$= new Array($1, $2, $4, line, col);
								symtab->AddSymbol( $2 , 2 , $1 );
							}

				| ';'
							{
								$$ = new Semicolon(line , col);
							}
				| '{' instructions '}'
							{
								$$ = new Braces( $2 , line , col);
							}
				| RETURN May_EXP ';'
							{
								$$ = new Return( $2 ,line , col);
							}
;
May_EXP :	 /*empty*/
							{
								$$ = new May_EXP( line , col);
							}
			|Expr
							{
								$$ = new May_EXP( $1 ,line , col);
							}
;
%%
int yyerror(const char* s)
{
	cout<<"\n\n_________________________Parser Error_________________________"<<endl;
	cout<<"Error Number: " <<errorno<<" "<<*yytext<<endl;
	cout<<"file input.txt, Line: "<<line<<endl;
	cout<<"Syntax Error"<<endl;
	return 1;
}