#ifndef SRC_GRAPH_H_
#define SRC_GRAPH_H_

#define H 25
#define W 80

#define NOTHING '.'
#define POINT '*'


#define XMIN 0
#define XMAX 4 * M_PI
#define YMIN -1
#define YMAX 1
#include "list.h"

char** init_field();
struct func_result f(double x, char * s);
char **build_graph(char** field, char *s);
void destroy_field(char** field);
void show_field(char** field);
void substitution(char **str, double arg);

#endif  // SRC_GRAPH_H_
