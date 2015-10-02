#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

int main() {
    unsigned char digest[SHA512_DIGEST_LENGTH];
    const char* string = "hello world"; 

    SHA512_CTX ctx;
    SHA384_Init(&ctx);
    SHA384_Update(&ctx, string, strlen(string));
    SHA384_Final(digest, &ctx);

    char mdString[SHA384_DIGEST_LENGTH*2+1];
    for (int i = 0; i < SHA384_DIGEST_LENGTH; i++)
        sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);

    printf("SHA384 digest: %s\n", mdString);


    return 0;
}