char *strsep(char **from, const char *delim) {
    char *s, *dp, *ret;

    if ((s = *from) == NULL)
        return NULL;

    ret = s;
    while (*s != '\0') {
        /* loop until the end of s, checking against each delimiting character,
         * if we find a delimiter set **s to '\0' and return our previous token
         * to the user. */
        dp = (char *)delim;
        while (*dp != '\0') {
            if (*s == *dp) {
                *s = '\0';
                *from = s + 1;
                return ret;
            }
            dp++;
        }
        s++;
    }
    /* end of string case */
    *from = NULL;
    return ret;
}