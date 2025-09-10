#include "consulta.h"
#include "medicamento.h"
#include "arquivo.h"

void menu() {
    printf("\n=== MENU CONSULTORIO ===\n");
    printf("1 - Inserir paciente\n");
    printf("2 - Imprimir pacientes\n");
    printf("3 - Buscar paciente\n");
    printf("4 - Remover paciente\n");
    printf("5 - Adicionar medicamento a paciente\n");
    printf("6 - Remover medicamento de paciente\n");
    printf("7 - Imprimir medicamentos de paciente\n");
    printf("8 - Importar arquivo consultas\n");
    printf("9 - Gerar relatorio da clinica.\n");
    printf("10 - Percorrer pacientes.\n");
    printf("0 - Sair\n");
    printf("Escolha: ");
}

int main() {
    ListaConsulta lista;
    criarListaConsulta(&lista);

    int opcao;
    char nome[50];
    unsigned int idade;
    NoConsulta *paciente;

    do {
        menu();
        scanf("%d", &opcao);
        getchar(); // limpar buffer
        system("cls");

        switch (opcao) {
            case 1:
                printf("Digite o nome do paciente: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';

                printf("Digite a idade: ");
                scanf("%u", &idade);
                getchar();

                paciente = criarCelulaConsulta(nome, idade);
                insereCelulaConsulta(&lista, paciente);
                printf("Paciente inserido com sucesso!\n");
                break;

            case 2:
                imprimirListaConsulta(&lista);
                break;

            case 3:
                printf("Digite o nome do paciente a buscar: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';
                buscarPacienteConsulta(&lista, nome);
                break;

            case 4:
                printf("Digite o nome do paciente a remover: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';
                removerPacienteConsulta(&lista, nome);
                break;

            case 5: {
                printf("Digite o nome do paciente: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';

                NoConsulta* temp = lista.cabeca;
                while (temp && strcasecmp(temp->paciente_consultado, nome) != 0) {
                    temp = temp->prox;
                }
                if (!temp) {
                    printf("Paciente nao encontrado.\n");
                    break;
                }

                char med[50];
                unsigned int qtd;
                printf("Digite o nome do medicamento: ");
                fgets(med, sizeof(med), stdin);
                med[strcspn(med, "\n")] = '\0';

                printf("Digite a quantidade: ");
                scanf("%u", &qtd);
                getchar();

                adicionarMedicamentoPaciente(temp, med, qtd);
                break;
            }

            case 6: {
                printf("Digite o nome do paciente: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';

                NoConsulta* temp = lista.cabeca;
                while (temp && strcasecmp(temp->paciente_consultado, nome) != 0) {
                    temp = temp->prox;
                }
                if (!temp) {
                    printf("Paciente nao encontrado.\n");
                    break;
                }

                char med[50];
                printf("Digite o nome do medicamento a remover: ");
                fgets(med, sizeof(med), stdin);
                med[strcspn(med, "\n")] = '\0';

                removerMedicamentoPaciente(temp, med);
                break;
            }

            case 7: {
                printf("Digite o nome do paciente: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';

                NoConsulta* temp = lista.cabeca;
                while (temp && strcasecmp(temp->paciente_consultado, nome) != 0) {
                    temp = temp->prox;
                }
                if (!temp) {
                    printf("Paciente nao encontrado.\n");
                } else {
                    imprimirMedicamentosPaciente(temp);
                }
                break;
            }
            case 8: {
                printf("Importando arquivo ...\n");

                FILE *fp = fopen("consultas.txt", "r");
                if(fp == NULL) {
                    printf("Arquivo não pode ser aberto!\n");
                    break;
                }

                arquivoToLista(fp, &lista);
                printf("Arquivo importado com sucesso!\n");

                fclose(fp);
                break;
            }
            case 9:{
                gerarRelatorio(&lista);
                break;
            }
            case 10:{
                percorrePacientes(&lista);
                break;
            }
            case 0:
                LiberarListaConsulta(&lista);
                printf("Encerrando programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}