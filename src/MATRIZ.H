#if ! defined( MATRIZ_ )
#define MATRIZ_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo matriz
*
*  Arquivo gerado:              MATRIZ.H
*  Letras identificadoras:      MAT
*
*  Autores: hg - Hugo Roque
*           nf - Nino Fabrizio
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor     Data     Observa��es
*       1.00   hg e nf  15/09/2013 Adapta��o do m�dulo para manipular matrizes
*
*  $ED Descri��o do m�dulo
*     Este m�dulo implementa um conjunto simples de fun��es para criar e
*     explorar matrizes.
*     A matriz possui uma cabe�a que cont�m uma refer�ncia para a ra�z da
*     matriz e outra para um n� corrente da matriz.
*     O modulo permite a manipula��o de m�ltiplas matrizes, por�m as fun��es
*     s� manipulam uma matriz de cada vez.
*     Ao iniciar a execu��o do programa n�o existe matriz.
*     A matriz poder� estar vazia. Neste caso a origem e o n� corrente
*     ser�o nulos, embora a cabe�a esteja definida.
*     O n� corrente ser� nulo se e somente se a matriz estiver vazia.
*
***************************************************************************/
 
#if defined( MATRIZ_OWN )
   #define MATRIZ_EXT
#else
   #define MATRIZ_EXT extern
#endif

#include "LISTA.H"

typedef struct tgMatriz MAT_tpMatriz ;

/***********************************************************************
*
*  $TC Tipo de dados: MAT Condicoes de retorno
*
*
***********************************************************************/

   typedef enum {

         MAT_CondRetOK = 0 ,
               /* Executou correto */

         MAT_CondRetNaoCriouOrigem = 1 ,
               /* N�o criou n� origem */

         MAT_CondRetNaoEhNo = 2 ,
               /* N�o � n� na dire��o desejada */

         MAT_CondRetMatrizNaoExiste = 3 ,
               /* Matriz n�o existe */

         MAT_CondRetNaoTemCorrente = 4 ,
               /* Matriz est� vazia */

         MAT_CondRetFaltouMemoria = 5
               /* Faltou mem�ria ao alocar dados */

   } MAT_tpCondRet ;


/***********************************************************************
*
*  $FC Fun��o: MAT Criar matriz
*
*  $ED Descri��o da fun��o
*     Cria uma nova matriz vazia.
*     Caso j� exista uma matriz, esta ser� destru�da.
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetFaltouMemoria
*
***********************************************************************/
   MAT_tpCondRet MAT_CriarMatriz( MAT_tpMatriz ** ppMatriz ) ;



/***********************************************************************
*
*  $FC Fun��o: MAT Inicializar a matriz
*
*  $EP Par�metros
*     $P pMatriz - matriz que ser� inicializada.
*                    Este par�metro � passado por refer�ncia.
*     $P Linhas - quantidade de linhas que a matriz ter�.
*     $P Colunas - quantidade de colunas que a matriz ter�.
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetFaltouMemoria
*
***********************************************************************/
   MAT_tpCondRet MAT_InicializarMatriz( MAT_tpMatriz * pMatriz , int Linhas , int Colunas ) ;



/***********************************************************************
*
*  $FC Fun��o: MAT Destruir matriz
*
*  $ED Descri��o da fun��o
*     Destr�i o corpo e a cabe�a da matriz, anulando a matriz corrente.
*     Faz nada caso a matriz corrente n�o exista.
*
*  $EP Par�metros
*     $P ppMatriz - � o ponteiro para a matriz que ser� destruida.
*                    Este par�metro � passado por refer�ncia.
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*
***********************************************************************/
   MAT_tpCondRet MAT_DestruirMatriz( MAT_tpMatriz ** ppMatriz ) ;


/***************************************************************************
*
*  $FC Fun��o: MAT Ir para n� ao norte.
*  
*  $ED Descri��o da fun��o
*  Muda o n� corrente da matriz para o n� na dire��o norte
*  
*  $EP Par�metros
*     pMatriz - ponteiro para matriz que manipulada.
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetNaoTemCorrente
*     MAT_CondRetNaoEhNo
*
***********************************************************************/
   MAT_tpCondRet MAT_IrNoNorte( MAT_tpMatriz * pMatriz ) ;


/***************************************************************************
*
*  $FC Fun��o: MAT Ir para n� ao sul.
*  
*  $ED Descri��o da fun��o
*  Muda o n� corrente da matriz para o n� na dire��o sul
*  
*  $EP Par�metros
*     pMatriz - ponteiro para matriz que manipulada.
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetNaoTemCorrente
*     MAT_CondRetNaoEhNo
*
***********************************************************************/
   MAT_tpCondRet MAT_IrNoSul( MAT_tpMatriz * pMatriz ) ;


/***************************************************************************
*
*  $FC Fun��o: MAT Ir para n� � este.
*  
*  $ED Descri��o da fun��o
*  Muda o n� corrente da matriz para o n� na dire��o este.
*  
*  $EP Par�metros
*     pMatriz - ponteiro para matriz que manipulada.
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetNaoTemCorrente
*     MAT_CondRetNaoEhNo
*
***********************************************************************/
   MAT_tpCondRet MAT_IrNoEste( MAT_tpMatriz * pMatriz ) ;


/***************************************************************************
*
*  $FC Fun��o: MAT Ir para n� � oeste.
*  
*  $ED Descri��o da fun��o
*  Muda o n� corrente da matriz para o n� na dire��o oeste
*  
*  $EP Par�metros
*     pMatriz - ponteiro para matriz que manipulada.
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetNaoTemCorrente
*     MAT_CondRetNaoEhNo
*
***********************************************************************/
   MAT_tpCondRet MAT_IrNoOeste( MAT_tpMatriz * pMatriz ) ;


/***************************************************************************
*
*  $FC Fun��o: MAT Ir para n� � nordeste.
*  
*  $ED Descri��o da fun��o
*  Muda o n� corrente da matriz para o n� na dire��o nordeste
*  
*  $EP Par�metros
*     pMatriz - ponteiro para matriz que manipulada.
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetNaoTemCorrente
*     MAT_CondRetNaoEhNo
*
***********************************************************************/
   MAT_tpCondRet MAT_IrNoNordeste( MAT_tpMatriz * pMatriz ) ;


/***************************************************************************
*
*  $FC Fun��o: MAT Ir para n� � sudeste.
*  
*  $ED Descri��o da fun��o
*  Muda o n� corrente da matriz para o n� na dire��o sudeste
*  
*  $EP Par�metros
*     pMatriz - ponteiro para matriz que manipulada.
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetNaoTemCorrente
*     MAT_CondRetNaoEhNo
*
***********************************************************************/
   MAT_tpCondRet MAT_IrNoSudeste( MAT_tpMatriz * pMatriz ) ;


/***************************************************************************
*
*  $FC Fun��o: MAT Ir para n� � sudoeste.
*  
*  $ED Descri��o da fun��o
*  Muda o n� corrente da matriz para o n� na dire��o sudoeste
*  
*  $EP Par�metros
*     pMatriz - ponteiro para matriz que manipulada.
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetNaoTemCorrente
*     MAT_CondRetNaoEhNo
*
***********************************************************************/
   MAT_tpCondRet MAT_IrNoSudoeste( MAT_tpMatriz * pMatriz ) ;


/***************************************************************************
*
*  $FC Fun��o: MAT Ir para n� � noroeste.
*  
*  $ED Descri��o da fun��o
*  Muda o n� corrente da matriz para o n� na dire��o noroeste
*  
*  $EP Par�metros
*     pMatriz - ponteiro para matriz que manipulada.
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetNaoTemCorrente
*     MAT_CondRetNaoEhNo
*  
***********************************************************************/
   MAT_tpCondRet MAT_IrNoNoroeste( MAT_tpMatriz * pMatriz ) ;



/***********************************************************************
*
*  $FC Fun��o: MAT Obter valor corrente
*
*  $EP Par�metros
*     $P ValorParm - � o par�metro que receber� o valor contido no n�.
*                    Este par�metro � passado por refer�ncia.
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetNaoTemCorrente
*
***********************************************************************/

   MAT_tpCondRet MAT_ObterValorCorr( MAT_tpMatriz * pMatriz , LIS_tppLista * ValorParm ) ;

/***********************************************************************
*
*  $FC Fun��o: MAT Atribuir valor corrente
*
*  $EP Par�metros
*     $P ValorParm - o valor que ser� atribuido ao n� corrente.
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetNaoTemCorrente
*
***********************************************************************/
   
   MAT_tpCondRet MAT_AtribuirValorCorr( MAT_tpMatriz * pMatriz , LIS_tppLista ValorParm ) ;

#undef MATRIZ_EXT

/********** Fim do m�dulo de defini��o: M�dulo matriz **********/

#else
#endif
