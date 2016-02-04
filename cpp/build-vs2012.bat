@echo off

md ide
cd ide
md vs2012
cd vs2012

cmake ../.. -G "Visual Studio 11 2012 Win64"