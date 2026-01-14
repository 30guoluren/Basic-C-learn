# 编译器和编译选项
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# 源文件目录
SRC_DIR = src
# 构建输出目录
BUILD_DIR = build

# 生成的可执行文件
TARGET = $(BUILD_DIR)/mk_system

# 自动收集 src 下所有 cpp 文件
SRC = $(wildcard $(SRC_DIR)/*.cpp)
# 对应的 obj 文件放到 build/
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC))

# 默认目标
all: $(TARGET)

# 链接可执行文件
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# 编译源文件为 obj 文件
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理构建文件
clean:
	rm -rf $(BUILD_DIR)/*

.PHONY: all clean