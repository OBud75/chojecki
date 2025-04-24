section .data
  input_msg db "ecrire", 0xA    
  input_msg_len equ $ - input_msg 
  msg db "cest ecrit "
  msg_len equ $ - msg 

section .bss
    buffer resb 128          

section .text
    global _start

_start:

  mov rax, 1              
  mov rdi, 1              
  lea rsi, [input_msg]
  mov rdx, input_msg_len
  syscall

 
  mov rax, 0              
  mov rdi, 0              
  lea rsi, [buffer]       
  mov rdx, 128            
  syscall                 

 
  mov rax, 1              
  mov rdi, 1              
  lea rsi, [msg]
  mov rdx, msg_len
  syscall


  mov rax, 1              
  mov rdi, 1              
  lea rsi, [buffer]       
  mov rdx, 128
  syscall                 


  mov rax, 60             
  mov rdi, 0            
  syscall                 

; Vous pouvez séparer les différentes paties en petites fonctions