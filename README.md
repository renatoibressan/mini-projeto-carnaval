
# mini-projeto-carnaval

Pequeno projeto em C (mini-projeto) usado para aprendizado e demonstração de estrutura básica de programas em C.

**Descrição**
- **mini-projeto-carnaval** é um projeto educacional e compacto em C que contém uma aplicação de linha de comando com arquivos fonte modulares organizados em `src/` e `include/`.
- O código está separado em módulos para tratamento de menu, operações de arquivo, lógica de criatura e utilitários.

**Estrutura do repositório**
- `build.bat` : script de compilação para Windows
- `include/` : cabeçalhos públicos usados pelo projeto
	- `arquivo.h`
	- `criatura.h`
	- `menu.h`
	- `utils.h`
- `src/` : arquivos fonte
	- `arquivo.c`
	- `criatura.c`
	- `main.c`
	- `menu.c`
	- `utils.c`

**Requisitos**
- Um compilador C (GCC/MinGW, Clang ou MSVC).
- Acesso básico ao terminal/linha de comando.

**Compilação (Windows)**
1. Abra o Prompt de Comando ou PowerShell na raiz do projeto.
2. Execute o script de compilação fornecido:

```powershell
build.bat
```

O script irá compilar os fontes e gerar um executável na raiz do projeto (o nome depende do toolchain).

**Compilação manual (GCC / MinGW / Linux / macOS)**
Você pode compilar manualmente com `gcc`. A partir da raiz do projeto execute:

```bash
gcc -Iinclude -o carnaval src/main.c src/menu.c src/arquivo.c src/criatura.c src/utils.c -Wall -Wextra
```

Isso gera um executável chamado `carnaval` (ou `carnaval.exe` no Windows). Ajuste nomes de arquivo e flags conforme seu compilador.

**Uso**
- Execute o executável gerado a partir da raiz do projeto:

```powershell
./carnaval    # Unix-like
.\carnaval.exe  # Windows PowerShell/CMD
```

- O programa apresenta um menu simples em CLI (veja `src/menu.c`) para interação. Comentários nas fontes e cabeçalhos em `include/` explicam as responsabilidades dos módulos.

**Observações e dicas**
- Se houver erros de cabeçalho faltando, verifique se o caminho de inclusão do compilador inclui `include/` (use `-Iinclude`).
- Para builds de depuração, adicione `-g` e remova otimizações. Para release, considere `-O2` ou `-O3`.

**Contribuição**
- Abra issues ou envie pull requests. Mantenha mudanças pequenas e documente alterações comportamentais nos comentários do código.

**Licença**
- Não há uma licença especificada neste repositório. Adicione um arquivo `LICENSE` ou contate o mantenedor para confirmar a licença.

**Contato**
- Para dúvidas sobre a estrutura do projeto ou solicitações de funcionalidades, abra uma issue no repositório.
