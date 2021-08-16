void print(char *toPrint, int len) {
  char* video_memory = (char*) 0xb8000;
    int i;
    for (i = 0; i<len; ++i ) {
        
        *video_memory = *toPrint;
        ++video_memory;

        ++video_memory;
        ++toPrint;
    }
}

void print_nl() {

}

void print_clear() {

}

int line_count(int increment) {
  static int line = 0;
  line = line + increment;
  return line;
}