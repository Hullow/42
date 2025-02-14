
## Credentials:
- Root password: Keychain-1993 (old: Debianunlock-1993)
- Additional user full name: Francis
- Additional user username: fallan
- Passwords:
	- (disk: still Debianunlock-1993)
	- fallan: password-2024 (nb: error message when shorter than 9 characters, and when trying to change right after, but no error for lack of uppercase character)
	- testusr: password-2025
- MariaDB: db name 'wordpress', user 'wordpressuser', password 'webadmin-1991'

## Questions/Answers
- Pourquoi Debian ?
	- plus simple, utilise partout
- LVM: a dynamic partition. Physical disks are united into Volume groups, which are then subdivided into logical volumes. LVM allows for dynamic partitioning, i.e. during system run, no need to reboot.
- apt vs aptitude: aptitude is a front-end to APT (Advanced Package Tool), the Debian (and Debian-based distros) native package manager tool. APT automates the retrieval, configuration and installation of software packages, from precompiled files or by compiling source code. APT is technically a frontend on dpkg
- Debian vs Rocky:
	- Debian: community Linux distribution, since 1993 (the 2nd oldest distro still active). Debian based include Ubuntu, Mint and Kali
	- Rocky developed by Rocky Software Foundation to continue CentOS (discontinued 2020). RHEL-based, focused on entreprise customers
- AppArmor vs SELinux: 
	- SELinux:
			- used in RHEL (Red Hat Entreprise Linux)
			- Built into Debian kernel but disabled. Can be installed
			- quite complex to use, leading many sysadmins to disable it, which causes security risks.
		- a Linux kernel module providing secure mechanisms for supporting access control security policies. For instance, SELinux can determine file mode modification policy in a way that is not changeable, and adds granularity to access control (who can unlink, append only, move a file, etc.), including for non-file resources like network and interprocess communications.
		- check if enabled: `sudo getenforce`
	- AppArmor:
			- Used in Ubuntu and Debian
			- Much easier to learn and use than SELinux, thus often considered the safer choice
			- Uses profiles to determine what files and permissions an application requires
			- Security policies based on paths
			- Provides [[Security-notes#^ccbb7a|Mandatory Access control]]

## Commands
- Checking if AppArmor is active: `sudo /usr/sbin/aa-status`
- `lsblk` to list storage volumes (partitions) ^9f40d4
- `apt list su* --installed` to show all installed packages starting with "su" ^b03539
- `chage -l <\username>` : see age information of user password
- SSH: `sudo vim /etc/ssh/sshd_config`: uncomment line "Port 22" and change to "Port 4242" (check with `sudo grep Port /etc/ssh/sshd_config`)
- Hostname: `hostname` to display current hostname, `sudo hostnamectl hostname <new_hostname>` to change name,  `hostnamectl` to display more details
- UFW: `sudo ufw enable,  ufw allow ssh, ufw allow 4242, ufw status, ufw delete [X] ddd`
- User permissions and groups: 
	- `groups fallan`: display group membership of user fallan
	- `groupadd --users fallan user42` to create user42 group with fallan in it
	- `getent group sudo` : list users part of the sudo group ^7fc8e8
	- `usermod -aG sudo <username>` ^77cbc1 (append Groups)
	- `sudo adduser/deluser` : add/delete user
- Password policy: 
	- What is PAM: a suite of libraries to configure methods to authenticate users, providing a flexible and centralized way to handle authentication methods for secured applications through configuration files rather than application code.
	- modified `/etc/login.defs` with sudo:
	```bash
	PASS_MAX_DAYS  30
	PASS_MIN_DAYS  2
	PASS_WARN_AGE  7
	```
	(n.b.: this setting only impact when creating a user)
	- used `chage --mindays 2 --maxdays 30 --warndays 7 fallan` and `chage --mindays 2 --maxdays 30 --warndays 7 root
	- PAM:
		- `/etc/security/pwquality.conf` (after installing with `sudo apt install libpam-pwquality`)
			- `difok = 7, minlen = 10, dcredit = 1, ucredit = 1, lcredit = 1, maxrepeat = 3, usercheck = 1, enforce_for_root`
- Configuration sudo:
	- `sudo visudo /etc/sudoers`:
	- Defaults    badpass_message="Wrong password, please retype"
	- Defaults    passwd_tries=3
	- Defaults    logfile="/var/log/sudo/sudo.log". ==> file to write logs to
	- Defaults    log_input, log_output ==> to log I/O for sudo
	- Defaults    requiretty.    ==> forces sudo to require we are in a logged in tty session. test with `ssh -T localhost 'sudo test'`=> should return `sudo: sorry, you must have a tty to run sudo`. See [article](https://www.baeldung.com/linux/sudo-requiretty-option)
	- usable paths: left as is (`/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/`)
- cf TTYs: "*While Linux systems can have multiple TTYs, their number is usually limited by the configuration. Actually, we can change this by modifying _/etc/init/tty*.conf_, _/etc/securetty_, _/etc/systemd/logind.conf, or similar configuration files depending on the Linux distribution._" (same [article](https://www.baeldung.com/linux/sudo-requiretty-option) as above)

## Bonus

### Webpages
Visit the Wordpress page: `lynx http://127.0.0.1:3000/wordpress`
Visit my PHP script `lynx https://127.0.0.1/hello.php`
Modify webpage `vim /var/www/servers/hello.php/hello.php`
### Wordpress
- configuration files: `/usr/share/wordpress/wpconfig.php` (&& `/etc/wordpress/config-127.0.0.1.php )
### MariaDB
- `sudo mysql -u root -p` : to start MariaDB interactive prompt
- `SHOW DATABASES;` shows databases
- `SELECT User, Host FROM mysql.user;` show users
- `USE <database_name>;` selects a database to work with
- `SHOW TABLES;` list all tables in the selected database
- `DESCRIBE <table_name>` : view the structure of a specific table
- `SHOW TABLE STATUS;` : get more detailed information about tables, including storage engine, row format, and table size
### Lighttpd server
Short:
- see server status: `sudo systemctl status lighttpd`
- edit server config file: `sudo vim /etc/lighttpd/lighttpd.conf`
- PHP FastCGI setup: see Lighttpd.conf file + /etc/php/8.2/cgi/php.ini `cgi.fix....=1;`
Detail:
Lighttpd ("Lighty") is a light FOSS server software. Lighter than Apache so more efficient.
- `sudo lighttpd -tt -f /etc/lighttpd/lighttpd.conf` to check the configuration
- `sudo lighttpd -D -f /etc/lighttpd/lighttpd.conf` start lighttpd directly in the foreground and not in the background as a daemon, without using systemd. To use when testing or debugging in the console, and systemctl for regular operation and production environments
- `sudo systemctl start/stop/restart/reload lighttpd` : running, stopping, restarting, reloading the server using systemd (init-V systems use the `service` command)
- `sudo systemctl enable lighttpd` 
- `sudo systemctl status lighttpd`
- `sudo lighttpd -D -f /etc/lighttpd/lighttpd.conf`: 
- data handled by the www-data user (and group) and in the `/var/www/servers` folder
- `sudo lighttpd-enable-mod` : to enable modules but not used afaik
### SSL/TLS self-signed certificate (HTTPS)
- configuration file: /etc/ssl/private/san.cnf
- private key: /etc/ssl/private/domain.key
- CSR: /etc/ssl/private/domain.csr
- SSL Certificate: /etc/ssl/certs/domain.crt
=> tout genere avec la commande `openssl`

Viewing the certificate: `openssl x509 -text -noout -in /etc/ssl/certs/domain.crt`

command explained: x509 to display X509 certificates, `-text`: print the certificate in text form, `-noout` outputs the details from the certificate, not the certificate itself (which is in binary form), `-in domain.crt` specifies the input certificate file.

- Pourquoi utiliser SSL/TLS ?
Using SSL/TLS on a local server, even when it's not exposed to the internet, can still provide several benefits related to security and best practices:

### 1. **Data Encryption:**

- **Protection of Sensitive Data:** SSL/TLS encrypts the data transmitted between the server and clients (like browsers). If you're handling any sensitive information, encryption protects this data from being intercepted or read by unauthorized users within the local network.

### 2. **Practice Security Best Practices:**

- **Developing Good Habits:** Implementing SSL/TLS on a local server is a good practice. It helps you and any other users develop a habit of implementing security measures by default, which is a critical mindset in cybersecurity.

### 3. **Testing and Development:**

- **Realistic Environment for Development:** If you’re developing websites or applications that will eventually be deployed to a production environment with SSL/TLS, using SSL/TLS in your development environment can help catch and resolve potential security issues early.
- **Compatibility Testing:** Modern web development often involves features that require HTTPS (like certain browser APIs). Testing on an HTTPS environment ensures compatibility.

### 4. **Internal Security:**

- **Mitigating Internal Threats:** Even within a local network, security threats can exist. Unauthorized access, packet sniffing, or insider threats can be mitigated by encrypting network traffic.
- **Compliance:** In some cases, compliance with data protection standards (like GDPR, HIPAA, etc.) requires encryption of data in transit, even on internal networks.

### 5. **Building a Secure Infrastructure:**

- **Foundation for Scaling:** If your local server might eventually be scaled up to a public-facing server, having SSL/TLS already set up makes the transition smoother and more secure.
- **Establishing Trust:** Using SSL/TLS can help in establishing trustworthiness of the server, even in a local setting, especially if different teams or departments are accessing it.