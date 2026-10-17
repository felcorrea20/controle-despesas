Esse projeto utiliza libs do mysql. Por isso é necessário incluir os caminhos do header e das libs.
    * Comando para achar o caminho do mysql.h:
        - mysql_config --cflags
    
    * Comando para achar o caminho e os nomes das libs:
        - mysql_config --libs

Com isso, o comando de compilação é o seguinte: 
g++ -I/usr/include/mysql main.cpp despesa.cpp -L/usr/lib/x86_64-linux-gnu -lmysqlclient -lzstd -lssl -lcrypto -lresolv -lm -o ./build/main.exe
