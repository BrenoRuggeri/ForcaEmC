# 🎯 Jogo da Forca em C
Este é um projeto simples e divertido de **jogo da forca**, feito em linguagem C. O jogador deve adivinhar uma palavra secreta chutando letras, com um número limitado de erros antes de "ser enforcado".

---

## 🕹️ Como jogar

- O jogo escolhe aleatoriamente uma palavra do banco de dados (`palavrasJogo.txt`).
- Você deve chutar letras para tentar adivinhar a palavra.
- Cada letra errada adiciona uma parte ao boneco da forca.
- O jogo termina quando:
  - Você acerta todas as letras da palavra (vitória).
  - Você erra 5 vezes (derrota).
- Ao final da partida, é possível adicionar novas palavras ao banco de dados.

---

## 🧠 Funcionalidades

- Banco de dados de palavras dinâmico.
- Gráfico do boneco da forca em ASCII que aparece progressivamente a cada erro.
- Sistema de vitórias e derrotas com mensagens personalizadas.
- Modularização com header (`forca.h`).
- Uso de arquivos (`palavrasJogo.txt`) para armazenar as palavras jogáveis.

---

## 📁 Estrutura dos arquivos

- `main.c` — Código principal do jogo.
- `forca.h` — Header file com definições, constantes e protótipos.
- `palavrasJogo.txt` — Banco de dados com a primeira linha sendo o número total de palavras, seguido das palavras linha a linha.
## 🎓 Certificado
![image](https://github.com/user-attachments/assets/9eb07349-8ca8-43a4-86d9-5a49dc69cb4d)

