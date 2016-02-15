#include <cstdlib>
#include <cstdio>

using namespace std;

int main ()
{
    FILE* fp = std::fopen("test.txt", "r");
    if(!fp) {
        std::perror("File opening failed");
        return EXIT_FAILURE;
    }

    int c{};
    while ((c = std::fgetc(fp)) != EOF) { // standard C I/O file reading loop
        std::putchar(c);
    }

    if (std::ferror(fp))
    {
        std::puts("I/O error when reading");
        return EXIT_FAILURE;
    }
    else if (std::feof(fp))
    {
        std::puts("End of file reached successfully");
    }
    std::fclose(fp);
    return EXIT_SUCCESS;
}
