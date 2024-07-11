# Script to display system information on all users ttys (wall)

CPU_PHYSICAL=$(lscpu | awk '$1=="CPU(s):" {print $2}')
VCPU=$(nproc)

DISK_USED=$(df -BM --total | grep total | awk '{sub(/M$/, "", $3); print $3}')
DISK_CAPACITY=$(df -h --total| awk '$1=="total" {print $2}')
DISK_USAGE=$(df -hP --total| grep total | awk '{print $5}')

MEM_TOTAL=$(free --mega| grep Mem: | awk '{print $2}')
MEM_USED=$(free --mega| grep Mem: | awk '{print $3}')

MEM_USED_PERCENT=$(free --mega| awk '$1=="Mem:" {printf("%.2f"), $3/$2*100}')

CPU_LOAD=$(mpstat | awk '$3=="all" {print 100-$13}')
LAST_BOOT=$(who -b | awk '{print $3" "$4" "$5}')
LVM_ACTIVE=$(if [ $(lsblk | grep "lvm" | wc -l) -eq 0 ]; then echo no; else echo yes; fi)
TCP_CONNECTIONS=$(ss | grep "tcp" | wc -l)
SERVER_USERS=$(users | wc -w)
IP_ADDRESS=$(hostname -I)
MAC_ADDRESS=$(ip -4 link show | grep ether | awk '{print $2}')
SUDO=$(journalctl _COMM=sudo -q | grep "COMMAND" | wc -l)

wall "	#Architecture: $(uname -a)
	#CPU physical: $CPU_PHYSICAL
	#vCPU: $VCPU
	#Memory Usage: $MEM_USED/${MEM_TOTAL}MB ($MEM_USED_PERCENT%)
	#Disk Usage: $DISK_USED/$DISK_CAPACITY ($DISK_USAGE)
	#CPU load: $CPU_LOAD%
	#Last boot: $LAST_BOOT
	#LVM active: $LVM_ACTIVE
	#Active TCP connections: $TCP_CONNECTIONS ESTABLISHED
	#User log: $SERVER_USERS
	#Network: $IP_ADDRESS ($MAC_ADDRESS)
	#Sudo: $SUDO cmd"