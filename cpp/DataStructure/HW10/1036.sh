#!/bin/bash
PjName="1036"
while
	echo "start"
	./$PjName""Data.out
	echo "Finish Data"
	./$PjName"".out < $PjName"".in > $PjName""data1.out
	echo "Finish 1"
	./$PjName""2.out < $PjName"".in > $PjName""data2.out
	echo "Finish 2"
	diff $PjName""data1.out $PjName""data2.out
do :; done
