int print_nl(int increment);
void shift_screen();
int get_fill_color(int color);

void print(const char *toPrint) {
  char* video_memory = (char*) 0xb8000;
  int lines = print_nl(0);
  lines = lines * 160;
  video_memory = video_memory + lines;
  int i = 0;
  while (*toPrint!=0) {
    if (lines + (i * 2)==(0xb8000 + 80*25*2)) {
      shift_screen();
      video_memory = video_memory - 160;
      i = i - 80;
    }
    ++i;
    *video_memory = *toPrint;//*t;
    ++video_memory;
    ++video_memory;
    ++toPrint;
  }
  i = floor(i/80);
  i++;
  print_nl(i);
  
}

void print_no_nl(const char *toPrint) {
  char* video_memory = (char*) 0xb8000;
  int lines = print_nl(0);
  lines = lines * 160;
  video_memory = video_memory + lines;
  int i = 0;
  while (*toPrint!=0) {
    if (lines + (i * 2)==(0xb8000 + 80*25*2)) {
      shift_screen();
      video_memory = video_memory - 160;
      i = i - 80;
    }
    ++i;
    *video_memory = *toPrint;//*t;
    ++video_memory;
    ++video_memory;
    ++toPrint;
  }
  i = floor(i/80);
  print_nl(i);
}

void print_color(const char *toPrint, char color) {
  char* video_memory = (char*) 0xb8000;
    int lines = print_nl(0);
    lines = lines * 160;
    video_memory = video_memory + lines;
    int i = 0;
    while (*toPrint!=0) {
      if (lines + (i * 2)==(80*25*2)) {
        shift_screen();
        video_memory = video_memory - 160;
        i = i - 80;
      }
      ++i;
      *video_memory = *toPrint;//*t;
      ++video_memory;
      *video_memory = color;
      ++video_memory;
      ++toPrint;
    }
    i = floor(i/80);
    i++;
    print_nl(i);
}
static void print_iter(char item,int replace_color) {
  char* video_memory = (char*) 0xb8000;
  if (replace_color==1) {
    video_memory++;
  }
  int i = 0;
  while (i<(80*25)) {
    *video_memory = item;
    ++video_memory;
    ++video_memory;
    ++i;
  }
}
void print_clear() {
  print_nl(-print_nl(0));
  print_iter(' ',0);
}
void print_fill_color(char color) {
  print_iter(color,1);
  get_fill_color(color);
}
void print_nuke() {
  print_fill_color(0x0e);
  print_clear();
}
void shift_screen() {
  char* video_memory = (char*) 0xb8000;
  memory_copy(160+video_memory,0 + video_memory,3840);
  video_memory = video_memory + 3840;
  int color = get_fill_color(-1);
  int i = 0;
  while (i<80) {
    *video_memory = ' ';
    ++video_memory;
    *video_memory = color;
    ++video_memory;
    ++i;
  }
}
int get_fill_color(int color) {
  static int myColor = 0x0e;
  if (color==-1) {
    return myColor;
  } else {
    myColor = color;
    return myColor;
  }
}
int print_nl(int increment) {
  static int line = 0;
  line = line + increment;
  while (line>24) {
    line = line - 1;
    shift_screen();
  }
  return line;
}