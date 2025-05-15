@echo off
REM new.bat: Create a problem directory with difficulty-based prefix
REM Usage: make new p=problem_name d=em

SET "PROBLEM_NAME=%1"
SET "DIFFICULTY=%d%"
SET "IGNORE=%d%"

IF "%PROBLEM_NAME%"=="" (
    echo Usage: make new p=problem_name d=difficulty
    exit /b 1
)

REM Difficulty to base mapping
IF "%DIFFICULTY%"=="e"  SET BASE=100
IF "%DIFFICULTY%"=="em" SET BASE=150
IF "%DIFFICULTY%"=="m"  SET BASE=200
IF "%DIFFICULTY%"=="mh" SET BASE=250
IF "%DIFFICULTY%"=="h"  SET BASE=300

IF "%BASE%"=="" (
    echo ❌ Invalid difficulty: %DIFFICULTY%
    exit /b 1
)

REM Find next number
SETLOCAL ENABLEDELAYEDEXPANSION
SET MAX=0
FOR /D %%D IN (%BASE%-*-*) DO (
    FOR /F "tokens=2 delims=-" %%A IN ("%%~nxD") DO (
        SET /A CUR=%%A
        IF !CUR! GEQ !MAX! SET /A MAX=CUR+1
    )
)

SET "FINAL=%BASE%-%MAX%-%PROBLEM_NAME%"
echo 📁 Creating: %FINAL%
mkdir "%FINAL%"
xcopy "TEMPLATE\*" "%FINAL%\" /E /I /Y >nul
echo ✅ Done: %FINAL%

REM Append to .gitignore if ignore=t
IF /I "%IGNORE%"=="t" (
    SET PATTERN=%BASE%-%NEXT%-*
    FINDSTR /X /C:"%PATTERN%" .gitignore >nul 2>&1
    IF ERRORLEVEL 1 (
        echo %PATTERN%>> .gitignore
        echo 📄 Added "%PATTERN%" to .gitignore
    ) ELSE (
        echo ℹ️ "%PATTERN%" already exists in .gitignore
    )
)