# Practice problem 12.6 - Shared data in threads
# Bryant & O'Hallaron – Computer Systems 3rd ed.

Variable		Referenced by
instance	main thread ?	|	peer thread 0 ?	|	peer thread 1 ?
**********************************************************************
ptr				yes					yes					yes
count			no					yes					yes
i.m				yes					no					no
msgs.m			yes					no					no
myid.p0			no					yes					no
myid.p1			no					no					yes


Shared variables: ptr, count, msgs.m
Not shared: i.m, myid