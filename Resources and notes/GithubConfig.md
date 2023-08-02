Comment installer github dans le terminal

Il vous faut:
* Un compte Github
* Une machine 42
* Une machine personnelle
* Des cles SSH sur votre machine 42 et votre machine personnelle. Pour les generer, terminal > ssh-keygen

Marche a suivre pour chaque machine:
Sur Github.com
* Connectez-vous a votre compte
* Creez un repositoire 42 (il peut etre prive)
* Parametres > Cles SSH et GPG
* Ajoutez votre cle SSH (rappel: cd ~/.ssh, cat <votre_cle.pub>) pour l'authentification

Sur votre machine
* git clone <git@github.com:<nom_d'utilisateur_github>/<nom du repositoire>.git <nom_de_votre_dossier_cible> // n.b.: vous pouvez les retrouver a partir de l'URL classique de votre repo: github.com/<nom_d'utilisateur_github>/<nom du repositoire>
* submodules: si le dossier que vous copiez contient deja des repositoires git, risque d'erreur type error: 'c00/' does not have a commit checked out 
=> git rm <path-to-submodule> && git commit -- https://linuxpip.org/git-does-not-have-a-commit-checked-out/
+> =====> du coup probleme de workflow => solution: dossier rendus sur machine ?
https://git-scm.com/book/fr/v2/Utilitaires-Git-Sous-modules



N.b.: en ajoutant votre cle publique de 42 a votre Github, vous donnez le droit a quiconque a acces a votre login 42 d'acceder a votre compte Github, sauf mesures de securite supplementaires (passphrase sur votre SSH par exemple)

Voila, vous avez desormais un repositoire Github ou vous pouvez push vos fichiers depuis 42 pour continuer a la maison sans doublons, cles USB, google drive, etc.

P.S.: pour acceder au manuel de github depuis le terminal, man git-<nom de la commande git> ;)

See https://git-scm.com/book/fr/v2/Utilitaires-Git-Sous-modules



==============



**En resume**
* Telecharger github cli sur https://cli.github.com/ et ouvrir le fichier gh





* https://cli.github.com/ > "Download for Mac"  // (n.b.: oui les mac de 42 sont intel et le fichier amd64 mais ca marche)

* Extraire l'archive

* Dans le dossier cree, ouvrir /bin et trouver le fichier gh => c'est l'executable

* Mettre le fichier dans un dossier qui sera dedie aux binaires rajoutes sur la machine (on ne peut pas en rajouter a /usr/local/bin en raison des permissions) - personnellement j'ai cree un dossier Users/<mon nom d'utilisateur>/bin/

* Rajouter le dossier cree a la variable environnementale PATH qui permet de reconnaitre les commandes et les executer, en tapant la commande 'PATH=$PATH:/votre/nouveau/dossier'

* 'echo $PATH' permet de verifier que le nouveau dossier est bien inclus dans le PATH

* finalement, 'which gh' montre ou se trouve le binaire dans le PATH 

Vous pouvez desormais taper la commande 'gh' dans votre terminal et communiquer avec Githuben ligne de commande.


**Comment set up**

**En resume**:
* gh auth:
	- login github avec username et mot de passe
	- ajoute une cle publique SSH a github depuis ma machine
	- demande de creer un token d'identification
* git clone <URL SSH du repertoire>
	- (verifier l'empreinte de la cle de Github)



* gh auth
What account do you want to log into? GitHub.com
? What is your preferred protocol for Git operations? SSH
? Upload your SSH public key to your GitHub account? /Users/<nom_d'utilisateur>/.ssh/id_rsa.pub
? Title for your SSH key: <ma_cle_ssh_42>
? How would you like to authenticate GitHub CLI? Paste an authentication token
Tip: you can generate a Personal Access Token here https://github.com/settings/tokens
The minimum required scopes are 'repo', 'read:org', 'admin:public_key'.
* Le token specifie les acces a votre repositoire github. Attention donc a limiter dans le temps. Qui a acces a votre machine et vos cles SSH peut donc modifier tous vos repositoires Github. 

* git clone <URL SSH de votre repositoire> dossier_cible //retrouver l'URL SSH de votre repo. Si votre URL est https://github.com/Username/Repo, elle aura le format 'git@github.com:Username/Repo.git // alternative gh repo clone
Il vous sera propose de verifier l'authenticite des cles du serveur, vous pouvez le verifier ici: https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/githubs-ssh-key-fingerprints

Comment utiliser
* Vous voulez poursuivre chez vous un exercice commence sur une machine de 42 ? git push.

* Vous travaillez chez vous ? Git pull (pour recuperer votre travail), git push pour faire des changements

* Une fois a 42, git pull pour recuperer votre travail fait a la maison.

* En cas de conflits: ..

* Si vous voulez que des fichiers ne soient pas suivis par git et donc pas push depuis une machine vers une autre, creez un fichier .gitignore. Vous pouvez le placer n'importe ou dans le dossier racine de votre repositoire git, donc la ou se trouve votre fichier .git. Pour plus d'infos sur la config du gitignore: https://www.freecodecamp.org/news/gitignore-file-how-to-ignore-files-and-folders-in-git

* Pour les commandes du man gh
