@echo off
setlocal

set Driver=PORT
set Layer=MCAL
set Author=Kerolos Hanna
set Email=Kerolos.Hanna@hotmail.com

set FILE_NAME=%Driver%_config.h
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
	echo #ifndef %Driver%_CONFIG_H
	echo #define %Driver%_CONFIG_H
	echo.
	echo.
	echo.
	echo #endif
) > %FILE_NAME%

set FILE_NAME=%Driver%_interface.h
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
	echo #ifndef %Driver%_INTERFACE_H
	echo #define %Driver%_INTERFACE_H
	echo.
	echo.
	echo.
	echo #endif
) > %FILE_NAME%

set FILE_NAME=%Driver%_private.h
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
	echo #ifndef %Driver%_PRIVATE_H
	echo #define %Driver%_PRIVATE_H
	echo.
	echo.
	echo.
	echo #endif
) > %FILE_NAME%

if %Layer%==HAL set FILE_NAME=%Driver%_program.c
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
	echo #include "..\..\MCAL\DIO\DIO_interface.h"
	echo.
	echo #include "%Driver%_config.h"
	echo #include "%Driver%_private.h"
	echo #include "%Driver%_interface.h"
) > %FILE_NAME%

if %Layer%==MCAL set FILE_NAME=%Driver%_program.c
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
) > %FILE_NAME%



if %Layer%==MCAL set FILE_NAME=%Driver%_register.h
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
	echo #ifndef %Driver%_REGISTER_H
	echo #define %Driver%_REGISTER_H
	echo.
	echo.
	echo.
	echo #endif
) > %FILE_NAME%


REM Exit with a specific exit code (e.g., 0 for success)
exit /b 0
