# TRABALHO-PRG2
# *Sistema de atendimento para o CERTEA.*

Aluno: Gabriel Schappo Silva<br>
Matrícula: 	202210503078


*-> Instituição:* CERTEA - CENTRO DE ESTIMULAÇÃO E REABILITAÇÃO EM TRANSTORNO DO ESPECTRO AUTISTA.

*-> Justificativa:*<br>
Eu escolhi esta instituição pois ja "trabalhei" com ela na disciplina de PROJETO INTEGRADOR I, onde tivemos que realizar um programa no app inventor para suprir demandas que afetavam a instituição.
Uma delas era a dificuldade de gerenciar o atendimento da instituição, e com isso desenvolvi esse programa para auxiliar nessa causa.

*-> Funcionalidades:*<br>
1 - Cadastrar Pacientes (Nome, idade, data de nascimento e descrição do problema do paciente).<br>
2 - Consultar Pacientes (Imprime todas as informações do paciente baseado no nome ou ID inseridos).<br>
3 - Gerenciar Atendimentos (Agendar, consultar e cancelar um atendimento).<br>
4 - Gerenciar Fila de Espera (Adicionar um paciente na fila de espera (caso o paciente não tenha horario marcado), chamar o proximo paciente da fila, e consultar a fila de espera).<br>
5 - Consultar Funcionários (Imprime todas as informações do funcionario baseado no ID inserido).

*-> Estruturas de Dados Utilizadas:*<br>
1 - Árvore Binária de Pesquisa (Utilizada para guardar os IDs dos pacientes).<br>
-Justificativa: Permite organizar os IDs e realizar buscas eficientes. Foi escolhida em vez de uma lista porque possibilita pesquisas mais rápidas quando está relativamente balanceada.<br>
2 - AVL (Utilizada para guardar os IDs dos funcionários).<br>
-Justificativa: Mantém a árvore automaticamente balanceada, garantindo buscas eficientes em O(log n). Foi escolhida em vez de uma ABP comum porque evita o desbalanceamento da árvore.<br>
3 - Lista Duplamente Encadeada (Utilizada para guardar os IDs dos atendimentos).<br>
-Justificativa: Facilita a inserção, remoção e consulta dos atendimentos, permitindo percorrer a lista nos dois sentidos. Foi escolhida em vez de um vetor porque não exige deslocar elementos durante as remoções.<br>
4 - Fila (Utilizada para guardar os IDs dos pacientes que estão na fila de espera).<br>
-Justificativa: Organiza os pacientes pela ordem de chegada. Foi escolhida em vez de uma pilha porque garante que o paciente que chegou primeiro seja chamado primeiro.<br>
5 - Arquivos .txt (Utilizados para armazenar as informações dos pacientes, funcionários, agendamentos e fila de espera).<br>
-Justificativa: Foram utilizados para que após o encerramento do programa, as informações não sejam perdidas.

*-> Como Compilar/Executar:*<br>
Aperte o botão "Run" ou pressione "Shift + F10" para executar o programa, a função "main" chama a função inicializar_sistema que carrega todo o sistema.

*-> Organização do Repositório:*<br>
Os arquivos .c estão localizados na pasta "src", os arquivos .h estão localizados na pasta "include", os arquivos .txt estão localizados na pasta "dados", e o main.c está localizado na pasta raiz do projeto "TRABALHO-PRG2".

*-> Dificuldades Encontradas:*<br>
Minha maior dificuldade foi na utilização das funções de manipulação de arquivos, é a única parte do conteúdo que não conheço bem, frequentemente eu tive que pesquisar como usar as funções e como elas funcionam.

*-> Uso de IA:*<br>
Utilizei IA para me auxiliar em como utilizar as funções de manipulação de arquivos, e também para aprender o que elas realmente fazem.
