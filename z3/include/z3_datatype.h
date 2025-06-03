#pragma once
#include "z3++.h"
#include "datatype.h"
#include "exceptions.h"

namespace smt {

class Z3DatatypeDecl : public AbsDatatypeDecl
{
 public:
  Z3DatatypeDecl(std::string name) : name(name){};

 protected:
  friend class Z3Solver;
  std::string name;
  std::vector<DatatypeConstructorDecl> consvec {};
};

class Z3DatatypeConstructorDecl : public AbsDatatypeConstructorDecl
{
 public:
  Z3DatatypeConstructorDecl(z3::context & c, std::string name)
      : c(c), constructorname(name){};
  bool compare(const DatatypeConstructorDecl &) const override;

 protected:
  friend class Z3Solver;

  z3::context & c;
  std::string constructorname, datatypename;
  std::vector<z3::symbol> fieldnames {};
  std::vector<z3::sort> sorts {};
};

class Z3Datatype : public AbsDatatype
{
 public:
  Z3Datatype(z3::context & c, z3::sort s) : c(c), datatype(s) {}
  std::string get_name() const override { return datatype.name().str(); }
  int get_num_constructors() const override
  {
    return Z3_get_datatype_sort_num_constructors(c, datatype);
  }
  int get_num_selectors(std::string name) const override
  {
    for (size_t i = 0; i < get_num_constructors(); i++)
    {
      z3::func_decl cons{ c, Z3_get_datatype_sort_constructor(c, datatype, i) };
      if (cons.name().str() == name) return cons.arity();
    }
    throw InternalSolverException(datatype.name().str() + "." + name
                                  + " not found");
  }

 private:
  z3::context & c;

  z3::sort datatype;
  friend class Z3Solver;
};

}  // namespace smt
