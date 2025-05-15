@echo off
REM Usage: print.bat filename

setlocal enabledelayedexpansion

set "FILE=%~1"
set "MAXCHARS=300"

if not exist "%FILE%" (
    echo File not found: %FILE%
    exit /b 1
)

REM Read file into a variable up to MAXCHARS chars
set "CONTENT="
set /a COUNT=0

for /f "usebackq delims=" %%A in ("%FILE%") do (
    set "LINE=%%A"
    set /a LEN=0
    call :strlen LEN LINE
    if !COUNT! lss %MAXCHARS% (
        set /a REMAIN=%MAXCHARS%-!COUNT!
        if !LEN! gtr !REMAIN! (
            set "LINE=!LINE:~0,!REMAIN!!"
            set /a COUNT=%MAXCHARS%
        ) else (
            set /a COUNT+=LEN
        )
        echo(!LINE!
    )
    if !COUNT! geq %MAXCHARS% (
        goto :TRUNCATED
    )
)

goto :EOF

:TRUNCATED
echo ... (truncated)
goto :EOF

:strlen
setlocal enabledelayedexpansion
set "s=!%2!"
set "len=0"
:strlen_loop
if defined s (
    set "s=!s:~1!"
    set /a len+=1
    goto strlen_loop
)
endlocal & set "%1=%len%"
goto :EOF
