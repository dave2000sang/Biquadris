CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -g -Werror=vla
OBJECTS = displays/graphics_display.o displays/window.o board.o  command.o  game.o  game_state.o  main.o  player.o blocks/block.o  blocks/i_block.o  blocks/j_block.o  blocks/l_block.o  blocks/o_block.o  blocks/s_block.o  blocks/t_block.o  blocks/z_block.o block_factory/block_factory.o  block_factory/level_one.o block_factory/level_two.o block_factory/level_four.o   block_factory/level_three.o  block_factory/level_zero.o displays/text_display.o abstract_player.o abstract_effect.o blind_effect.o heavy_effect.o force_effect.o reduce_effect.o

DEPENDS = ${OBJECTS:.o=.d}
EXEC = biquadris

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
-include {DEPENDS}
