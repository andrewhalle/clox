debug_default := '-D DEBUG_TRACE_EXECUTION -D DEBUG_PRINT_CODE'

build debug=debug_default:
  clang -g {{debug}} -o main *.c

clean:
  rm main
