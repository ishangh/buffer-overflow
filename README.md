# buffer-overflow
A simulation of stack based buffer overflow vulnerability

## Environment Settings
- A 32-bit OS (Ubuntu 16.04) as shellcode is for 32-bit OS
- Setting up `zsh`.
    1. `sudo apt install zsh`
    2. `cd /bin`
    3. `sudo rm sh`
    4. `sudo ln -s /bin/zsh /bin/sh`
- `/bin/bash` has one additional check which prevents root access to the shell, can be fixed by adding more shellcode.

## Steps to see the working of overflow attack
- Steps as root user
    - `sudo sysctl -w kernel.randomize_va_space=0`
        - Disable ASLR
    - `sudo gcc -g vuln.c -o vuln -fno-stack-protector -z execstack`
        - Turn off stack protection and make it executable
    - `sudo chmod 4755 vuln`
        - Allow every user to execute the file
- Steps as non-root user
    - Update the address in eip in `exploit.py`
    - `gdb vuln`
        - Access gdb
    - `(gdb) break 9
        - Add a break just before return`
    - `(gdb) run $(python2 exploit.py)`
        - Run the exploit with unknown eip
    - `(gdb) x/40x $esp`
        - Get the return address to which it should point to
    - Update exploit.py
    - .`./vuln $(python2 exploit.py)`
        - running the `vuln` file to get the root access
    - Expected outcome is a root shell spawned by a non-root user.
    - `#` sign in shell and `whoami` returns `root` as username.
