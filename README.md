# introduction
This is a very simple interpreter for c-like code, inspired by [c4](https://github.com/rswier/c4). The key difference between c4 and this interpreter is the latter one is embedded, and by it's very name, we can use this embedded interpreter to interpret and run a c-like code sinppet which, more often than not, is used to configure the main program, and can take the form of sole xml-file or string.

# components
This tiny embedded c interpreter is mainly composed of four parts:
- dependency
- lex
- parser
- executor

# usage
Suppose a scenario where there are two variables in main program named `result` and `data`, and we want to multiply the `data` by a number say 6, and store the result in the `result` variable. This sounds simple right? but what we do here is to write the logical code as an external configuration data not directly in the program, yes it is data not code. 

In order to realize this, we need the program to have the ability to parse the configuration data with logic into some thing can be executed,say bytecode, and the bytecode can intereact with the main program by accessing the two variables,`result` and `data`. The following steps show how to do it.

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

# link
There is a project named [satellite-borne-device-management](https://github.com/Gyumeijie/satellite-borne-device-management) uses this embedded interpreter to configure the program.

# todo 
- [ ] redesign the APIs for more usablity.
> Mainly center on seperating dependency variable info into two parts, the first part is static decalrative info 
> including type and name of a dependency; And the second part is about the dynamic runtime info concerning address
> of that dependency.
- [ ] refactor code for more Maintainability.
- [ ] support more grammar.
- [ ] add safety check for accessing dependency variable(s) in code block.

