@echo off
rem RCS: @(#) $Id: mkd.bat,v 1.3.8.1 2000/04/06 22:38:39 spolk Exp $

if exist %1\. goto end

if "%OS%" == "Windows_NT" goto winnt

md %1
if errorlevel 1 goto end

goto success

:winnt
md %1
if errorlevel 1 goto end

:success
echo created directory %1

:end


