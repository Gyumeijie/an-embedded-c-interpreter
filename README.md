# an-embedded-c-interpreter
A very simple interpreter for C, inspired by [c4](https://github.com/rswier/c4)

# components
This tiny embedded c interpreter is mainly composed of four parts:
- dependency
- lex
- parser
- executor

# usage
1. Initilizatize the parser and the executor
```c
 parser_init();  
 executor_init();
```

2. Add dependecy
```c
   dep_itemsp = init_dependency_items(2);
   add_dependency_item(dep_itemsp, "data", &data, INT);
   add_dependency_item(dep_itemsp, "result", &result, INT);
```
>Notice that the ***data*** and ***result*** are variables in the main program, both with integer type, and the two will be used
in the code block.

3. Get the code block ready
```c
 char* src = "use{} action{result = data * 6;}";
```
>***"use{} action{result = data * 6;}"*** is what we call ***code block***, which can be place in the source file or configuration
file, say xml-format file. The following xml snippet is a simple demo of xml-format code block:
> ```xml
> <code_block name="arbitary-name-you-like">
>   use{} action{result = data * 6;} 
> </code_block>
> ```

4. Compile the source code
```c
int* code = compile_src_code(dep_itemsp, src);
```

5. Run the compiled byte code
```c
run_code(code);
```

 When excution is done, the ***result*** ,in the main program, will have a value of 6, given ***data*** is 1.
