# Leo's Makefile for compiling OSL shaders
SRC_UTILS= geomMapping.osl alterMatrix.osl perturbCoords.osl cpattern.osl
SRC_GENERATORS= fieldNoise.osl fieldNoiseM.osl fieldNoiseMMatrix.osl
SRC_PROCESSORS= blendVectors.osl tileCoords.osl
# Gather all shader sources to a big list
SRC=$(SRC_UTILS) $(SRC_GENERATORS) $(SRC_PROCESSORS)

# Compile targets are estimated automatically
SHADERS=$(SRC:.osl=.oso)
OBJ=$(addprefix shaders/, $(SHADERS))

#SRC=$(appendprefix src/, $(SRC))

# Chose OSLC executable
OSLC=/home/claude/opt/appleseed/bin/oslc

all: $(OBJ)

shaders/%.oso: src/%.osl
	$(OSLC) $< -o $@

clean:
	rm $(OBJ)
