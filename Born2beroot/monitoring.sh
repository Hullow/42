CPU_PHYSICAL=$(lscpu | awk '$1=="CPU(s):" {print $2}')

DISK_USED=$(df -BM --total | grep total | awk '{sub(/M$/, "", $3); print $3}')
DISK_CAPACITY=$(df -h --total| awk '$1=="total" {print $2}')
DISK_USAGE=$(df -hP --total| grep total | awk '{print $5}')

MEM_TOTAL=$(free --mega| grep Mem: | awk '{print $2}')
MEM_USED=$(free --mega| grep Mem: | awk '{print $3}')
MEM_USED_PERCENT=$(echo "scale=2; ($MEM_USED/$MEM_TOTAL)*100" | bc)

TCP_CONNECTIONS=$(awk 'NR>1 {count++} END {print count}' /proc/net/tcp)

echo "Broadcast message from $(whoami)@$(hostname) ($(date)):"
echo "\t#Architecture: $(uname -a)"
echo "\t#CPU physical: $CPU_PHYSICAL"
echo "\t#vCPU: $(nproc)"
echo "\t#Memory Usage: $MEM_USED/$MEM_TOTAL \bMB ($MEM_USED_PERCENT%)"
echo "\t#Disk Usage: $DISK_USED/$DISK_CAPACITY ($DISK_USAGE)"
echo "\t#Active TCP connections: $TCP_CONNECTIONS ESTABLISHED"