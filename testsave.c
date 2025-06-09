void saveScore(int playerScore, int playerErrors)
{
  char resposta;
  printf("Deseja salvar sua pontuação? (s/n): ");
  scanf(" %c", &resposta);
  if (resposta != 's' && resposta != 'S')
  {
    printf("Progresso não salvo.\n");
    return;
  }
  FILE *arquivo;
  char apelido[21];
  printf("Digite seu apelido(até 20 caracteres): ");
  getchar();
  fgets(apelido, sizeof(apelido), stdin);
  if (apelido[strlen(apelido) - 1] == '\n')
  {
    apelido[strlen(apelido) - 1] = '\0';
  }
  arquivo = fopen("", "a");
  if (arquivo == NULL)
  {
    printf("Erro ao abrir ou criar o arquivo!\n");
    return;
  }
  fprintf(arquivo, "Jogador: %s | Score: %d | Errors: %d\n", apelido, playerScore, playerErrors);
  fclose(arquivo);
  printf("Pontuação salva com sucesso!\n");
}
