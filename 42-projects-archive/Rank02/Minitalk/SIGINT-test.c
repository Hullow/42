#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void sig_handler(int signum, siginfo_t* info, void* context)
{
   (void)context;
   (void)info;
   (void)signum;
   printf("\nSignal handler function called %d\n", signum);
}

int main(void)
{
   struct sigaction sa;
  
   sigemptyset(&sa.sa_mask);
   sa.sa_flags = SA_RESTART | SA_SIGINFO;
   sa.sa_sigaction = sig_handler;
   sigaction(SIGINT, &sa, NULL);
   while (1)
     sleep(1);
   return (0);
}