#VARIABLES

ARCH=$(uname -r)
#CPU_PHYSICAL=$(lscpu | grep ^CPU\(s\): | awk '{print $2}')
#vCPU=$(nproc)
MEM_TOTAL=$(free | grep Mem: | awk '{print $2}')
MEM_USED=$(free | grep Mem: | awk '{print $3}')
#DISK_CAPACITY=$(df -h --total | grep ^total | awk '{print $2}')
#DISK_USAGE=$(df -h --total | grep ^total | awk '{print $3}')

DISK_CAPACITY=$(df | grep disk3 | awk '{print $2}')
DISK_USED=$(df | grep disk3 | awk '{print $3}')
#DISK_USED=$(du)
DISK_USAGE=$(expr $DISK_CAPACITY / $DISK_USED)

#CPU_LOAD=$()

TCP_CONNECTIONS=$(awk 'NR>1 {count++} END {print count}' /proc/net/tcp)

echo "Broadcast message from $(whoami) ($(date))":
echo "#Architecture: $ARCH"
echo "#CPU physical: $CPU_PHYSICAL"
echo "#vCPU: $vCPU"
echo "Disk capacity: $DISK_CAPACITY"
echo "Disk Used: $DISK_USED"
echo "Disk Usage: "
x=100
echo "scale=2; $DISK_USED/$DISK_CAPACITY%" | bc
# echo "#Memory Usage: $(MEM_USED)/$(MEM_TOTAL)"
# echo "#: $"
y=-3
result=$(expr $x / $y)

echo "Result: $result"