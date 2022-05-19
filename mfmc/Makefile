CC=g++
CFLAGS=-Wall -std=c++11 -g
EXT=cpp

SOURCE_DIR=src
BUILD_DIR=objs

TARGETS ?= main
SOURCES := $(shell find $(SOURCE_DIR) -name '*.$(EXT)')

# --- FUNCTIONS --- #
# Get corresponding object file from c/cpp file(s)
define get_obj
	$(patsubst %.$(EXT),$(BUILD_DIR)/%.o,$(notdir $(1)))
endef

# Creates an obj file from a given C file
define mk_c_rule
$(patsubst %.$(EXT),$(BUILD_DIR)/%.o,$(notdir $(1))): $(1)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $$^ -c -o $$@
endef

# --- HELPER VARS --- #
# List of all relevant object files
OBJ_FILES := $(call get_obj,$(SOURCES))



# --- BUILD RULES --- #

# Build all
all: $(TARGETS)


# Build object files
$(foreach f, $(SOURCES), $(eval $(call mk_c_rule, $(f))))

# Build executable
$(TARGETS): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

clean:
	rm -f $(TARGETS)
	rm -rf $(BUILD_DIR)

run:
	./main

.PHONY: clean run all



