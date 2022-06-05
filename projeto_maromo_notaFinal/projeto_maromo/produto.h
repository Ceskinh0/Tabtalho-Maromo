struct Produto {
    int codigo;
    char descricao[61];
    char fornecedor[61];
    int quantEstoque;
    double preco;
};
typedef struct Produto produto;

void inicializar(produto * p[], int tam);

void adicionar(produto* p[], int pos);

void listarTodos(produto* p[], int pos);

void encontrar(produto* p[], int proc, int pos);

void atualizar(produto* p[], int proc, int pos);

void comprar(produto* p[], int proc, int pos);

void vender(produto* p[], int proc, int pos);
