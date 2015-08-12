#include <numpy_eigen/boost_python_headers.hpp>

void exportProblemManager();
void exportOptimizer();
void exportOptimizerOptions();
void exportOptimizationProblem();
void exportSampler();
void exportDesignVariable();
void exportErrorTerm();
//void exportBSplineMotionError();
void exportMEstimators();
void exportJacobianContainer();
void exportBackendExpressions();
//void exportErrorTermTransformation();

void exportBackend()
{
  exportProblemManager();
  exportOptimizer();
  exportOptimizerOptions();
  exportOptimizationProblem();
  exportSampler();
  exportDesignVariable();
  exportErrorTerm();
  //exportBSplineMotionError();
  exportMEstimators();
  exportJacobianContainer();
  exportBackendExpressions();
  //exportErrorTermTransformation();
}

