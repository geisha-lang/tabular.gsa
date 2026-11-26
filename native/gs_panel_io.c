#include <stdint.h>
#include <stdio.h>

int32_t gs_data_write_bytes(const char *path, const void *buf, int64_t len)
{
    if (path == NULL || (buf == NULL && len > 0) || len < 0) return -1;
    FILE *fp = fopen(path, "wb");
    if (fp == NULL) return -1;
    if (len > 0) {
        size_t written = fwrite(buf, 1, (size_t)len, fp);
        if ((int64_t)written != len) {
            fclose(fp);
            return -1;
        }
    }
    if (fclose(fp) != 0) return -1;
    return 0;
}
