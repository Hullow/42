# B2broot - Notes


## Requirements
- Debian => latest stable (no testing/unstable)
	- SELinux => should stay active and be configured in a way adapted to the subject
	- **AppArmor** should stay also active


## Working notes
- 12/12/23
	- Conseils **pberset**
Entraine toi maison sur virtual box, tu le fais plusieurs fois

Prevoir partitions pour bonus si jamais

Bonus: pas faire partition trop grosse (30gb de l’exemple ca va pas)

wordpress: pas faire (“j’ai fait .exe… “?)

	- **Damian**
Pas eu moyen d'installer Linux avec VirtualBox sur M1
=> downloaded UTM
- To read: https://docs.getutm.app/    –    https://www.virtualbox.org/wiki/Virtualization

- 13/13/23
Geneve/SDL:
	- read and took some notes about SELinux, AppArmor, partitioning, filesystems, mount points, ...
	- downloaded Debian ?image? and started it on UTM on my M1

- 14/12/23
- Read through VirtualBox's manual, created a VM but failed to make it run so far ("No bootable medium found! System halted.")
To do: 
	- **partitions**: 3 partitions, 1st mounted to /boot, 2nd very small size (1K) wh3rd encrypted and subdivided in 7 LVM groups (root, swap, home, var, srv, tmp, var--log), each mounted to the corresponding directory
	- Change Image write mode from normal to other option? (https://www.virtualbox.org/manual/ch05.html#hdimagewrites)
	- Read about hard disks in [VBox's manual](https://www.virtualbox.org/manual/ch05.html)
