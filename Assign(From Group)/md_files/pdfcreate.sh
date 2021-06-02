#!/bin/zsh

TEMP=/tmp/pdfcreate.tmp
HEAD=head.tex
ITER=0

for i in $@
do
	pandoc -H $HEAD -V colorlinks -V urlcolor=NavyBlue  --from=gfm --to=pdf $i  --pdf-engine=xelatex -o $TEMP.$ITER.pdf
	ITER=$(expr $ITER + 1)
done

gs -q -dNOPAUSE -dBATCH -sDEVICE=pdfwrite -sOutputFile=- $TEMP.*.pdf
rm $TEMP*
