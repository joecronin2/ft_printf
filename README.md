*This Project has been created as part of the 42 curriculum by jcronin* 
## Description
```ft_printf``` is a custom implementation of the standard libc function ```printf()```, and it is meant to replicate most of it's behavior.
Printf makes it easy for a programmer to format strings and print them out to stdout using type specifiers. Type specifiers start with a '%', and the following character specifies what type is converted into a string. Here's an example:
```ft_printf("abc %d def", 123);```
This prints out "abc 123 def". 
Doing this without ```printf()``` would be considerably harder to implement and read. In this case, it would require writing the first string, then converting the decimal to a string with something like ```itoa()```.
## Instructions
The resulting binary from this project is a library file with the name ```ft_printf.a``` that can later be used to link against other projects.
This project can be automatically built with ```make```. To remove temporary files, use ```make clean``` or ```make fclean```.

## Resources
The main resource I used for this project is ```man 3``` for details about functions, and the standard implementation of ```printf()``` for comparison.

For new topics I am less familiar with, like how to use variadic arguments, I used a combination of search engines and LLMs. I strictly use LLMs for gaining understanding of new topics, and no code has been written or debugged with AI.
