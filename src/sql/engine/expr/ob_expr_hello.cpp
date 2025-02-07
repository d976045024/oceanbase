#define USING_LOG_PREFIX SQL_ENG

#include "ob_expr_hello.h"
#include "sql/engine/ob_exec_context.h"
#include "sql/session/ob_sql_session_info.h"

using namespace oceanbase::common;
// using namespace oceanbase::sql;
static const char* SAY_HELLO = "Hello OceanBase!";

namespace oceanbase
{
namespace sql
{

ObExprHello::ObExprHello(ObIAllocator &alloc) : ObStringExprOperator(alloc, T_FUN_SYS_HELLO, N_HELLO, 0, NOT_VALID_FOR_GENERATED_COL)
{
}

ObExprHello::~ObExprHello()
{
}

int ObExprHello::calc_result_type0(ObExprResType &type, ObExprTypeCtx &type_ctx) const
{
  UNUSED(type_ctx);
  type.set_varchar();
  type.set_default_collation_type();
  type.set_collation_level(CS_LEVEL_SYSCONST);
  type.set_length(OB_MAX_DATABASE_NAME_LENGTH);
  return OB_SUCCESS;
}
int ObExprHello::cg_expr(ObExprCGCtx &op_cg_ctx, const ObRawExpr &raw_expr,
                       ObExpr &rt_expr) const
{
  int ret = OB_SUCCESS;
  UNUSED(raw_expr);
  UNUSED(op_cg_ctx);
  rt_expr.eval_func_ = ObExprHello::eval_hello;
  return ret;
}

int ObExprHello::eval_hello(const ObExpr &expr, ObEvalCtx &ctx, ObDatum &res_datum)
{
  int ret = OB_SUCCESS;
  res_datum.set_string(ObString(SAY_HELLO));
  return ret;
}

}
}