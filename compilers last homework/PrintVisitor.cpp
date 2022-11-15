#include "ast.h"
using std::cout;
using std::endl;
// no return : -1, int=1, double=2, boolean=3

PrintVisitor::PrintVisitor()
{
	types[0] = "null";
	types[1] = "int";
	types[2] = "double";
	types[3] = "boolean";
	types[4] = "void";
	types[5] = "string";
}
void PrintVisitor::Visit(Node *n)
{
	cout << "";
}
void PrintVisitor::Visit(Identifier *n)
{
	cout << s;
	cout << "Identifier_name: " << n->name << ".";
	cout << "\n";
}
void PrintVisitor::Visit(Integer_value *n)
{
	cout << s;
	cout << "int: value: " << n->value << ".";
	cout << "\n";
}
void PrintVisitor::Visit(Real_value *n)
{
	cout << s;
	cout << "double: value: " << n->value << ".";
	cout << "\n";
}
void PrintVisitor::Visit(String_value * n)
{
	cout << s;
	cout << "string: value: " << n->value << ".";
	cout << "\n";
}
void PrintVisitor::Visit(True_value *n)
{
	cout << s;
	cout << "boolean: value: " << n->value << ".";
	cout << "\n";
}
void PrintVisitor::Visit(False_value *n)
{
	cout << s;
	cout << "boolean: value: " << n->value << ".";
	cout << "\n";
}
void PrintVisitor::Visit(Parameter *n)
{
	cout << s;
	cout << "parameter: " << types[n->type] << " " << n->ident->name;
	cout << "\n";
}
void PrintVisitor::Visit(Params *n)
{
	cout << s;
	cout << "Parameters: " << endl;
	s += "      |";
	for (int i = 0; i < n->parameter_list->size(); i++)
	{
		n->parameter_list->at(i)->accept(this);
	}
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(Expr *n)
{
	cout << s;
}
void PrintVisitor::Visit(Expr_List *n)
{
	cout << s;
	cout << "Expressions: " << endl;
	s += "      |";
	for (int i = 0; i < n->expressions->size(); i++)
	{
		n->expressions->at(i)->accept(this);
	}
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(NegativeExpr *n)
{
	cout << s;
	cout << "! Expression :";
	s += "      |";
	n->expr->accept(this);
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(MinusExpr *n)
{
	cout << s;
	cout << "- Expression :" << endl;
	s += "      |";
	n->expr->accept(this);
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(PlusExpr *n)
{
	cout << s;
	cout << "+ Expression :" << endl;
	s += "      |";
	n->expr->accept(this);
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(ParenthesesExpr *n)
{
	cout << s;
	cout << " ( Expression ) : " << endl;
	n->expr->accept(this);
}
void PrintVisitor::Visit(IdentifierExpr *n)
{
	cout << s;
	cout << " Identifier (Expression) : " << endl;
	s += "      |";
	n->ident->accept(this);
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(VariableArrayElenment * n)
{
	cout << s;
	cout << "Variable Array Element: " << endl;
	s += "		|";
	n->ident->accept(this);
	n->expression->accept(this);
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(Identifier_Eq_Expr *n)
{
	cout << s;
	cout << "Identifier = Expression :" << endl;
	s += "      |";
	n->ident->accept(this);
	n->expr->accept(this);
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(VariableArrayElenment_Eq_Expr * n)
{
	cout << s;
	cout << "Variable Array Element = Expression :" << endl;
	s += "      |";
	n->ident->accept(this);
	n->equalExpr->accept(this);
	cout << s;
	cout << "Index type is: " << types[n->indexexpr->type] << endl;

	n->indexexpr->accept(this);
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(Identifier_Expr_list *n)
{
	cout << s;
	cout << "Identifier_Expression_list:" << endl;
	s += "      |";
	n->ident->accept(this);
	if (n->expression_list)
		for (int i = 0; i < n->expression_list->expressions->size(); i++) {
			n->expression_list->expressions->at(i)->accept(this);
		}
	s = s.substr(0, s.length() - 7);

}
void PrintVisitor::Visit(Expr_Plus_Expr *n)
{
	cout << s;
	cout << "Expression + Expression:" << endl;
	s += "      |";
	n->exprL->accept(this);
	n->exprR->accept(this);
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(Expr_Minus_Expr *n)
{
	cout << s;
	cout << "Expression - Expression:" << endl;
	s += "      |";
	n->exprL->accept(this);
	n->exprR->accept(this);
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(Expr_Multiply_Expr *n)
{
	cout << s;
	cout << "Expression * Expression:" << endl;
	s += "      |";
	n->exprL->accept(this);
	n->exprR->accept(this);
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(Expr_Div_Expr *n)
{
	cout << s;
	cout << "Expression / Expression:" << endl;
	s += "      |";
	n->exprL->accept(this);
	n->exprR->accept(this);
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(Expr_Modulo_Expr *n)
{
	cout << s;
	cout << "Expression % Expression:" << endl;
	s += "      |";
	n->exprL->accept(this);
	n->exprR->accept(this);
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(Expr_And_Expr *n)
{
	cout << s;
	cout << "Expression && Expression:" << endl;
	s += "      |";
	n->exprL->accept(this);
	n->exprR->accept(this);
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(Expr_Or_Expr *n)
{
	cout << s;
	cout << "Expression | Expression:" << endl;
	s += "      |";
	n->exprL->accept(this);
	n->exprR->accept(this);
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(Expr_Equal_Expr *n)
{
	cout << s;
	cout << "Expression = Expression:" << endl;
	s += "      |";
	n->exprL->accept(this);
	n->exprR->accept(this);
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(Expr_NotEqual_Expr *n)
{
	cout << s;
	cout << "Expression != Expression:" << endl;
	s += "      |";
	n->exprL->accept(this);
	n->exprR->accept(this);
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(Expr_Geater_Expr *n)
{
	cout << s;
	cout << "Expression > Expression:" << endl;
	s += "      |";
	n->exprL->accept(this);
	n->exprR->accept(this);
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(Expr_Less_Expr *n)
{
	cout << s;
	cout << "Expression < Expression:" << endl;
	s += "      |";
	n->exprL->accept(this);
	n->exprR->accept(this);
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(Expr_Sup_Expr *n)
{
	cout << s;
	cout << "Expression >= Expression:" << endl;
	n->exprL->accept(this);
	n->exprR->accept(this);
}
void PrintVisitor::Visit(Expr_Inf_Expr *n)
{
	cout << s;
	cout << "Expression <= Expression:" << endl;
	n->exprL->accept(this);
	n->exprR->accept(this);
}
void PrintVisitor::Visit(IntegerExpr *n)
{
	cout << s;
	cout << "Integer Expression: " << "Value: " << n->intvalue->value << endl;
}
void PrintVisitor::Visit(RealExpr *n)
{
	cout << s;
	cout << "Real_Expression: " << "Value: " << n->realvalue->value << endl;
}
void PrintVisitor::Visit(TrueExpr *n)
{
	cout << s;
	cout << "True Expression: " << "Value: True" << endl;
}
void PrintVisitor::Visit(FalseExpr *n)
{
	cout << s;
	cout << "False Expression: " << "Value: False" << endl;

}
void PrintVisitor::Visit(StringExpr * n)
{
	cout << s;
	cout << "String Expression: " << "Value: " << n->stringvalue << endl;
}
void PrintVisitor::Visit(NullExpr *n)
{
	cout << s;
	cout << "NULL_Expression: " << endl;
	cout << "\n";
}
void PrintVisitor::Visit(May_EXP *n)
{
	cout << s;
	cout << "False_Expression: " << endl;
	n->expr->accept(this);
	cout << "\n";
}
void PrintVisitor::Visit(Inst *n)
{
	cout << s;
	cout << "Instr: " << endl;
	n->accept(this);
	cout << "\n";
}
void PrintVisitor::Visit(Instructions *n)
{
	cout << s;
	cout << "Instructions: " << endl;
	s += "      |";
	for (int i = 0; i < n->insts->size(); i++)
	{
		n->insts->at(i)->accept(this);
	}
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(While *n)
{
	cout << s;
	cout << "While_Loop: " << endl;
	s += "      |";
	n->expr->accept(this);
	n->inst->accept(this);

}
void PrintVisitor::Visit(For *n)
{
	cout << s;
	cout << " For Loop: " << endl;
	s += "      |";
	cout << s << "loop variable is " << n->ident->name << endl;
	n->conditionExpr->accept(this);
	n->loopExpr->accept(this);
	n->inst->accept(this);
	s = s.substr(0, s.length() - 7);

}
void PrintVisitor::Visit(For_Expr * n)
{
	cout << s;
	cout << " For Loop: " << endl;
	s += "      |";
	cout << s << "loop variable is '" << n->ident->name << "' with initial value expression" << endl;
	s += "      |";
	n->assignexpr->accept(this);
	s = s.substr(0, s.length() - 7);
	n->conditionExpr->accept(this);
	n->loopExpr->accept(this);
	n->inst->accept(this);
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(If *n)
{
	cout << s;
	cout << "If Condition: " << endl;
	s += "      |";
	n->expr->accept(this);
	n->inst->accept(this);
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(If_Else *n)
{
	cout << s;
	cout << "If Else Condition: " << endl;
	s += "      |";
	cout << s;
	cout << "Condition: " << endl;
	s += "      |";
	n->expr->accept(this);
	s = s.substr(0, s.length() - 7);
	cout << s;
	cout << "IF State " << endl;
	s += "      |";
	n->inst_if->accept(this);
	s = s.substr(0, s.length() - 7);
	cout << s;
	cout << "Else_State: " << endl;
	s += "      |";
	n->inst_else->accept(this);
	s = s.substr(0, s.length() - 7);
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(ExprInstruction *n)
{
	n->expr->accept(this);
}
void PrintVisitor::Visit(Identifier_Eq_Expr_Inst *n)
{
	cout << s;
	cout << "Identifier = Expression: " << endl;
	s += "      |";
	cout << s << "Identifier: " << n->ident->name << " Type: " << types[n->type] << endl;
	n->expr->accept(this);
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(Identifier_Declaration * n)
{
}
void PrintVisitor::Visit(Array * n)
{
	cout << s;
	cout << "Array :" << endl;
	s += "		|";
	cout << s;
	cout << "Array Name is : " << n->ident->name << endl;
	cout << s;
	cout << "Array Type is : " << types[n->type] << endl;
	cout << s;
	cout << "Array Size is : " << n->size->value << endl;
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(Semicolon *n)
{
	cout << s << "just ;" << endl;
}
void PrintVisitor::Visit(Braces *n)
{
	cout << s;
	cout << "Instructions: " << endl;
	s += "      |";
	for (int i = 0; i < n->instructions->insts->size(); i++) {
		n->instructions->insts->at(i)->accept(this);
	}
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(Return *n)
{
	cout << s;
	cout << "Return: " << endl;
	s += "      |";
	if (n->expr != NULL)n->expr->expr->accept(this);
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(Function *n)
{
	cout << s;
	cout << "Function : " << endl;
	s += "      |";
	cout << "Name is : " << n->ident->name;
	cout << s;
	cout << "Type is : " << types[n->type];
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(Type_Param_Fun *n)
{
	cout << endl;
	cout << s;
	cout << "Function: " << n->ident->name << endl;
	s += "      |";
	cout << s << "return type : " << types[n->type] << endl;
	if (n->parameters) n->parameters->accept(this);
	n->instructions->accept(this);
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(Void_Param_Fun *n)
{
	cout << endl;
	cout << s;
	cout << "Function: " << n->ident->name << endl;
	s += "      |";
	cout << s << "return type : " << "Void" << endl;
	if (n->parameters) n->parameters->accept(this);
	n->instructions->accept(this);
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(Global *n)
{
	/*s += "      |";
	cout << s;
	cout << "Global: " << endl;*/
	n->accept(this);
	//s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(Identifier_Global *n)
{
	cout << endl;
	cout << s;
	cout << "Global Identifier: " << endl;
	s += "      |";
	cout << s << "Identifier: " << n->ident->name << " Type: " << types[n->type] << endl;
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(Identifier_Expr_Global *n)
{
	cout << endl;
	cout << s;
	cout << "Global Identifier = Expression: " << endl;
	s += "      |";
	cout << s << "Identifier: " << n->ident->name << " Type: " << types[n->type] << endl;
	n->expr->accept(this);
	s = s.substr(0, s.length() - 7);
}
void PrintVisitor::Visit(Body *n) {}
void PrintVisitor::Visit(Func_Body *n)
{
	n->body->accept(this);
	n->function->accept(this);
}
void PrintVisitor::Visit(Global_Body *n)
{
	n->body->accept(this);
	n->global->accept(this);
}
void PrintVisitor::Visit(Class *n)
{
	cout << "Class: " << n->ident->name;
	cout << "\n";
	s = "|       |";
	n->body->accept(this);
	s = s.substr(0, s.length() - 7);
	cout << "\n";
}
