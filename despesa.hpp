#ifndef CLASSE_DESPESA
#define CLASSE_DESPESA

#include <string>

class despesa {

public:
    despesa(const std::uint16_t &numero_despesa,
            const std::string &descricao,
            const double &valor_total,
            const std::uint16_t &parcelas, 
            const std::uint16_t &dia_limite_pagamento);

    std::uint16_t get_numero_despesa();
    void set_numero_despesa(const std::uint16_t &numero_despesa);

	std::string get_descricao();
    void set_descricao(const std::string &descricao);

	double get_valor_total();
    void set_valor_total(const double &valor_total);

	std::uint16_t get_parcelas();
    void set_parcelas(const std::uint16_t &parcelas);

    std::uint16_t get_dia_limite_pagamento();
    void set_dia_limite_pagamento(const std::uint16_t &dia_limite_pagamento);

    std::string retorna_insert_query();

private:
    std::uint16_t numero_despesa_;
	std::string descricao_;
	double valor_total_;
	std::uint16_t parcelas_; 
    std::uint16_t dia_limite_pagamento_;

};  

#endif /* CLASSE_DESPESA */