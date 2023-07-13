/* this is a test application
 * to demonstrate how Landing Zone
 * can prove whether a given user
 * action can lead to known-vulnerable
 * functions in a software application.
 */
#include <stdio.h>
#include <stdlib.h>

int mock2(void);

int mock3(void);

// https://nvd.nist.gov/vuln/detail/CVE-2023-0466
int mock_CVE_2023_0466(void) {
    puts("mock_CVE_2023_0466");
    return 0;
}

// https://nvd.nist.gov/vuln/detail/CVE-2023-0215
int mock_CVE_2023_0215(void) {
    puts("mock_CVE_2023_0215");
    return 0;
}

// https://nvd.nist.gov/vuln/detail/CVE-2022-4450
int mock_CVE_2022_4450(void) {
    puts("mock_CVE_2022_4450");
    return 0;
}

int mock1(int i) {
    if (i == 1) {
        mock_CVE_2023_0466();
    } else if (i == 2) {
        mock2();
    } else if (i == 3) {
        mock3();
    } else {
        return 0;
    }

    return 0;
}

int mock2(void) {
    mock_CVE_2023_0215();
    return 0;
}

int mock3(void) {
    mock_CVE_2022_4450();
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("usage:\n%s <choice 1-3>\n", argv[0]);
        printf("example:\n%s 1\n", argv[0]);
        return 0;
    }
    int arg = atoi(argv[1]);
    mock1(arg);

    return 0;
}