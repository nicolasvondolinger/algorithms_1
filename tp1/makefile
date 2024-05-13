# Compilador
CXX = g++

# Opções de compilação
CXXFLAGS = -std=c++11 -Wall -Wextra

# Nome do executável
TARGET = main

# Lista de arquivos fonte
SRCS = main.cpp

# Lista de arquivos objeto gerados a partir dos arquivos fonte
OBJS = $(SRCS:.cpp=.o)

# Comando para compilar o programa
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Regra para compilar os arquivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para limpar arquivos gerados
clean:
	rm -f $(OBJS) $(TARGET)

# Phony target para garantir que as regras sejam executadas mesmo se houver
# um arquivo chamado clean ou dependências
.PHONY: clean
