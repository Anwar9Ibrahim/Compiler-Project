#include "ast.h"
#include "AcceptVisitor.h"
#include <iostream>

using std::cout;
using std::endl;

Void_Param_Fun * writeline_write_int;
Void_Param_Fun * writeline_write_real;
Void_Param_Fun * writeline_write_string;
Void_Param_Fun * writeline_write_bool;
Type_Param_Fun * readline_read_int;
Type_Param_Fun * readline_read_real;
Type_Param_Fun * readline_read_string;
Type_Param_Fun * readline_read_key;

extern SymbolTable *symtab;
// no return : -1, int=1, double=2, boolean=3

// Class Node
Node::Node(int line, int col) {
	this->line = line;
	this->col = col;
	this->father = NULL;
}

// Class IDENT
Identifier::Identifier(string ident, int line, int col)
	: Node(line, col)
{
	this->name = ident;
}

// Class Integer_value
Integer_value::Integer_value(int line, int col)
	: Node(line, col)
{
	this->type = 1;
	this->value = 0;
}
Integer_value::Integer_value(int value, int line, int col)
	: Node(line, col)
{
	this->type = 1;
	this->value = value;
}

// Class Real_value
Real_value::Real_value(int line, int col)
	: Node(line, col)
{
	this->type = 2;
	this->value = 0;
}
Real_value::Real_value(double value, int line, int col)
	: Node(line, col)
{
	this->type = 2;
	this->value = value;
}

String_value::String_value(int line, int col)
	: Node(line, col)
{
	this->type = 5;
	this->value = "";
}
String_value::String_value(string value, int line, int col)
	: Node(line, col)
{
	this->type = 5;
	this->value = value;
}

// Class Parameter
Parameter::Parameter(int  type, Identifier * ident, int line, int col)
	: Node(line, col)
{
	this->type = type;
	this->ident = ident;
	if (ident != NULL) {
		ident->father = this;
	}

}

// Class Params List of Parameter
Params::Params(Parameter* paramter, int line, int col)
	:Node(line, col)
{
	this->parameter_list = new vector<Parameter*>;
	this->addParameter(paramter);
}
void Params::addParameter(Parameter* paramter)
{
	this->parameter_list->push_back(paramter);
	if (paramter != NULL)
		paramter->father = this;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

// Class Expr_List
Expr_List::Expr_List(Expr * expr, int line, int col)
	:Node(line, col)
{
	this->expressions = new vector<Expr *>;
	this->addExpression(expr);
}
void Expr_List::addExpression(Expr * expr)
{
	this->expressions->push_back(expr);
	if (expr != NULL)
		expr->father = this;
}

// Class NegativeExpr
NegativeExpr::NegativeExpr(Expr* expression, int line, int col)
	:Expr(line, col)
{
	this->expr = expression;
	if (expr != NULL)
		expr->father = this;

}

// Class MinusExpr
MinusExpr::MinusExpr(Expr* expression, int line, int col)
	:Expr(line, col)
{
	this->expr = expression;
	if (expr != NULL)
		expr->father = this;
}

// Class PlusExpr
PlusExpr::PlusExpr(Expr* expression, int line, int col)
	:Expr(line, col)
{
	this->expr = expression;
	if (expr != NULL)
		expr->father = this;
}

// Class ParenthesesExpr
ParenthesesExpr::ParenthesesExpr(Expr* expression, int line, int col)
	:Expr(line, col)
{
	this->expr = expression;
	if (expr != NULL)
		expr->father = this;
}

// Class IdentifierExpr
IdentifierExpr::IdentifierExpr(Identifier * ident, int line, int col)
	:Expr(line, col)
{
	this->ident = ident;
	if (ident != NULL)
		ident->father = NULL;
}

VariableArrayElenment::VariableArrayElenment(Identifier * id, Expr * expr, int line, int col)
	:Expr(line, col)
{
	this->ident = id;
	this->expression = expr;
	if (id != NULL)
		id->father = this;
	if (expr != NULL)
		expr->father = this;
}
// Class Identifier_Eq_Expr
Identifier_Eq_Expr::Identifier_Eq_Expr(Identifier * ident, Expr * expression, int line, int col)
	:Expr(line, col)
{
	this->ident = ident;
	this->expr = expression;
	if (ident != NULL)
		ident->father = this;

	if (expression != NULL)
		expression->father = this;
}

VariableArrayElenment_Eq_Expr::VariableArrayElenment_Eq_Expr(Identifier * ident, Expr * indexexpr, Expr * equalExpr, int line, int col)
	:Expr(line, col)
{
	this->ident = ident;
	this->equalExpr = equalExpr;
	this->indexexpr = indexexpr;
	if (ident != NULL)
		ident->father = this;
	if (indexexpr != NULL)
		indexexpr->father = this;
	if (equalExpr != NULL)
		equalExpr->father = this;
}

// Class Identifier_Expr_list
Identifier_Expr_list::Identifier_Expr_list(Identifier* ident, Expr_List* expr_list, int line, int col)
	:Expr(line, col)
{
	this->expression_list = expr_list;
	this->ident = ident;
	if (ident != NULL) {
		ident->father = this;
	}
	if (expr_list != NULL) {
		expr_list->father = this;
	}
}

// Class Expr_Plus_Expr
Expr_Plus_Expr::Expr_Plus_Expr(Expr * expressionl, Expr * expressionr, int line, int col)
	:Expr(line, col)
{
	this->exprL = expressionl;
	this->exprR = expressionr;
	if (expressionl != NULL) {
		expressionl->father = this;
	}
	if (expressionr != NULL) {
		expressionr->father = this;
	}
}

// Class Expr_Minus_Expr
Expr_Minus_Expr::Expr_Minus_Expr(Expr * expressionl, Expr * expressionr, int line, int col)
	:Expr(line, col)
{
	this->exprL = expressionl;
	this->exprR = expressionr;
	if (expressionl != NULL) {
		expressionl->father = this;
	}
	if (expressionr != NULL) {
		expressionr->father = this;
	}
}

// Class Expr_Multiply_Expr
Expr_Multiply_Expr::Expr_Multiply_Expr(Expr * expressionl, Expr * expressionr, int line, int col)
	:Expr(line, col)
{
	this->exprL = expressionl;
	this->exprR = expressionr;
	if (expressionl != NULL) {
		expressionl->father = this;
	}
	if (expressionr != NULL) {
		expressionr->father = this;
	}
}

// Class Expr_Div_Expr
Expr_Div_Expr::Expr_Div_Expr(Expr * expressionl, Expr * expressionr, int line, int col)
	:Expr(line, col)
{
	this->exprL = expressionl;
	this->exprR = expressionr;
	if (expressionl != NULL) {
		expressionl->father = this;
	}
	if (expressionr != NULL) {
		expressionr->father = this;
	}
}

// Class Expr_Modulo_Expr
Expr_Modulo_Expr::Expr_Modulo_Expr(Expr * expressionl, Expr * expressionr, int line, int col)
	:Expr(line, col)
{
	this->exprL = expressionl;
	this->exprR = expressionr;
	if (expressionl != NULL) {
		expressionl->father = this;
	}
	if (expressionr != NULL) {
		expressionr->father = this;
	}
}

// Class Expr_And_Expr
Expr_And_Expr::Expr_And_Expr(Expr * expressionl, Expr * expressionr, int line, int col)
	:Expr(line, col)
{
	this->exprL = expressionl;
	this->exprR = expressionr;
	if (expressionl != NULL) {
		expressionl->father = this;
	}
	if (expressionr != NULL) {
		expressionr->father = this;
	}
}

// Class Expr_Or_Expr
Expr_Or_Expr::Expr_Or_Expr(Expr * expressionl, Expr * expressionr, int line, int col)
	:Expr(line, col)
{
	this->exprL = expressionl;
	this->exprR = expressionr;
	if (expressionl != NULL) {
		expressionl->father = this;
	}
	if (expressionr != NULL) {
		expressionr->father = this;
	}
}

// Class Expr_Equal_Expr
Expr_Equal_Expr::Expr_Equal_Expr(Expr * expressionl, Expr * expressionr, int line, int col)
	:Expr(line, col)
{
	this->exprL = expressionl;
	this->exprR = expressionr;
	if (expressionl != NULL) {
		expressionl->father = this;
	}
	if (expressionr != NULL) {
		expressionr->father = this;
	}
}

// Class Expr_NotEqual_Expr
Expr_NotEqual_Expr::Expr_NotEqual_Expr(Expr * expressionl, Expr * expressionr, int line, int col)
	:Expr(line, col)
{
	this->exprL = expressionl;
	this->exprR = expressionr;
	if (expressionl != NULL) {
		expressionl->father = this;
	}
	if (expressionr != NULL) {
		expressionr->father = this;
	}
}

// Class Expr_Geater_Expr
Expr_Geater_Expr::Expr_Geater_Expr(Expr * expressionl, Expr * expressionr, int line, int col)
	:Expr(line, col)
{
	this->exprL = expressionl;
	this->exprR = expressionr;
	if (expressionl != NULL) {
		expressionl->father = this;
	}
	if (expressionr != NULL) {
		expressionr->father = this;
	}
}

// Class Expr_Less_Expr
Expr_Less_Expr::Expr_Less_Expr(Expr * expressionl, Expr * expressionr, int line, int col)
	:Expr(line, col)
{
	this->exprL = expressionl;
	this->exprR = expressionr;
	if (expressionl != NULL) {
		expressionl->father = this;
	}
	if (expressionr != NULL) {
		expressionr->father = this;
	}
}

// Class Expr_Sup_Expr
Expr_Sup_Expr::Expr_Sup_Expr(Expr * expressionl, Expr * expressionr, int line, int col)
	:Expr(line, col)
{
	this->exprL = expressionl;
	this->exprR = expressionr;
	if (expressionl != NULL) {
		expressionl->father = this;
	}
	if (expressionr != NULL) {
		expressionr->father = this;
	}
}

// Class Expr_Inf_Expr
Expr_Inf_Expr::Expr_Inf_Expr(Expr * expressionl, Expr * expressionr, int line, int col)
	:Expr(line, col)
{
	this->exprL = expressionl;
	this->exprR = expressionr;
	if (expressionl != NULL) {
		expressionl->father = this;
	}
	if (expressionr != NULL) {
		expressionr->father = this;
	}
}

// Class IntegerExpr
IntegerExpr::IntegerExpr(Integer_value* intvalue, int line, int col)
	:Expr(line, col)
{
	this->intvalue = intvalue;
	if (intvalue != NULL) {
		intvalue->father = this;
	}
}

// Class RealExpr
RealExpr::RealExpr(Real_value* realvalue, int line, int col)
	:Expr(line, col)
{
	this->realvalue = realvalue;
	if (realvalue != NULL) {
		realvalue->father = this;
	}
}

StringExpr::StringExpr(string value, int line, int col)
	:Expr(line, col)
{
	this->stringvalue = value;
}

// Class TrueExpr
TrueExpr::TrueExpr(True_value* truevalue, int line, int col)
	:Expr(line, col)
{
	this->truevalue = truevalue;
	if (truevalue != NULL) {
		truevalue->father = this;
	}
}

// Class FalseExpr
FalseExpr::FalseExpr(False_value* falsevalue, int line, int col)
	:Expr(line, col)
{
	this->falsevalue = falsevalue;
	if (falsevalue != NULL) {
		falsevalue->father = this;
	}
}

// Class NullExpr
NullExpr::NullExpr(int line, int col)
	:Expr(line, col) {}

// Class NullExpr
May_EXP::May_EXP(Expr* expr, int line, int col)
	: Expr(line, col)
{
	this->expr = expr;
	if (expr != NULL) {
		expr->father = this;
	}
}
May_EXP::May_EXP(int line, int col)
	: Expr(line, col)
{
	this->expr = NULL;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

// Class Instructions
Instructions::Instructions(int line, int col)
	:Inst(line, col)
{
	this->insts = new vector< Inst * >;
}
Instructions::Instructions(Inst * inst, int line, int col)
	: Inst(line, col)
{
	this->insts = new vector<Inst*>;
	insts->push_back(inst);
	if (inst != NULL) {
		inst->father = this;
	}
}
void Instructions::addInstruction(Inst * inst)
{
	this->insts->push_back(inst);
	if (inst != NULL) {
		inst->father = this;
	}
}

// Class While
While::While(Expr * expr, Inst * inst, int line, int col)
	:Inst(line, col)
{
	this->expr = expr;
	this->inst = inst;
	if (expr != NULL) {
		expr->father = this;
	}
	if (inst != NULL) {
		inst->father = this;
	}
}

// Class For
For::For(int type, Identifier* ident, Expr* conexpr, Expr* loopexpr, Inst * inst, int line, int col)
	:Inst(line, col)
{
	this->type = type;
	this->ident = ident;
	this->conditionExpr = conexpr;
	this->loopExpr = loopexpr;
	this->inst = inst;

	if (ident != NULL) {
		ident->father = this;
	}
	if (conexpr != NULL) {
		conexpr->father = this;
	}
	if (loopexpr != NULL) {
		loopexpr->father = this;
	}
	if (inst != NULL) {
		inst->father = this;
	}
}

For_Expr::For_Expr(int type, Identifier* ident , Expr* ass, Expr* conexpr, Expr* loopexpr, Inst * inst, int line, int col)
	:Inst(line, col)
{
	this->type = type;
	this->ident = ident;
	this->assignexpr = ass;
	this->conditionExpr = conexpr;
	this->loopExpr = loopexpr;
	this->inst = inst;

	if (ident != NULL) {
		ident->father = this;
	}
	if (ass != NULL)
	{
		ass->father = this;
	}
	if (conexpr != NULL) {
		conexpr->father = this;
	}
	if (loopexpr != NULL) {
		loopexpr->father = this;
	}
	if (inst != NULL) {
		inst->father = this;
	}
}

// Class If
If::If(Expr * expr, Inst * inst, int line, int col)
	:Inst(line, col)
{
	this->expr = expr;
	this->inst = inst;
	if (expr != NULL) {
		expr->father = this;
	}
	if (inst != NULL) {
		inst->father = this;
	}
}

// Class If_Else
If_Else::If_Else(Expr * expr, Inst * instif, Inst * instelse, int line, int col)
	:Inst(line, col)
{
	this->expr = expr;
	this->inst_else = instelse;
	this->inst_if = instif;
	if (expr != NULL) {
		expr->father = this;
	}
	if (instelse != NULL) {
		instelse->father = this;
	}
	if (instif != NULL) {
		instif->father = this;
	}
}

// Class ExprInstruction
ExprInstruction::ExprInstruction(Expr * expr, int line, int col)
	:Inst(line, col)
{
	this->expr = expr;
	if (expr != NULL) {
		expr->father = this;
	}
}

// Class Identifier_Eq_Expr_Inst
Identifier_Eq_Expr_Inst::Identifier_Eq_Expr_Inst(int  type, Identifier* ident, Expr* expr, int line, int col)
	:Inst(line, col)
{
	this->type = type;
	this->ident = ident;
	this->expr = expr;
	if (ident != NULL) {
		ident->father = this;
	}
	if (expr != NULL) {
		expr->father = this;
	}

}

Identifier_Declaration::Identifier_Declaration(int type, Identifier * ident, int line, int col)
	:Inst(line, col)
{
	this->type = type;
	this->ident = ident;
	if (ident != NULL) {
		ident->father = this;
	}
}

Array::Array(int type, Identifier * id, Integer_value* size, int line, int col)
	:Inst(line, col)
{
	this->type = type;
	this->ident = id;
	this->size = size;
	if (ident != NULL) {
		ident->father = this;
	}
}
// Class Braces
Braces::Braces(Instructions * insts, int line, int col)
	:Inst(line, col)
{
	this->instructions = insts;
	if (insts != NULL) {
		insts->father = this;
	}
}

// Class Return
Return::Return(May_EXP* expr, int line, int col)
	:Inst(line, col)
{
	this->expr = expr;
	if (expr != NULL) {
		expr->father = this;
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

// Class *type_Param_Fun
Type_Param_Fun::Type_Param_Fun(int  type, Identifier * ident, Params * params, Instructions * insts, int line, int col)
	:Function(line, col)
{
	this->ident = ident;
	this->instructions = insts;
	this->parameters = params;
	this->type = type;
	this->CG_visited = false;

	if (ident != NULL) {
		ident->father = this;
	}
	if (insts != NULL) {
		insts->father = this;
	}
	if (params != NULL) {
		params->father = this;
	}
}

// Class Void_Param_Fun
Void_Param_Fun::Void_Param_Fun(Identifier * ident, Params * params, Instructions * insts, int line, int col)
	:Function(line, col)
{
	this->type = 4;
	this->ident = ident;
	this->instructions = insts;
	this->parameters = params;
	this->CG_visited = false;

	if (ident != NULL) {
		ident->father = this;
	}
	if (insts != NULL) {
		insts->father = this;
	}
	if (params != NULL) {
		params->father = this;
	}
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

// Class Identifier_Global
Identifier_Global::Identifier_Global(int type, Identifier* ident, int line, int col)
	:Global(line, col)
{
	this->type = type;
	this->ident = ident;
	if (ident != NULL) {
		ident->father = this;
	}
}

// Class Identifier_Expr_Global
Identifier_Expr_Global::Identifier_Expr_Global(int type, Identifier* ident, Expr* expr, int line, int col)
	:Global(line, col)
{
	this->type = type;
	this->ident = ident;
	this->expr = expr;
	if (ident != NULL) {
		ident->father = this;
	}
	if (expr != NULL) {
		expr->father = this;
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

// Class Func_Body
Func_Body::Func_Body(Body* body, Function* func, int line, int col)
	:Body(line, col)
{
	this->body = body;
	this->function = func;
	if (body != NULL) {
		body->father = this;
	}
	if (func != NULL) {
		func->father = this;
	}

}

// Class Global_Body
Global_Body::Global_Body(Body* body, Global* global, int line, int col)
	:Body(line, col)
{
	this->body = body;
	this->global = global;
	if (body != NULL) {
		body->father = this;
	}
	if (global != NULL) {
		global->father = this;
	}

}

// Class Class
Class::Class(Identifier* ident, Body* body, int line, int col)
	:Node(line, col)
{
	this->body = body;
	this->ident = ident;
	if (body != NULL) {
		body->father = this;
	}
	if (ident != NULL) {
		ident->father = this;
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
void Initializer::initialize()
{
	//  _write_int
	Identifier * id_write_int = new Identifier("write", 0, 0);
	Identifier * id_param_write_int = new Identifier("1_write_int_x", 0, 0);
	symtab->AddSymbol(id_param_write_int, 2, 1);
	Params * prameters_write_int = new Params(new Parameter(1, id_param_write_int, 0, 0), 0, 0);
	writeline_write_int = new Void_Param_Fun(id_write_int, prameters_write_int, NULL, 0, 0);
	writeline_write_int->CG_visited = true;
	symtab->AddSymbol(id_write_int, 3, 4, prameters_write_int, writeline_write_int);

	//  _write_real
	Identifier * id_write_real = new Identifier("write", 0, 0);
	Identifier * id_param_write_real = new Identifier("1_write_real_x", 0, 0);
	symtab->AddSymbol(id_param_write_real, 2, 2);
	Params * prameters_write_real = new Params(new Parameter(2, id_param_write_real, 0, 0), 0, 0);
	writeline_write_real = new Void_Param_Fun(id_write_real, prameters_write_real, NULL, 0, 0);
	writeline_write_real->CG_visited = true;
	symtab->AddSymbol(id_write_real, 3, 4, prameters_write_real, writeline_write_real);

	//  _write_string
	Identifier * id_write_string = new Identifier("write", 0, 0);
	Identifier * id_param_write_string = new Identifier("1_write_string_x", 0, 0);
	symtab->AddSymbol(id_param_write_string, 2, 5);
	Params * prameters_write_string = new Params(new Parameter(5, id_param_write_string, 0, 0), 0, 0);
	writeline_write_string = new Void_Param_Fun(id_write_string, prameters_write_string, NULL, 0, 0);
	writeline_write_string->CG_visited = true;
	symtab->AddSymbol(id_write_string, 3, 4, prameters_write_string, writeline_write_string);

	//  _write_bool
	Identifier * id_write_bool = new Identifier("write", 0, 0);
	Identifier * id_param_write_bool = new Identifier("1_write_bool_x", 0, 0);
	symtab->AddSymbol(id_param_write_bool, 2, 3);
	Params * prameters_write_bool = new Params(new Parameter(3, id_param_write_bool, 0, 0), 0, 0);
	writeline_write_bool = new Void_Param_Fun(id_write_bool, prameters_write_bool, NULL, 0, 0);
	writeline_write_bool->CG_visited = true;
	symtab->AddSymbol(id_write_bool, 3, 4, prameters_write_bool, writeline_write_bool);


	//  _read_int
	Identifier * id_read_int = new Identifier("readInt", 0, 0);
	readline_read_int = new Type_Param_Fun(1,id_read_int, NULL, NULL, 0, 0);
	readline_read_int->CG_visited = true;
	symtab->AddSymbol(id_read_int, 3, 1, NULL, readline_read_int);

	//  _read_real
	Identifier * id_read_real = new Identifier("readReal", 0, 0);
	readline_read_real = new Type_Param_Fun(2, id_read_real, NULL, NULL, 0, 0);
	readline_read_real->CG_visited = true;
	symtab->AddSymbol(id_read_real, 3, 2, NULL, readline_read_real);

	//  _read_string
	Identifier * id_read_string = new Identifier("readString", 0, 0);
	readline_read_string = new Type_Param_Fun(2, id_read_string, NULL, NULL, 0, 0);
	readline_read_string->CG_visited = true;
	symtab->AddSymbol(id_read_string, 3, 2, NULL, readline_read_string);

	//  _read_key
	Identifier * id_read_key = new Identifier("readKey", 0, 0);
	readline_read_key = new Type_Param_Fun(4, id_read_key, NULL, NULL, 0, 0);
	readline_read_key->CG_visited = true;
	symtab->AddSymbol(id_read_key, 3, 4, NULL, readline_read_key);

	////  _read_bool
	//Identifier * id_read_bool = new Identifier("readBoolean", 0, 0);
	//Type_Param_Fun * readline_read_bool = new Type_Param_Fun(1, id_read_bool, NULL, NULL, 0, 0);
	//readline_read_bool->CG_visited = true;
	//symtab->AddSymbol(id_read_bool, 3, 1, NULL, readline_read_bool);
}


