#include "ast.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
using std::cout;
using std::ostringstream;
using std::endl;
using std::ofstream;


extern SymbolTable * symtab;
extern ofstream vcode;

// Kind 1=global 2=local 3=function
/*
types[0] = "null";
types[1] = "int";
types[2] = "double";
types[3] = "boolean";
types[4] = "void";
*/

std::string to_string_with_precision(const double a_value)
{
	std::ostringstream out;
	out << std::setprecision(6) << a_value;
	return out.str();
}

void CodeGeneration::w(string s)
{
	vcode << s << endl;
}
CodeGeneration::CodeGeneration()
{
	f = 0; g = 999;
	types[0] = "null";
	types[1] = "int";
	types[2] = "double";
	types[3] = "boolean";
	types[4] = "void";
	types[5] = "string";
	funcs = new vector < Symbol*>();
}
void CodeGeneration::Visit(Node *n)
{
}
void CodeGeneration::Visit(Identifier *n)
{
}
void CodeGeneration::Visit(Integer_value *n)
{
	w("pushi " + std::to_string(n->value));
}
void CodeGeneration::Visit(Real_value *n)
{
	w("pushf " + std::to_string(n->value));
}
void CodeGeneration::Visit(String_value * n)
{
	string s = "";
	for (int i = 1; i < n->value.length() - 1; i++)
	{
		s += n->value[i];
	}
	w("pushs \"" + s + "\"");
}
void CodeGeneration::Visit(True_value *n)
{
	w("pushi 1");
}
void CodeGeneration::Visit(False_value *n)
{
	w("pushi 0");
}
void CodeGeneration::Visit(Parameter *n)
{
}
void CodeGeneration::Visit(Params *n)
{
	for (int i = 0; i <n->parameter_list->size(); i++)
	{
		Parameter * p = n->parameter_list->at(i);
		p->ident->symbol->location = i - n->parameter_list->size();
	}
}
void CodeGeneration::Visit(Expr *n)
{
}
void CodeGeneration::Visit(Expr_List *n)
{
	for (int i = 0; i < n->expressions->size(); i++)
	{
		n->expressions->at(i)->accept(this);
	}
}
void CodeGeneration::Visit(NegativeExpr *n)
{
	n->expr->accept(this);
	w("pushi 0");
	w("equal");
}
void CodeGeneration::Visit(MinusExpr *n)
{
	n->expr->accept(this);
	if (n->type == 1) {
		w("pushi -1");
		w("mul ");
	}
	else {
		w("pushf -1");
		w("fmul ");
	}

}
void CodeGeneration::Visit(PlusExpr *n)
{
}
void CodeGeneration::Visit(ParenthesesExpr *n)
{
	n->expr->accept(this);
	n->type = n->expr->type;
}
void CodeGeneration::Visit(IdentifierExpr *n)
{
	if (n->ident != NULL)
	{
		n->ident->accept(this);
		if (n->ident->symbol->kind == 1)
		{
			w("pushg " + std::to_string(n->ident->symbol->location));
		}
		else
		{
			w("pushl " + std::to_string(n->ident->symbol->location));
		}
	}
}
void CodeGeneration::Visit(VariableArrayElenment * n)
{
	if (n->ident != NULL) n->ident->accept(this);
	//w("storeg " + std::to_string(g));
	if (n->ident->symbol->kind == 1)
	{
		w("pushg " + std::to_string(n->ident->symbol->location));
	}
	else
	{
		w("pushl " + std::to_string(n->ident->symbol->location) );
	}
	if (n->expression != NULL) n->expression->accept(this);
	//w("pushg " + std::to_string(g));
	w("loadn");

}
void CodeGeneration::Visit(Identifier_Eq_Expr *n)
{
	n->expr->accept(this);
	n->ident->accept(this);
	if (n->ident->symbol->type == 2 && n->expr->type == 1) w("itof");
	if (n->ident->symbol->kind == 1)
	{
		w("storeg " + std::to_string(n->ident->symbol->location));
		w("pushg " + std::to_string(n->ident->symbol->location));
	}
	else if (n->ident->symbol->kind == 2)
	{
		w("storel " + std::to_string(n->ident->symbol->location));
		w("pushl " + std::to_string(n->ident->symbol->location));
	}

}
void CodeGeneration::Visit(VariableArrayElenment_Eq_Expr * n)
{
	if (n->ident != NULL) n->ident->accept(this);
	//w("storeg " + std::to_string(g));
	if (n->ident->symbol->kind == 1)
	{
		w("pushg " + std::to_string(n->ident->symbol->location));
	}
	else
	{
		w("pushl " + std::to_string(n->ident->symbol->location));
	}
	if (n->indexexpr != NULL) n->indexexpr->accept(this);
	//w("pushg " + std::to_string(g));
	if (n->equalExpr != NULL) n->equalExpr->accept(this);
	w("storen");
}
void CodeGeneration::Visit(Identifier_Expr_list *n)
{
	/*string label = "";
	label += n->ident->name;
	string functionKey = "3";
	functionKey += n->ident->name;
	if (n->expression_list) {
		n->expression_list->accept(this);
		for (int i = 0; i < n->expression_list->expressions->size(); i++)
		{
			label += "__" + types[n->expression_list->expressions->at(i)->type];
			functionKey += "@" + types[n->expression_list->expressions->at(i)->type];
		}
	}*/
	if (n->expression_list) {
		for (int i = 0; i < n->expression_list->expressions->size(); i++)
		{
			n->expression_list->expressions->at(i)->accept(this);
			if (n->expression_list->expressions->at(i)->type == 1 && n->function->parameters->parameter_list->at(i)->type == 2)
				w("itof");
		}
	}
	string label = "";
	label += n->ident->name;
	if (n->function->parameters)
	{
		for (int i = 0; i < n->function->parameters->parameter_list->size(); i++)
		{
			label += "__" + types[n->function->parameters->parameter_list->at(i)->type];
		}
	}
	w("pusha " + label);
	w("call");

	Symbol * functionSymbol = n->function->ident->symbol;
	if (functionSymbol)
	{
		funcs->push_back(functionSymbol);
		if (n->expression_list != NULL && n->expression_list->expressions && n->expression_list->expressions->size() > 0)
			w("pop " + std::to_string(n->expression_list->expressions->size()));
		if (functionSymbol->type != 4) w("pushg " + std::to_string(g));
	}
	else
	{
		// Add errors
	}
}
void CodeGeneration::Visit(Expr_Plus_Expr *n)
{
	if (n->exprL != NULL) n->exprL->accept(this);

	if (n->exprR != NULL) n->exprR->accept(this);
	if (n->exprL->type == 1 && n->exprR->type == 1) w("add");
	else
		if (n->exprL->type == 1)
		{
			w("storeg " + std::to_string(g));
			w("itof");
			w("pushg " + std::to_string(g));
			w("fadd");
		}
		else
			if (n->exprR->type == 1)
			{
				w("itof");
				w("fadd");
			}
			else
				if (n->exprL->type == 2 && n->exprR->type == 2) w("fadd");
}
void CodeGeneration::Visit(Expr_Minus_Expr *n)
{
	if (n->exprL != NULL) n->exprL->accept(this);
	if (n->exprR != NULL) n->exprR->accept(this);
	if (n->exprL->type == 1 && n->exprR->type == 1) w("sub");
	else
		if (n->exprL->type == 1)
		{
			w("storeg " + std::to_string(g));
			w("itof");
			w("pushg " + std::to_string(g));
			w("fsub");
		}
		else
			if (n->exprR->type == 1)
			{
				w("itof");
				w("fsub");
			}
			else
				if (n->exprL->type == 2 && n->exprR->type == 2) w("fsub");
}
void CodeGeneration::Visit(Expr_Multiply_Expr *n)
{
	if (n->exprL != NULL) n->exprL->accept(this);
	if (n->exprR != NULL) n->exprR->accept(this);
	if (n->exprL->type == 1 && n->exprR->type == 1) w("mul");
	else
		if (n->exprL->type == 1)
		{
			w("storeg " + std::to_string(g));
			w("itof");
			w("pushg " + std::to_string(g));
			w("fmul");
		}
		else
			if (n->exprR->type == 1)
			{
				w("itof");
				w("fmul");
			}
			else
				if (n->exprL->type == 2 && n->exprR->type == 2) w("fmul");
}
void CodeGeneration::Visit(Expr_Div_Expr *n)
{
	if (n->exprL != NULL) n->exprL->accept(this);
	if (n->exprR != NULL) n->exprR->accept(this);
	if (n->exprL->type == 1 && n->exprR->type == 1) w("div");
	else
		if (n->exprL->type == 1)
		{
			w("storeg " + std::to_string(g));
			w("itof");
			w("pushg " + std::to_string(g));
			w("fdiv");
		}
		else
			if (n->exprR->type == 1)
			{
				w("itof");
				w("fdiv");
			}
			else
				if (n->exprL->type == 2 && n->exprR->type == 2) w("fdiv");
}
void CodeGeneration::Visit(Expr_Modulo_Expr *n)
{
	if (n->exprL != NULL) n->exprL->accept(this);
	if (n->exprR != NULL) n->exprR->accept(this);
	if (n->exprL->type == 1 && n->exprR->type == 1) w("mod");
}
void CodeGeneration::Visit(Expr_And_Expr *n)
{
	if (n->exprL != NULL) n->exprL->accept(this);
	if (n->exprR != NULL) n->exprR->accept(this);
	w("add");
	w("pushi 2");
	w("equal");
}
void CodeGeneration::Visit(Expr_Or_Expr *n)
{
	if (n->exprL != NULL) n->exprL->accept(this);
	if (n->exprR != NULL) n->exprR->accept(this);
	w("add");
	w("pushi 0");
	w("equal");
	w("not");
}
void CodeGeneration::Visit(Expr_Equal_Expr *n)
{
	if (n->exprL != NULL) n->exprL->accept(this);
	if (n->exprR != NULL) n->exprR->accept(this);
	if (n->exprL->type == 1 && n->exprR->type == 1) w("equal");
	else
		if (n->exprL->type == 1)
		{
			w("storeg " + std::to_string(c));
			w("itof");
			w("pushg " + std::to_string(c));
			w("equal");
		}
		else
			if (n->exprR->type == 1)
			{
				w("itof");
				w("equal");
			}
			else
				if (n->exprL->type == 2 && n->exprR->type == 2) w("equal");
}
void CodeGeneration::Visit(Expr_NotEqual_Expr *n)
{
	if (n->exprL != NULL) n->exprL->accept(this);
	if (n->exprR != NULL) n->exprR->accept(this);
	if (n->exprL->type == 1 && n->exprR->type == 1) w("equal");
	else
		if (n->exprL->type == 1)
		{
			w("storeg " + std::to_string(c));
			w("itof");
			w("pushg " + std::to_string(c));
			w("equal");
		}
		else
			if (n->exprR->type == 1)
			{
				w("itof");
				w("equal");
			}
			else
				if (n->exprL->type == 2 && n->exprR->type == 2) w("equal");
	w("not");
}
void CodeGeneration::Visit(Expr_Geater_Expr *n)
{
	if (n->exprL != NULL) n->exprL->accept(this);
	if (n->exprR != NULL) n->exprR->accept(this);
	if (n->exprL->type == 1 && n->exprR->type == 1) w("sup");
	else
		if (n->exprL->type == 1)
		{
			w("storeg " + std::to_string(c));
			w("itof");
			w("pushg " + std::to_string(c));
			w("sup");
		}
		else
			if (n->exprR->type == 1)
			{
				w("itof");
				w("sup");
			}
			else
				if (n->exprL->type == 2 && n->exprR->type == 2) w("sup");
}
void CodeGeneration::Visit(Expr_Less_Expr *n)
{
	if (n->exprL != NULL) n->exprL->accept(this);
	if (n->exprR != NULL) n->exprR->accept(this);
	if (n->exprL->type == 1 && n->exprR->type == 1) w("inf");
	else
		if (n->exprL->type == 1)
		{
			w("storeg " + std::to_string(c));
			w("itof");
			w("pushg " + std::to_string(c));
			w("inf");
		}
		else
			if (n->exprR->type == 1)
			{
				w("itof");
				w("inf");
			}
			else
				if (n->exprL->type == 2 && n->exprR->type == 2) w("inf");
}
void CodeGeneration::Visit(Expr_Sup_Expr *n)
{
	if (n->exprL != NULL) n->exprL->accept(this);
	if (n->exprR != NULL) n->exprR->accept(this);
	if (n->exprL->type == 1 && n->exprR->type == 1) w("supeq");
	else
		if (n->exprL->type == 1)
		{
			w("storeg " + std::to_string(c));
			w("itof");
			w("pushg " + std::to_string(c));
			w("supeq");
		}
		else
			if (n->exprR->type == 1)
			{
				w("itof");
				w("supeq");
			}
			else
				if (n->exprL->type == 2 && n->exprR->type == 2) w("supeq");
}
void CodeGeneration::Visit(Expr_Inf_Expr *n)
{
	if (n->exprL != NULL) n->exprL->accept(this);
	if (n->exprR != NULL) n->exprR->accept(this);
	if (n->exprL->type == 1 && n->exprR->type == 1) w("infeq");
	else
		if (n->exprL->type == 1)
		{
			w("storeg " + std::to_string(c));
			w("itof");
			w("pushg " + std::to_string(c));
			w("infeq");
		}
		else
			if (n->exprR->type == 1)
			{
				w("itof");
				w("infeq");
			}
			else
				if (n->exprL->type == 2 && n->exprR->type == 2) w("infeq");
}
void CodeGeneration::Visit(IntegerExpr *n)
{
	n->intvalue->accept(this);
}
void CodeGeneration::Visit(RealExpr *n)
{
	n->realvalue->accept(this);
}
void CodeGeneration::Visit(TrueExpr *n)
{
	w("pushi 1");
}
void CodeGeneration::Visit(FalseExpr *n)
{
	w("pushi 0");
}
void CodeGeneration::Visit(StringExpr * n)
{
	string s = "";
	for (int i = 1; i < n->stringvalue.length() - 1; i++)
	{
		s += n->stringvalue[i];
	}
	w("pushs \"" + s + "\"");;
}
void CodeGeneration::Visit(NullExpr *n)
{
	//////////////////////////////////////////////////////
}
void CodeGeneration::Visit(May_EXP *n)
{
	if (n->expr != NULL) n->expr->accept(this);
}
void CodeGeneration::Visit(Inst *n)
{
}
void CodeGeneration::Visit(Instructions *n)
{
	for (int i = 0; i < n->insts->size(); i++)
	{
		n->insts->at(i)->accept(this);
	}
}
void CodeGeneration::Visit(While *n)
{
	whileLabel++;
	int label = whileLabel;
	w("WHILE_BEGIN" + std::to_string(whileLabel) + ":");
	if (n->expr != NULL)
	{
		n->expr->accept(this);
	}
	w("jz WHILE_END" + std::to_string(whileLabel));
	if (n->inst != NULL)
	{
		n->inst->accept(this);
	}
	w("jump WHILE_BEGIN" + std::to_string(whileLabel));
	w("WHILE_END" + std::to_string(whileLabel) + ":");
}
void CodeGeneration::Visit(For *n)
{
	forLabel++;
	int label = forLabel;
	if (n->ident != NULL)
	{
		n->ident->symbol->location = g;
		w("pushi 0");
		w("storeg " + std::to_string(g));
	}
	w("FOR_BEGIN" + std::to_string(label) + ":");
	if (n->conditionExpr != NULL) n->conditionExpr->accept(this);
	w("jz FOR_END" + std::to_string(label));
	if (n->inst != NULL) n->inst->accept(this);
	if (n->loopExpr != NULL) n->loopExpr->accept(this);
	w("jump FOR_BEGIN" + std::to_string(label));
	w("FOR_END" + std::to_string(label) + ":");
}
void CodeGeneration::Visit(For_Expr * n)
{
	forLabel++;
	int label = forLabel;
	n->assignexpr->accept(this);
	w("storeg " + std::to_string(g));
	n->ident->symbol->location = g;
	w("FOR_BEGIN" + std::to_string(label) + ":");
	if (n->conditionExpr != NULL) n->conditionExpr->accept(this);
	w("jz FOR_END" + std::to_string(label));
	if (n->inst != NULL) n->inst->accept(this);
	if (n->loopExpr != NULL) n->loopExpr->accept(this);
	w("jump FOR_BEGIN" + std::to_string(label));
	w("FOR_END" + std::to_string(label) + ":");
}
void CodeGeneration::Visit(If *n)
{
	ifLabel++;
	int label = ifLabel;
	w("IF_BEGIN" + std::to_string((label)) + ":");
	if (n->expr != NULL) n->expr->accept(this);
	w("jz IF_END" + std::to_string((label)));
	if (n->inst != NULL) n->inst->accept(this);
	w("IF_END" + std::to_string((label)) + ":");
}
void CodeGeneration::Visit(If_Else *n)
{
	ifElseLabel++;
	int label = ifElseLabel;
	w("IF_BEGIN" + std::to_string((label)) + ":");
	if (n->expr != NULL) n->expr->accept(this);
	w("jz ELSE_BEGIN" + std::to_string((label)));
	if (n->inst_if != NULL) n->inst_if->accept(this);
	w("IF_END" + std::to_string((label)) + ":");
	w("jump ELSE_END" + std::to_string((label)));
	w("ELSE_BEGIN" + std::to_string((label)) + ":");
	if (n->inst_else != NULL)n->inst_else->accept(this);
	w("ELSE_END" + std::to_string((label)) + ":");
}
void CodeGeneration::Visit(ExprInstruction *n)
{
	if (n->expr) n->expr->accept(this);
}
void CodeGeneration::Visit(Identifier_Eq_Expr_Inst *n)
{
	n->expr->accept(this);
	if (n->ident->symbol->kind == 1)
	{
		n->ident->symbol->location = g;
		w("storel " + std::to_string(g));
		w("pushl " + std::to_string(g));
		g--;
	}
	else if (n->ident->symbol->kind == 2)
	{
		if (n->expr->type == 1 && n->ident->symbol->type == 2) {
			w("itof");
		}
		n->ident->symbol->location = f;
		w("storel " + std::to_string(f));
		w("pushl " + std::to_string(f));
		f++;
	}
}
void CodeGeneration::Visit(Identifier_Declaration * n)
{
	w("pushi 0");
	if (n->ident->symbol->type == 2) w("itof");
	n->ident->symbol->location = f;
	w("storel " + std::to_string(f));
	w("pushl " + std::to_string(f));
	f++;
}
void CodeGeneration::Visit(Array * n)
{
	w("alloc " + std::to_string(n->size->value));
	w("storel " + std::to_string(f));
	int type = n->type;
	for (int j = 0; j < n->size->value; j++)
	{
		if (type == 1)
		{
			w("pushl " + std::to_string(f));
			w("pushi " + std::to_string(j));
			w("pushi 0");
			w("storen");
		}
		else
			if (type == 3)
			{
				w("pushl " + std::to_string(f));
				w("pushi " + std::to_string(j));
				w("pushi 0");
				w("storen");
			}
			else
				if (type == 2)
				{
					w("pushl " + std::to_string(f));
					w("pushi " + std::to_string(j));
					w("pushf 0.0");
					w("storen");
				}
				else
					if (type == 5)
					{
						w("pushl " + std::to_string(f));
						w("pushi " + std::to_string(j));
						w("pushs \"\"");
						w("storen");
					}
	}
	w("pushl " + std::to_string(f));
	f++;
}
void CodeGeneration::Visit(Semicolon *n)
{
}
void CodeGeneration::Visit(Braces *n)
{
	if (n->instructions != NULL) n->instructions->accept(this);
}
void CodeGeneration::Visit(Return *n)
{
	n->expr->accept(this);
	if (n->expr->type == 1 && n->function->type == 2) w("itof");
	w("storeg " + std::to_string(g));
	w("pushg " + std::to_string(g));
	w("return");
}
void CodeGeneration::Visit(Function *n)
{
}
void CodeGeneration::Visit(Type_Param_Fun *n)
{
	if (n->CG_visited == false)
	{
		f = 0;
		n->CG_visited = true;
		string label = "";
		label += n->ident->name;
		if (n->parameters)
		{
			for (int i = 0; i < n->parameters->parameter_list->size(); i++)
			{
				label += "__" + types[n->parameters->parameter_list->at(i)->type];
			}
		}
		w(label + ":");
		if (n->parameters) n->parameters->accept(this);
		if (n->instructions)n->instructions->accept(this);
		if (n->ident->name != "main") w("return");
	}
}
void CodeGeneration::Visit(Void_Param_Fun *n)
{
	if (n->CG_visited == false)
	{
		f = 0;
		n->CG_visited = true;
		string label = "";
		label += n->ident->name;
		if (n->parameters)
		{
			for (int i = 0; i < n->parameters->parameter_list->size(); i++)
			{
				label += "__" + types[n->parameters->parameter_list->at(i)->type];
			}
		}
		w(label + ":");
		if (n->parameters) n->parameters->accept(this);
		if (n->instructions)n->instructions->accept(this);
		if (n->ident->name != "main") w("return\n\n\n");
	}
}
void CodeGeneration::Visit(Global *n)
{
}
void CodeGeneration::Visit(Identifier_Global *n)
{
	w("pushi 0");
	if (n->ident->symbol->type == 2) {
		w("itof");
	}
	n->ident->symbol->location = g;
	w("storeg " + std::to_string(g));
	w("pushg " + std::to_string(g));
	g--;
}
void CodeGeneration::Visit(Identifier_Expr_Global *n)
{
	n->expr->accept(this);
	n->ident->symbol->location = g;
	if (n->ident->symbol->type == 2 && n->expr->type == 1) w("itof");
	w("storeg " + std::to_string(g));
	w("pushg " + std::to_string(g));
	g--;
}
void CodeGeneration::Visit(Body *n)
{
}
void CodeGeneration::Visit(Func_Body *n)
{
	n->body->accept(this);
}
void CodeGeneration::Visit(Global_Body *n)
{
	n->body->accept(this);
	n->global->accept(this);
}
void CodeGeneration::Visit(Class *n)
{
	w("start");
	if (n->body != NULL) n->body->accept(this);
	w("pusha main");
	w("call");
	symtab->current->hashTab->GetMember("3main")->function->accept(this);
	w("stop");
	w("");
	for (int i = 0; i < funcs->size(); i++)
	{
		funcs->at(i)->function->accept(this);
	}
	generateReadWriteFunction();
}
void CodeGeneration::generateReadWriteFunction()
{
	w("\n\n\n");
	w("\n\n\n");
	////writeline integer
	w("write__int:");
	w("pushl -1");
	w("storel 0");
	w("pushl 0");
	w("pushl 0");
	w("writei");
	w("return\n\n\n");

	////writeline real
	w("write__double:");
	w("pushl -1");
	w("storel 0");
	w("pushl 0");
	w("pushl 0");
	w("writef");
	w("return\n\n\n");

	////writeline real
	w("write__string:");
	w("pushl -1");
	w("storel 0");
	w("pushl 0");
	w("pushl 0");
	w("writes");
	w("return\n\n\n");



	////writeline boolean
	w("write__boolean:");
	w("pushl -1");
	w("storel 0");
	w("pushl 0");
	w("pushl 0");
	w("writei");
	w("return\n\n\n");

	////read integer
	w("readInt:");
	w("read");
	w("atoi");
	w("storeg " + std::to_string(g) + "");
	w("return\n\n\n");

	////read real
	w("readReal:");
	w("read");
	w("atof");
	w("storeg " + std::to_string(g) + "");
	w("return\n\n\n");

	////read string
	w("readString:");
	w("read");
	w("storeg " + std::to_string(g) + "");
	w("return\n\n\n");

	/////readkey
	w("readKey:");
	w("read");
	w("pop 1");
	w("return");
}