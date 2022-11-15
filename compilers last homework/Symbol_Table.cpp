#include "ast.h"
using std::cout;
using std::endl;


// no return : -1, int=1, double=2, boolean=3
// Kind 1=global 2=local 3=function
/*
	types[0] = "null";
	types[1] = "int";
	types[2] = "double";
	types[3] = "boolean";
	types[4] = "void";
*/

//==================================== Symbol =======================================================

Symbol::Symbol(string name, int kind, int type)
{
	this->name = name;
	// Kind 1=global 2=local 3=function
	this->kind = kind;
	this->type = type;
	this->function = NULL;
	this->parameterList = NULL;
}

Symbol::Symbol(string name, int kind, int type ,Params * ps, Function * function)
{
	this->name = name;
	// Kind 1=global 2=local 3=function
	this->kind = kind;
	this->type = type;
	this->function = function;
	this->parameterList = new vector<int>;
	if (ps)
	{
		for (int i = 0; i < ps->parameter_list->size(); i++)
			this->parameterList->push_back(ps->parameter_list->at(i)->type);
	}
}

//==================================== Scope =======================================================

Scope::Scope()
{
	this->father = NULL;
	this->hashTab = new HashTab;
	this->children = new vector<Scope *>;
}

void Scope::AddChild()
{
	Scope *child = new Scope();
	this->children->push_back(child);
	child->father = this;
}

//==================================== Error =======================================================


Error::Error(string message, int line, int col) :Node(line,col)
{
	this->message = message;
}
Errors::Errors()
{
	this->errorLists = new vector<Error *>;

}
void Errors::AddError(string message, int line, int column)
{
	Error *error = new Error(message, line, column);
	this->errorLists->push_back(error);
}
void Errors::Print()
{
	int size = this->errorLists->size();
	if (size == 0)
		cout << "Semntic analysis was done successfully! " << endl;
	else
	{
		cout << "There are " << size << " semantic errors: " << endl;
		for (int i = 0; i < size; i++)
		{
			cout	<< this->errorLists->at(i)->message << " at line: "
					<< this->errorLists->at(i)->line << " , column: "
					<< this->errorLists->at(i)->col << endl;
		}
	}
}

//==================================== SymbolTable =======================================================

SymbolTable::SymbolTable()
{
	this->current = new Scope();
	this->errors = new Errors();
	types[0] = "null";
	types[1] = "int";
	types[2] = "double";
	types[3] = "boolean";
	types[4] = "void";
	types[5] = "string";
}

SymbolTable::SymbolTable(Errors* errors)
{
	this->current = new Scope();
	this->errors = errors;
	types[0] = "null";
	types[1] = "int";
	types[2] = "double";
	types[3] = "boolean";
	types[4] = "void";
	types[5] = "string";
}


bool SymbolTable::AddSymbol(Identifier * ident, int kind, int type )
{
	string key =  ident->name;
	//if (this->Lookup(key) == NULL)
	if (this->current->hashTab->GetMember(key) == NULL)
	{
		Symbol *symbol = new Symbol(key, kind, type);
		this->current->hashTab->AddKey(key, symbol);
		ident->symbol = symbol;
		return true;
	}
	else
	{
		this->errors->AddError("Redefinition of Identifier variable '" + ident->name + "'", ident->line, ident->col);
		return false;
	}
}

bool SymbolTable::AddSymbol(Identifier * ident, int kind, int type, Params * ps, Function * fun)
{
	string key = std::to_string(kind) + ident->name;
	string parameter_key;
	if (ps)
	{
		for (int i = 0; i < ps->parameter_list->size(); i++)
		{
			int t = ps->parameter_list->at(i)->type;
			//parameter_key = ps->parameter_list->at(i)->ident->name;
			//Symbol *symbol = new Symbol(parameter_key, 2, t);
			//this->current->hashTab->AddKey(parameter_key, symbol);
			key += "@" + types[t];
		}
	}
	
	if (this->Lookup(key) == NULL)
	{
		Symbol *symbol = new Symbol(key, kind,type, ps,  fun);
		this->current->hashTab->AddKey(key, symbol);
		ident->symbol = symbol;
		return true;
	}
	else
	{
		this->errors->AddError("Redefinition of Identifier function '" + ident->name + "'", ident->line, ident->col);
		return false;
	}
}

void SymbolTable::OpenScope()
{
	this->current->AddChild();
	this->current = this->current->children->at(this->current->children->size() - 1);
}

Symbol * SymbolTable::Lookup(string name)
{
	Scope *scope = this->current;
	Symbol  *symbol = NULL;
	while (scope != NULL)
	{
		symbol = scope->hashTab->GetMember(name);
		if (symbol != NULL)
			return symbol;
		scope = scope->father;
	}
	return NULL;
}

bool SymbolTable::IsDeclared(Identifier * ident)
{
	Symbol *symbol = this->Lookup(ident->name);
	if (symbol != NULL)
	{
		ident->symbol = symbol;
		return true;
	}
	else
	{
		this->errors->AddError("Undeclared Identifier '" + ident->name + "'", ident->line, ident->col);
		return false;
	}
}

bool SymbolTable::IsDeclared(Identifier * ident, Deffered * deffered)
{
	Symbol *symbol = this->Lookup(ident->name);
	if (symbol != NULL)
	{
		ident->symbol = symbol;
		return true;
	}
	else
	{
		deffered->identifiers->push_back(ident);
		return false;
	}
}

bool SymbolTable::IsDeclared(Identifier * id, Expr_List * el)
{
	string key = "3"+id->name;
	int matched = 0;
	if (el)
	{
		for (int i = 0; i < el->expressions->size(); i++)
		{
			int t = el->expressions->at(i)->type;
			key += "@" + types[t];
		}
	}
	Symbol *symbol = this->Lookup(key);
	if (symbol != NULL)
	{
		id->symbol = symbol;
		return true;
	}
	else
	{
		//this->errors->AddError("Undeclared Identifier '" + id->name + "'", id->line, id->col);
		return false;
	}
}

void SymbolTable::CloseScope()
{
	this->current = this->current->father;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

Deffered::Deffered()
{
	this->identifiers = new vector<Identifier *>;
}

void Deffered::AddIdent(Identifier *id)
{
	this->identifiers->push_back(id);
}

void Deffered::CheckAll(SymbolTable *symtab)
{
	for (int i = 0; i < this->identifiers->size(); i++)
	{
		Symbol *symbol = symtab->current->hashTab->GetMember(this->identifiers->at(i)->name);
		if (symbol != 0)
			this->identifiers->at(i)->symbol = symbol;
		else
			symtab->errors->AddError("Undeclared Identifier '" + this->identifiers->at(i)->name + "'", this->identifiers->at(i)->line, this->identifiers->at(i)->col);
	}

}
