@echo off
rem RCS: @(#) $Id: rmd.bat,v 1.4.6.1 2000/05/04 21:26:31 spolk Exp $

if not exist %1\tag.txt goto end

echo Removing directory %1

if "%OS%" == "Windows_NT" goto winnt

cd %1
if errorlevel 1 goto end
del *.*
cd ..
rmdir %1
if errorlevel 1 goto end
goto success

:winnt
rmdir %1 /s /q
if errorlevel 1 goto end

:success
echo deleted directory %1

:end

