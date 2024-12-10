# Get_Next_Line
In this project the objective was to create a function that reads an fd line by line,, no matter the length or the number of lines.
Each time the functions is called it should return a line and, as long as that fd is not closed, 
it will always return the next line in subsequent calls until it reaches the end of the file or the fd is closed.

It is a simplified implementation of the readline function present in the C library.

## Bonus
In the bonus part is to make it so the function can read from multiple fd's at the same time.
For example, if I open two files and alternatly call the function passing one fd then the other, it will return 
