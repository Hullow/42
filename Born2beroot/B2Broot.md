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
[Create logical volumes](https://www.redhat.com/sysadmin/creating-logical-volumes) for bonus


dpkg error code 1: a check or assertion command returned false

see var/log/dpkg.log
 var/lib/dpkf/available