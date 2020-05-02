#ifndef SMT_DEFS_H
#define SMT_DEFS_H

#include <memory>

namespace smt {

struct Op;

class AbsSort;
using Sort = std::shared_ptr<AbsSort>;

class AbsTerm;
using Term = std::shared_ptr<AbsTerm>;

class AbsSmtSolver;
using SmtSolver = std::shared_ptr<AbsSmtSolver>;


namespace Configurations{
    // configuration export to the user
    struct MsatInterpolatorConfiguration {
    std::string interpolation_mode;
    /*
        -theory.bv.interpolation_mode=INT
            Interpolation technique to use for bit-vectors. Possible values are:
            - 0 : equality substitution + LA(Z) encoding  + bit-level 
            interpolation 
            - 1 : LA(Z) encoding + bit-level interpolation
            - 2 : bit-level interpolation only
            - 3 : LA(Z) encoding + equality substitution + bit-level interpolation
            - 4 : equality substitution + bit-level interpolation.
    */
    std::string eq_propagation;
    MsatInterpolatorConfiguration() : // default value
    interpolation_mode("0"), eq_propagation("false") {}
    };
} // name space configurations

}  // namespace smt

#endif
