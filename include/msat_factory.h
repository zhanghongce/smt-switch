#include "smt_defs.h"

namespace smt {
  class MsatSolverFactory
  {
    using MsatInterpolatorConfiguration = Configurations::MsatInterpolatorConfiguration;
  public:
    static SmtSolver create();
    static SmtSolver create_interpolating_solver(
      const MsatInterpolatorConfiguration & cfg = MsatInterpolatorConfiguration());
  };
}  // namespace smt
