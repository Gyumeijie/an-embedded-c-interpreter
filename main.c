#include <stdio.h>
#include "parser.h"
#include "executor.h"
#include "dependency.h"

int main()
{
   // Initalization works
   parser_init();
   executor_init();

   // This two variables is in the main program, and will be used in the following code block
   int data = 13; 
   int result;
   
   // Add the dependency information
   struct dependency_items* dep_itemsp;
   dep_itemsp = init_dependency_items(2);
   add_dependency_item(dep_itemsp, "data", &data, INT);
   add_dependency_item(dep_itemsp, "result", &result, INT);

   // Get the code block ready
   char* src = "use{} action{result = data * 6;}";
   
   /*
    Compile the source code of the block, together with the dependencies which supply basic information about the 
    dependending variables
   */ 
   int* code = compile_src_code(dep_itemsp, src);
   
   /* 
     Fire the compiled code, during excution the block interacts with the main program through acessing the dependending
     variables
    */
   run_code(code);

   // Check the excution: the result will be 78
   printf("result is %d\n",  result);
}
