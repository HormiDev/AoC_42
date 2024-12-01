## --- Día 1: Histeria del historiador ---
El Historiador en Jefe siempre está presente en el gran lanzamiento del trineo de Navidad, ¡pero nadie lo ha visto en meses! Lo último que se supo de él fue que estaba visitando lugares que son históricamente importantes para el Polo Norte; un grupo de Historiadores Superiores le ha pedido que los acompañe mientras revisan los lugares que creen que es más probable que visite.

A medida que se marca cada ubicación, la marcarán en su lista con una estrella . Suponen que el Historiador en jefe debe estar en uno de los primeros cincuenta lugares que buscarán, así que para salvar la Navidad, debes ayudarlos a obtener cincuenta estrellas en su lista antes de que Papá Noel se vaya el 25 de diciembre.

Consigue estrellas resolviendo acertijos. Cada día del calendario de Adviento habrá dos acertijos disponibles; el segundo se desbloqueará al completar el primero. Cada acertijo otorga una estrella . ¡Buena suerte!

Aún no te has ido y el grupo de historiadores élficos de alto rango ya se ha topado con un problema: su lista de ubicaciones para revisar está vacía . Finalmente, alguien decide que el mejor lugar para revisar primero sería la oficina del historiador jefe.

Al llegar a la oficina, todos confirman que el Historiador en Jefe no se encuentra en ninguna parte. En cambio, los elfos descubren una variedad de notas y listas de lugares históricamente importantes. Esta parece ser la planificación que el Historiador en Jefe estaba haciendo antes de irse. ¿Quizás estas notas se puedan usar para determinar qué lugares buscar?

En toda la oficina del jefe, los lugares de importancia histórica no están enumerados por su nombre, sino por un número único llamado ID de ubicación . Para asegurarse de que no se les pase nada por alto, los historiadores se dividieron en dos grupos, cada uno de los cuales buscó en la oficina e intentó crear su propia lista completa de ID de ubicación.

Hay un solo problema: al colocar las dos listas una al lado de la otra (la entrada de tu rompecabezas), rápidamente se hace evidente que no son muy similares. ¿Quizás puedas ayudar a los Historiadores a conciliar sus listas?

Por ejemplo:
```
3   4
4   3
2   5
1   3
3   9
3   3
```
¡Tal vez las listas solo tengan una pequeña diferencia! Para averiguarlo, empareja los números y mide la distancia entre ellos. Empareja el número más pequeño de la lista de la izquierda con el número más pequeño de la lista de la derecha , luego el segundo número más pequeño de la izquierda con el segundo número más pequeño de la derecha , y así sucesivamente.

Dentro de cada par, calcula la distancia entre los dos números; tendrás que sumar todas esas distancias . Por ejemplo, si emparejas un 3de la lista de la izquierda con un 7de la lista de la derecha, la distancia entre ellos es 4; si emparejas un 9con un 3, la distancia entre ellos es 6.

En la lista de ejemplo anterior, los pares y las distancias serían los siguientes:

El número más pequeño de la lista de la izquierda es 1y el número más pequeño de la lista de la derecha es 3. La distancia entre ellos es 2.
El segundo número más pequeño de la lista de la izquierda es 2, y el segundo número más pequeño de la lista de la derecha es otro 3. La distancia entre ellos es 1.
El tercer número más pequeño en ambas listas es 3, por lo que la distancia entre ellos es 0.
Los siguientes números que se deben emparejar son 3y 4, una distancia de 1.
Los quintos números más pequeños en cada lista son 3y 5, una distancia de 2.
Finalmente, el número más grande en la lista de la izquierda es 4, mientras que el número más grande en la lista de la derecha es 9; estos están 5separados por una distancia.
Para encontrar la distancia total entre la lista de la izquierda y la de la derecha, suma las distancias entre todos los pares que encontraste. En el ejemplo anterior, esto es 2 + 1 + 0 + 1 + 2 + 5, ¡una distancia total de 11!

Tus listas de izquierda y derecha contienen muchos identificadores de ubicación. ¿Cuál es la distancia total entre tus listas?

La respuesta de tu rompecabezas fue 1879048.

## --- Segunda parte ---
Su análisis no hizo más que confirmar lo que todos temían: las dos listas de identificaciones de ubicación son realmente muy diferentes.

¿O sí?

Los historiadores no se ponen de acuerdo sobre qué grupo cometió los errores ni sobre cómo leer la mayor parte de la letra del jefe, pero en medio de la conmoción se nota un detalle interesante: ¡ en ambas listas aparecen muchos identificadores de ubicación! Tal vez los otros números no sean identificadores de ubicación en absoluto, sino más bien letras malinterpretadas.

Esta vez, deberás averiguar exactamente con qué frecuencia aparece cada número de la lista de la izquierda en la lista de la derecha. Calcula un puntaje de similitud total sumando cada número de la lista de la izquierda después de multiplicarlo por la cantidad de veces que ese número aparece en la lista de la derecha.

Aquí están nuevamente las mismas listas de ejemplos:
```
3   4
4   3
2   5
1   3
3   9
3   3
```
Para estas listas de ejemplo, este es el proceso para encontrar el puntaje de similitud:

El primer número de la lista de la izquierda es 3. Aparece en la lista de la derecha tres veces, por lo que el puntaje de similitud aumenta en .3 * 3 = 9
El segundo número de la lista de la izquierda es 4. Aparece una vez en la lista de la derecha, por lo que el puntaje de similitud aumenta en .4 * 1 = 4
El tercer número de la lista de la izquierda es 2. No aparece en la lista de la derecha, por lo que el puntaje de similitud no aumenta ( 2 * 0 = 0).
El cuarto número, 1, tampoco aparece en la lista correcta.
El quinto número, 3, aparece en la lista de la derecha tres veces; el puntaje de similitud aumenta en 9.
El último número, 3, aparece en la lista de la derecha tres veces; el puntaje de similitud aumenta nuevamente en 9.
Entonces, para estas listas de ejemplo, el puntaje de similitud al final de este proceso es 31( 9 + 4 + 0 + 0 + 9 + 9).

Considere nuevamente las listas de la izquierda y la derecha. ¿Cuál es su índice de similitud?

La respuesta de tu rompecabezas fue 21024792.

¡Ambas partes de este rompecabezas están completas! Te dan dos estrellas doradas: **