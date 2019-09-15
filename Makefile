# Leo's Makefile for compiling OSL shaders
SRC_UTILS= geomMapping.osl sTiles.osl rotateM.osl scaleM.osl shearM.osl translateM.osl
SRC_MAP_PERTURB=perturbCoords.osl perturbUV.osl
SRC_GENERATORS= fieldNoise.osl fieldNoiseM.osl newMMatrix.osl
SRC_PROCESSORS= blendVectors.osl tileCoords.osl
SRC_PBRPACK= packPbr.osl unpackPbr.osl blendPbr.osl
SRC_TEXTURES=voronoi.osl
SRC_PATTERN=dstStencil.osl
# Gather all shader sources to a big list
SRC=$(SRC_UTILS) $(SRC_GENERATORS) $(SRC_PROCESSORS) $(SRC_MAP_PERTURB) $(SRC_PBRPACK) $(SRC_TEXTURES) $(SRC_PATTERN)

# Compile targets are estimated automatically
SHADERS=$(SRC:.osl=.oso)
OBJ=$(addprefix shaders/, $(SHADERS))

#SRC=$(appendprefix src/, $(SRC))

# Tell make where to find OSLC executable. Please edit line below.
OSLC=/home/leonard/opt/appleseed/bin/oslc

all: $(OBJ)

shaders/%.oso: src/%.osl
	$(OSLC) -Iinclude $< -o $@

clean:
	rm $(OBJ)
