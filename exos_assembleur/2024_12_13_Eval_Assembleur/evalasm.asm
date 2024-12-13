;assembleur, ce programme demande le prenom avant de lafficher
section .data
  input_msg db "Quel est votre prénom ?", 0xA    
  input_msg_len equ $ - input_msg 
  msg db "Bonjour "
  msg_len equ $ - msg 

section .bss
    buffer resb 128          ; Resa 128 bits

section .text
    global _start

_start:
  ; input
  mov rax, 1; Syscall sys_write 
  mov rdi, 1              
  lea rsi, [input_msg]
  mov rdx, input_msg_len
  syscall

  ; read input t
  mov rax, 0 ; Syscall sys_read 
  mov rdi, 0              
  lea rsi, [buffer]       
  mov rdx, 128            
  syscall ; syscall

  ; write txt
  mov rax, 1; Syscall sys_write 
  mov rdi, 1              
  lea rsi, [msg]
  mov rdx, msg_len
  syscall

  ; read input 
  mov rax, 1; Syscall sys_write 
  mov rdi, 1              
  lea rsi, [buffer]       
  mov rdx, 128
  syscall ; syscall

  ; quit
  mov rax, 60 ; Syscall
  mov rdi, 0           	  
  syscall                 
