/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:04:21 by francis           #+#    #+#             */
/*   Updated: 2024/07/11 22:18:29 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"
#include <stdio.h>

// struct sigaction	sigact;
void	ft_send_signal_one(int server_pid);

 /* // For testing and debugging purposes
void	handler(int signum)
{	
	if (signum == SIGUSR1) // if bit is 0
	{
// printf("\nhandler: SIGUSR1, byte is %d and // multiplicator is %d\n", byte, multiplicator);
		write(1, "\nclient: SIGUSR1 received from server\n", 39);
	}
	else if (signum == SIGUSR2) // if bit is 1
	{
		write(1, "1", 1);
	}
} */

// recursive function converting decimal to binary, sending SIGUSR1 signal for
// each '0' bit and SIGUSR2 for each '1' bit
// usleep slows down execution to allow for each bit to be received by server 
void	ft_binary_signal(int server_pid, unsigned int number)
{
	if (number == 0)
	{
		if (kill(server_pid, SIGUSR1) == -1)
		{
			ft_printf("\nclient: kill error");
			exit(-1);
		}
		usleep (600);
	}
	else if (number == 1)
	{
		if (kill(server_pid, SIGUSR2) == -1)
		{
			ft_printf("\nclient: kill error");
			exit(-1);
		}
		usleep (600);
	}
	else
	{
		ft_binary_signal(server_pid, number / 2);
		ft_binary_signal(server_pid, number % 2);
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
	unsigned int ascii_value;
^
	server_pid = 0;
	i = -1;
	ascii_value = 128;
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		while (argv[2][++i])
		{
			while (ascii_value > 1)
			{
				if ((unsigned int) argv[2][i] < ascii_value)
					ft_send_signal_one(server_pid);
				ascii_value /= 2;
			}
			ascii_value = 128;
			ft_binary_signal(server_pid, (unsigned int) argv[2][i]);
		}
	}
	else
		ft_printf("please input args\n");
	return (0);
}

void	ft_send_signal_one(int server_pid)
{
	if (kill(server_pid, SIGUSR1) == -1)
	{
		ft_printf("\nclient: kill error");
		exit(-1);
	}
	usleep (600);
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