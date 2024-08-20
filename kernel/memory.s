    .section .bss
    .lcomm e820_entries, 128 * 20  # Alocar espaço para 128 entradas, 20 bytes cada (tamanho da struct e820_entry)

    .section .data
    .globl e820_entries_count
e820_entries_count:
    .int 0  # Inicializa o contador de entradas com 0

    .section .text
    .globl detect_memory
    .extern e820_entries_count

detect_memory:
    pusha                     # Salva todos os registradores
    xor %ebx, %ebx            # Inicializa o cont_id (ebx) com 0

.next_entry:
    mov $0xE820, %eax         # Código da função
    mov $0x534D4150, %edx     # 'SMAP'
    mov $20, %ecx             # Tamanho da estrutura e820_entry
    lea e820_entries(,%ebx,8), %edi # Aponta para a próxima entrada

    int $0x15                 # Chama a interrupção 0x15, função E820h

    jc .done                  # Sai se houve carry (erro)
    cmp $0x534D4150, %eax     # Verifica se o valor de retorno é 'SMAP'
    jne .done                 # Sai se não for
    test %ebx, %ebx           # Verifica se ebx é zero
    jz .done                  # Sai se for

    inc e820_entries_count    # Incrementa o contador de entradas
    cmp $128, e820_entries_count # Verifica se atingiu o limite máximo de entradas
    jge .done                 # Sai se atingiu

    jmp .next_entry           # Continua com a próxima entrada

.done:
    popa                      # Restaura todos os registradores
    ret

