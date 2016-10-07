#ifndef ASLAM_BACKEND_DV_MATRIX_HPP
#define ASLAM_BACKEND_DV_MATRIX_HPP

#include <aslam/backend/JacobianContainer.hpp>
#include <boost/shared_ptr.hpp>
#include <set>

namespace aslam {
namespace backend {

/**
 * \class MatrixExpressionNode
 * \brief The superclass of all classes representing transformations.
 */
class MatrixExpressionNode {
 public:
  MatrixExpressionNode();
  virtual ~MatrixExpressionNode();

  /// \brief Evaluate the transformation matrix.
  Eigen::Matrix3d evaluate();
  Eigen::Matrix3d toMatrix3x3() { return evaluate(); }

  /// \brief Evaluate the Jacobians and apply the chain rule.
  void evaluateJacobians(JacobianContainer & outJacobians, const Eigen::MatrixXd & applyChainRule) const;

  void getDesignVariables(DesignVariable::set_t & designVariables) const;
 protected:
  // These functions must be implemented by child classes.
  virtual Eigen::Matrix3d evaluateImplementation() const = 0;
  virtual void evaluateJacobiansImplementation(JacobianContainer & outJacobians, const Eigen::MatrixXd & applyChainRule) const = 0;
  virtual void getDesignVariablesImplementation(DesignVariable::set_t & designVariables) const = 0;
};

}  // namespace backend
}  // namespace aslam

#endif /* ASLAM_BACKEND_DV_MATRIX_HPP */
