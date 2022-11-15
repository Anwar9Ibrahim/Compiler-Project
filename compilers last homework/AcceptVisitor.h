#pragma once
#include "ast.h"

void Node::accept(Visitor * V)
{
	V->Visit(this);
}
void Identifier::accept(Visitor * V)
{
	V->Visit(this);
}
void Integer_value::accept(Visitor * V)
{
	V->Visit(this);
}
void Real_value::accept(Visitor * V)
{
	V->Visit(this);
}
void True_value::accept(Visitor * V)
{
	V->Visit(this);
}
void False_value::accept(Visitor * V)
{
	V->Visit(this);
}
void String_value::accept(Visitor * V)
{
	V->Visit(this);
}
void Parameter::accept(Visitor * V)
{
	V->Visit(this);
}
void Params::accept(Visitor * V)
{
	V->Visit(this);
}
void Expr::accept(Visitor * V)
{
	V->Visit(this);
}
void Expr_List::accept(Visitor * V)
{
	V->Visit(this);
}
void NegativeExpr::accept(Visitor * V)
{
	V->Visit(this);
}
void MinusExpr::accept(Visitor * V)
{
	V->Visit(this);
}
void PlusExpr::accept(Visitor * V)
{
	V->Visit(this);
}
void ParenthesesExpr::accept(Visitor * V)
{
	V->Visit(this);
}
void IdentifierExpr::accept(Visitor * V)
{
	V->Visit(this);
}
void VariableArrayElenment::accept(Visitor * V)
{
	V->Visit(this);
}
void Array::accept(Visitor * V)
{
	V->Visit(this);
}
void Identifier_Eq_Expr::accept(Visitor * V)
{
	V->Visit(this);
}
void VariableArrayElenment_Eq_Expr::accept(Visitor * V)
{
	V->Visit(this);
}
void Identifier_Expr_list::accept(Visitor * V)
{
	V->Visit(this);
}
void Expr_Plus_Expr::accept(Visitor * V)
{
	V->Visit(this);
}
void Expr_Minus_Expr::accept(Visitor * V)
{
	V->Visit(this);
}
void Expr_Multiply_Expr::accept(Visitor * V)
{
	V->Visit(this);
}
void Expr_Div_Expr::accept(Visitor * V)
{
	V->Visit(this);
}
void Expr_Modulo_Expr::accept(Visitor * V)
{
	V->Visit(this);
}
void Expr_And_Expr::accept(Visitor * V)
{
	V->Visit(this);
}
void Expr_Or_Expr::accept(Visitor * V)
{
	V->Visit(this);
}
void Expr_Equal_Expr::accept(Visitor * V)
{
	V->Visit(this);
}
void Expr_NotEqual_Expr::accept(Visitor * V)
{
	V->Visit(this);
}
void Expr_Geater_Expr::accept(Visitor * V)
{
	V->Visit(this);
}
void Expr_Less_Expr::accept(Visitor * V)
{
	V->Visit(this);
}
void Expr_Sup_Expr::accept(Visitor * V)
{
	V->Visit(this);
}
void Expr_Inf_Expr::accept(Visitor * V)
{
	V->Visit(this);
}
void IntegerExpr::accept(Visitor * V)
{
	V->Visit(this);
}
void RealExpr::accept(Visitor * V)
{
	V->Visit(this);
}
void TrueExpr::accept(Visitor * V)
{
	V->Visit(this);
}
void FalseExpr::accept(Visitor * V)
{
	V->Visit(this);
}
void StringExpr::accept(Visitor * V)
{
	V->Visit(this);
}
void NullExpr::accept(Visitor * V)
{
	V->Visit(this);
}
void May_EXP::accept(Visitor * V)
{
	V->Visit(this);
}
void Inst::accept(Visitor * V)
{
	V->Visit(this);
}
void Instructions::accept(Visitor * V)
{
	V->Visit(this);
}
void While::accept(Visitor * V)
{
	V->Visit(this);
}
void For::accept(Visitor * V)
{
	V->Visit(this);
}
void For_Expr::accept(Visitor * V)
{
	V->Visit(this);
}
void If::accept(Visitor * V)
{
	V->Visit(this);
}
void If_Else::accept(Visitor * V)
{
	V->Visit(this);
}
void ExprInstruction::accept(Visitor * V)
{
	V->Visit(this);
}
void Identifier_Eq_Expr_Inst::accept(Visitor * V)
{
	V->Visit(this);
}
void Identifier_Declaration::accept(Visitor * V)
{
	V->Visit(this);
}
void Semicolon::accept(Visitor * V)
{
	V->Visit(this);
}
void Braces::accept(Visitor * V)
{
	V->Visit(this);
}
void Return::accept(Visitor * V)
{
	V->Visit(this);
}
void Function::accept(Visitor * V)
{
	V->Visit(this);
}
void Type_Param_Fun::accept(Visitor * V)
{
	V->Visit(this);
}
void Void_Param_Fun::accept(Visitor * V)
{
	V->Visit(this);
}
void Global::accept(Visitor * V)
{
	V->Visit(this);
}
void Identifier_Global::accept(Visitor * V)
{
	V->Visit(this);
}
void Identifier_Expr_Global::accept(Visitor * V)
{
	V->Visit(this);
}
void Body::accept(Visitor * V)
{
	V->Visit(this);
}
void Func_Body::accept(Visitor * V)
{
	V->Visit(this);
}
void Global_Body::accept(Visitor * V)
{
	V->Visit(this);
}
void Class::accept(Visitor * V)
{
	V->Visit(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void Body::accept(GetFunctionsVisitor * V)
{
	V->Visit(this);
}

void Func_Body::accept(GetFunctionsVisitor * V)
{
	V->Visit(this);
}
void Global_Body::accept(GetFunctionsVisitor * V)
{
	V->Visit(this);
}
void Class::accept(GetFunctionsVisitor * V)
{
	V->Visit(this);
}


