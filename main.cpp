#include <iostream>
#include <cstdlib>
#include <string>
#include <mysql.h> 

#include "despesa.hpp"

void limpaTela()
{
	if (system("CLS")) system("clear");
}

short int opcaoEscolhidaMenu()
{
	
	limpaTela();
	
	short int opcao = 0;
		
	std::cout << " CONTROLE DE DESPESAS " << '\n';
	std::cout << " 1 - LANCAR " << '\n';
	std::cout << " 2 - VISUALIZAR " << '\n';
	std::cout << " 3 - ALTERAR " << '\n';
	std::cout << " 4 - DELETAR " << '\n';
	std::cout << " 5 - SAIR " << '\n';
	
	std::cout << "Escolha uma opcao: ";
	std::cin >> opcao;
	
	limpaTela();
		
	return opcao;
		
}

MYSQL *conectaBanco()
{

	MYSQL *conexao = mysql_init(NULL);
	if (conexao == NULL) {
		std::cerr << "Erro ao iniciar MySQL: " << mysql_error(conexao) << '\n';
		return NULL;
	}

	MYSQL *resultado = mysql_real_connect(
		conexao,
		"127.0.0.1",      
		"despesas_app",           
		"felipedespesa321", 
		"controle_despesa",
		3306,             
		NULL,
		0
	);

	if (resultado == NULL) {
		std::cerr << "Erro ao conectar MySQL: " << mysql_error(conexao) << '\n';
		mysql_close(conexao);
		return NULL;
	}

	return conexao;

}

void gravaNovaDespesa(MYSQL *conexao, despesa &nova_despesa)
{

	std::string query = nova_despesa.retorna_insert_query();

	int query_state = mysql_query(conexao, query.c_str());
	if (query_state != 0)
		std::cerr << "Erro ao executar a query: " << mysql_error(conexao) << '\n';
	else
		std::cout << "Nova despesa gravada com sucesso" << '\n';

}

void lancarNovaDespesa(MYSQL *conexao)
{

    std::uint16_t numero_despesa;
	std::string descricao;
	double valor_total;
	std::uint16_t parcelas; 
    std::uint16_t dia_limite_pagamento;
	
	std::cout << "LANCAMENTO DE DESPESA" << '\n';
	
	std::cout << "Numero da despesa: ";
	std::cin >> numero_despesa;

	std::cout << "Descricao: ";
	std::cin.ignore();
	std::getline(std::cin, descricao);

	std::cout << "Valor total a pagar: ";
	std::cin >> valor_total; 

	std::cout << "Quantidade de parcelas: ";
	std::cin >> parcelas;

	std::cout << "Dia limite para pagamento: ";
	std::cin >> dia_limite_pagamento;

	despesa nova_despesa{numero_despesa, descricao, valor_total, parcelas, dia_limite_pagamento};

	gravaNovaDespesa(conexao, nova_despesa);
	
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
		std::cout << "Programa sendo finalizado..." << '\n';
		break;
	default:
		std::cout << "Opcao inexistente..." << '\n';
		break;
	}

	mysql_close(conexao);
	
	return 0;
}