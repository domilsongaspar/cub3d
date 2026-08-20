# cub3D

Projeto de raycasting 3D desenvolvido para o currículo da escola 42. Esta implementação renderiza uma cena 3D simples a partir de um mapa 2D usando um motor de raycasting e a biblioteca gráfica MiniLibX.

Todas as funcionalidades obrigatórias e os bônus foram concluídos neste repositório.

## Funcionalidades
- Renderizador 3D baseado em raycasting
- Texturas nas paredes e cores para chão/teto
- Renderização de sprites (objetos/inimigos)
- Minimap e validação/parsing de mapas
- Portas com abertura/fecho
- Controles por mouse e teclado

## Requisitos
- Linux
- GCC
- MiniLibX (incluído na pasta `mlx/`)

## Compilar
Execute `make` na raiz do projeto. O repositório contém um `Makefile` que gera o binário `cub3d`.

```sh
make
```

## Uso
Execute o programa passando um arquivo `.cub` da pasta `maps/`:

```sh
./cub3d maps/subject_map.cub
```

Controles (padrão):
- `W` / `S`: avançar / recuar
- `A` / `D`: mover lateralmente (strafe)
- Setas esquerda/direita: rotacionar a vista
- Mouse: olhar ao redor
- `ESC`: sair

## Mapas
Os mapas são arquivos `.cub` localizados na pasta `maps/`. O parser valida texturas, cores e o fechamento do mapa. Use os mapas de exemplo incluídos para testar o motor.

## Observações
- Projeto feito para fins educacionais como parte do currículo da 42.
- Todos os bônus foram implementados e testados localmente.

## Autor
Aluno da 42 — projeto concluído com todos os bônus.