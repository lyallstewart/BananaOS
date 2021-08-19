int line_count(int increment);
void print_clear();
void print_nl();

void print(const char *toPrint) {
  //const char* t = toPrint;

  char* video_memory = (char*) 0xb8000;
    int lines = line_count(0);
    lines = lines * 160;
    video_memory = video_memory + lines;
    int i = 0;
    while (*toPrint!=0) {
        ++i;
        *video_memory = *toPrint;//*t;
        ++video_memory;
        *video_memory = 0x4a;
        ++video_memory;
        ++toPrint;
    }
    i = floor(i/80);
    i++;
    line_count(i);
}

void print_error(char *toPrint) {

}
void print_nl() {
  line_count(1);
}

void print_clear() {

}

int line_count(int increment) {
  static int line = 0;
  line = line + increment;
  return line;
}