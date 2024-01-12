#!/bin/bash #>> you are telling your environment/ os to use bash as a command interpreter
arc=$(uname -a) #uname displays information about the system and -a means all information


#grep or "global regular expression print” is a command used in searching 
#and matching text files contained in the regular expressions

#awk is a kind of super command with which you can do many things
#for example awk '{ print $2; }' prints the second field of each line

#The /proc/cpuinfo command provides information about 
pcpu=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l) 

vcpu=$(grep "^processor" /proc/cpuinfo | wc -l) #Provides each processor with an identifying number.
						#If you have one processor it will display a 0. 
						#If you have more than one processor it will display 
						#all processor information separately counting the processors
						#using zero notation.

#The free command provides information about the total amount of the physical and 
#swap memory, as well as the free and used memory
# -m displays the amount of memory in mebibytes
fram=$(free -m | awk '$1 == "Mem:" {print $2}') #Display the free/unused memory

uram=$(free -m | awk '$1 == "Mem:" {print $3}') #Diplay the used memory

pram=$(free | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}') #Display the usage rate as a percentage


#The df command (short for disk free), is used to display information related to
# file systems about total space and available space.
fdisk=$(df -BG | grep '^/dev/' | grep -v '/boot$' | awk '{ft += $2} END {print ft}')

udisk=$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} END {print ut}')

pdisk=$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} {ft+= $2} END {printf("%d"), ut/ft*100}')


cpul=$(top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf("%.1f%%"), $1 + $3}')


lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')


#here the goal is to know if your VM has dynamic partitions.
#so if you have more than 0 partitions when you type the lsblk command
#then you can display "yes
lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -eq 0 ]; then echo no; else echo yes; fi)

ctcp=$(ss -neopt state established | wc -l)


       ip-address(8), ip-addrlabel(8), ip-ioam(8), ip-l2tp(8), ip-link(8), ip-maddress(8), ip-monitor(8), ip-
       mptcp(8), ip-mroute(8), ip-neighbour(8), ip-netns(8), ip-ntable(8), ip-route(8), ip-rule(8), ip-
       stats(8) ip-tcp_metrics(8), ip-token(8), ip-tunnel(8), ip-vrf(8), ip-xfrm(8)


OBJECT := { link | address | addrlabel | route | rule | neigh | ntable | tunnel | tuntap | maddress |
		mroute | mrule | monitor | xfrm | netns | l2tp | tcp_metrics | token | macsec | vrf | mptcp |
		ioam | stats }

1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
2: enp0s3: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
    inet 10.0.2.15/24 brd 10.0.2.255 scope global dynamic enp0s3
       valid_lft 72155sec preferred_lft 72155sec





ulog=$(users | wc -w)

#hostname command displays the system hostname
ip=$(hostname -I) # -I is used to get all IP(network) addresses

mac=$(ip link show | grep "ether" | awk '{print $2}')

cmds=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

#here you will call all the variables that you created above
#and display eveything in an aesthetic way
wall "	#Architecture: $arc
	#CPU physical: $pcpu
	#vCPU: $vcpu
	#Memory Usage: $uram/${fram}MB ($pram%)
	#Disk Usage: $udisk/${fdisk}Gb ($pdisk%)
	#CPU load: $cpul
	#Last boot: $lb
	#LVM use: $lvmu
	#Connections TCP: $ctcp ESTABLISHED
	#User log: $ulog
	#Network: IP $ip ($mac)
	#Sudo: $cmds cmd"