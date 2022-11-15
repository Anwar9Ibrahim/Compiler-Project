#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "hash_fun.h"
#include "hash_table.h"
#include "ast.h"

using std::string;
using std::vector;


extern int whileLabel ;
extern int ifLabel ;
extern int ifElseLabel ;
extern int ifLabel;
extern int forLabel ;


class Visitor;
class Error;
class Errors;
class Symbol;
class Scope;
class SymbolTable;
class Deffered;
class Array;
class GetFunctionsVisitor;
class Function;

typedef CHashTable <Symbol> HashTab;


class Node
{
public:
	int line;
	int col;
	Node *father;
	Node(int , int);
	virtual void accept(Visitor *);
};

class Identifier : public  Node
{
public:
	Symbol *symbol;
	string name;
	Identifier(string, int, int);
	virtual void accept(Visitor *);
};


class Integer_value : public  Node
{
public:
	int type;
	int value;
	Integer_value(int, int);
	Integer_value(int, int, int);
	virtual void accept(Visitor *);
};

class Real_value : public  Node
{
public:
	int type;
	double value;
	Real_value(int, int);
	Real_value(double, int, int);
	virtual void accept(Visitor *);
};

class String_value : public  Node
{
public:
	int type;
	string value;
	String_value(int, int);
	String_value(string, int, int);
	virtual void accept(Visitor *);
};

class True_value : public Node
{
public:
	int type;
	const bool value = true;
	True_value(int line, int col) : Node(line, col) {}
	virtual void accept(Visitor *);
};

class False_value : public  Node
{
public:
	int type;
	const bool value = false;
	False_value(int line, int col) : Node(line, col) {}
	virtual void accept(Visitor *);
};

class Parameter : public Node
{
public:
	// we don't have a situation when the user can define his own type
	//so we can just use integer values to indicate diffrent types we have
	int type;
	Identifier * ident;
	Parameter(int , Identifier *, int, int);
	virtual void accept(Visitor *);
};

class Params : public  Node
{
public:
	vector<Parameter *> *parameter_list;
	// if we have a situation when the function can have no parameters then we need this constructor Params(int, int).
	Params(Parameter*, int, int);
	// when we have more than one parameter, we call this function to add the parameters to the list we have.
	void addParameter(Parameter *);
	virtual void accept(Visitor *);
};

//=======================================================================================================================================
//=======================================================================================================================================
// ====================================================== Start :Expression Classes =====================================================

class Expr : public  Node
{
public:
	int type;
	Expr(int line, int col) :Node(line, col) {}
	virtual void accept(Visitor *);
};

class Expr_List : public  Node
{
public:
	vector <Expr * > *expressions;
	Expr_List(int line, int col) :Node(line, col) {}
	Expr_List(Expr *, int, int);
	void addExpression(Expr *);
	virtual void accept(Visitor *);
};

// '!'Expr
class NegativeExpr : public  Expr
{
public:
	Expr *expr;
	NegativeExpr(Expr*, int, int);
	virtual void accept(Visitor *);
};

//'-' Expr
class MinusExpr : public  Expr
{
public:
	Expr *expr;
	MinusExpr(Expr*, int, int);
	virtual void accept(Visitor *);
};

// '+' Expr
class PlusExpr : public  Expr
{
public:
	Expr *expr;
	PlusExpr(Expr*, int, int);
	virtual void accept(Visitor *);
};

//'(' Expr ')'
class ParenthesesExpr : public  Expr
{
public:
	Expr *expr;
	ParenthesesExpr(Expr*, int, int);
	virtual void accept(Visitor *);

};

// IDENT	
class IdentifierExpr : public Expr
{
public:
	Identifier *ident;
	IdentifierExpr(Identifier *, int, int);
	virtual void accept(Visitor *);
};

class VariableArrayElenment : public Expr
{
public:
	Identifier *ident;
	Expr *expression;
	VariableArrayElenment(Identifier *, Expr *, int, int);
	virtual void accept(Visitor *);
};

// IDENT '=' Expr
class Identifier_Eq_Expr : public Expr
{
public:
	Identifier * ident;
	Expr *expr;
	Identifier_Eq_Expr(Identifier * ident, Expr* expr, int, int);
	virtual void accept(Visitor *);
};

class VariableArrayElenment_Eq_Expr : public Expr
{
public:
	Identifier * ident;
	Expr *indexexpr;
	Expr *equalExpr;
	VariableArrayElenment_Eq_Expr(Identifier * ident, Expr *indexexpr , Expr *equalExpr ,int line, int col);
	virtual void accept(Visitor *);
};

// IDENT '(' Expr_List ')'
class Identifier_Expr_list : public  Expr
{
public:
	Identifier * ident;
	Expr_List * expression_list;
	Function * function;
	Identifier_Expr_list(Identifier*, Expr_List*, int, int);
	virtual void accept(Visitor *);
};

class Expr_Plus_Expr : public  Expr
{
public:
	Expr *exprL;
	Expr *exprR;
	Expr_Plus_Expr(Expr *, Expr *, int, int);
	virtual void accept(Visitor *);
};

class Expr_Minus_Expr : public  Expr
{
public:
	Expr *exprL;
	Expr *exprR;
	Expr_Minus_Expr(Expr *, Expr *, int, int);
	virtual void accept(Visitor *);
};

class Expr_Multiply_Expr : public  Expr
{
public:
	Expr *exprL;
	Expr *exprR;
	Expr_Multiply_Expr(Expr *, Expr *, int, int);
	virtual void accept(Visitor *);
};

class Expr_Div_Expr : public  Expr
{
public:
	Expr *exprL;
	Expr *exprR;
	Expr_Div_Expr(Expr *, Expr *, int, int);
	virtual void accept(Visitor *);
};

class Expr_Modulo_Expr : public  Expr
{
public:
	Expr *exprL;
	Expr *exprR;
	Expr_Modulo_Expr(Expr *, Expr *, int, int);
	virtual void accept(Visitor *);
};

class Expr_And_Expr : public  Expr
{
public:
	Expr *exprL;
	Expr *exprR;
	Expr_And_Expr(Expr *, Expr *, int, int);
	virtual void accept(Visitor *);
};

class Expr_Or_Expr : public  Expr
{
public:
	Expr *exprL;
	Expr *exprR;
	Expr_Or_Expr(Expr *, Expr *, int, int);
	virtual void accept(Visitor *);
};

class Expr_Equal_Expr : public  Expr
{
public:
	Expr *exprL;
	Expr *exprR;
	Expr_Equal_Expr(Expr *, Expr *, int, int);
	virtual void accept(Visitor *);
};

class Expr_NotEqual_Expr : public  Expr
{
public:
	Expr *exprL;
	Expr *exprR;
	Expr_NotEqual_Expr(Expr *, Expr *, int, int);
	virtual void accept(Visitor *);
};

class Expr_Geater_Expr : public  Expr
{
public:
	Expr *exprL;
	Expr *exprR;
	Expr_Geater_Expr(Expr *, Expr *, int, int);
	virtual void accept(Visitor *);
};

class Expr_Less_Expr : public  Expr
{
public:
	Expr *exprL;
	Expr *exprR;
	Expr_Less_Expr(Expr *, Expr *, int, int);
	virtual void accept(Visitor *);
};

class Expr_Sup_Expr : public  Expr
{
public:
	Expr *exprL;
	Expr *exprR;
	Expr_Sup_Expr(Expr *, Expr *, int, int);
	virtual void accept(Visitor *);
};

class Expr_Inf_Expr : public  Expr
{
public:
	Expr *exprL;
	Expr *exprR;
	Expr_Inf_Expr(Expr *, Expr *, int, int);
	virtual void accept(Visitor *);
};

class IntegerExpr : public  Expr
{
public:
	Integer_value *intvalue;
	IntegerExpr(Integer_value*, int, int);
	virtual void accept(Visitor *);
};

class RealExpr : public  Expr
{
public:
	Real_value *realvalue;
	RealExpr(Real_value*, int, int);
	virtual void accept(Visitor *);
};

class TrueExpr : public  Expr
{
public:
	True_value * truevalue;
	TrueExpr(True_value*, int, int);
	virtual void accept(Visitor *);
};

class FalseExpr : public  Expr
{
public:
	False_value *falsevalue;
	FalseExpr(False_value*, int, int);
	virtual void accept(Visitor *);
};

class StringExpr : public Expr
{
public:
	string stringvalue;
	StringExpr(string, int, int);
	virtual void accept(Visitor *);
};

// i am not sure how we can define this.
// and in ast.cpp
class NullExpr : public Expr
{
public:
	const Expr* exp = NULL;
	NullExpr(int, int);
	virtual void accept(Visitor *);
};

class May_EXP : public Expr
{
public:
	Expr* expr;
	May_EXP(int, int);
	May_EXP(Expr*, int, int);
	virtual void accept(Visitor *);
};

// ====================================================== End : Expression Classes ======================================================
//=======================================================================================================================================
//=======================================================================================================================================
//=======================================================================================================================================
//====================================================== Start : Instruction Classes ===================================================

class Inst : public Node
{
public:
	// no return : -1, int=1, double=2, boolean=3
	int return_type;
	Inst(int line, int col) : Node(line, col) { return_type =4;}
	virtual void accept(Visitor *);
};

class Instructions : public Inst
{
public:
	vector <Inst * > *insts;
	Instructions(int, int);
	Instructions(Inst *, int, int);
	void addInstruction(Inst *);
	virtual void accept(Visitor *);
};

class While : public Inst
{
public:
	Expr *expr;
	Inst *inst;
	While(Expr *, Inst *, int, int);
	virtual void accept(Visitor *);
};

class For : public Inst
{
public:
	int type;
	Identifier* ident;
	Expr* conditionExpr;
	Expr* loopExpr;
	Inst *inst;
	For(int, Identifier*, Expr*, Expr*, Inst *, int, int);
	virtual void accept(Visitor *);
};
class For_Expr : public Inst
{
public:
	int type;
	Identifier* ident;
	Expr* assignexpr;
	Expr* conditionExpr;
	Expr* loopExpr;
	Inst *inst;
	For_Expr(int, Identifier*, Expr*, Expr*, Expr*, Inst *, int, int);
	virtual void accept(Visitor *);
};

class If : public Inst
{
public:
	Expr *expr;
	Inst *inst;
	If(Expr *, Inst *, int, int);
	virtual void accept(Visitor *);
};

class If_Else : public Inst
{
public:
	Expr *expr;
	Inst *inst_if;
	Inst *inst_else;
	If_Else(Expr *, Inst *, Inst *, int, int);
	virtual void accept(Visitor *);
};

class ExprInstruction : public Inst
{
public:
	Expr *expr;
	ExprInstruction(Expr *, int, int);
	virtual void accept(Visitor *);
};

class Identifier_Eq_Expr_Inst : public Inst
{
public:
	int type;
	Identifier * ident;
	Expr * expr;
	Identifier_Eq_Expr_Inst(int, Identifier *, Expr *, int, int);
	virtual void accept(Visitor *);
};

class Identifier_Declaration : public Inst
{
public:
	int type;
	Identifier * ident;
	Identifier_Declaration(int, Identifier *,  int, int);
	virtual void accept(Visitor *);
};

class Array : public Inst
{
public:
	int type;
	Integer_value* size;
	Identifier * ident;
	Array(int type, Identifier * id, Integer_value * size, int line , int col);
	virtual void accept(Visitor *);
};

class Semicolon : public Inst
{
public:
	Semicolon(int line, int col) :Inst(line, col) {}
	virtual void accept(Visitor *);
};

class Braces : public Inst
{
public:
	Instructions *instructions;
	Braces(Instructions *, int, int);
	virtual void accept(Visitor *);
};

class Return : public Inst
{
public:
	May_EXP* expr;
	Function * function;
	Return(May_EXP*, int, int);
	virtual void accept(Visitor *);
};

// ====================================================== End : Instruction Classes ======================================================
//=======================================================================================================================================
//=======================================================================================================================================
//=======================================================================================================================================
// ====================================================== Start : Function Classes ===================================================

class Function : public Node
{
public:
	Identifier *ident;
	int type;
	Params *parameters;
	bool CG_visited;
	Function(int line, int col) : Node(line, col) {}
	virtual void accept(Visitor *);
};

class Type_Param_Fun : public Function
{
public:
	Instructions * instructions;
	Type_Param_Fun(int, Identifier *, Params *, Instructions *, int, int);
	virtual void accept(Visitor *);
};

class Void_Param_Fun : public Function
{
public:
	Instructions * instructions;
	Void_Param_Fun(Identifier *, Params *, Instructions *, int, int);
	virtual void accept(Visitor *);
};

class Void_Fun : public Function
{
public:
	Identifier *ident;
	Instructions * instructions;
	Void_Fun(Identifier *, Instructions *, int, int);
	virtual void accept(Visitor *);
};

// ====================================================== End : Function Classes ======================================================
//=======================================================================================================================================
//=======================================================================================================================================
// ====================================================== Start : Global Classes ===================================================

class Global : public Node
{
public:
	Global(int line, int col) : Node(line, col) {}
	virtual void accept(Visitor *);
};

class Identifier_Global : public Global
{
public:
	int type;
	Identifier* ident;
	Identifier_Global(int, Identifier*, int, int);
	virtual void accept(Visitor *);
};

class Identifier_Expr_Global : public Global
{
public:
	int type;
	Identifier* ident;
	Expr* expr;
	Identifier_Expr_Global(int, Identifier*, Expr*, int, int);
	virtual void accept(Visitor *);
};

// ====================================================== End : Global Classes ======================================================
//=======================================================================================================================================
//=======================================================================================================================================
// ====================================================== Start : Body & Class Classes ===================================================

class Body : public Node
{
public:
	Body(int line, int col) :Node(line, col) {}
	virtual void accept(Visitor *);
	virtual void accept(GetFunctionsVisitor *);
};

class Func_Body : public Body
{
public:
	Body* body;
	Function*  function;
	Func_Body(Body*, Function*, int, int);
	virtual void accept(Visitor *);
	virtual void accept(GetFunctionsVisitor *);
};

class Global_Body : public Body
{
public:
	Body* body;
	Global* global;
	Global_Body(Body*, Global*, int, int);
	
	virtual void accept(Visitor *);
	virtual void accept(GetFunctionsVisitor *);
};

class Class : public Node
{
public:
	Identifier* ident;
	Body* body;
	Class(Identifier*, Body*, int, int);
	virtual void accept(Visitor *);
	virtual void accept(GetFunctionsVisitor *);
};

// ====================================================== End : Body & Class Classes ===================================================
//=======================================================================================================================================
//=======================================================================================================================================
// ====================================================== Start : Visitors ===================================================

class Visitor
{
public:
	virtual void Visit(Node *n) = 0;
	virtual void Visit(Identifier *n) = 0;
	virtual void Visit(Integer_value *n) = 0;
	virtual void Visit(Real_value *n) = 0;
	virtual void Visit(String_value *n) = 0;
	virtual void Visit(True_value *n) = 0;
	virtual void Visit(False_value *n) = 0;
	virtual void Visit(Parameter *n) = 0;
	virtual void Visit(Params *n) = 0;
	virtual void Visit(Expr *n) = 0;
	virtual void Visit(Expr_List *n) = 0;
	virtual void Visit(NegativeExpr *n) = 0;
	virtual void Visit(MinusExpr *n) = 0;
	virtual void Visit(PlusExpr *n) = 0;
	virtual void Visit(ParenthesesExpr *n) = 0;
	virtual void Visit(IdentifierExpr *n) = 0;
	virtual void Visit(VariableArrayElenment *n) = 0;
	virtual void Visit(Identifier_Eq_Expr *n) = 0;
	virtual void Visit(VariableArrayElenment_Eq_Expr *n) = 0;
	virtual void Visit(Identifier_Expr_list *n) = 0;
	virtual void Visit(Expr_Plus_Expr *n) = 0;
	virtual void Visit(Expr_Minus_Expr *n) = 0;
	virtual void Visit(Expr_Multiply_Expr *n) = 0;
	virtual void Visit(Expr_Div_Expr *n) = 0;
	virtual void Visit(Expr_Modulo_Expr *n) = 0;
	virtual void Visit(Expr_And_Expr *n) = 0;
	virtual void Visit(Expr_Or_Expr *n) = 0;
	virtual void Visit(Expr_Equal_Expr *n) = 0;
	virtual void Visit(Expr_NotEqual_Expr *n) = 0;
	virtual void Visit(Expr_Geater_Expr *n) = 0;
	virtual void Visit(Expr_Less_Expr *n) = 0;
	virtual void Visit(Expr_Sup_Expr *n) = 0;
	virtual void Visit(Expr_Inf_Expr *n) = 0;
	virtual void Visit(IntegerExpr *n) = 0;
	virtual void Visit(RealExpr *n) = 0;
	virtual void Visit(TrueExpr *n) = 0;
	virtual void Visit(FalseExpr *n) = 0;
	virtual void Visit(StringExpr *n) = 0;
	virtual void Visit(NullExpr *n) = 0;
	virtual void Visit(May_EXP *n) = 0;
	virtual void Visit(Inst *n) = 0;
	virtual void Visit(Instructions *n) = 0;
	virtual void Visit(While *n) = 0;
	virtual void Visit(For *n) = 0;
	virtual void Visit(For_Expr *n) = 0;
	virtual void Visit(If *n) = 0;
	virtual void Visit(If_Else *n) = 0;
	virtual void Visit(ExprInstruction *n) = 0;
	virtual void Visit(Identifier_Eq_Expr_Inst *n) = 0;
	virtual void Visit(Identifier_Declaration *n) = 0;
	virtual void Visit(Array *n) = 0;
	virtual void Visit(Semicolon *n) = 0;
	virtual void Visit(Braces *n) = 0;
	virtual void Visit(Return *n) = 0;
	virtual void Visit(Function *n) = 0;
	virtual void Visit(Type_Param_Fun *n) = 0;
	virtual void Visit(Void_Param_Fun *n) = 0;
	virtual void Visit(Global *n) = 0;
	virtual void Visit(Identifier_Global *n) = 0;
	virtual void Visit(Identifier_Expr_Global *n) = 0;
	virtual void Visit(Body *n) = 0;
	virtual void Visit(Func_Body *n) = 0;
	virtual void Visit(Global_Body *n) = 0;
	virtual void Visit(Class *n) = 0;
};

class PrintVisitor : public Visitor
{
private:
	string s;
	string types[6];
public:
	PrintVisitor();
	virtual void Visit(Node *n ) ;
	virtual void Visit(Identifier *n) ;
	virtual void Visit(Integer_value *n) ;
	virtual void Visit(Real_value *n) ;
	virtual void Visit(String_value *n) ;
	virtual void Visit(True_value *n) ;
	virtual void Visit(False_value *n) ;
	virtual void Visit(Parameter *n) ;
	virtual void Visit(Params *n) ;
	virtual void Visit(Expr *n) ;
	virtual void Visit(Expr_List *n) ;
	virtual void Visit(NegativeExpr *n) ;
	virtual void Visit(MinusExpr *n) ;
	virtual void Visit(PlusExpr *n) ;
	virtual void Visit(ParenthesesExpr *n) ;
	virtual void Visit(IdentifierExpr *n) ;
	virtual void Visit(VariableArrayElenment *n);
	virtual void Visit(Identifier_Eq_Expr *n) ;
	virtual void Visit(VariableArrayElenment_Eq_Expr *n);
	virtual void Visit(Identifier_Expr_list *n) ;
	virtual void Visit(Expr_Plus_Expr *n) ;
	virtual void Visit(Expr_Minus_Expr *n) ;
	virtual void Visit(Expr_Multiply_Expr *n) ;
	virtual void Visit(Expr_Div_Expr *n) ;
	virtual void Visit(Expr_Modulo_Expr *n) ;
	virtual void Visit(Expr_And_Expr *n) ;
	virtual void Visit(Expr_Or_Expr *n) ;
	virtual void Visit(Expr_Equal_Expr *n) ;
	virtual void Visit(Expr_NotEqual_Expr *n) ;
	virtual void Visit(Expr_Geater_Expr *n) ;
	virtual void Visit(Expr_Less_Expr *n) ;
	virtual void Visit(Expr_Sup_Expr *n) ;
	virtual void Visit(Expr_Inf_Expr *n) ;
	virtual void Visit(IntegerExpr *n) ;
	virtual void Visit(RealExpr *n) ;
	virtual void Visit(TrueExpr *n) ;
	virtual void Visit(FalseExpr *n) ;
	virtual void Visit(StringExpr *n);
	virtual void Visit(NullExpr *n) ;
	virtual void Visit(May_EXP *n) ;
	virtual void Visit(Inst *n) ;
	virtual void Visit(Instructions *n) ;
	virtual void Visit(While *n) ;
	virtual void Visit(For *n) ;
	virtual void Visit(For_Expr *n);
	virtual void Visit(If *n) ;
	virtual void Visit(If_Else *n) ;
	virtual void Visit(ExprInstruction *n) ;
	virtual void Visit(Identifier_Eq_Expr_Inst *n) ;
	virtual void Visit(Identifier_Declaration *n) ;
	virtual void Visit(Array *n) ;
	virtual void Visit(Semicolon *n) ;
	virtual void Visit(Braces *n) ;
	virtual void Visit(Return *n) ;
	virtual void Visit(Function *n);
	virtual void Visit(Type_Param_Fun *n) ;
	virtual void Visit(Void_Param_Fun *n) ;
	virtual void Visit(Global *n);
	virtual void Visit(Identifier_Global *n) ;
	virtual void Visit(Identifier_Expr_Global *n) ;
	virtual void Visit(Body *n) ;
	virtual void Visit(Func_Body *n) ;
	virtual void Visit(Global_Body *n) ;
	virtual void Visit(Class *n);
};

class TypeChecking : public Visitor
{
private:
	string types[6];
public:
	TypeChecking();
	vector<Function *> *functions;
	int matchCall(Identifier *,Expr_List *el, Function * f);
	void mismatchError(int, int, int, int);
	void conditionError(int ,int);
	virtual void Visit(Node *n);
	virtual void Visit(Identifier *n);
	virtual void Visit(Integer_value *n);
	virtual void Visit(Real_value *n);
	virtual void Visit(String_value *n);
	virtual void Visit(True_value *n);
	virtual void Visit(False_value *n);
	virtual void Visit(Parameter *n);
	virtual void Visit(Params *n);
	virtual void Visit(Expr *n);
	virtual void Visit(Expr_List *n);
	virtual void Visit(NegativeExpr *n);
	virtual void Visit(MinusExpr *n);
	virtual void Visit(PlusExpr *n);
	virtual void Visit(ParenthesesExpr *n);
	virtual void Visit(IdentifierExpr *n);
	virtual void Visit(VariableArrayElenment *n);
	virtual void Visit(Identifier_Eq_Expr *n);
	virtual void Visit(VariableArrayElenment_Eq_Expr *n);
	virtual void Visit(Identifier_Expr_list *n);
	virtual void Visit(Expr_Plus_Expr *n);
	virtual void Visit(Expr_Minus_Expr *n);
	virtual void Visit(Expr_Multiply_Expr *n);
	virtual void Visit(Expr_Div_Expr *n);
	virtual void Visit(Expr_Modulo_Expr *n);
	virtual void Visit(Expr_And_Expr *n);
	virtual void Visit(Expr_Or_Expr *n);
	virtual void Visit(Expr_Equal_Expr *n);
	virtual void Visit(Expr_NotEqual_Expr *n);
	virtual void Visit(Expr_Geater_Expr *n);
	virtual void Visit(Expr_Less_Expr *n);
	virtual void Visit(Expr_Sup_Expr *n);
	virtual void Visit(Expr_Inf_Expr *n);
	virtual void Visit(IntegerExpr *n);
	virtual void Visit(RealExpr *n);
	virtual void Visit(TrueExpr *n);
	virtual void Visit(FalseExpr *n);
	virtual void Visit(StringExpr *n) ;
	virtual void Visit(NullExpr *n);
	virtual void Visit(May_EXP *n);
	virtual void Visit(Inst *n);
	virtual void Visit(Instructions *n);
	virtual void Visit(While *n);
	virtual void Visit(For *n);
	virtual void Visit(For_Expr *n);
	virtual void Visit(If *n);
	virtual void Visit(If_Else *n);
	virtual void Visit(ExprInstruction *n);
	virtual void Visit(Identifier_Eq_Expr_Inst *n);
	virtual void Visit(Identifier_Declaration *n) ;
	virtual void Visit(Array *n);
	virtual void Visit(Semicolon *n);
	virtual void Visit(Braces *n);
	virtual void Visit(Return *n);
	virtual void Visit(Function *n);
	virtual void Visit(Type_Param_Fun *n);
	virtual void Visit(Void_Param_Fun *n);
	virtual void Visit(Global *n);
	virtual void Visit(Identifier_Global *n);
	virtual void Visit(Identifier_Expr_Global *n);
	virtual void Visit(Body *n);
	virtual void Visit(Func_Body *n);
	virtual void Visit(Global_Body *n);
	virtual void Visit(Class *n);
};

class CodeGeneration : public Visitor
{
private:
	string types[6];

public:
	CodeGeneration();
	int g;
	int f;
	int c;
	string later;
	void Operation(string s);
	void w(string s);
	//void wl(string s);
	vector <Symbol * > *funcs;
	//void initialize();
	void generateReadWriteFunction();
	virtual void Visit(Node *n);
	virtual void Visit(Identifier *n);
	virtual void Visit(Integer_value *n);
	virtual void Visit(Real_value *n);
	virtual void Visit(String_value *n);
	virtual void Visit(True_value *n);
	virtual void Visit(False_value *n);
	virtual void Visit(Parameter *n);
	virtual void Visit(Params *n);
	virtual void Visit(Expr *n);
	virtual void Visit(Expr_List *n);
	virtual void Visit(NegativeExpr *n);
	virtual void Visit(MinusExpr *n);
	virtual void Visit(PlusExpr *n);
	virtual void Visit(ParenthesesExpr *n);
	virtual void Visit(IdentifierExpr *n);
	virtual void Visit(VariableArrayElenment *n);
	virtual void Visit(Identifier_Eq_Expr *n);
	virtual void Visit(VariableArrayElenment_Eq_Expr *n);
	virtual void Visit(Identifier_Expr_list *n);
	virtual void Visit(Expr_Plus_Expr *n);
	virtual void Visit(Expr_Minus_Expr *n);
	virtual void Visit(Expr_Multiply_Expr *n);
	virtual void Visit(Expr_Div_Expr *n);
	virtual void Visit(Expr_Modulo_Expr *n);
	virtual void Visit(Expr_And_Expr *n);
	virtual void Visit(Expr_Or_Expr *n);
	virtual void Visit(Expr_Equal_Expr *n);
	virtual void Visit(Expr_NotEqual_Expr *n);
	virtual void Visit(Expr_Geater_Expr *n);
	virtual void Visit(Expr_Less_Expr *n);
	virtual void Visit(Expr_Sup_Expr *n);
	virtual void Visit(Expr_Inf_Expr *n);
	virtual void Visit(IntegerExpr *n);
	virtual void Visit(RealExpr *n);
	virtual void Visit(TrueExpr *n);
	virtual void Visit(FalseExpr *n);
	virtual void Visit(StringExpr *n);
	virtual void Visit(NullExpr *n);
	virtual void Visit(May_EXP *n);
	virtual void Visit(Inst *n);
	virtual void Visit(Instructions *n);
	virtual void Visit(While *n);
	virtual void Visit(For *n);
	virtual void Visit(For_Expr *n);
	virtual void Visit(If *n);
	virtual void Visit(If_Else *n);
	virtual void Visit(ExprInstruction *n);
	virtual void Visit(Identifier_Eq_Expr_Inst *n);
	virtual void Visit(Identifier_Declaration *n);
	virtual void Visit(Array *n);
	virtual void Visit(Semicolon *n);
	virtual void Visit(Braces *n);
	virtual void Visit(Return *n);
	virtual void Visit(Function *n);
	virtual void Visit(Type_Param_Fun *n);
	virtual void Visit(Void_Param_Fun *n);
	virtual void Visit(Global *n);
	virtual void Visit(Identifier_Global *n);
	virtual void Visit(Identifier_Expr_Global *n);
	virtual void Visit(Body *n);
	virtual void Visit(Func_Body *n);
	virtual void Visit(Global_Body *n);
	virtual void Visit(Class *n);
};

class GetFunctionsVisitor 
{

public:
	vector<Function *> * Functions;
	GetFunctionsVisitor() {
		Functions = new vector<Function *>();
	}
	virtual void Visit(Body *n);
	virtual void Visit(Func_Body *n);
	virtual void Visit(Global_Body *n);
	virtual void Visit(Class *n);
};
// ====================================================== End : Visitors ===================================================
//=======================================================================================================================================
//=======================================================================================================================================
// ====================================================== Start : Symbol Table ===================================================

class Symbol
{
public:
	string name;
	// Kind 1=global 2=local 3=function
	int kind;
	int type;
	int location;
	Array * array;
	vector<int> *parameterList;
	Function *function;
	Symbol(string name, int kind, int type);
	Symbol(string name, int kind, int type, Params * ps, Function * );
};

class Scope
{
public:
	Scope *father;
	vector<Scope *> *children;
	HashTab	*hashTab;
	Scope();
	void AddChild();
};

class SymbolTable
{
private:
	string types[6];
public:
	Scope *current;
	Errors *errors;

	SymbolTable();
	SymbolTable(Errors *errors);

	bool AddSymbol(Identifier *id, int kind, int type);
	bool AddSymbol(Identifier *id, int kind, int type, Params *ps, Function *fun);

	void OpenScope();
	Symbol *Lookup(string name);
	bool IsDeclared(Identifier *id);
	bool IsDeclared(Identifier *id, Deffered * deffered);
	bool IsDeclared(Identifier *id, Expr_List *el);
	void CloseScope();
};

class Error : public Node
{
public:
	string message;
	Error(string message, int, int);
};

class Errors 
{
public:
	vector<Error *> *errorLists;
	Errors();
	void AddError(string message, int line, int column);
	void Print();
};

class Deffered
{
public:
	vector<Identifier *> *identifiers;
	Deffered();
	void AddIdent(Identifier *);
	void CheckAll(SymbolTable *symtab);
};
class Initializer
{
public:
	static void initialize();
};