# 🧠 Jogo da Memória em C - Trabalho Final 🧠

---

## 📚 Informações Gerais

* **Período Letivo:** 2025/1
* **Curso:** Tecnologia em Análise e Desenvolvimento de Sistemas (ADS)
* **Turma:** 1º Semestre
* **Disciplina:** Linguagem de Programação I

---

## 🎯 Proposta

Desenvolvimento de um Jogo da Memória utilizando a linguagem C, aplicando os conceitos de lógica, programação estruturada, manipulação de matrizes, números aleatórios, entrada/saída de dados e manipulação de arquivos.

---

## 📜 Regras do Jogo

1.  **Geração:** Uma matriz 4x4 é preenchida com 8 pares de números aleatórios (0 a 9).
2.  **Visualização:** A matriz com os números é mostrada por 5 segundos. Em seguida, é substituída por uma matriz onde todas as células contêm um caractere ASCII pré-definido (escolhido entre 1 e 6).
3.  **Primeira Jogada:** O jogador informa a linha e a coluna da primeira carta a ser revelada. O número correspondente é mostrado.
4.  **Segunda Jogada:** O jogador informa a linha e a coluna da segunda carta, tentando encontrar o par da primeira.
5.  **Acerto:** Se os números forem iguais:
    * O jogador ganha 1 ponto de acerto.
    * As posições permanecem reveladas (ou são marcadas de alguma forma).
    * Um *beep* é emitido (`\a`, caractere ASCII 7).
    * O jogador tenta novamente (volta ao passo 3).
6.  **Erro:** Se os números forem diferentes:
    * O jogador ganha 1 ponto de erro.
    * As cartas voltam a ser escondidas (mostrando o caractere ASCII).
    * O jogador tenta novamente (volta ao passo 3).
7.  **Fim de Jogo:** O jogo termina quando:
    * Todos os 8 pares forem encontrados (Vitória!).
    * O número de erros ultrapassar 10 (Derrota!).
8.  **Salvar Pontuação:** Ao final, o jogo pergunta se o jogador deseja salvar a pontuação. Se sim, pede o nome e salva o nome, acertos e erros no arquivo `jogomemoria2025.txt`.
9.  **Jogar Novamente:** Após salvar (ou não), o jogo pergunta se o jogador quer iniciar uma nova partida ou sair.


