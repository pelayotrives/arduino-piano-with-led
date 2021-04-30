  // Código creado por Pelayo Trives para la PEC2 de la asignatura Diseño de interacción del Grado en Multimedia de la UOC.
  
  int notas[] = {261,294,330,349,392}; // Declaramos una matriz con la que, posteriormente, podremos ayudarnos para represetar las notas de nuestro piano. La llamaremos notas y estará compuesta de 5 elementos, los cuales son las frecuencias de las notas DO, RE, MI, FA y SOL.
  const int pinAltavoz = 8; // Declaramos esta constante (pues no variará) que será el pin (del Arduino, el número 8) al que conectaremos el piezo (desde la protoboard).
  const int pinLed = 6; // Declaramos esta constante (pues no variará) que será el pin (del Arduino, el número 6) al que conectaremos el LED (desde la protoboard).

  void setup() {
  
  Serial.begin(9600); // Esta instrucción le indica al Arduino que inicie comunicación con el ordenador a una velocidad de 9600 bits por segundo.
  pinMode(pinLed, OUTPUT); // Con esta función vamos a configurar el modo de trabajo del pin utilizado para el LED, en este caso el 6, para que sea de entrada o salida.
  digitalWrite(pinLed, HIGH); // Iniciamos una función que servirá, al iniciar el programa, si el LED funciona. Con esto lo encenderemos.
  delay(2000); // Con esto establecemos que la duración del encendido del LED será 2000 ms.
  digitalWrite(pinLed, LOW); // Con esto el LED se apagará.
  
  }

  void loop() {
  
  int valorAnalogico = analogRead(A0); // Estableceremos una variable llamada valorAnalogico, la cual será el pin A0 de nuestro Arduino, que usaremos para almacenar el valor de dicha clavija (que en principio será 0).
  
  Serial.println(valorAnalogico); // Con esto podremos ver los valores para ajustar las comparativas del if mediante el monitor de serie.

  if (valorAnalogico > 5) { // Aseguramos la comparativa con 5 para evitar falsos positivos.
    digitalWrite(pinLed, HIGH); // Si el valor es superior a 5, el LED se encenderá.
   } else {
    digitalWrite(pinLed, LOW); // Y si no lo es, no se encenderá.
   }
  
  if(valorAnalogico >= 1015 && valorAnalogico <= 1025) { // Además de el LED encenderse, si el valor está entre 1015 y 1025...
    tone(pinAltavoz, notas[0]); // Tocaremos la nota DO (primer valor de la matriz), en parte posible porque el piezo está conectado al pin 8 de nuestro Arduino (pinAltavoz).
   }
   else if(valorAnalogico >= 995 && valorAnalogico <= 1005) { // Además de el LED encenderse, si el valor está entre 995 y 1005...
    tone(pinAltavoz, notas[1]); // Tocaremos RE
   }
   else if(valorAnalogico >= 505 && valorAnalogico <= 515) { // Además de el LED encenderse, si el valor está entre 505 y 515...
    tone(pinAltavoz, notas[2]); // Tocaremos MI
   }
   else if(valorAnalogico >= 690 && valorAnalogico <= 700) { // Además de el LED encenderse, si el valor está entre 690 y 700...
    tone(pinAltavoz, notas[3]); // Tocaremos FA
   }
   else if(valorAnalogico >= 5 && valorAnalogico <= 15) { // Además de el LED encenderse, si el valor está entre 5 y 15...
    tone(pinAltavoz, notas[4]); // Tocaremos SOL
   }
   else {
    noTone(pinAltavoz); // Parará la generación de pulsos, es decir, si esta función no estuviese, al pulsar cualquier botón, no se detendría una vez quitásemos el dedo.
   }
   
  }
