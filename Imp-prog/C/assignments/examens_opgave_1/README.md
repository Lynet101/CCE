Skriv et program der modellerer en simpel regnemaskine. Regnemaskinen holder styr på ét enkelt tal af typen double, som indholder det hidtidigt beregnede resultat. Dette tal kaldes akkumulatoren. Akkumulatores startværdi er 0.0. I en simpel, iterativ dialog med brugeren udføres der forskellige beregninger på akkumulatoren. Disse beregninger kan være styret af unære eller binære operatorer, som i denne opgave alle noteres med netop ét tegn.

Unære operationer (som står foran sin operand, og derfor er prefix) udfører en beregning på akkmulatoren:

      operator akkumulator

Binære operationer udfører en beregning på akkulatoren og en ekstra operand på følgende måde:

      akkumulator operator højre_opperand

I begge tilfælde lægges værdien af udtrykket tilbage i akkumulatoren.

Det anbefales at operationen, som regnemaskinen skal udføre, indlæses som en char med scanf. Binære operatorer kræver en operand, der indlæses som en double af scanf.

Du skal have en funktion, scan_data, med to output parametre, som returnerer en operator og en mulig højre operand fra en datalinje. Hvis der anvendes en unær operator sættes operanden blot til 0.0.

Du skal også have en funktion, do_next_op, som udfører den påkrævede operation: do_next_op skal have to input parametre (operator og operand) foruden akkumulatoren, som både skal kunne bruges til input og output (og som derfor skal være en pointer). Operanden ignoreres for unære operatorer.

Regnemaskinens samlede dialog skal indkapsles i en funktion, run_calculator, som skal returnere slutværdien af akkumulatoren.

Overvej også at skrive en boolsk funktion, der kan afgøre om en operator (af typen char) er binær.

Her er de gyldige binære operatorer i regnemaskinen:

  +    for addition af akkumulatoren med operanden
  -    for subtraktion af akkumulatoren med operanden
  *    for multiplikation af akkumulatoren med operanden
  /    for division af akkumulatoren med operanden
  ^    for potensopløftning af akkumulatoren med operanden

Og her er de gyldige unære operatorer:

  #    for kvadratroden af akkumulatoren
  %    for at vende fortegnet af akkumulatoren
  !    for at dividere 1 med akkumulatoren
  q    for at afslutte regnemaskinen med slutresultatet

Din regnemaskine skal nægte at tage kvadratroden af et negativt tal, og den skal nægte at dividere med nul. I tilfælde af en sådan ulovlig operation, skal akkumulatoren blot efterlades uændret. Der skal ikke udskrives fejlmeddelelser.

Din regnemaskine skal vise den akkumulerede værdi efter hver operation.



## Ønskede funktioner
    • run_calculator
        - Abstraherer og indkapsler dialogen i den samlede regnemaskine
    • scan_data
        - Abstraherer indlæsning
        - Skal indlase en operator
        - Skal ogsa indlase en operand his operatoren er binar
        - To output parametre
    • do_next_op
        - Input: operator og operand
        - Input/output: akkumulatoren
    • En boolsk funktion der afgor om en operator er binæer
        - En input: Operatoren 
