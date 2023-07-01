@echo off
setlocal enabledelayedexpansion

rem Get the 2 input string variables.
set /p Driver="The Driver Name:"

rem Convert the 2 string variables to uppercase.
set Driver=!Driver:a=A!
set Driver=!Driver:b=B!
set Driver=!Driver:c=C!
set Driver=!Driver:d=D!
set Driver=!Driver:e=E!
set Driver=!Driver:f=F!
set Driver=!Driver:g=G!
set Driver=!Driver:h=H!
set Driver=!Driver:i=I!
set Driver=!Driver:j=J!
set Driver=!Driver:k=K!
set Driver=!Driver:l=L!
set Driver=!Driver:m=M!
set Driver=!Driver:n=N!
set Driver=!Driver:o=O!
set Driver=!Driver:p=P!
set Driver=!Driver:q=Q!
set Driver=!Driver:r=R!
set Driver=!Driver:s=S!
set Driver=!Driver:t=T!
set Driver=!Driver:u=U!
set Driver=!Driver:v=V!
set Driver=!Driver:w=W!
set Driver=!Driver:x=X!
set Driver=!Driver:y=Y!
set Driver=!Driver:z=Z!

set /p Layer="The Layer (MCAL - HAL - LIB - APP):"
set Layer=!Layer:a=A!
set Layer=!Layer:b=B!
set Layer=!Layer:c=C!
set Layer=!Layer:d=D!
set Layer=!Layer:e=E!
set Layer=!Layer:f=F!
set Layer=!Layer:g=G!
set Layer=!Layer:h=H!
set Layer=!Layer:i=I!
set Layer=!Layer:j=J!
set Layer=!Layer:k=K!
set Layer=!Layer:l=L!
set Layer=!Layer:m=M!
set Layer=!Layer:n=N!
set Layer=!Layer:o=O!
set Layer=!Layer:p=P!
set Layer=!Layer:q=Q!
set Layer=!Layer:r=R!
set Layer=!Layer:s=S!
set Layer=!Layer:t=T!
set Layer=!Layer:u=U!
set Layer=!Layer:v=V!
set Layer=!Layer:w=W!
set Layer=!Layer:x=X!
set Layer=!Layer:y=Y!
set Layer=!Layer:z=Z!

set Author=Kerolos Hanna"
set Email=Kerolos.Hanna@hotmail.com





md COTs\%Layer%\%Driver%

REM make the c file according to the driver type

if %Layer%==HAL set FILE_NAME1=%Driver%_program.c
REM Create the file with multiple lines
(
	echo /*****************************************************************/
	echo /*****************************************************************/
	echo /************		Author: %Author%			**************/
	echo /************		%Email%		**************/
	echo /************		Layer:	%Layer%					**************/
	echo /************		SWC:	%Driver%						**************/
	echo /************		version: 1.00					**************/
	echo /*****************************************************************/
	echo /*****************************************************************/
	echo.
	echo #include "..\..\LIB\STD_TYPES.h"
	echo #include "..\..\LIB\BIT_MATH.h"
	echo.
	echo #include "%Driver%_config.h"
	echo #include "%Driver%_private.h"
	echo #include "%Driver%_interface.h"
) > COTs\%Layer%\%Driver%\%FILE_NAME1%

if %Layer%==MCAL set FILE_NAME2=%Driver%_program.c
REM Create the file with multiple lines
(
	echo /*****************************************************************/
	echo /*****************************************************************/
	echo /************		Author: %Author%			**************/
	echo /************		%Email%		**************/
	echo /************		Layer:	%Layer%					**************/
	echo /************		SWC:	%Driver%						**************/
	echo /************		version: 1.00					**************/
	echo /*****************************************************************/
	echo /*****************************************************************/
	echo.
	echo #include "..\..\LIB\STD_TYPES.h"
	echo #include "..\..\LIB\BIT_MATH.h"
	echo.
	echo #include "%Driver%_register.h"
	echo #include "%Driver%_config.h"
	echo #include "%Driver%_private.h"
	echo #include "%Driver%_interface.h"
) > COTs\%Layer%\%Driver%\%FILE_NAME2%

REM Creating the private.h file
set FILE_NAME3=%Driver%_private.h
(
	echo /*****************************************************************/
	echo /*****************************************************************/
	echo /************		Author: %Author%			**************/
	echo /************		%Email%		**************/
	echo /************		Layer:	%Layer%					**************/
	echo /************		SWC:	%Driver%						**************/
	echo /************		version: 1.00					**************/
	echo /*****************************************************************/
	echo /*****************************************************************/
	echo.
	echo #ifndef %Driver%_PRIVATE_H
	echo #define %Driver%_PRIVATE_H
	echo.
	echo.
	echo.
	echo #endif
) > COTs\%Layer%\%Driver%\%FILE_NAME3%

REM Creating the config.h file
set FILE_NAME4=%Driver%_config.h
(
	echo /*****************************************************************/
	echo /*****************************************************************/
	echo /************		Author: %Author%			**************/
	echo /************		%Email%		**************/
	echo /************		Layer:	%Layer%					**************/
	echo /************		SWC:	%Driver%						**************/
	echo /************		version: 1.00					**************/
	echo /*****************************************************************/
	echo /*****************************************************************/
	echo.
	echo #ifndef %Driver%_CONFIG_H
	echo #define %Driver%_CONFIG_H
	echo.
	echo.
	echo.
	echo #endif
) > COTs\%Layer%\%Driver%\%FILE_NAME4%

REM Creating the interface.h file
set FILE_NAME5=%Driver%_interface.h
(
	echo /*****************************************************************/
	echo /*****************************************************************/
	echo /************		Author: %Author%			**************/
	echo /************		%Email%		**************/
	echo /************		Layer:	%Layer%					**************/
	echo /************		SWC:	%Driver%						**************/
	echo /************		version: 1.00					**************/
	echo /*****************************************************************/
	echo /*****************************************************************/
	echo.
	echo #ifndef %Driver%_INTERFACE_H
	echo #define %Driver%_INTERFACE_H
	echo.
	echo.
	echo.
	echo #endif
) > COTs\%Layer%\%Driver%\%FILE_NAME5%

REM this file will only be created if the Driver is MCAL
if %Layer%==MCAL set FILE_NAME6=%Driver%_register.h
(
	echo /*****************************************************************/
	echo /*****************************************************************/
	echo /************		Author: %Author%			**************/
	echo /************		%Email%		**************/
	echo /************		Layer:	%Layer%					**************/
	echo /************		SWC:	%Driver%						**************/
	echo /************		version: 1.00					**************/
	echo /*****************************************************************/
	echo /*****************************************************************/
	echo.
	echo #ifndef %Driver%_REGISTER_H
	echo #define %Driver%_REGISTER_H
	echo.
	echo.
	echo.
	echo #endif
) > COTs\%Layer%\%Driver%\%FILE_NAME6%

REM Exit with a specific exit code (e.g., 0 for success)
exit /b 0
