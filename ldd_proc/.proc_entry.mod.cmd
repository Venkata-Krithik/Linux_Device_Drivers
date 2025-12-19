savedcmd_/home/ubuntu/ldd/ldd_proc/proc_entry.mod := printf '%s\n'   proc_entry.o | awk '!x[$$0]++ { print("/home/ubuntu/ldd/ldd_proc/"$$0) }' > /home/ubuntu/ldd/ldd_proc/proc_entry.mod
