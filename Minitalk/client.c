/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:04:21 by francis           #+#    #+#             */
/*   Updated: 2024/07/11 20:09:45 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"
#include <stdio.h>

// For testing and debugging purposes
void	binary_handler(int signum)
{	
	if (signum == SIGUSR1) // if bit is 0
	{
// printf("\nhandler: SIGUSR1, byte is %d and // multiplicator is %d\n", byte, multiplicator);
		write(1, "0", 1);
	}
	else if (signum == SIGUSR2) // if bit is 1
	{
		write(1, "1", 1);
	}
}

// uses binary signal to reconstruct 7-bit numbers to integers,
// which are then used as ascii codes to be written to stdout
void	client_sigaction_handler(int signum, siginfo_t *info, void *context)
{
	static int	byte = 0;
	static int	bit = 8;

	(void)context;
	(void)info;
	if (signum == SIGUSR1)
	{
		bit--;
	}
	else if (signum == SIGUSR2)
	{
		byte += 1 << bit;
		bit--;
	}
	if (bit < 0 || byte == 6)
	{
		if (byte == 6)
			ft_printf("server sent acknowledgment\n");
		else
			ft_printf("server sent %d\n", byte);
		byte = 0;
		bit = 8;
	}
}

// takes in 2 command line arguments: server PID and character string
// each character is encoded in 7 bits and 
// sent to the server using ft_binary_signal
// for 6-bit characters (ASCII 32 to 64, thus < 64), a '0' is sent first 
int	main(int argc, char **argv)
{
	int	server_pid;
	int	i;

	printf("client PID: %d\n", getpid());
	server_pid = 0;
	i = -1;
	int j = 7;
	struct sigaction	sigact;
	if (argc == 3)
	{
		sigact.sa_sigaction = client_sigaction_handler;
		sigaction(SIGUSR1, &sigact, NULL);
		sigaction(SIGUSR2, &sigact, NULL);
		server_pid = ft_atoi(argv[1]);
		while (argv[2][++i])
		{
			// 00101
			// / 2 ** 3
			// 1 << 0-7
			// 00000000
			// while (ascii_value > 1)
			// {
			// 	if ((unsigned int) argv[2][i] < ascii_value)
			// 		ft_send_signal_one(server_pid);
			// 	ascii_value /= 2;
			// }
			// ascii_value = 128;
			ft_send_binary_signal(server_pid, (unsigned int) argv[2][i], 8);
			while (j > 0)
			{
				j--;
				pause();
			}
			j = 7;
		}
	}
	else
		ft_printf("please input args\n");
	return (0);
}

/* 
100-character long ASCII Test strings:

s9DACTNXq;}j*.MhbrenRQ/^bi9;1%{>rJ9~o>JFMx}
N5z]JY:(BW>xHd4Pz*(mus1U_qB3B=/kMcg>$R>(~*(R)e4&o35J&<b)

;lTF_SIf:,^4TRu@Dy%A$Nme*QTk3-@)jN5_9Gkq+}fx]T
=WB5st[2PR=kZ^*&ndc;-M*I(NCX=O3MlFFqD@cy4M5Q5/.nfRex+7

l.FT&1s~_:q@2^-2<*i)CCk;a%3>~_3mSr1Qu*qm}NLrm,
Wn#&S@dmZ~#U=bHWwdiGDxYCm$&|=7w#^q2+i0bfxmS.m}0C:Ep=k,

3u/Ys0rAL:d49{wFXi<]E0/M;q$XHV/Eba9YfFk*:]DRdmvW);)3/~Q&.zVL%{7hdsdY[?YHJu[Q]$bqQI{a(mhr5Q-MXSHo(_pJ

-weFi/N:vIe|2,PDcXw5PmLH<iSM9_@_<2/+:,]|<k/865
A+D,^=KO4E2?HV^N+_D,w9L)~Fs*{sf+qb|6RcHMA%n{3x(e@Zh*G[

2Kz0fJ<5/vUdCNx9dveu}S{E_L3a2HP6y*RV2--M~cJx$F
1hD?*TbL73UiT?ZF+0p7^7Pivp<{K6J?x?t|LC4HX,z*=ZQaZ?w=ae

9-MNt0^Ul~Q]citr)>4;j:G%64?~3#0_nd7vQ7r2Y&n=lS
S;dx$45Qd(gMekRB+VuEcqB#kdAu}Y9~T;DdaKO>~:I5(A$ZQq?;%8

l*?_?_/4[(@5puEhG_YoN9WHCQ|eV0Z<kb~?_(>+OTx[HL
[JWmTEK3aWUBa=?4#qpVnkO5[L:p;zpNbkerR$A{FbP2LDk;nsAPFI

[A]J)<3/^(|u#%caY2md3nps?M@=W&H4w]gX[_zgTfUuDx
d_*BWm)#m4v@8eO/]i8zolk]*o=~1Eg)4_9_/U&/|b)b_3sdn8FwN%

7Ms^G-%vaT3a^Plu9Y+rG2H_QX?Qdtv[T|XpT7I@JU++Bu
8g7cpCZ^2f=G,Bu&[z5Z)Ax}_C#kr@eP7qG,DuHBI##-_w.F:7kE<F
*/