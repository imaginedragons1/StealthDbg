# stealthdbg Debugger

stealthdbg Debugger is an open-source, hypervisor-assisted, user-mode and kernel-mode Windows debugger with a focus on using modern hardware technologies. It is a debugger designed for analyzing, fuzzing and reversing.

## Description

stealthdbg is designed with a focus on using modern hardware technologies to provide new features to the debuggers' world. It operates on top of Windows by virtualizing an already running system using Intel VT-x and Intel PT. This debugger aims not to use any APIs and software debugging mechanisms, but instead, it uses Second Layer Page Table (a.k.a. Extended Page Table or EPT) extensively to monitor both kernel and user executions.
stealthdbg comes with features like hidden hooks, which is as fast as old inline hooks, but also stealth. It mimics hardware debug registers for (read & write) to a specific location, but this time entirely invisible for both Windows kernel and the programs, and of course without any limitation in size or count!

Using TLB-splitting, and having features such as measuring code coverage and monitoring all mov(s) to/from memory by a function, makes stealthdbg a unique debugger.

Although it has novel features, stealthdbg tries to be as stealth as possible. It doesn’t use any debugging APIs to debug Windows or any application, so classic anti-debugging methods won’t detect it. Also, it resists the exploitation of time delta methods (e.g., RDTSC/RDTSCP) to detect the presence of hypervisors, therefore making it much harder for applications, packers, protectors, malware, anti-cheat engines, etc. to discover the debugger.

THE DESCRIPTION IS REMOVED FOR ANONYMITY.

## Unique Features
### First Release (v0.1.0.0)
* Advanced Hypervisor-based Kernel Mode Debugger 
* Classic EPT Hook (Hidden Breakpoint) 
* Inline EPT Hook (Inline Hook) 
* Monitor Memory For R/W (Emulating Hardware Debug Registers Without Limitation) 
* SYSCALL Hook (Disable EFER & Handle #UD)
* SYSRET Hook (Disable EFER & Handle #UD) 
* CPUID Hook & Monitor 
* RDMSR Hook & Monitor 
* WRMSR Hook & Monitor
* RDTSC/RDTSCP Hook & Monitor
* RDPMC Hook & Monitor 
* VMCALL Hook & Monitor 
* Debug Registers Hook & Monitor
* I/O Port (In Instruction) Hook & Monitor
* I/O Port (Out Instruction) Hook & Monitor 
* MMIO Monitor
* Exception (IDT < 32) Monitor
* External-Interrupt (IDT > 32) Monitor 
* Running Automated Scripts 
* Transparent-mode 
* Running Custom Assembly In Both VMX-root, VMX non-root (Kernel & User) 
* Checking For Custom Conditions 
* Process-specific & Thread-specific Debugging 
* VMX-root Compatible Message Tracing 
* Powerful Kernel Side Scripting Engine 
* Support To Symbols (Parsing PDB Files) 
* Mapping Data To Symbols & Create Structures, Enums From PDB Files 
* Event Forwarding (#DFIR) 
* Transparent Breakpoint Handler 
* Various Custom Scripts 

## Scripts
You can write your **[scripts](https://link-anonymized.com)** to automate your debugging journey. **StealthDbg** has a powerful, fast, and entirely kernel-side implemented [script engine](https://link-anonymized.com).
