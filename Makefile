TARGET := fft

OBJECT := obj/main.o obj/io.o obj/cpx_op.o obj/fft_comp.o obj/fft_prep_bit.o obj/fft_prep_cpx.o

$(TARGET): $(OBJECT)
	gcc -o $@ $^ -lm

$(OBJECT): obj/%.o: src/%.c
	gcc -std=c99 -I inc/ -c -o $@ $^

clean:
	rm $(OBJECT) $(TARGET)
