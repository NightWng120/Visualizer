# run:
# 	gcc example2.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o example2
# 	./example2
run:
	gcc visualizer.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o visualizer
	./visualizer
