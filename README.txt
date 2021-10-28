# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    README.txt                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 13:15:16 by JEAN-SEBA         #+#    #+#              #
#    Updated: 2021/10/28 09:49:17 by jcourtem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Project: ft_printf from 42 Network.

Description: 
    This is a 42 Network project from the level_2. I need to rebuild the 
    printf function from the libc library.

Directive:
    Read the fr.subject.pdf file.


Project Structure:

    /ft_printf/
    /ft_printf/Makefile
    /ft_printf/README.txt
    /ft_printf/libftprintf.a    (when compiled with make)
    /ft_printf/a.out            (when compiled with make main for testing purposes)
    /ft_printf/.gitignore
    /ft_printf/srcs/
    /ft_printf/srcs/.main.c
    /ft_printf/srcs/ft_check_flag.c
    /ft_printf/srcs/ft_intlen.c 
    /ft_printf/srcs/ft_printf.c
    /ft_printf/srcs/ft_put_c.c
    /ft_printf/srcs/ft_put_h.c
    /ft_printf/srcs/ft_put_i.c
    /ft_printf/srcs/ft_put_p.c
    /ft_printf/srcs/ft_put_percent.c
    /ft_printf/srcs/ft_put_s.c
    /ft_printf/srcs/ft_put_u.c
    /ft_printf/srcs/ft_putnbr.c
    /ft_printf/srcs/ft_strlen.c
    /ft_printf/include/FT_PRINTF_H

Function Description by files:
 
    |                  |                                 |                          |               |                              |                                               |                  
    |------------------|---------------------------------|--------------------------|---------------|------------------------------|-----------------------------------------------|
    | FILES            | FUNCTIONS PROTOTYPE             | DESCRIPTION              |  INPUT/ARGS:  | PROCESS:                     | OUTPUT:                                       |               
    |------------------|---------------------------------|--------------------------|---------------|------------------------------|-----------------------------------------------|
    | /.main.c:        |                                 | Use for testing purposes |               |                              |                                               |
    |------------------|---------------------------------|--------------------------|---------------|------------------------------|-----------------------------------------------|
    | /ft_printf.c:    | ft_printf(const char *str, ...);| Main fucntion to call.   | - *str        |                              | - in code: the 'count' of character printed   |
    |                  |                                 | It will first            | - va_args     |                              | - stdout: the printed str with expended flags |
    |------------------|---------------------------------|--------------------------|---------------|------------------------------|-----------------------------------------------|
    |                  | ft_printf_helper \              |                          | - *str        |                              |                                               |
    |                  | (const char *str, va_list ap, \ |                          | - va_list ap  |                              |                                               |
    |                  | int *count)                     |                          | - count       |                              |                                               |
    |------------------|---------------------------------|--------------------------|---------------|------------------------------|-----------------------------------------------|
    |                  |                                 |                          |               |                              |                                               |
    |/ ft_check_flag.c | void	ft_check_flag \          |                          |               |                              |                                               |
    |                  | (const char flag, va_list ap, \ |                          |               |                              |                                               |
    |                  | int *count);                    |                          |               |                              |                                               |
    |------------------|---------------------------------|--------------------------|---------------|------------------------------|-----------------------------------------------|
    | /ft_put_percent.c| int     ft_put_percent(const  \ |                          | - *str        |                              |                                               |
    |                  | char *str, int i, int *count);  |                          | - int I       |                              |                                               |
    |                  |                                 |                          | - *count      |                              |                                               |
    |------------------|---------------------------------|--------------------------|---------------|------------------------------|-----------------------------------------------|  

    
Modifications Log: 

28-10*2021:

    after reformating the ft_put_p.c source, I have a segfault because of line # 36 ¨*nb = (unsigned long)n;¨ 

27-10-2021:

Pre Push checkup: 
    
    [X] Norminette
    [X] tripouille
    [X] Santanas
    

Entry #2:
    - So after, now that the function work on tripouille/printfTester, I need to fix it for it to work with the satanas/ft_printf_tester.
    test # 91, 92, 94 don't work.
    91:
                    Input: "%%p is how you print a pointer in printf"
            printf output: %p is how you print a pointer in printf
        ft_printf out_put: % is how you print a pointer in printf
        
        Personal test: trying this input with my main function, gives me the expected ouptput.
    92:
                    Input: "the '%%%%' is used to print a %% in printf"
            printf output: the '%%' is used to print a % in printf
        ft_printf out_put: the '%% is used to print a % in printf

        Personal test: Again, with this input in my main funciton, I get the expected output.
    94:
                    Input: "%%c%%s%%p%%d%%i%%u%%x%%X%%"
            printf output: %c%s%p%d%i%u%x%X%
        ft_printf out_put: %%%%%%%%%

        Personal test: same here.

    - Maybe there is something going on on the satanas/ft_printf_tester side.
    - I redid the test but this time I used the sh test "*" command to test them individually and they all work. Lets try running the fulle 
    test suit again. test done 3 times.
    - Everything works this time!
    _ Testing tripouille/printfTester | done 3 time. 

Entry #1:
    - Since yesterday, I have been trying to fix the '%' printing from my ft_printf project. Testing from the tripouille/printfTester
    everything is fine, but when I test with satanas/ft_printf_tester, the '%' test fails. The probleme is that the index is not always 
    ok when returning from ft_check_flags, where the '%' symbol are dealt with, 
    My solution is to create a separate funtion that will calculate the amount of consecutives '%' from the current position in *str, 
    and will print half of that. 
    If the amount of '%' is odd (percent_amount_in_str % 2) decrement (int) i, for it has overpassed the position that we 
    ultimatly want once we're out of that function and back into ft_printf_helper.

    - I had to modify a chunk of the code because I cannot return more than one variable after the function is completed. I changed the
    int count to a int *count so that when I carry the variable through the funcitons to print the different char, i can modify it's 
    value by dereferencing it.