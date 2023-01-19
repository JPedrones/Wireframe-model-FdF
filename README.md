## FdF - Fil de Fer

Fdf é um wireframe model 3D, consiste em projetar em uma nova janela um mapa 3d com profundidade e em [projeção isométrica](https://pt.wikipedia.org/wiki/Perspectiva_isom%C3%A9trica). Neste projeto foi usado o X-Server e a [Minilibx](https://harm-smits.github.io/42docs/libs/minilibx.html) (uma biblioteca baseada na LibX e foi criada por estudantes da 42 para facilitar o estudo de projetos gráficos).

Neste projeto foi utilizado uma versão do algoritmo [bresenham](https://pt.wikipedia.org/wiki/Algoritmo_de_Bresenham) para desenhar retas diagonais.

**Desafios do projeto:** Aprender a utilizar a Minilibx e a Xlib, entender os conceitos do servidor gráfico e o conceito de desenhar pixels em tela.

### Como executar:

- ![Minilibx](https://github.com/42Paris/minilibx-linux) instalado, basta seguir as instruções do link.
- Ambiente Linux ou WSL2.  
**NOTA:** Se for windows 10 é necessário instalar um X-Server para windows.
```
$ make
```
```
$ ./fdf ./maps/[mapa escolhido].fdf
```

##
![t1.fdf map](/imgs/t1.png)
![elem-col.fdf map](/imgs/elem-col.png)
![pylone.fdf map](/imgs/pylone.png)
