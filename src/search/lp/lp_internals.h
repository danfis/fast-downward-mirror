#ifndef LP_LP_INTERNALS_H
#define LP_LP_INTERNALS_H

/*
  This file provides some internal functions for the LP solver code.
  They could be implemented in linear_program.cc but we moved them here
  to avoid a long and complex file. They should not be necessary outside
  of linear_program.cc. If you need them, think about extending the
  LP class instead.
*/

#include "../utils/language.h"

#include <memory>

/*
  The following block works around a bug regarding the visibility of
  std::isnan that shows up with certain combinations of gcc version
  and OSI version, such as gcc 5.4.0-6ubuntu1~16.04.2 and OSI 0.103.0.
  Unfortunately the workaround breaks other gcc versions, so it is
  only activated if a suitable option is set. For more information,
  see https://bugs.launchpad.net/ubuntu/+source/gcc-5/+bug/1617838.
  Hopefully we can get rid of this once we require a more recent OSI
  version.
*/
#ifdef DOWNWARD_USE_GCC_5_4_OSI_WORKAROUND
#include <cmath>
using std::isnan;
#endif

class CoinError;
class OsiSolverInterface;

namespace lp {
enum class LPSolverType;

std::unique_ptr<OsiSolverInterface> create_lp_solver(LPSolverType solver_type);

/*
  Print the CoinError and then exit with ExitCode::CRITICAL_ERROR.
  Note that out-of-memory conditions occurring within CPLEX code cannot
  be caught by a try/catch block. When CPLEX runs out of memory,
  the planner will attempt to terminate gracefully, like it does with
  uncaught out-of-memory exceptions in other parts of the code.
*/
NO_RETURN
void handle_coin_error(const CoinError &error);
}

#endif
