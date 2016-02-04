@echo off

md ide
cd ide
md vs2015
cd vs2015

cmake ../.. -G "Visual Studio 14 2015 Win64"
