# run:
# 	gcc example2.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o example2
# 	./example2
ray:
	rm visualizer
	gcc visualizer.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o visualizer
	./visualizer
gl:
	gcc -Wall -Wextra -g $(pkg-config --cflags opengl glfw3) glvisualizer.c      $(pkg-config --libs opengl glfw3) -o glvisualizer
	# gcc -Wall -Wextra -g $(pkg-config --cflags opengl glfw3) glvisualizer.c \ 
	# 	$(pkg-config --libs opengl glfw3) -o glvisualizer
	./glvisualizer
