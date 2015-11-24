@echo off

md ide
cd ide
md vs2013
cd vs2013

cmake ../.. -G "Visual Studio 12 2013 Win64"
