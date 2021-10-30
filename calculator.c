#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "expr.h"
#include "expr_student.h"

float showDetail(Expr *root){
    float ret = 0;
    if (root != NULL) {
        float lchild = showDetail(root->left);
        float rchild = showDetail(root->right);
        if (root->left == NULL && root->right == NULL) {
            ret = root->eval(lchild, rchild, root->floatVal);
        } else {
            ret = root->eval(lchild, rchild, 0);
            printf("%s = %f\n", root->origText, ret);
        }
    }
    return ret;
}
void freeExpr(Expr* root) {
    if (root != NULL) {
        free(root->origText);
        freeExpr(root->left);
        freeExpr(root->right);
        free(root);
    }
}

int main(void){
	while(1){
		int rc;
        size_t len = 256;
		// input
        printf("> ");
        char* line = malloc(len * sizeof(char));
        memset(line, '\0', len);
        rc = getline(&line, &len, stdin);
        if(rc == EOF) {
            free(line);
            break;
        }
        char* line_strip = strchr(line, '\n');
        if(line_strip != NULL)
            *line_strip = '\0';

		Expr *root = parseExpr(line);
		if(root == NULL){
			printf("Could not parse the expression: %s\n", line);
		} else {
			printf("%f\n", showDetail(root));
		}
		freeExpr(root);
		free(line);
	}
	return 0;
}