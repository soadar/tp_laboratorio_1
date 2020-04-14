/** \brief Muestra menu principal
 *
 * \param x es el primer operando A
 * \param x es el primer operando B
 * \return devuelve la seleccion del usuario
 *
 */
char menuIngreso(int x, int y);


/** \brief Muestra menu calculos
 *
 * \param x es el primer operando A
 * \param x es el primer operando B
 *
 */
void menuCalculos (int x, int y);


/** \brief Muestra menu resultados
 *
 * \param x es el primer operando A
 * \param x es el primer operando B
 *
 */
void menuResultados(int x, int y);

/** \brief realiza la suma del operando A y el operando B
 *
 * \param x es el primer operando A
 * \param x es el primer operando B
 * \return devuelve la suma del operando A y el operando B
 *
 */
int suma(int x, int y);


/** \brief realiza la resta del operando A y el operando B
 *
 * \param x es el primer operando A
 * \param x es el primer operando B
 * \return devuelve la resta del operando A y el operando B
 *
 */
int resta(int x, int y);


/** \brief realiza la multiplicacion del operando A y el operando B
 *
 * \param x es el primer operando A
 * \param x es el primer operando B
 * \return devuelve la multiplicacion del operando A y el operando B
 *
 */
int multiplicacion(int x, int y);


/** \brief realiza el factorial del operando solicitado
 *
 * \param numero es el operando solicitado
 * \return devuelve el factorial del operando solicitado
 *
 */
int factorial (int *pResultado, int numero);


/** \brief realiza la division del operando A y el operando B
 *
 * \param pResultado guarda el resultado del calculo en caso correcto
 * \param x es el primer operando A
 * \param x es el primer operando B
 * \return devuelve 0 si el dato solicitado es correcto, -1 si el dato es invalido
 *
 */
int dividir (float* pResultado, int numero1, int numero2);


/** \brief realiza la comprobacion si el valor ingresado es un dato numerico dentro del rango solicitado
 *
 * \param pResultado guarda el resultado del calculo en caso correcto
 * \param mensaje para que ingrese el dato solicitado
 * \param mensajeError mensaje de error si el valor no esta dentro de lo solicitado
 * \param minimo menor dato valido
 * \param maximo mayor dato valido
 * \param reintentos cantidad de reintentos posibles
 * \return devuelve 0 si el dato solicitado es correcto, -1 si el dato es invalido
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);



/** \brief realiza la comprobacion si el valor ingresado es un caracter valido dentro del rango solicitado
 *
 * \param pResultado guarda el dato ingresado en caso correcto
 * \param mensaje para que ingrese el dato solicitado
 * \param mensajeError mensaje de error si el valor no esta dentro de lo solicitado
 * \param minimo menor dato valido
 * \param maximo mayor dato valido
 * \param reintentos cantidad de reintentos posibles
 * \return devuelve 0 si el dato solicitado es correcto, -1 si el dato es invalido
 *
 */
int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos);
