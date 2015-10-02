#include <stdio.h>
#include <string.h>
#include <openssl/ripemd.h>

int main() {
    unsigned char digest[RIPEMD160_DIGEST_LENGTH];
    const char* string = "hello world";

    RIPEMD160_CTX ctx;
    RIPEMD160_Init(&ctx);
    RIPEMD160_Update(&ctx, string, strlen(string));
    RIPEMD160_Final(digest, &ctx);

    char mdString[RIPEMD160_DIGEST_LENGTH*2+1];
    for (int i = 0; i < RIPEMD160_DIGEST_LENGTH; i++)
        sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);

    printf("RIPEMD160 digest: %s\n", mdString);

    return 0;
}