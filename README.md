# TRABALHO FINAL AED I

<aside>
ALUNOS: <br>
- Ryan Pablo Almeida Costa - 12421BCC050 <br>
- Tiago Beijo Lemes Monteiro Junior - 12421BCC095<br>
- Pedro dos Santos Sales -
</aside>

## Estruturas Utilizadas

- Descritor para lista de consultas
- Nó para lista de consultas
- Descritor para lista de medicamentos
- Nó para lista de medicamentos

## Estruturação

```python
| consulta.h
| consulta.c
| medicamento.h
| medicamento.c
| main.c
| README.md
```

## Compilando o projeto
```terminal
gcc main.c medicamento.c consulta.c -o programa
```

## Lista.h

Redefinimos o tipo unsigned int para uint com o intuito de facilitar a escrita do código;

Criamos nós diferentes e descritores diferentes para as duas listas para não adicionar complicações desnecessárias com o union;"# trabalho-aed" 
