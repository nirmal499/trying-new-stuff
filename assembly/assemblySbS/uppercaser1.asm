section .bss
    ; Buff resb 1
    BUFFLEN equ 1024                    ; Length of the buffer
    Buff: resb BUFFLEN                  ; Text buffer itself. Basically it is [Buff resb 1024]
section .data

section .text
global _start

_start:

nop ; This no-op keeps the degbugger happy

; Put your experiments between the two nops...

; Read a buffer full of text from stdin:
Read:   mov eax,3                       ; Specify sys_read call
        mov ebx,0                       ; Specify FILE DESCRIPTOR 0 :stdin
        mov ecx,Buff                    ; Pass address of the buffer to read to OR Pass offset of the buffer to read to
        ; mov edx,1                       ; Tell sys_read ot read one char from stdin
        mov edx,BUFFLEN                 ; Pass number of bytes to read at one pass
        int 80h                         ; Call sys_read to fill the buffer

        mov esi,eax                     ; Copy sys_read return value for safekeeping
        cmp eax,0                       ; If eax=0, sys_read reached EOF on stdin
        je Done                         ; Jump If Equal (to 0, from compare)

        ; Set up the registers for the process buffer step:
        mov ecx,esi                     ; Place the number of bytes read into ecx
        mov ebp,Buff                    ; Place address of buffer into ebp
        dec ebp                         ; Adjust count to offset [Off by One Error]
   

        ; cmp eax,0                       ; Look at sys_read's return value in eax. Checks if eax value is 0
        ; je Exit                         ; je -> Jump if Zero . The CMP instruction compares its two operands and sets the flags accordingly.
                                        ; The conditional jump instruction that follows each CMP instruction
                                        ; takes action based on the state of the flags

                                        ; sys_read return's 0 , it means we have reached End Of File [file is stdin [file descriptor 0]]
                                        ; If it returns a positive value, this value is the number
                                        ; of characters it has read from the file


        ;Go through the buffer and convert lowercase to uppercase characters:
Scan:

        cmp byte [ebp+ecx], 61h            ; Test inputed char[1 btye] against lowecase 'a'
        jb Next                         ; jb -> Jump If Below .This instruction jumps if the preceding CMP’s left
                                        ; operand is lower in value than its right operand.
                                        ; If below 'a’ in ASCII chart, that means inputted char is not lowercase

        cmp byte [ebp+ecx], 7Ah            ; Test inputed char[1 btye] against lowecase 'z'
        ja Next                         ; ja -> Jump If Above .This instruction jumps if the preceding CMP’s left
                                        ; operand is higer in value than its right operand.
                                        ; If above 'z’ in ASCII chart, that means inputted char is not lowercase

        sub byte [ebp+ecx],20h             ; Subtract 20h from lowercase to give uppercase

Next:   dec ecx                         ; Decrement counter
        jnz Scan                        ; If characters remain, loop back. It means jump if eax not zero

                                        ; ...and then write out the buffer which is now full of processed text to stdout
      
        ; Write the buffer full of processed text to stdout:
Write:  mov eax,4                       ; Specify sys_write call
        mov ebx,1                       ; Specify file descriptor 1: stdout [This is the file where we want to write the converted uppercase]
        mov ecx,Buff                    ; Pass address of the character to write
        ; mov edx,1                       ; Pass number of chars to write
        mov edx,esi                     ; Pass the # of bytes of data in the buffer[number of chars[bytes] to write in file descriptor 1:stdout]
        int 80h                         ; Make sys_write kernel call
        jmp Read                        ; ...then Loop back and load another buffer full

        ; All done! Let’s end this party:
Done:   mov eax,1                       ; Code for exit syscall
        mov ebx,0                       ; Return a code of 0 to Linux[echo $?]
        int 80h                         ; Make a kernel call to exit program
        


; Put your experiments between the two nops...

nop