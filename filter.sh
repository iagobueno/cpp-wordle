#!/bin/bash

# usage:
# ./filter.sh <number-of-chars>

if [ "$#" -ne 2 ]; then
    echo
    echo "Número incorreto de argumentos."
    echo "usage:"
    echo "$0 <tamanho-palavra> <modo>"
    exit 1
fi

CHARS=$1
MODE=$2

if [ ${MODE} -eq 1 ]; then
    OUTPUT="dict/br-utf8.txt"
    FILE="./dict/br-utf8-${CHARS}.txt"
else
    OUTPUT="dict/br-sem-acentos-utf8.txt"
    FILE="./dict/br-sem-acentos-utf8-${CHARS}.txt"
fi

if [ -f ${FILE} ]; then
	rm ${FILE}
fi

# Para cada linha, checa se o tamanho da palavra é igual a CHARS
# e se a linha começa em minúsculo. Se sim, dá append no arquivo filtrado
while read -r line
do
	if [ ${CHARS} == ${#line} ] && [[ ! $line =~ ^[A-Z](.*)$ ]]; then
		echo ${line} >> ${FILE}
	fi

done < ${OUTPUT}