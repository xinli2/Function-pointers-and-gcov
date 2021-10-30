#ifndef __EXPR_STUDENT_INCLUDED__
#define __EXPR_STUDENT_INCLUDED__
#include "expr.h"

Expr *parseExpr(char *in);
void freeExpr(Expr* root);

#endif
