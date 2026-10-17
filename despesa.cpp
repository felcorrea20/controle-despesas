#include "despesa.hpp"

despesa::despesa(const std::uint16_t &numero_despesa,
                 const std::string &descricao,
                 const double &valor_total,
                 const std::uint16_t &parcelas, 
                 const std::uint16_t &dia_limite_pagamento) 
                : numero_despesa_(numero_despesa), descricao_(descricao), valor_total_(valor_total), parcelas_(parcelas), dia_limite_pagamento_(dia_limite_pagamento)
{
}

std::uint16_t despesa::get_numero_despesa()
{
    return this->numero_despesa_;
}
void despesa::set_numero_despesa(const std::uint16_t &numero_despesa)
{
    this->numero_despesa_ = numero_despesa;
}

std::string despesa::get_descricao()
{
    return this->descricao_;
}
void despesa::set_descricao(const std::string &descricao)
{
    this->descricao_ = descricao;
}

double despesa::get_valor_total()
{
    return this->valor_total_;
}
void despesa::set_valor_total(const double &valor_total)
{
    this->valor_total_ = valor_total;
}

std::uint16_t despesa::get_parcelas()
{
    return this->parcelas_;
}
void despesa::set_parcelas(const std::uint16_t &parcelas)
{
    this->parcelas_ = parcelas;
}

std::uint16_t despesa::get_dia_limite_pagamento()
{
    return this->dia_limite_pagamento_;
}
void despesa::set_dia_limite_pagamento(const std::uint16_t &dia_limite_pagamento)
{
    this->dia_limite_pagamento_ = dia_limite_pagamento;
}

std::string despesa::retorna_insert_query()
{
	std::string query = "INSERT INTO despesas (numero_despesa, descricao, valor_a_pagar, parcela, dia_limite_pagamento) VALUES (";
    query += std::to_string(this->numero_despesa_) + ", ";
    query += '"' + this->descricao_ + '"' + ", ";
    query += std::to_string(this->valor_total_) + ", ";
    query += std::to_string(this->parcelas_) + ", ";
    query += std::to_string(this->dia_limite_pagamento_) + ");";

    return query;
}