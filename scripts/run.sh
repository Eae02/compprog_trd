#!/bin/bash
folder=$1;shift
for f in $folder/*.in; do
	echo $f
	pre=${f%.in}
	out=$pre.out
	$* < $f > $out
	diff $out $pre.ans
