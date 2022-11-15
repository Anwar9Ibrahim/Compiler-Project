#include "ast.h"
#include <math.h>
#include <cmath>

using std::cout;
using std::endl;
extern Deffered *deffered;
extern Class * root;
extern Void_Param_Fun * writeline_write_int;
extern Void_Param_Fun * writeline_write_real;
extern Void_Param_Fun * writeline_write_string;
extern Void_Param_Fun * writeline_write_bool;
extern Type_Param_Fun * readline_read_int;
extern Type_Param_Fun * readline_read_real;
extern Type_Param_Fun * readline_read_string;
extern Type_Param_Fun * readline_read_key;

// Kind 1=global 2=local 3=function
/*
types[0] = "null";
types[1] = "int";
types[2] = "double";
types[3] = "boolean";
types[4] = "void";
*/
extern SymbolTable * symtab;
void GetFunctionsVisitor::Visit(Body *n)
{

}
void GetFunctionsVisitor::Visit(Func_Body *n)
{
	n->body->accept(this);
	Functions->push_back(n->function);
}
void GetFunctionsVisitor::Visit(Global_Body *n)
{
	n->body->accept(this);
}
void GetFunctionsVisitor::Visit(Class *n)
{
	n->body->accept(this);
}
bool typechecking_Assign_mismatch(int l, int r)
{
	bool mismatch = false;
	if (l == 1)
	{
		if (r == 1) mismatch = false;
		else mismatch = true;
	}
	else if (l == 2)
	{
		if (r == 1 || r == 2)  mismatch = false;
		else mismatch = true;
	}
	else if (l == 3)
	{
		if (r == 3)  mismatch = false;
		else mismatch = true;
	}
	return mismatch;
}
bool typechecking_operation_mismatch(int l, int r)
{
	bool mismatch = false;
	if (l == 1)
	{
		if (r == 1 || r == 2) mismatch = false;
		else mismatch = true;
	}
	else if (l == 2)
	{
		if (r == 1 || r == 2)  mismatch = false;
		else mismatch = true;
	}
	else if (l == 3)
	{
		if (r == 3)  mismatch = false;
		else mismatch = true;
	}
	return mismatch;
}
int  typechecking_operation_type(int l, int r)
{
	if (l == 1)
	{
		if (r == 1) return 1;
		else if (r == 2) return 2;
		else  return 0;
	}
	if (l == 2)
	{
		if (r == 1 || r == 2) return 2;
		else return 0;
	}
	if (l == 3)
	{
		if (r == 3) return 3;
		else return 0;
	}
	else return 0;
}
void TypeChecking::mismatchError(int l, int r, int  line, int col)
{
	symtab->errors->AddError("Type mismatch the LHS is: " + types[l] + ", while RHS is:" + types[r] + ".", line, col);
}
void TypeChecking::conditionError(int  line, int col)
{
	symtab->errors->AddError("Should be boolean expression.", line, col);
}
TypeChecking::TypeChecking()
{
	types[0] = "null";
	types[1] = "int";
	types[2] = "double";
	types[3] = "boolean";
	types[4] = "void";
	types[5] = "string";

	GetFunctionsVisitor *visitor = new GetFunctionsVisitor();
	visitor->Visit(root);
	functions = visitor->Functions;
	functions->push_back(writeline_write_int);
	functions->push_back(writeline_write_real);
	functions->push_back(writeline_write_string);
	functions->push_back(writeline_write_bool);
	functions->push_back(readline_read_int);
	functions->push_back(readline_read_real);
	functions->push_back(readline_read_string);
	functions->push_back(readline_read_key);
}
void TypeChecking::Visit(Node *n)
{
}
void TypeChecking::Visit(Identifier *n)
{

}
void TypeChecking::Visit(Integer_value *n)
{
	n->type = 1;
}
void TypeChecking::Visit(Real_value *n)
{
	n->type = 2;
}
void TypeChecking::Visit(String_value * n)
{
	n->type = 5;
}
void TypeChecking::Visit(True_value *n)
{
	n->type = 3;
}
void TypeChecking::Visit(False_value *n)
{
	n->type = 3;
}
void TypeChecking::Visit(Parameter *n)
{

}
void TypeChecking::Visit(Params *n)
{
	for (int i = 0; i < n->parameter_list->size(); i++)
	{
		n->parameter_list->at(i)->accept(this);
	}
}
void TypeChecking::Visit(Expr *n)
{
}
void TypeChecking::Visit(Expr_List *n)
{
	for (int i = 0; i < n->expressions->size(); i++)
	{
		n->expressions->at(i)->accept(this);
	}
}
void TypeChecking::Visit(NegativeExpr *n)
{
	n->expr->accept(this);
	if (n->expr->type == 3)
	{
		n->type = 3;
	}
	else {
		symtab->errors->AddError("Error :: Expresion Type should be boolean to negate it.", n->line, n->col);
	}
}
void TypeChecking::Visit(MinusExpr *n)
{
	n->expr->accept(this);
	if (n->expr->type == 1 || n->expr->type == 2) {
		n->type = n->expr->type;
	}
	else {
		symtab->errors->AddError("Error :: Expresion Type should be int or double.", n->line, n->col);
	}
}
void TypeChecking::Visit(PlusExpr *n)
{
}
void TypeChecking::Visit(ParenthesesExpr *n)
{
	n->expr->accept(this);
	n->type = n->expr->type;
}
void TypeChecking::Visit(IdentifierExpr *n)
{
	n->type = n->ident->symbol->type;
}
void TypeChecking::Visit(VariableArrayElenment * n)
{
	n->type = n->ident->symbol->type;
}
void TypeChecking::Visit(Identifier_Eq_Expr *n)
{
	n->expr->accept(this);
	int l = n->ident->symbol->type;
	int r = n->expr->type;
	bool mismatch = typechecking_operation_mismatch(l, r);
	n->type = typechecking_operation_type(l, r);
	if (mismatch) mismatchError(l, r, n->line, n->col);
}
void TypeChecking::Visit(VariableArrayElenment_Eq_Expr * n)
{
	Array *A = n->ident->symbol->array;
	n->indexexpr->accept(this);
	if (n->indexexpr->type != 1)
	{
		symtab->errors->AddError("Inder Array not integer ", n->line, n->col);
	}
	n->equalExpr->accept(this);
	int l = n->ident->symbol->type;
	int r = n->equalExpr->type;
	bool mismatch = typechecking_operation_mismatch(l, r);
	n->type = typechecking_operation_type(l, r);
	if (mismatch) mismatchError(l, r, n->line, n->col);
}
int TypeChecking::matchCall(Identifier * id, Expr_List * el, Function * f)
{
	if (id->name != f->ident->name) {
		return 0;
	}
	if (f->parameters) {
		if (el->expressions->size() != f->parameters->parameter_list->size()) {
			return 0;
		}
	}
	// except void f(double)                 f(1)
	for (int i = 0; i < el->expressions->size(); i++) {
		if (el->expressions->at(i)->type != f->parameters->parameter_list->at(i)->type
			&&
			!(el->expressions->at(i)->type == 1 && f->parameters->parameter_list->at(i)->type == 2)) {
			return 0;
		}
	}

	bool exactMatch = true;
	for (int i = 0; i < el->expressions->size(); i++) {
		if (el->expressions->at(i)->type != f->parameters->parameter_list->at(i)->type) {
			exactMatch = false;
		}
	}
	if (exactMatch) return 1;
	return 2;
}
void TypeChecking::Visit(Identifier_Expr_list *n)
{
	/*if (n->expression_list) { n->expression_list->accept(this); }
	symtab->IsDeclared(n->ident, n->expression_list);
	if (n->ident->symbol != NULL) n->type = n->ident->symbol->type;
	else
	{*/
	
	int numberOfMatch = 0;
	Function * matchedFunction = NULL;
	if (n->expression_list) {
		n->expression_list->accept(this);
		for (int i = 0; i < functions->size(); i++) {
			int typeMatch = matchCall(n->ident, n->expression_list, functions->at(i));
			if (typeMatch == 1) {
				numberOfMatch =1 ;
				matchedFunction = functions->at(i);
				break;
			}
			else if (typeMatch==2)
			{
				numberOfMatch++;
				matchedFunction = functions->at(i);
			}
		}
	}
	else {
		for (int i = 0; i < functions->size(); i++) {
			if (n->ident->name == functions->at(i)->ident->name) {
				numberOfMatch = 1;
				matchedFunction = functions->at(i);
				break;
			}
		}
	}
	if (numberOfMatch > 1) {
		symtab->errors->AddError("Ambigious Call Function.", n->line, n->col);
	}
	else if (numberOfMatch < 1) {
		symtab->errors->AddError("Function Not Found.", n->line, n->col);
	}
	else {
		n->function = matchedFunction;
		n->type = matchedFunction->ident->symbol->type;
	}
}
void TypeChecking::Visit(Expr_Plus_Expr *n)
{
	n->exprL->accept(this);
	n->exprR->accept(this);
	int l = n->exprL->type;
	int r = n->exprR->type;
	bool mismatch = typechecking_operation_mismatch(l, r);
	int i = typechecking_operation_type(l, r);
	n->type = typechecking_operation_type(l, r);
	if (mismatch) mismatchError(l, r, n->line, n->col);
}
void TypeChecking::Visit(Expr_Minus_Expr *n)
{
	n->exprL->accept(this);
	n->exprR->accept(this);
	int l = n->exprL->type;
	int r = n->exprR->type;
	bool mismatch = typechecking_operation_mismatch(l, r);
	n->type = typechecking_operation_type(l, r);
	if (mismatch) mismatchError(l, r, n->line, n->col);
}
void TypeChecking::Visit(Expr_Multiply_Expr *n)
{
	n->exprL->accept(this);
	n->exprR->accept(this);
	int l = n->exprL->type;
	int r = n->exprR->type;
	bool mismatch = typechecking_operation_mismatch(l, r);
	n->type = typechecking_operation_type(l, r);
	if (mismatch) mismatchError(l, r, n->line, n->col);
}
void TypeChecking::Visit(Expr_Div_Expr *n)
{
	n->exprL->accept(this);
	n->exprR->accept(this);
	int l = n->exprL->type;
	int r = n->exprR->type;
	bool mismatch = typechecking_operation_mismatch(l, r);
	n->type = typechecking_operation_type(l, r);
	if (mismatch)mismatchError(l, r, n->line, n->col);
}
void TypeChecking::Visit(Expr_Modulo_Expr *n)
{
	n->exprL->accept(this);
	n->exprR->accept(this);
	int l = n->exprL->type;
	int r = n->exprR->type;
	bool mismatch = typechecking_operation_mismatch(l, r);
	n->type = typechecking_operation_type(l, r);
	if (mismatch) mismatchError(l, r, n->line, n->col);
}
void TypeChecking::Visit(Expr_And_Expr *n)
{
	n->exprL->accept(this);
	n->exprR->accept(this);
	int l = n->exprL->type;
	int r = n->exprR->type;
	if (l == 3 && r == 3)
	{
		n->type = 3;
	}
	else if (l == r)
	{
		symtab->errors->AddError("Should be boolean expression.", n->line, n->col);
	}
	else
	{
		symtab->errors->AddError("Type mismatch the LHS is: " + types[l] + ", while RHS is:" + types[r] + ".", n->line, n->col);
	}
}
void TypeChecking::Visit(Expr_Or_Expr *n)
{
	n->exprL->accept(this);
	n->exprR->accept(this);
	int l = n->exprL->type;
	int r = n->exprR->type;
	if (l == 3 && r == 3)
	{
		n->type = 3;
	}
	else if (l == r)
	{
		symtab->errors->AddError("Should be boolean expression.", n->line, n->col);
	}
	else
	{
		symtab->errors->AddError("Type mismatch the LHS is: " + types[l] + ", while RHS is:" + types[r] + ".", n->line, n->col);
	}
}
void TypeChecking::Visit(Expr_Equal_Expr *n)
{
	n->exprL->accept(this);
	n->exprR->accept(this);
	int l = n->exprL->type;
	int r = n->exprR->type;
	bool mismatch = typechecking_operation_mismatch(l, r);
	n->type = typechecking_operation_type(l, r);
	if (n->type != 0) n->type = 3;
	if (mismatch) mismatchError(l, r, n->line, n->col);

}
void TypeChecking::Visit(Expr_NotEqual_Expr *n)
{
	n->exprL->accept(this);
	n->exprR->accept(this);
	int l = n->exprL->type;
	int r = n->exprR->type;
	bool mismatch = typechecking_operation_mismatch(l, r);
	n->type = typechecking_operation_type(l, r);
	if (n->type != 0) n->type = 3;
	if (mismatch) mismatchError(l, r, n->line, n->col);
}
void TypeChecking::Visit(Expr_Geater_Expr *n)
{
	n->exprL->accept(this);
	n->exprR->accept(this);
	int l = n->exprL->type;
	int r = n->exprR->type;
	bool mismatch = typechecking_operation_mismatch(l, r);
	n->type = typechecking_operation_type(l, r);
	if (n->type != 0) n->type = 3;
	if (mismatch) mismatchError(l, r, n->line, n->col);
}
void TypeChecking::Visit(Expr_Less_Expr *n)
{
	n->exprL->accept(this);
	n->exprR->accept(this);
	int l = n->exprL->type;
	int r = n->exprR->type;
	bool mismatch = typechecking_operation_mismatch(l, r);
	n->type = typechecking_operation_type(l, r);
	if (n->type != 0) n->type = 3;
	if (mismatch) mismatchError(l, r, n->line, n->col);
}
void TypeChecking::Visit(Expr_Sup_Expr *n)
{
	n->exprL->accept(this);
	n->exprR->accept(this);
	int l = n->exprL->type;
	int r = n->exprR->type;
	bool mismatch = typechecking_operation_mismatch(l, r);
	n->type = typechecking_operation_type(l, r);
	if (n->type != 0) n->type = 3;
	if (mismatch) mismatchError(l, r, n->line, n->col);
}
void TypeChecking::Visit(Expr_Inf_Expr *n)
{
	n->exprL->accept(this);
	n->exprR->accept(this);
	int l = n->exprL->type;
	int r = n->exprR->type;
	bool mismatch = typechecking_operation_mismatch(l, r);
	n->type = typechecking_operation_type(l, r);
	if (n->type != 0) n->type = 3;
	if (mismatch) mismatchError(l, r, n->line, n->col);
}
void TypeChecking::Visit(IntegerExpr *n)
{
	n->type = 1;
}
void TypeChecking::Visit(RealExpr *n)
{
	n->type = 2;
}
void TypeChecking::Visit(TrueExpr *n)
{
	n->type = 3;
}
void TypeChecking::Visit(FalseExpr *n)
{
	n->type = 3;
}
void TypeChecking::Visit(StringExpr * n)
{
	n->type = 5;
}
void TypeChecking::Visit(NullExpr *n)
{
	n->type = 0;
}
void TypeChecking::Visit(May_EXP *n)
{
	if (n->expr != NULL)
	{
		n->expr->accept(this);
		n->type = n->expr->type;
	}
}
void TypeChecking::Visit(Inst *n)
{
}
void TypeChecking::Visit(Instructions *n)
{
	for (int i = 0; i < n->insts->size(); i++)
	{
		n->insts->at(i)->accept(this);
	}
	for (int i = 0; i < n->insts->size(); i++)
	{
		if (n->insts->at(i)->return_type != 4)
		{
			n->return_type = n->insts->at(i)->return_type;
			break;
		}
	}
}
void TypeChecking::Visit(While *n)
{
	n->expr->accept(this);
	if (n->expr->type != 3) conditionError(n->line, n->col);
	n->inst->accept(this);
}
void TypeChecking::Visit(For *n)
{
	n->conditionExpr->accept(this);
	if (n->conditionExpr->type != 3) conditionError(n->line, n->col);
	n->loopExpr->accept(this);
	n->inst->accept(this);
}
void TypeChecking::Visit(For_Expr * n)
{
	n->assignexpr->accept(this);
	n->conditionExpr->accept(this);
	if (n->conditionExpr->type != 3) conditionError(n->line, n->col);
	n->loopExpr->accept(this);
	n->inst->accept(this);
}
void TypeChecking::Visit(If *n)
{
	n->expr->accept(this);
	n->inst->accept(this);
	n->return_type = 4;
}
void TypeChecking::Visit(If_Else *n)
{
	n->expr->accept(this);
	n->inst_if->accept(this);
	n->inst_else->accept(this);
	int ret_if = n->inst_if->return_type;
	int ret_else = n->inst_else->return_type;
	if (ret_if * ret_else < 0)
	{
		n->return_type = -1;
	}
	else
	{
		n->return_type = (ret_if > ret_else) ? ret_if : ret_else;
	}
}
void TypeChecking::Visit(ExprInstruction *n)
{
	n->expr->accept(this);
}
void TypeChecking::Visit(Identifier_Eq_Expr_Inst *n)
{
	n->expr->accept(this);
	int l = n->ident->symbol->type;
	int r = n->expr->type;
	bool mismatch = typechecking_Assign_mismatch(l, r);
	n->type = n->ident->symbol->type;
	if (mismatch) mismatchError(l, r, n->line, n->col);
}
void TypeChecking::Visit(Identifier_Declaration * n)
{
	n->type = n->ident->symbol->type;
}
void TypeChecking::Visit(Array * n)
{
	n->type = n->ident->symbol->type;
}
void TypeChecking::Visit(Semicolon *n)
{
}
void TypeChecking::Visit(Braces *n)
{
	n->instructions->accept(this);
	n->return_type = n->instructions->return_type;
}
void TypeChecking::Visit(Return *n)
{
	n->expr->accept(this);
	n->return_type = n->expr->type;
	Node *f = n->father;
	while (dynamic_cast<Function*> (f) == NULL) {
		f = f->father;
	}
	Function* fun = dynamic_cast<Function*> (f);
	n->function = fun;
	if (fun->type != n->return_type && !(fun->type == 2 && n->return_type == 1)) {
		symtab->errors->AddError("Error :: Function: '" + fun->ident->name + "' has a type: " + types[fun->type] + " but return type: " + types[n->return_type] + ".", n->line, n->col);
	}
}
void TypeChecking::Visit(Function *n)
{
}
void TypeChecking::Visit(Type_Param_Fun *n)
{
	n->type = n->ident->symbol->type;
	if (n->parameters) n->parameters->accept(this);
	n->instructions->accept(this);
	if (n->instructions->return_type == 4)
	{
		symtab->errors->AddError("Error :: Function: '" + n->ident->name + "' don't have return value or not all paths return value", n->line, n->col);
	}
	else
	{
		if (n->instructions->return_type != n->type && !(n->type == 2 && n->instructions->return_type == 1))
		{
			symtab->errors->AddError("Error :: Function: '" + n->ident->name + "' has a type: " +
				types[n->type] + " but return type: " + types[n->instructions->return_type] + ".", n->line, n->col);
		}
	}
}
void TypeChecking::Visit(Void_Param_Fun *n)
{
	if (n->parameters) n->parameters->accept(this);
	n->instructions->accept(this);
	if (n->instructions->return_type != 4)
	{
		symtab->errors->AddError("Error :: Function: '" + n->ident->name + "' is a void function and have return value", n->line, n->col);
	}
}
void TypeChecking::Visit(Global *n)
{
}
void TypeChecking::Visit(Identifier_Global *n)
{

}
void TypeChecking::Visit(Identifier_Expr_Global *n)
{
	n->expr->accept(this);
	int l = n->ident->symbol->type;
	int r = n->expr->type;
	bool mismatch = typechecking_operation_mismatch(l, r);
	n->type = typechecking_operation_type(l, r);
	if (mismatch) mismatchError(l, r, n->line, n->col);

}
void TypeChecking::Visit(Body *n)
{

}
void TypeChecking::Visit(Func_Body *n)
{
	n->function->accept(this);
	n->body->accept(this);
}
void TypeChecking::Visit(Global_Body *n)
{
	n->global->accept(this);
	n->body->accept(this);
}
void TypeChecking::Visit(Class *n)
{
	n->body->accept(this);
	if (symtab->current->hashTab->GetMember("3main") == NULL)
	{
		symtab->errors->AddError("There is no main function", 0, 0);
	}
}