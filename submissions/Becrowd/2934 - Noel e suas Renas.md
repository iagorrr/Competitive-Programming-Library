# 2934 - Noel e Suas Renas

Resumidamente o problema pede para que sejam escolhida uma [subsequência](https://en.wikipedia.org/wiki/Subsequence) das renas de maneira que dentre as renas escolhidas a diferença entre a altura de duas renas escolhidas seja exatamente **1**, vamos chamar esse subproblema de **subproblema 1**, no entanto ainda existe a possiblidade de adicionar uma rena de altura qualquer em qualquer posição, vamos chamar essa parte de **subproblema 2**.

Para resolver o **subproblema 1** poderíamos modelar uma dp da seguinte forma:

    dp[*i*] = máximo de renas que consigo escolher,
            considerando que a última rena escolhida
            possúi altura *i*
    
    1 <= i <= 10^6

Com o caso base sendo `dp[0] = -oo` pois não é possível escolher uma rena de altura 0, e todos os demais estados sendo inicializados com zero.

Com isso bastaria iterar sobre o vetor de alturas das renas da esquerda para a direita,  e perceber que se uma rena possúi altura `hi` a resposta dela vai ser:
    
    dp[hi] = max(dp[hi], dp[hi-1])

pois só é possível escolher uma rena com altura `hi` se a rena anterior possuir altura `hi-1`.

Partindo desse princípio é possível evoluir para o **subproblema 2**, e considerar que uma rena de altura qualquer pode ser inserida no meio, início ou fim da subsequência, vamos chamar essa rena de **rena x**

Vamos precisar modelar a dp da seguinte maneira agora:

    
    1 <= i <= 10^6
    j sendo um booleano (true ou false) / (1 ou 0).

    dp[*i*][*j*] =  máximo de renas que consigo escolher,
                    considerando que a última rena escolhida
                    possúi altura *i*, e se *j* for verdadeiro
                    já coloquei a *rena x*, caso contrário ainda
                    não coloquei a *rena x*
                
Nosso caso base continua sendo o mesmo: `dp[0] = -oo`, no entanto é necessário tomar um certo cuidado com a primeira rena, seja `h1` a altura da primeira rena, então:
    
    dp[h1][0] = 1, simplesmente começar com a primeira rena
    
    if h1 > 1
        dp[h1][1] = 2, considerar que colocamos a *rena x* no início com altura h1-1
    
    dp[h1+1][1] = 2, colocar a *rena x* após a primeira rena com *hi+1*

Supondo que estamos analisando a i-ésima rena de altura **hi** as transições dela serão :

    dp[hi][false] = max {
                        1 => basta escolher essa rena *i*
                            e ignorar todas as renas anteriores

                        dp[hi-1][false] + 1 => continuar a subequência
                                               de uma rena com altura hi-1
                    }

    dp[hi][true] = max {
                        dp[hi-1][true] + 1 => considerar que ja foi escolhida
                                              a *rena x* e continuar a subsequência
                                              a partir de *hi-1*

                        dp[hi-2][false] + 2 => considerar que não foi escolhida a 
                                               *rena x*, escolher ela com altura *hi-1*
                                               portanto será inserida após a rena *hi-2*,
                                               e por fim colocar a rena *hi* após a *rena x*
                    }

Lembrando que é necessário fazer os devidos tratamentos para evitar acesso indevido de memória e coisas relacionadas.
