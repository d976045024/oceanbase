#ifndef OCEANBASE_SQL_EXPR_HELLO_H
#define OCEANBASE_SQL_EXPR_HELLO_H
#include "sql/engine/expr/ob_expr_operator.h"
namespace oceanbase {

namespace sql {

class ObExprHello : public ObStringExprOperator
{
public:
  explicit ObExprHello(common::ObIAllocator &alloc);
  virtual ~ObExprHello();

  virtual int calc_result_type0(ObExprResType &type, common::ObExprTypeCtx &type_ctx) const;
  virtual int cg_expr(ObExprCGCtx &expr_cg_ctx, const ObRawExpr &raw_expr,
                       ObExpr &rt_expr) const override;
  static int eval_hello(const ObExpr &expr, ObEvalCtx &ctx, ObDatum &res_datum);
};

}
}

#endif