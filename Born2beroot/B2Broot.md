# B2broot - Notes


## Requirements
- Debian => latest stable (no testing/unstable)
	- SELinux => should stay active and be configured in a way adapted to the subject
	- **AppArmor** should stay also active


## Working notes
### 12/12/23
	- Conseils **pberset**
Entraine toi maison sur virtual box, tu le fais plusieurs fois

Prevoir partitions pour bonus si jamais

Bonus: pas faire partition trop grosse (30gb de l’exemple ca va pas)

wordpress: pas faire (“j’ai fait .exe… “?)

	- **Damian**
Pas eu moyen d'installer Linux avec VirtualBox sur M1
=> downloaded UTM
- To read: https://docs.getutm.app/    –    https://www.virtualbox.org/wiki/Virtualization

### 13/13/23
Geneve/SDL:
	- read and took some notes about SELinux, AppArmor, partitioning, filesystems, mount points, ...
	- downloaded Debian ?image? and started it on UTM on my M1

### 14/12/23
- Read through VirtualBox's manual, created a VM but failed to make it run so far ("No bootable medium found! System halted.")
To do: 
	- **partitions**: 3 partitions, 1st mounted to /boot, 2nd very small size (1K) wh3rd encrypted and subdivided in 7 LVM groups (root, swap, home, var, srv, tmp, var--log), each mounted to the corresponding directory
	- Change Image write mode from normal to other option? (https://www.virtualbox.org/manual/ch05.html#hdimagewrites)
	- Read about hard disks in [VBox's manual](https://www.virtualbox.org/manual/ch05.html)
	- read [about LVM](https://www.redhat.com/sysadmin/lvm-vs-partitioning) if necessary

### 15/12/23
(Using [Pasquale Rossi's guide](https://github.com/pasqualerossi/Born2BeRoot-Guide) and [42 gitbook](https://42-cursus.gitbook.io/guide/rank-01/born2beroot/install-your-virtual-machine))
VM setup notes:
- Machine: c2r7s2
- Folder: /Users/fallan/goinfre/fallanVMs/fallan-B2BRoot
- Image: *debian-12.4.0-amd64-netinst.iso* from cdimage.debian.org/debian-cd/current/amd64/iso-cd/
- RAM: 1024 MB
- Storage: 8.00 GB, dynamic, [[Programming-notes#^1f390e|VDI]] (n.b.: partitioning crashed with 1.00GB and 1.90GB)
- Language: English
- Country: Switzerland
- Locale settings country base: United States - en_US.UTF-8
- Keymap: American English (due to my QWERTY layout)
- Hostname: fallan42
- Domain name: \<blank\>
- Root password: Debianunlock-1993
- Additional user full name: Francis
- Additional user username: fallan
- User password: Safepassword42
- Hostname password: Debianunlock-1993
- Partitioning:
	- Guided - use entire disk and set up encrypted LVM
	- Disk to partition: SCSI2 (0,0,0) (sda)
	- partitioning scheme: separate /home partition
	- Encryption passphrase: Debianunlock-1993
	- Amount of volume group to use for partitioning: "max"
	- Partition disks: left unchanged and "Finish partitioning and write changes to disk"
- Scan installation media "yes", then "no"
- Debian archive mirror: country: Switzerland, URL: mirror1.infomaniak.com/debian/
- Popularity contest: no
- Software to install: standard system utilities, SSH server **+ web server** (no GUI)
- Install [[Programming-notes#^428b1b|GNU GRUB boot loader]]: yes 

N.b.: when turning off the VM, choose "Save the machine state to prevent losing all info". Even the case with clones from snapshots !

### 18/12/23
- (still following [prossi's guide](https://github.com/pasqualerossi/Born2BeRoot-Guide) )
- Configured sudo starting by logging in as root use `su -`
- Updated package info of installed packages using `apt-get update -y` followed by upgrading with `apt-get upgrade -y`
- (played around a bit, explored)
- Installed lvm2 using `sudo apt install lvm2`
- Resizing my logical volumes to make space for new ones:
	- `lvresize -A y -L-250M -v fallan42--vg-home
	- (verbose)
	- (tried various stuff but resizing a volume I'm using at the moment requires unmounting etc so decide to redo it at installation)
- Partitioning:
	- Manual
	- Three primary partitions: 1st with 500MB is mounted to /boot, other two unmounted
	- Encrypt the third partition
	- Logical volumes:
		- create volume group named "fallan42-vg" using device /dev/sda3-crypt
		- create 7 logical volumes as demanded
		- ext4 for all LVMs, left reserved blocks at 5%, mount each volume to corresponding folder (except swap which is used as swap area instead of ext4 filesystem)
- Country: Switzerland
- Mirror archive: deb.debian.org
- scan additional media: no
- popularity contest: no
- Software to install: web, SSH, standard software utilities
- sudo:
	- su -
	- apt-get update -y
	- apt-get upgrade -y
	- apt install sudo
	- usermod -aG sudo fallan
	- sudo visudo (nb: in nano, so `ctrl+O to save and `ctrl+X` to exit)
	- (visudo is a utility to edit sudo safely, avoiding syntax errors and warning other users in the system that the sudoers file is being edited, if necessary)
```bash
# User privilege specification
fallan   ALL=(ALL)ALL
```
- git, vim ?
## Commands:
- `lsblk` to list storage volumes (partitions) ^9f40d4
- `apt list su* --installed` to show all installed packages starting with "su" ^b03539
- `usermod -aG sudo <username>` ^77cbc1
- `getent group sudo` : list users part of the sudo group ^7fc8e8

To do next:
- bootable flag: on ? (sda1 cf Père Meechan)
[Create logical volumes](https://www.redhat.com/sysadmin/creating-logical-volumes) for bonus


dpkg error code 1: a check or assertion command returned false

see var/log/dpkg.log
 var/lib/dpkf/available

## 19/12/23
- gotham machine: 
	- login fallan
	- password: password
	- root/encrypt: unlock

- relogging in Asgard, had issue "virtualbox Cannot register the DVD image because a CD/DVD image with UUID already exists" => solved by deleting the stuff between tags `<DVDImages></DVDImages>` in the .vbox file of each VM (same folder as .vdi file) (source: [Stackoverflow](https://stackoverflow.com/questions/36857343/virtualbox-import-error-cannot-register-the-dvd-image))

- suite de l'installation:
	- ssh:
		- already installed but my `sudo apt install openssh-server` at least set it as "manually installed"
		- `sudo nano /etc/ssh/sshd_config`: uncomment line "Port 22" and change to "Port 4242" (check with sudo grep Port /etc/ssh/sshd_config)
		- `sudo service ssh restart` 
		- `sudo apt install ufw`, `sudo ufw enable,  ufw allow ssh, ufw allow 4242, ufw status, ufw delete [X]
		- setup port forwarding in VirtualBox settings, then close and `sudo reboot`. Then iTerm, ssh fallan@127.0.0.1 (=> localhost)
		- hostname change: `sudo hostnamectl hostname <new_hostname>`, `hostname` to display current hostname, `hostnamectl` to display more details
## 21/12/23
- `sudo apt install libpam-pwquality`
- `groupadd --users fallan user42` to create user42 group with fallan in it. (note: `groups` doesn't list user42 whereas `groups fallan` does, weirdly)
- password policy (following prossi but also [server-world](https://www.server-world.info/en/note?os=Debian_12&p=pam&f=1)):
	- modified `/etc/login.defs` with sudo:
	```bash
	PASS_MAX_DAYS  30
	PASS_MIN_DAYS  2
	PASS_WARN_AGE  7
	```
	(n.b.: this setting only impact when creating a user)
	- used `chage --mindays 2 --maxdays 30 --warndays 7 fallan` and `chage --mindays 2 --maxdays 30 --warndays 7 root
	- PAM:
		- /etc/security/pwquality.conf
			- difok = 7, minlen = 10, dcredit = 1, ucredit = 1, lcredit = 1, maxrepeat = 3, usercheck = 1, enforce_for_root
	
**left to do** : change passwoords of all user accounts on the machine, incl. root

## 31/12/23
- Relogging into Debian emulator in UTM on my MacBook:
	- disk encryption password: debian
	- login: fallan
	- password: "password"


## 8/1/24
- Removed users "testusr", "testusr2" by editing `/etc/shadow`, `/etc/passwd` and `/etc/group`,
- Changed passwords of all accounts on the VM, root included:
	- (disk: still Debianunlock-1993)
	- root: Keychain-1993
	- fallan: password-2024 (nb: error message when shorter than 9 characters, and when trying to change right after, but no error for lack of uppercase character)
	- testusr: Password-2025
- `sudo visudo /etc/sudoers`:
	- Defaults    badpass_message="Wrong password, please retype"
	- Defaults    passwd_tries=3
	- Defaults    logfile="/var/log/sudo/sudo.log". ==> file to write logs to
	- Defaults    log_input, log_output ==> to log I/O for sudo
	- Defaults    requiretty.    ==> forces sudo to require we are in a logged in tty session. test with `ssh -T localhost 'sudo test'`=> should return `sudo: sorry, you must have a tty to run sudo`. See [article](https://www.baeldung.com/linux/sudo-requiretty-option)
	- usable paths: left as is (`/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/`)
	- 
- Script `monitoring.sh`
	- Commands:
		- `uname -r` : display OS architecture and kernel release
		- (arch : display CPU architecture)
		- (`uname`: display kernel name => Linux)
		- (`users`: display currently logged in users)
		- `lscpu | grep ^CPU\(s\): | awk '{print $2}'` (see [article](https://how.wtf/grep-for-contents-after-pattern-match.html) for explanation) : display physical processors
		- `nproc`: display vCPUs assigned to the VM:  This command prints the number of processing units available to the current process. In a virtualized environment, this command displays the number of vCPUs assigned to the VM (see [article](https://webhostinggeeks.com/howto/how-to-display-the-number-of-processors-vcpu-on-linux-vps/))
		- `free | grep Mem: | awk '{print $2}'` :  total memory
		- `free | grep Mem: | awk '{print $3}'` :  used memory
		- `df -h --total | grep ^total | awk '{print $2}'` : total storage
		- `df -h --total | grep ^total | awk '{print $3}'` : used storage
		- `top -i | grep ^%Cpu\(s\): | awk '{print $1}'` : CPU usage =>time out
		- `vmstat -y`
		- CPU usage: see https://askubuntu.com/questions/274349/getting-cpu-usage-realtime 
		- installed sysstat which installed mpstat. Now need to go to next line with awk (how?)

## 10/1/24
- fixing git issue from MacBook caused by large .iso file in previous commit causing issues with github sync. Solution: git rebase, delete file in problematic commits, then rebase all the way to HEAD, then merge with remote.
- MacBook: trying to advance with the emulator but need to set up a lot

## 11/1/24
- Script `monitoring.sh` (continued)
	- count TCP connections: `awk 'NR>1 {count++} END {print count}' /proc/net/tcp`
	- 

self-evaluation: 
- chage -l <username> to see password change policy
