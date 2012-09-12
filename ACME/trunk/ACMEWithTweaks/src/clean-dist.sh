#!/bin/sh

if test -d autom4te.cache
then
rm -r autom4te.cache
#rmdir autom4te.cache
fi	


if test -f Makefile.in
then
rm Makefile.in
fi	

if test -f configure
then
rm configure
fi	

if test -f aclocal.m4
then
rm aclocal.m4
fi	
