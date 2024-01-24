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
	- Commands (continued)
		- count TCP connections: `awk 'NR>1 {count++} END {print count}' /proc/net/tcp`
		- date of last reboot: `who -b | grep boot | awk '{print $3" "$4" "$5}'`
		- number of sudo commands executed: `sudo grep sudo /var/log/secure` or `sudo grep sudo /var/log/auth.log` ([StackExchange](https://unix.stackexchange.com/questions/167935/details-about-sudo-commands-executed-by-all-user)) or `sudo journalctl _COMM=sudo`
		- Calculations: see [article](https://www.linuxjournal.com/content/mastering-division-variables-bash)
		- LVM: from gitbook solution `lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -eq 0 ]; then echo no; else echo yes; fi)`
		- IP address of server:
		> RFC 1918 specified a private address space of IPs reserved for internal networks:
			10.0.0.0 – 10.255.255.255 (10.0.0.0/8)
			172.16.0.0 – 172.31.255.255 (172.16.0.0/12)
			192.168.0.0 – 192.168.255.255 (192.168.0.0/16)
			(see [types of IP addresses](https://nordvpn.com/blog/types-of-ip-addresses/))
		Using `ip - `ere we have lo and enp0s3
self-evaluation: 
- chage -l <username> to see password change policy

IP_ADDRESS=$(hostname -I)
MAC_ADDRESS=$(ip -4 link show | grep ether | awk '{print $2}')

## 17/1/24
- Script `monitoring.sh` (continued)
	- Sudo logins: corrected to `SUDO=$(journalctl _COMM=sudo -q | grep "COMMAND" | wc -l)`
	- `Crontab -e`: `*/10 * * * * ~/monitoring.sh >/dev/null 2>&1`
		`>/dev/null`: sends stdout to black hole instead of email
		`2>&1` : sends stderr (2) to same as stdout (1)

The full script:
```bash
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

wall "  #Architecture: $(uname -a)
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
```


- Wordpress server:
	- Installation:
	- `sudo apt update`
		- `sudo apt upgrade`
		- `sudo apt install wordpress mariadb-server lighttpd php`
		- `sudo apt-get remove apache2*` : because "If you are not going to use Apache v1.3/2.x at all, then it is better to remove it (make sure you have a backup of Apache data and config file):" (see [Cyberciti article](https://www.cyberciti.biz/tips/installing-and-configuring-lighttpd-webserver-howto.html))
	- Lighttpd:
		- Running the server:`systemctl start lighttpd` (/stop /restart)
		- [Configuration](https://redmine.lighttpd.net/projects/lighttpd/wiki/TutorialConfiguration):
			- 


- `vim /var/www/html/index.html`

## 18/1/23
- Preparing for examination by rereading subject, taking summary notes for the eval, testing system again (e.g. creating user, assigning groups, changing user and seeing if crontab works)
- Issue: can't log in to root, seems like I forgot the password: neither "Debianunlock-1993", "Keychain-1993", nor "Debian", nor "" work...what to do what to do.
	- Ok, changed it from fallan, it was actually the same as fallan I suppose. Changed it back to "Keychain-1993"
- Checking if AppArmor is active: `sudo /usr/sbin/aa-status`
- Server: 
	- /var/www : mkdir servers
	- Lighttpd: looked at the docs' [quickstart](https://redmine.lighttpd.net/projects/lighttpd/wiki/TutorialConfiguration) and managed to load the index.html at /var/www/server/index.html using the lynx browser with `lynx http://127.0.0.1:3000/index.html`

## 19/1/23
- Server continued:
- Lighttpd [Config options](https://redmine.lighttpd.net/projects/lighttpd/wiki/Docs_ConfigurationOptions) (for modules) => enabled (the already default installed) FastCGI [module](https://redmine.lighttpd.net/projects/lighttpd/wiki/Mod_fastcgi) for PHP support
- Tried a quick PHP setup by going through [an old Cyberciti blogpost](https://www.cyberciti.biz/tips/lighttpd-php-fastcgi-configuration.html), and a hello.php script as in [PHP's documentation](https://www.php.net/manual/en/tutorial.firstpage.php) but it doesn't work (error 503 Service unavailable, or error 500 Internal Server Error), despite multiple new sockets spawning at /tmp/ (only 0-3 funny enough)
	- `/etc/lighttpd/lighttpd.conf` : 
	```
	server.document-root = "/var/www/servers/"
	
	server.port = 3000
	
	# If running lighttpd earlier than lighttpd 1.4.71, uncomment (remove '#') to add the following:
	mimetype.assign = (
	  ".html" => "text/html",
	  ".txt" => "text/plain",
	  ".jpg" => "image/jpeg",
	  ".png" => "image/png"
	)
	```


## 22/1/23
- fallan user password expired, changed it to "newpass-2024" 
- Continuing server setup, setting up PHP on Lighttpd with FastCGI module:
	- following the [old (2006) Cyberciti blogpost](https://www.cyberciti.biz/tips/lighttpd-php-fastcgi-configuration.html), decide to install php-cgi. 'apt show php-cgi' => "Note that MOST users probably want the php-fpm package that provide FastCGI support.". Thus, **install php-fpm**, a PHP dependency package which "provides the Fast Process Manager interpreter that runs as a daemon and receives Fast/CGI requests."
	- N.b.:
> The following packages were automatically installed and are no longer required:
 libapr1 libaprutil1 libaprutil1-dbd-sqlite3 libaprutil1-ldap libevent-core-2.1-7 liblua5.3-0
  linux-image-6.1.0-15-amd64 ssl-cert
Use 'sudo apt autoremove' to remove them."
	- sudo apt autoremove: 
> Removed linux-image-6.1.0-15-amd64 (6.1.66-1) ...
/etc/kernel/postrm.d/initramfs-tools:
update-initramfs: Deleting /boot/initrd.img-6.1.0-15-amd64
(...)
Warning: os-prober will not be executed to detect other bootable partitions.
Systems on them will not be added to the GRUB boot configuration.
Check GRUB_DISABLE_OS_PROBER documentation entry.
(...)
Removing ssl-cert (1.1.2) ...
- test `lynx http://127.0.0.1:3000/hello.php` again, still HTTP error ("HTTP/1.0 503 Service Unavailable")
- found [official PHP lighttpd setup guide](https://www.php.net/manual/en/install.unix.lighttpd-14.php), recommends php-cgi so `sudo apt remove php-fpm` and `sudo apt install php-cgi`:
	- in lighttpd.conf:
	```
	server.modules += ( "mod_fastcgi" )
	
	fastcgi.server = ( ".php" =>
	  ((
		"bin-path" => "/usr/local/bin/php-cgi",
		"socket" => "/tmp/php.socket"
		))
	)
	```
	- [lighttpd community tutorial: PHP + lighttpd setup](https://redmine.lighttpd.net/projects/lighttpd/wiki/TutorialLighttpdAndPHP#Configuration):
		- in `/etc/php/8.2/cgi/php.ini`: 
		> `cgi.fix_pathinfo = 1`
		- `sudo lighttpd -tt -f /etc/lighttpd/lighttpd.conf` to check config
		- `sudo lighttpd -D -f /etc/lighttpd/lighttpd.conf` to start server for testing:
		error "(gw_backend.c.537) bind failed for: tcp:127.0.0.1:80: Permission denied"
		- From [Atlassian help](https://confluence.atlassian.com/confkb/permission-denied-error-when-binding-a-port-290750651.html):
		>Ports below 1024 are called **Privileged Ports** and in Linux (and most UNIX flavors and UNIX-like systems), they are not allowed to be opened by any non-root user. This is a security feature originally implemented as a way to prevent a malicious user from setting up a malicious service on a well-known service port."

		=> back to previous snapshot (so beginning of the present day).
		- Install php8.2-cgi (for a change):
		> dpkg: error processing archive /var/cache/apt/archives/php8.2-cgi_8.2.7-1~deb12u1_amd64.deb (--unpack):
		 cannot copy extracted data for './usr/bin/php-cgi8.2' to '/usr/bin/php-cgi8.2.dpkg-new': failed to write (No space left on device)
		Errors were encountered while processing:
		 /var/cache/apt/archives/php8.2-cgi_8.2.7-1~deb12u1_amd64.deb
		E: Sub-process /usr/bin/dpkg returned an error code (1)
		- `sudo apt autoremove` (removed same as above) + `sudo apt install php8.2-cgi`
		- Config in short:
			```
			# Activated modules
			server.modules += ( "mod_fastcgi" )
			
			fastcgi.server = ( ".php" =>
				((
			"bin-path" => "/usr/bin/php-cgi",
			"socket" => "/tmp/php.socket"
				)) 
			)
			  fastcgi.debug = 1
			```
			- in /etc/php/8.2/cgi/php.ini file, set `cgi.fix_pathinfo=1`.
			- 500 internal server error
			- ChatGPT: check log `tail /var/log/lighttpd/error.log` => "2024-01-22 15:29:44: (mod_fastcgi.c.449) FastCGI-stderr:PHP Parse error: syntax error, unexpected string content "\<p>Hello World\</p>; ?> -->" in /var/www/servers/hello.php on line 8" => replace line 8 with `<?php echo '<p>Hello World</p>'; ?>`
			- `lynx http://127.0.0.1:3000/hello.php` works ! 
			- Asked ChatGPT for more interesting scripts than "Hello World". (see ["Sysadmin" chat](https://chat.openai.com/share/25291e7b-99ac-452a-bb4e-51df624d7dd8))

## 23/1/23
- Continuing PHP script with ChatGPT assistance:
	- to create visit counting file: `su`, `echo "0" > /var/www/servers/visit-counter.txt`, `chown www-data:www-data visit-counter.txt`, `chmod 664 visit-counter.txt` => it works, counting visits each time.
	- Full script (/var/www/servers/hello.php)
```PHP
<!DOCTYPE html>
<html>
	<head>
		<title>PHP Test</title>
	</head>
	<body>
	Ceci est la page hello.php, et ce qui suit est un script PHP:
<?php
# Salutations dynamiques en fonction de l'heure du jour
date_default_timezone_set('Europe/Zurich');
$hour = date("H:i");

if ($hour < 12) {
	echo '<p>Bonjour ! Il est ' . $hour .' heure. Bonne matinee !</p>';
} elseif ($hour < 18) {
	echo '<p>Bonjour. Il est ' . $hour . ' heure. Bonne apres-midi!</p>';
} else {
	echo '<p>Bonsoir ! Il est ' . $hour . ' heure. Bonne soiree!</p>';
}

# Compliment a l'evaluateur choisi d'une liste au hasard
$compliments = ["Quel honneur t'avoir comme evaluateur/trice!", "Tres cool que tu m'evalues (j'espere que l'evaluation sera clemente !)", "Merci pour l'evaluation", "Ton evaluation c'est du 5/5 jusqu'ici" ];
$randomIndex = array_rand($compliments);
echo '<p>' . $compliments[$randomIndex] . '</p>';

# Informations sur le serveur et le visiteur
echo '<p>Logiciel server: ' . $_SERVER['SERVER_SOFTWARE'] . '</p>';
echo '<p>Addresse IP du visiteur: ' . $_SERVER['REMOTE_ADDR'] . '</p>';

# Compteur de visites
$file = 'visit-counter.txt';

// Lire le nombre de visites dans le fichier
$hits = file_exists($file) ? file_get_contents($file) : 0;

// Incrementer les visites
$hits++;

// Enregistrer le nouveau numero dans le fichier
file_put_contents($file, $hits);

// Afficher le nombre de visites
echo "<p>Cette page a ete visionnee $hits fois.</p>";

// Reporting d'erreurs dans le script
error_reporting(E_ALL);
ini_set("display_errors", 1);
?>
	</body>
</html>
```
- Wordpress + MariaDB setup:
	- MariaDB: `sudo mysql_secure_installation` (a binary included in mariadb-server package, that sets up mariadb security, e.g. reserving access to root, removing freely accessible test server, etc.)
	 > 	Note from ChatGPT: "MariaDB is designed to be a binary drop-in replacement for MySQL, which means it maintains high compatibility with MySQL, including client tools, command-line utilities, and scripts like `mysql_secure_installation`. This compatibility allows users to switch from MySQL to MariaDB without having to learn new commands or change their operational scripts."
	- Installing more PHP modules: `php -m` to check installed modules; no need though, you can just run `sudo apt-get install php-mysql php-gd php-xml php-mbstring`
- Configuring MariaDB: 
	- log in: `sudo mysql -u root -p`
	- create a new db: `CREATE DATABASE wordpress;`
	- create a new user: CREATE USER 'wordpressuser'@'localhost' IDENTIFIED BY 'webadmin-1991';
	- Grant privileges: `GRANT ALL PRIVILEGES ON wordpress.* TO 'wordpressuser'@'localhost';`
	- Flush privileges: `FLUSH PRIVILEGES; EXIT;` (n.b.: an important command that is **used to refresh the user privileges**)
- Configuring Wordpress ([following B2BRoot bonus guide](https://github.com/mcombeau/Born2beroot/blob/main/guide/bonus_debian.md))
	- create link from server's document root to WordPress directory: `sudo ln -s /usr/share/wordpress /var/www/servers/wordpress`
	- edit configuration file /usr/share/wordpress/wp-config.php ([WordPress manual](https://developer.wordpress.org/advanced-administration/wordpress/wp-config/)) => access README with `sudo gzip -d /usr/share/doc/wordpress/README.Debian.gz`
	- in `/usr/share/wordpress/wpconfig.php` (`sudo vim`) :
> 
	/** The name of the database for WordPress */
	define( 'DB_NAME', 'wordpress' );
	
	/** Database username */
	define( 'DB_USER', 'wordpressuser' );
	
	/** Database password */
	define( 'DB_PASSWORD', 'webadmin-1991' );
	
	/** Database host */
	 define( 'DB_HOST', 'localhost' ); 

- 


## 24/1/23
- Trying to load Wordpress, checking MariaDB config, etc.
- `sudo chown -R www-data:www-data /usr/share/wordpress
`
- `sudo chmod -R 755 /usr/share/wordpress`


- create testusr3 with password "simplepassword" to test logging in to MariaDB => didn't work in any way !


- Managed to finally set up Wordpress:
	- chown www-data:www-data and /usr/share/wordpress and /var/www/servers/wordpress to own the link to it, chmod 777 to allow read (and write and execute...=> test only read !)
	- Changed lighttpd.conf:
	  ```
		url.rewrite-if-not-file = (
	    "^/wordpress/wp-admin$" => "/wordpress/wp-admin/",
	    "^/wordpress/(wp-(content|admin|includes).*)" => "/wordpress/$1",
	    "^/wordpress/(.*\.php)$" => "/wordpress/$1",
	    "^/wordpress/.*$" => "/wordpress/index.php"
	)
		server.modules += ( "mod_rewrite" )
	  ```
	of note:
		- server.document-root set to "/var/www/servers" rather than /wordpress.
		- url rewrite rules for Wordpress (from ChatGPT) + enable rewrite module
	- create an additional and specific **config-127.0.0.1.php file for Wordpress in /etc/wordpress** to fix error "Location URL is not absolute" when browsing `lynx http://127.0.0.1:3000/wordpress`, followed by error: "Neither /etc/wordpress/config-127.0.0.1.php nor /etc/wordpress/config-0.0.1.php could be found. Ensure one of them exists, is readable by the webserver and contains the right password/username." According to ChatGPT, Debian needs such a config file to load : "looking for its configuration file based on the hostname is behavior is specific to the way WordPress is packaged and configured in Debian-based systems." This file, (made readable to www-data) contains:
		```
			<?php
			define('DB_NAME', 'wordpress');
			define('DB_USER', 'wordpressuser');
			define('DB_PASSWORD', 'webadmin-1991');
			define('DB_HOST', 'localhost');
			define('DB_CHARSET', 'utf8');
			define('DB_COLLATE', '');
			
			# define('AUTH_KEY',         'put your unique phrase here');
			# define('SECURE_AUTH_KEY',  'put your unique phrase here');
			# define('LOGGED_IN_KEY',    'put your unique phrase here');
			# define('NONCE_KEY',        'put your unique phrase here');
			# define('AUTH_SALT',        'put your unique phrase here');
			# define('SECURE_AUTH_SALT', 'put your unique phrase here');
			# define('LOGGED_IN_SALT',   'put your unique phrase here');
			# define('NONCE_SALT',       'put your unique phrase here');
			
			$table_prefix = 'wp_';
			?>
		```

		- DDDD


- Wordpress setup:
	- Site title: Born2BeWebmaster
	- Username: fallan
	- Password: PwAPyoWYxQeK => change it!!
	- Email: fallan@student.42lausanne.ch
- Log in: message "wp-admin.php" => 403 Forbidden. Website now loads with `lynx http://127.0.0.1:3000/wordpress` but cannot log in as admin. `lynx http://127.0.0.1:3000/wordpress/wp-admin` gives a 403 Forbidden error


- Additional service to add: [Let's Encrypt](https://www.howtoforge.com/how-to-install-lighttpd-with-php-and-mariadb-on-debian-10/#secure-lighttpd-with-lets-encrypt-free-ssl) ?