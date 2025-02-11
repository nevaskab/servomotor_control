<h1 align = "center">Controle de servomotor utilizando simulador Wokwi e placa Pi Pico W.</h1>

<p align = "center">O projeto apresentado utiliza simulador wokwi para controlar um servomotor em placa Pi Pico W.</p>

---
<h3>🎯 Objetivos</h3>
<p>O programa desenvolvido em Linguagem C para placa Pi Pico W tem como principais objetivos:</p>

- ☑️ Ajustar o braço a 180° e esperar 5 segundos
- ☑️ Ajustar o braço a 90° e esperar 5 segundos
- ☑️ Ajustar o braço a 0° e esperar 5 segundos
- ☑️ Desenvolver um movimento contínuo suave de 0° a 180°
- ☑️ Extra: Testar o código utilizando o LED Azul (GPIO 12)
  
---
<h3>🛠️ Ferramentas</h3>

  - Simulador Wokwi implementado ao ambiente VScode
  - Ferramentas CMake e Pico SDK instaladas
  - Extra: placa BitDogLab
---

<h3>🚀 Utilizando o programa</h3>

Siga as etapas a seguir:
- Clone o repositório usando o comando abaixo
    
	```gitconfig
	git clone https://github.com/nevaskab/servomotor_control.git
	```
  
- Compile e Rode o código <br>

 	![Captura de tela 2025-01-19 150112](https://github.com/user-attachments/assets/62fbcc03-5653-4826-be75-316d8e6581bb)

- Inicie a simulação no arquivo "diagram.json"

	![image](https://github.com/user-attachments/assets/91df9d25-d9d3-487c-85a3-6a5984bef813)

 	- Extra: Caso queira testar o que acontece com o LED Azul, faça o que está descrito no bloco abaixo

  ```c
	//Comente a linha do pino 22 (GPIO do servomotor) e descomente a linha do pino 12 (GPIO do LED RGB na cor Azul)
	//define SERVO_PIN 22
	#define SERVO_PIN 12
  ```
	- Conecte a placa ao computar com o modo Bootsel ativado, compile e rode.
---

<h2>Para mais detalhe sobre o funcionamento...</h2>
Visite: 

### Autor
---
<a><img style="border-radius: 50%;" src="https://avatars.githubusercontent.com/u/133506658?s=400&u=add96d4ebb6071b0473386091845a1509b3de27b&v=4" width="100px;" alt=""/>
<br />
<sub><b>Andressa Martins</b></sub></a>

Feito por Andressa Martins. Entre em contato <3.

<a href="mailto:andressa.devsystem@gmail.com"><img alt="Static Badge" src="https://img.shields.io/badge/andressa.devsystem%40gmail.com-black?style=flat&logo=gmail&logoColor=%23EA4335&logoSize=auto&color=EDF2F4"></a>
