# 4260-p4

Philip Wright

This program creates a new process and then makes a new time for the next fork/exec. The processes is assigned a class (user or real time) and put into queue0(real time) or queue1(user). Once there is something in the queues it then detect that there is a non-empty queue and start pulling from the queues checking queue0 first and down the priority chain to queue 3. Once a process is pulled from the
queue it's sent a message to start. After getting that wake/up message user will decide to terminate, use full-time, or use
some time(preempted) and sends what it does back to OSS. If a process uses some time before being preempted then we loop and wait for OSS to increment the clock past the point of being blocked. A message is sent to OSS telling it that the process has finished the blocking time. OSS increments the clock based on the cost of the queues and also each iteration of the loop in OSS. Local process id's are reused on generation as soon as the previous process with that same id terminates.

To compile type: make
To execute: ./oss
The generated log file is outputlog.txt
