#!/bin/bash

# -=-=-=-=-	CLRS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

DEF_COLOR='\033[0;39m'
BLACK='\033[0;30m'
RED='\033[1;91m'
GREEN='\033[1;92m'
YELLOW='\033[0;93m'
BLUE='\033[0;94m'
MAGENTA='\033[0;95m'
CYAN='\033[0;96m'
GRAY='\033[0;90m'
WHITE='\033[0;97m'

printf ${BLUE}"\n-------------------------------------------------------------\n"${DEF_COLOR};
printf ${YELLOW}"\n\t\tTEST CREATED BY: "${DEF_COLOR};
printf ${CYAN}"GEMARTIN\t\n"${DEF_COLOR};
printf ${BLUE}"\n-------------------------------------------------------------\n"${DEF_COLOR};

rm -rf traces.txt
rm -rf 0

# -=-=-=-=-	Control errors -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

FILE=$PWD/push_swap
FICHERO=test_check.txt

if [ -f "$FILE" ]; then
	echo -n
else
	printf "${RED}NO EXIST PUSH_SWAP PROGRAM ${DEF_COLOR}\n";
	exit 0
fi

if [ $1 == -v ];then
if [ -z "$2" ];then
	n=500;
else
	n=$2;
fi
ARG=$(ruby -e "puts (0..($n)).to_a.shuffle.join(' ')"); ./push_swap $ARG | ./pro_checker $ARG
exit 0
fi

if [ $1 == -v2 ];then
ARG=$2; ./push_swap $ARG | ./pro_checker $ARG
exit 0
fi

if [ -z "$1" ] || [ $1 != -b ]; then
printf ${BLUE}"\n-------------------------------------------------------------\n"${DEF_COLOR};
printf ${BLUE}"\n\t\t\tCONTROL ERRORS\t\n"${DEF_COLOR};
printf ${BLUE}"\n-------------------------------------------------------------\n\n"${DEF_COLOR};

ARG="a"
printf ${BLUE}"\n-------------------------------------------------------------\n\n"${DEF_COLOR};
printf ${BLUE}"\n\t\t  All size test + leaks check\t\n"${DEF_COLOR};
printf ${BLUE}"\n-------------------------------------------------------------\n\n"${DEF_COLOR};

echo All size test >> traces.txt

printf "\n${WHITE}⚠️ This test is very long. It is recommended to use it only when the project is finished or in an evaluation ⚠️${DEF_COLOR}\n\n\n";

sleep 1

res_1=0
res_2=0
res_3=0
res_4=0
cont=1
cont2=1
cont3=1
cont4=0
while [ $cont2 -lt 501 ]
do
cont=1
while [ $cont -lt 6 ]
do
ARG=$(ruby -e "puts (00..($cont2)).to_a.shuffle.join(' ')");
N=$(./push_swap $ARG | wc -l)
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}$cont3 .[OK]${DEF_COLOR}";
	((cont2++))
	printf	"${MAGENTA} Num args: $cont2 ${DEF_COLOR}"
	((cont2--))
	printf "${CYAN} Moves:$N${DEF_COLOR}\n";
	((res_1++))
else
	printf "${RED}$cont3 .[KO]${DEF_COLOR}\n";
	echo TEST $cont ARG:"$ARG" >> traces.txt
	((res_2++))
fi
if [ $cont -eq 5 ]; then

R=$(leaks -atExit -- ./push_swap $ARG > /dev/null && echo $?)
((cont4++))
if [[ $R == 0 ]]; then
  printf "${GREEN}$cont3 [MEMORY OK] ${DEF_COLOR}\n";
  ((res_3++))
else
  printf "${RED}$cont3 [KO LEAKS] ${DEF_COLOR}\n";
  echo TEST LEAKS $cont ARG:"$ARG" >> traces.txt
  ((res_4++))
fi
fi
((cont++))
((cont3++))
done
((cont2++))
done

((cont3--))

if [ $res_1 == $cont3 ]; then
	printf "${GREEN}\nCongrats , all tests have been completed successfully 🥳✅\n"
	echo OK >> traces.txt
fi
if [ $res_2 != 0 ]; then
printf	"${GREEN}\nOK${WHITE} TESTS $res_1/$cont3\n"
printf	"${RED}\nKO${WHITE} TESTS $res_2/$cont3\n"
printf "${CYAN}\nCheck traces $PWD/traces.txt\n"
fi

if [ $res_4 != 0 ]; then
printf	"${GREEN}\nOK${WHITE} TESTS $res_3/$cont4\n"
printf	"${RED}\nKO${WHITE} TESTS $res_4/$cont4\n"
printf "${CYAN}\nCheck traces $PWD/traces.txt\n"
fi

else

FILE=$PWD/checker

if [ -f "$FILE" ]; then
	echo -n
else
	printf "${RED}NO EXIST CHECKER PROGRAM${DEF_COLOR}\n";
	exit 0
fi

printf ${MAGENTA}"\n-------------------------------------------------------------\n\n"${DEF_COLOR};
printf ${MAGENTA}"\n\t\t\t  BONUS\t\t\n"${DEF_COLOR};
printf ${MAGENTA}"\n-------------------------------------------------------------\n\n"${DEF_COLOR};

printf ${MAGENTA}"\n-------------------------------------------------------------\n"${DEF_COLOR};
printf ${MAGENTA}"\n\t\t\tCONTROL ERRORS\t\n"${DEF_COLOR};
printf ${MAGENTA}"\n-------------------------------------------------------------\n\n"${DEF_COLOR};

./checker "a" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}1.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}1.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}1.[KO] ${DEF_COLOR}\n";
fi


./checker "111a11" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}2.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}2.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}2.[KO] ${DEF_COLOR}\n";
fi


./checker "hello world" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}3.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}3.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}3.[KO] ${DEF_COLOR}\n";
fi


./checker "" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}4.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}4.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}4.[KO] ${DEF_COLOR}\n";
fi

./checker "0 0" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}5.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}5.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}5.[KO] ${DEF_COLOR}\n";
fi

./checker "111-1 2 -3" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}7.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}7.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}7.[KO] ${DEF_COLOR}\n";
fi

./checker "-3 -2 -2" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}8.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}8.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}8.[KO] ${DEF_COLOR}\n";
fi

./checker "\n" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}9.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}9.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}9.[KO] ${DEF_COLOR}\n";
fi

./checker "-2147483649" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}10.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}10.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}10.[KO] ${DEF_COLOR}\n";
fi

./checker "-2147483650" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}11.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}11.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}11.[KO] ${DEF_COLOR}\n";
fi

./checker "2147483648" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}12.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}12.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}12.[KO] ${DEF_COLOR}\n";
fi

./checker "8 "9 1" 12" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}13.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}13.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}13.[KO] ${DEF_COLOR}\n";
fi

./checker "10 -1 -2 -3 -4 -5 -6 90 99 10" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}14.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}14.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}14.[KO] ${DEF_COLOR}\n";
fi

./checker "1 +1 -1" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}15.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}15.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}15.[KO] ${DEF_COLOR}\n";
fi

./checker "3333-3333 1 4" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}16.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}16.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}16.[KO] ${DEF_COLOR}\n";
fi

./checker "111a111 -4 3" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}17.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}17.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}17.[KO] ${DEF_COLOR}\n";
fi

./checker "111111 "-4 3"" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}18.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}18.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}18.[KO] ${DEF_COLOR}\n";
fi

./checker "2147483649" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}19.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}19.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}19.[KO] ${DEF_COLOR}\n";
fi

./checker "2147483647+1" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}20.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}20.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}20.[KO] ${DEF_COLOR}\n";
fi

./checker "0 1 2 3 4 5 0" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}21.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}21.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}21.[KO] ${DEF_COLOR}\n";
fi

./checker "3 +3" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}22.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}22.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}22.[KO] ${DEF_COLOR}\n";
fi

./checker "3+3" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}23.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}23.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}23.[KO] ${DEF_COLOR}\n";
fi

./checker "42 42" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}24.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}24.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}24.[KO] ${DEF_COLOR}\n";
fi

./checker "42 " -42" " 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}25.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}25.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}25.[KO] ${DEF_COLOR}\n";
fi

./checker "4222-4222" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}26.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}26.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}26.[KO] ${DEF_COLOR}\n";
fi

./checker "99999999999999999999999999" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}27.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}27.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}27.[KO] ${DEF_COLOR}\n";
fi

./checker "-99999999999999999999999999" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}28.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}28.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}28.[KO] ${DEF_COLOR}\n";
fi

./checker "0 -0 1 -1" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}29.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}29.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}29.[KO] ${DEF_COLOR}\n";
fi

./checker "0 +0 1 -1" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}30.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}30.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}30.[KO] ${DEF_COLOR}\n";
fi

./checker "111+111 -4 3" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}31.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}31.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}31.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

./checker "-" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}32.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}32.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}32.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

./checker "+" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}33.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}33.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}33.[KO] ${DEF_COLOR}\n";
fi

./checker "--123 1 321" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}34.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}34.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}34.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

./checker "++123 1 321" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}35.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}35.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}35.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

./checker "09 9 3 -1" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}36.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}36.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}36.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

./checker "00000001 1 9 3" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}37.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}37.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}37.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

./checker "-5 00000003 003 9 1" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}38.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}38.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}38.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

echo -e "saa" | ./checker "1" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
    printf "${GREEN}39.[OK] ${DEF_COLOR}\n";
  else
    printf "${RED}39.[KO] ${DEF_COLOR}\n";
    break
  fi
done < test_check.txt
else
  printf "${RED}39.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

echo -e "sa\n" | ./checker "1" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
    printf "${GREEN}40.[OK] ${DEF_COLOR}\n";
  else
    printf "${RED}40.[KO] ${DEF_COLOR}\n";
    break
  fi
done < test_check.txt
else
  printf "${RED}40.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

echo -e "SA" | ./checker "1" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
    printf "${GREEN}41.[OK] ${DEF_COLOR}\n";
  else
    printf "${RED}41.[KO] ${DEF_COLOR}\n";
    break
  fi
done < test_check.txt
else
  printf "${RED}41.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

echo -e "sa " | ./checker "1" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
    printf "${GREEN}42.[OK] ${DEF_COLOR}\n";
  else
    printf "${RED}42.[KO] ${DEF_COLOR}\n";
    break
  fi
done < test_check.txt
else
  printf "${RED}42.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

echo -e "" | ./checker "1" 2> test_check.txt > /dev/null
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
    printf "${GREEN}43.[OK] ${DEF_COLOR}\n";
  else
    printf "${RED}43.[KO] ${DEF_COLOR}\n";
    break
  fi
done < test_check.txt
else
  printf "${RED}43.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt


# Checkear nombres de funciones diferentes
printf ${MAGENTA}"\n-------------------------------------------------------------\n"${DEF_COLOR};
printf ${MAGENTA}"\n\t\t\tCheck operations\t\t\n"${DEF_COLOR};
printf ${MAGENTA}"\n-------------------------------------------------------------\n\n"${DEF_COLOR};

#pruebas SA
ARG="2 1 3";
S=$(echo -e "sa" | ./checker_Mac $ARG)
R=$(echo -e "sa" | ./checker $ARG)
if [ $S == $R ]; then
	printf "${GREEN}1.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}1.[KO] ${DEF_COLOR}\n";
fi

#pruebas SB
ARG="2 1 3 4";
S=$(echo -e "pb\npb\nsb\npa\npa" | ./checker_Mac $ARG)
R=$(echo -e "pb\npb\nsb\npa\npa" | ./checker $ARG)
if [ $S == $R ]; then
  printf "${GREEN}2.[OK] ${DEF_COLOR}\n";
else
  printf "${RED}2.[KO] ${DEF_COLOR}\n";
fi

#pruebas SS
ARG="2 1 4 3";
S=$(echo -e "pb\npb\nss\npa\npa" | ./checker_Mac $ARG)
R=$(echo -e "pb\npb\nss\npa\npa" | ./checker $ARG)
L=$(echo -e "pb\npb\nss\npa\npa" | leaks -atExit -- ./checker $ARG > /dev/null && echo $?)
if [ $S == $R ]; then
  printf "${GREEN}3.[OK] ${DEF_COLOR}";
else
  printf "${RED}3.[KO]${DEF_COLOR}";
fi
if [[ $L == 0 ]]; then
  printf "${GREEN}[MEMORY OK] ${DEF_COLOR}\n";
else
  printf "${RED}[KO LEAKS] ${DEF_COLOR}\n";
fi

#pruebas RA
ARG="2 1";
S=$(echo -e "ra" | ./checker_Mac $ARG)
R=$(echo -e "ra" | ./checker $ARG)
if [ $S == $R ]; then
  printf "${GREEN}4.[OK] ${DEF_COLOR}\n";
else
  printf "${RED}4.[KO] ${DEF_COLOR}\n";
fi

#pruebas RA
ARG="100 101 1 2 3 4 5 6 7 8 9 10 11 12 13 14";
S=$(echo -e "ra\nra" | ./checker_Mac $ARG)
R=$(echo -e "ra\nra" | ./checker $ARG)
if [ $S == $R ]; then
  printf "${GREEN}5.[OK] ${DEF_COLOR}\n";
else
  printf "${RED}5.[KO] ${DEF_COLOR}\n";
fi

#pruebas de todo
ARG="1";
S=$(echo -e "sa\nsb\nss\npa\npb\npa\npb\nsb\npa\nra\nrb\nrr\nrra\nrrb\nrrr" | ./checker_Mac $ARG)
R=$(echo -e "sa\nsb\nss\npa\npb\npa\npb\nsb\npa\nra\nrb\nrr\nrra\nrrb\nrrr" | ./checker $ARG)
L=$(echo -e "sa\nsb\nss\npa\npb\npa\npb\nsb\npa\nra\nrb\nrr\nrra\nrrb\nrrr" | leaks -atExit -- ./checker $ARG > /dev/null && echo $?)
if [ $S == $R ]; then
  printf "${GREEN}6.[OK] ${DEF_COLOR}";
else
  printf "${RED}6.[KO] ${DEF_COLOR}";
fi
if [[ $L == 0 ]]; then
  printf "${GREEN}[MEMORY OK] ${DEF_COLOR}\n";
else
  printf "${RED}[KO LEAKS] ${DEF_COLOR}\n";
fi

printf ${MAGENTA}"\n-------------------------------------------------------------\n"${DEF_COLOR};
printf ${MAGENTA}"\n\t\t\tBasic Input\t\t\n"${DEF_COLOR};
printf ${MAGENTA}"\n-------------------------------------------------------------\n\n"${DEF_COLOR};

ARG="2 1";
S=$(./push_swap $ARG | ./checker_Mac $ARG)
R=$(./push_swap $ARG | ./checker $ARG)
if [ $S == $R ]; then
	printf "${GREEN}1.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}1.[KO]${DEF_COLOR}\n";
fi

ARG="2 1 3";
S=$(./push_swap $ARG | ./checker_Mac $ARG)
R=$(./push_swap $ARG | ./checker $ARG)
if [ $S == $R ]; then
	printf "${GREEN}2.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}2.[KO]${DEF_COLOR}\n";
fi

ARG="1 3 2";
S=$(./push_swap $ARG | ./checker_Mac $ARG)
R=$(./push_swap $ARG | ./checker $ARG)
if [ $S == $R ]; then
	printf "${GREEN}3.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}3.[KO]${DEF_COLOR}\n";
fi

ARG="2 3 1";
S=$(./push_swap $ARG | ./checker_Mac $ARG)
R=$(./push_swap $ARG | ./checker $ARG)
if [ $S == $R ]; then
	printf "${GREEN}4.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}4.[KO]${DEF_COLOR}\n";
fi

ARG="3 2 1";
S=$(./push_swap $ARG | ./checker_Mac $ARG)
R=$(./push_swap $ARG | ./checker $ARG)
if [ $S == $R ]; then
	printf "${GREEN}5.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}5.[KO]${DEF_COLOR}\n";
fi

ARG="3 1 2";
S=$(./push_swap $ARG | ./checker_Mac $ARG)
R=$(./push_swap $ARG | ./checker $ARG)
if [ $S == $R ]; then
	printf "${GREEN}6.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}6.[KO]${DEF_COLOR}\n";
fi


ARG="4 3 2 1";
S=$(./push_swap $ARG | ./checker_Mac $ARG)
R=$(./push_swap $ARG | ./checker $ARG)
if [ $S == $R ]; then
	printf "${GREEN}7.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}7.[KO]${DEF_COLOR}\n";
fi

ARG="4 2 1 3";
S=$(./push_swap $ARG | ./checker_Mac $ARG)
R=$(./push_swap $ARG | ./checker $ARG)
if [ $S == $R ]; then
	printf "${GREEN}8.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}8.[KO]${DEF_COLOR}\n";
fi

ARG="4 3 1 2";
S=$(./push_swap $ARG | ./checker_Mac $ARG)
R=$(./push_swap $ARG | ./checker $ARG)
if [ $S == $R ]; then
	printf "${GREEN}9.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}9.[KO]${DEF_COLOR}\n";
fi

ARG="3 2 1 4";
S=$(./push_swap $ARG | ./checker_Mac $ARG)
R=$(./push_swap $ARG | ./checker $ARG)
if [ $S == $R ]; then
	printf "${GREEN}10.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}10.[KO]${DEF_COLOR}\n";
fi

printf ${MAGENTA}"\n-------------------------------------------------------------\n\n"${DEF_COLOR};
printf ${MAGENTA}"\n\t\t\tSize 5\t\t\n"${DEF_COLOR};
printf ${MAGENTA}"\n-------------------------------------------------------------\n\n"${DEF_COLOR};

ARG="2 1 3 4 5";
S=$(./push_swap $ARG | ./checker_Mac $ARG)
R=$(./push_swap $ARG | ./checker $ARG)
if [ $S == $R ]; then
	printf "${GREEN}1.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}1.[KO]${DEF_COLOR}\n";
fi

ARG="5 4 3 2 1";
S=$(./push_swap $ARG | ./checker_Mac $ARG)
R=$(./push_swap $ARG | ./checker $ARG)
if [ $S == $R ]; then
	printf "${GREEN}2.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}2.[KO]${DEF_COLOR}\n";
fi

ARG="5 4 1 2 3";
S=$(./push_swap $ARG | ./checker_Mac $ARG)
R=$(./push_swap $ARG | ./checker $ARG)
if [ $S == $R ]; then
	printf "${GREEN}3.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}3.[KO]${DEF_COLOR}\n";
fi

ARG="5 4 3 1 2";
S=$(./push_swap $ARG | ./checker_Mac $ARG)
R=$(./push_swap $ARG | ./checker $ARG)
if [ $S == $R ]; then
	printf "${GREEN}4.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}4.[KO]${DEF_COLOR}\n";
fi

ARG="4 5 3 1 2";
S=$(./push_swap $ARG | ./checker_Mac $ARG)
R=$(./push_swap $ARG | ./checker $ARG)
if [ $S == $R ]; then
	printf "${GREEN}5.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}5.[KO]${DEF_COLOR}\n";
fi

ARG="3 2 1 5 4";
S=$(./push_swap $ARG | ./checker_Mac $ARG)
R=$(./push_swap $ARG | ./checker $ARG)
if [ $S == $R ]; then
	printf "${GREEN}6.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}6.[KO]${DEF_COLOR}\n";
fi


ARG="1 2 3 5 4";
S=$(./push_swap $ARG | ./checker_Mac $ARG)
R=$(./push_swap $ARG | ./checker $ARG)
if [ $S == $R ]; then
	printf "${GREEN}7.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}7.[KO]${DEF_COLOR}\n";
fi

ARG="2 1 4 5 3";
S=$(./push_swap $ARG | ./checker_Mac $ARG)
R=$(./push_swap $ARG | ./checker $ARG)
if [ $S == $R ]; then
	printf "${GREEN}8.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}8.[KO]${DEF_COLOR}\n";
fi

ARG="1 3 2 5 4";
S=$(./push_swap $ARG | ./checker_Mac $ARG)
R=$(./push_swap $ARG | ./checker $ARG)
if [ $S == $R ]; then
	printf "${GREEN}9.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}9.[KO]${DEF_COLOR}\n";
fi

ARG="2 3 4 5 1";
S=$(./push_swap $ARG | ./checker_Mac $ARG)
R=$(./push_swap $ARG | ./checker $ARG)
if [ $S == $R ]; then
	printf "${GREEN}10.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}10.[KO]${DEF_COLOR}\n";
fi

rm -rf 0
rm -rf test_check.txt

printf ${MAGENTA}"\n-------------------------------------------------------------\n\n"${DEF_COLOR};
printf ${MAGENTA}"\n\t\t  Multiple size <= 100\t\t\n"${DEF_COLOR};
printf ${MAGENTA}"\n-------------------------------------------------------------\n\n"${DEF_COLOR};

echo BONUS-Multiple size '<'= 100 >> traces.txt

val=101

if [ $2 ]; then
	val=$(($2+1))
fi
res_1=0
res_2=0
cont=1
while [ $cont -lt $val ]
do
ARG=$(ruby -e "puts (00..99).to_a.shuffle.join(' ')");
S=$(./push_swap $ARG | ./checker_Mac $ARG)
R=$(./push_swap $ARG | ./checker $ARG)
if [ $S == $R ] && [ $R == "OK" ]; then
	printf "${GREEN}$cont .[OK] ${DEF_COLOR}";
	((res_1++))
else
	printf "${RED}$cont .[KO] ${DEF_COLOR}";
	echo TEST $cont ARG:"$ARG" >> traces.txt
	((res_2++))
fi
((cont++))
done

echo

((val--))
if [ $res_1 == $val ]; then
	printf "${GREEN}\nCongrats , all tests have been completed successfully 🥳✅\n"
	echo OK >> traces.txt
fi
if [ $res_2 != 0 ]; then
printf	"${GREEN}\nOK${WHITE} TESTS $res_1/$val${DEF_COLOR}\n"
printf	"${RED}\nKO${WHITE} TESTS $res_2/$val${DEF_COLOR}\n"
printf "${CYAN}\nCheck traces $PWD/traces.txt${DEF_COLOR}\n"
fi

rm -rf 0
rm -rf test_check.txt

printf ${MAGENTA}"\n-------------------------------------------------------------\n\n"${DEF_COLOR};
printf ${MAGENTA}"\n\t\t  Multiple size <= 500\t\t\n"${DEF_COLOR};
printf ${MAGENTA}"\n-------------------------------------------------------------\n\n"${DEF_COLOR};

echo BONUS-Multiple size '<'= 500 >> traces.txt

val=101

if [ $2 ]; then
	val=$(($3+1))
fi

res_1=0
res_2=0
cont=1
while [ $cont -lt $val ]
do
ARG=$(ruby -e "puts (00..499).to_a.shuffle.join(' ')");
S=$(./push_swap $ARG | ./checker_Mac $ARG)
R=$(./push_swap $ARG | ./checker $ARG)
if [ $S == $R ] && [ $R == "OK" ]; then
	printf "${GREEN}$cont .[OK] ${DEF_COLOR}";
	((res_1++))
else
	printf "${RED}$cont .[KO] ${DEF_COLOR}";
	echo TEST $cont ARG:"$ARG" >> traces.txt
	((res_2++))
fi
((cont++))
done

echo

((val--))
if [ $res_1 == $val ]; then
	printf "${GREEN}\nCongrats , all tests have been completed successfully 🥳✅\n"
	echo OK >> traces.txt
fi
if [ $res_2 != 0 ]; then
printf	"${GREEN}\nOK${WHITE} TESTS $res_1/$val\n"
printf	"${RED}\nKO${WHITE} TESTS $res_2/$val\n"
printf "${CYAN}\nCheck traces $PWD/traces.txt\n"
fi

rm -rf 0
rm -rf test_check.txt

printf ${MAGENTA}"\n-------------------------------------------------------------\n\n"${DEF_COLOR};
printf ${MAGENTA}"\n\t\t  All size test + leaks check\t\n"${DEF_COLOR};
printf ${MAGENTA}"\n-------------------------------------------------------------\n\n"${DEF_COLOR};

echo BONUS-All size test >> traces.txt

val=500
res_1=0
res_2=0
cont=1
var=0
while [ $cont -lt $val ] && [ $var -lt 500 ]
do
ARG=$(ruby -e "puts (00..$var).to_a.shuffle.join(' ')");
var=$(($var + 1))
S=$(./push_swap $ARG | ./checker_Mac $ARG)
R=$(./push_swap $ARG | ./checker $ARG)
if [ $S == $R ]; then
	printf "${GREEN}$cont .[OK] ${DEF_COLOR}";
	((res_1++))
else
	printf "${RED}$cont .[KO] ${DEF_COLOR}";
	echo TEST $cont ARG:"$ARG" >> traces.txt
 	((res_2++))
fi
R=$(./push_swap $ARG | leaks -atExit -- ./checker $ARG > /dev/null && echo $?)
if [[ $R == 0 ]]; then
  printf "${GREEN}[MOK] ${DEF_COLOR}";
else
  printf "${RED} [KO LEAKS] ${DEF_COLOR}";
fi
echo
((cont++))
done

while [ $var -lt 1000 ]
do
ARG=$(ruby -e "puts (00..$var).to_a.shuffle.join(' ')");
var=$(($var + 25))
S=$(./push_swap $ARG | ./checker_Mac $ARG)
R=$(./push_swap $ARG | ./checker $ARG)
if [ $S == $R ]; then
	printf "${GREEN}$cont .[OK] ${DEF_COLOR}";
	((res_1++))
else
	printf "${RED}$cont .[KO] ${DEF_COLOR}";
	echo TEST $cont ARG:"$ARG" >> traces.txt
 	((res_2++))
fi
R=$(./push_swap $ARG | leaks -atExit -- ./checker $ARG > /dev/null && echo $?)
if [[ $R == 0 ]]; then
  printf "${GREEN}[MOK] ${DEF_COLOR}";
else
  printf "${RED} [KO LEAKS] ${DEF_COLOR}";
fi
echo
((cont++))
done

((cont--))
echo

val=$(($val+$var))

((val--))
if [ $res_1 == $cont ]; then
	printf "${GREEN}\nCongrats , all tests have been completed successfully 🥳✅\n"
	echo OK >> traces.txt
fi
if [ $res_2 != 0 ]; then
printf	"${GREEN}\nOK${WHITE} TESTS $res_1/$cont\n"
printf	"${RED}\nKO${WHITE} TESTS $res_2/$cont\n"
printf "${CYAN}\nCheck traces $PWD/traces.txt\n"
fi

fi

rm -rf 0
rm -rf test_check.txt
