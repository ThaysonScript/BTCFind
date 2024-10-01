#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_valid_bitcoin_address(const char *address) {
    // Verifica se o endereço começa com '1', '3' ou 'bc1'
    if (strncmp(address, "1", 1) == 0 || strncmp(address, "3", 1) == 0) {
        // Verifica o comprimento do endereço
        int length = strlen(address);
        return length >= 26 && length <= 35; // Endereços legíveis
    } else if (strncmp(address, "bc1", 3) == 0) {
        // Endereço Bech32
        return strlen(address) >= 42; // Comprimento mínimo para endereços Bech32
    }
    return false;
}

int main() {
    const char *address1 = "1A1zP1eP5QGefi2DMPTfTL5SLmv7DivfNa"; // Exemplo de endereço
    const char *address2 = "bc1qw4t3h6x3f6v0m9e50y4p0c9p4u8e62ndz2k8gz"; // Exemplo de endereço Bech32

    printf("Endereço 1: %s - %s\n", address1, is_valid_bitcoin_address(address1) ? "Válido" : "Inválido");
    printf("Endereço 2: %s - %s\n", address2, is_valid_bitcoin_address(address2) ? "Válido" : "Inválido");

    return 0;
}
