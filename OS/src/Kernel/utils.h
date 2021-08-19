long double floor(long double x)
{
    long double xcopy=x<0?x-1:x;
    unsigned int zeros=0;
    long double n=1;
    for(n=1;xcopy>n*10;n*=10,++zeros);
    for(xcopy-=n;zeros!=-1;xcopy-=n)
        if(xcopy<0)
        {
            xcopy+=n;
            n/=10;
            --zeros;
        }
    xcopy+=n;
    return x<0?(xcopy==0?x:x-(1-xcopy)):(x-xcopy);
}
void memory_copy(char *source, char *dest, int nbytes) {
    int i;
    for (i = 0; i < nbytes; i++) {
        *(dest + i) = *(source + i);
    }
}

/**
 * K&R implementation
 */
void int_to_ascii(int n, char str[]) {
    int i, sign;
    if ((sign = n) < 0) n = -n;
    i = 0;
    do {
        str[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) str[i++] = '-';
    str[i] = '\0';

    /* TODO: implement "reverse" */
}