section .bss
e820_entries resb 128 * 20 ; Alocar espaço para 128 entradas, 20 bytes cada (tamanho da struct e820_entry)

section .data
e820_entries_count dd 0

section .text
global detect_memory
extern e820_entries_count

detect_memory:
    pusha                     ; Salva todos os registradores
    xor ebx, ebx              ; Inicializa o cont_id (ebx) com 0

.next_entry:
    mov eax, 0xE820           ; Código da função
    mov edx, 0x534D4150       ; 'SMAP'
    mov ecx, 20               ; Tamanho da estrutura e820_entry
    lea edi, [e820_entries + ebx * 20] ; Aponta para a próxima entrada

    int 0x15                  ; Chama a interrupção 0x15, função E820h

    jc .done                  ; Sai se houve carry (erro)
    cmp eax, 0x534D4150       ; Verifica se o valor de retorno é 'SMAP'
    jne .done                 ; Sai se não for
    test ebx, ebx             ; Verifica se ebx é zero
    jz .done                  ; Sai se for

    inc dword [e820_entries_count] ; Incrementa o contador de entradas
    cmp dword [e820_entries_count], 128 ; Verifica se atingiu o limite máximo de entradas
    jge .done                 ; Sai se atingiu

    jmp .next_entry           ; Continua com a próxima entrada

.done:
    popa                      ; Restaura todos os registradores
    ret

