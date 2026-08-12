#include <iostream>
#include <cstdlib>
#include <string>
#include <mysql.h> 

using namespace std;

void limpaTela()
{
	if (system("CLS")) system("clear"); // horrivel
}

short int opcaoEscolhidaMenu()
{
	
	limpaTela();
	
	short int opcao = 0;
		
	cout << " CONTROLE DE DESPESAS " << endl;
	cout << " 1 - LANCAR " << endl;
	cout << " 2 - VISUALIZAR " << endl;
	cout << " 3 - ALTERAR " << endl;
	cout << " 4 - DELETAR " << endl;
	cout << " 5 - SAIR " << endl;
	
	cout << "Escolha uma opcao: ";
	cin >> opcao;
	
	limpaTela();
		
	return opcao;
		
}

MYSQL *conectaBanco()
{

	MYSQL *conexao = mysql_init(NULL);
	if (conexao == NULL) {
		cerr << "Erro ao iniciar MySQL: " << mysql_error(conexao) << endl;
		return NULL;
	}

	MYSQL *resultado = mysql_real_connect(
		conexao,
		"127.0.0.1",      
		"root",           
		"tchiulepe321", 
		"controle_despesa",
		3306,             
		NULL,
		0
	);

	if (resultado == NULL) {
		cerr << "Erro ao conectar MySQL: " << mysql_error(conexao) << endl;
		mysql_close(conexao);
		return NULL;
	}

	return conexao;

}

void gravaNovaDespesa(MYSQL *conexao, int numero_despesa, string descricao, float valorTotal, short int parcelas, short int dia_limite_pagamento)
{

	string query = "INSERT INTO despesas (numero_despesa, descricao, valor_a_pagar, parcela, dia_limite_pagamento) ";
	short int parcelaAtual = 1;
	float valorCadaParcela = valorTotal / parcelas;
	
	cout << (conexao == NULL) << " - " << numero_despesa << " - " << descricao << " - " << valorTotal << " - " << parcelas << " - " << dia_limite_pagamento << " - " << valorCadaParcela << endl;

	// do {
	// 	query += "VALUES " + (string) numero_despesa + ", ";
	// 	query += descricao + ", ";
	// 	query += (string) valorCadaParcela + ", ";
	// 	query += (string) parcelaAtual + ", ";
	// 	query += (string) dia_limite_pagamento + ";";

	// } while (++parcelaAtual <= parcelas);

	// if (conexao == NULL) {
	// 	return ;
	// }

}

void lancarNovaDespesa(MYSQL *conexao)
{

	int numero_despesa;
	string descricao;
	double valorTotal;
	short int parcelas, dia_limite_pagamento;
	
	cout << "LANCAMENTO DE DESPESA" << endl;
	
	cout << "Numero da despesa: ";
	cin >> numero_despesa;

	cout << "Descricao: ";
	cin >> descricao;

	cout << "Valor total a pagar: ";
	cin >> valorTotal; 

	cout << "Quantidade de parcelas: ";
	cin >> parcelas;

	cout << "Dia limite para pagamento: ";
	cin >> dia_limite_pagamento;

	gravaNovaDespesa(conexao, numero_despesa, descricao, valorTotal, parcelas, dia_limite_pagamento);
	
}

void visualizarDespesas()
{
	
}

void alterarDespesa()
{
	
}

void deletarDespesa()
{
	
}

void criaTabelaDespesa(MYSQL *conexao)
{

	string query = "CREATE TABLE despesas (";
	query += "id INT PRIMARY KEY AUTO_INCREMENT, ";
	query += "numero_despesa INT NOT NULL, ";
	query += "descricao VARCHAR(100) NOT NULL, ";
	query += "valor_a_pagar DECIMAL(8,2) NOT NULL CHECK (valor_a_pagar > 0), ";
	query += "parcela TINYINT NOT NULL CHECK (parcela > 0), ";
	query += "dia_limite_pagamento TINYINT NOT NULL CHECK (dia_limite_pagamento BETWEEN 1 AND 31), ";
	query += "is_parcela_paga BOOL DEFAULT FALSE, ";
	query += "data_insercao DATE DEFAULT (CURRENT_DATE), ";
	query += "UNIQUE (numero_despesa, parcela) )";

	int query_state = mysql_query(conexao, query.c_str());
	if (query_state != 0) {
		cerr << "Erro ao executar a query: " << mysql_error(conexao) << endl;
	} else {
		cout << "Tabela 'despesas' criada com sucesso" << endl;
	}

}

int main(int argc, char** argv)
{

	MYSQL *conexao = conectaBanco();
	if (conexao == NULL) {
		return 0;
	}

	short int opcao = opcaoEscolhidaMenu();
	switch(opcao)
	{
	case 1:
		lancarNovaDespesa(conexao);
		break;
	case 2:
		visualizarDespesas();
		break;
	case 3:
		alterarDespesa();
		break;
	case 4:
		deletarDespesa();
		break;
	case 5:
		cout << "Programa sendo finalizado..." << endl;
		break;
	// case 6:
	// 	criaTabelaDespesa(conexao);
	// 	break;
	default:
		cout << "Opcao inexistente..." << endl;
		break;
	}

	mysql_close(conexao);
	
	return 0;
}