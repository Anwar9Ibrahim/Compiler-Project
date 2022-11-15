#include <iostream>
#include <fstream>
#include "ast.h"
using std::ofstream;
using std::cout;
using std::endl;




extern int yylex();
extern int yyerror(const char *s);
extern int yydebug;
extern int yyparse();

ofstream vcode("vmcode.txt");
extern Class * root;
SymbolTable * symtab;
Deffered *deffered;
int main()
{

	symtab = new SymbolTable();
	deffered = new Deffered();
	yydebug = 0;
	yyparse();
	if (root != NULL)
	{
		deffered->CheckAll(symtab);
		if (symtab->errors->errorLists->size() > 0)
		{
			symtab->errors->Print();
		}
		else
		{
			TypeChecking *typechecking = new TypeChecking();
			typechecking->Visit(root);
			if (symtab->errors->errorLists->size() > 0)
			{
				symtab->errors->Print();
			}
			else
			{
				PrintVisitor * prniter = new PrintVisitor();
				CodeGeneration *cg = new CodeGeneration();
				cg->Visit(root);
				system("start D:\\compiler\\AnwarNeemat\\vm.exe -dump  -count \"D:\\compiler\\AnwarNeemat\\compilers last homework\\vmcode.txt\"");
				prniter->Visit(root);
			}

		}
	}
	return 0;
}