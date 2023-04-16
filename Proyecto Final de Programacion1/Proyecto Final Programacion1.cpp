// Proyecto Final Programación 1 2do Cuatrimestre - Gestion de Vuelos para una Aerolinea
// Profesor: Ricardo Coppo
// Autor: Balot Luciano Nicolas
// Contacto: lnbalot02@gmail.com
// Fecha de entrega: 18-11-22

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <conio.h>

using namespace std;


//Estado de los asientos del avion:
//Asiento vacio = 0
//Asiento reservado = 1
//Asiento confirmado = 2

void Menu_Principal();
void Menu_Reserva();
void Menu_Confirmacion();
void Menu_Cancelar();
void Menu_Avion();
void Menu_Socio();
void Crear_Socio();
void Ver_Socios();
void Agregar_Socio();
void Menu_Info();

int av = 0, clase = 0, asiento = 0, m = 0, av1[49], av2[49], av3[49], i;

struct Datos {
	string Nombre, Apellido, Direccion, Telefono;
}datos;

int main() {

	Menu_Principal();

	system("pause");
	system("cls");

	return 0;

}

void Menu_Principal()
{
	system("cls");
	int OpcionMenu;

	while (1 == 1) {

		//Tttulo del menu principal.
		cout << "-----------------------------------------------" << endl;
		cout << "|                  MENU PRINCIPAL             |" << endl;
		cout << "|                  BALOT AIRLINES             |" << endl;
		cout << "-----------------------------------------------" << endl;

		//Opciones del menu principal.
		cout << "|        1- Reservar un vuelo.                |" << endl;
		cout << "|        2- Confirmar mi reserva.             |" << endl;
		cout << "|        3- Cancelar mi reserva.              |" << endl;
		cout << "|        4- Estado del avion.                 |" << endl;
		cout << "|        5- Mas informacion.                  |" << endl;
		cout << "|        6- Socios.                           |" << endl;
		cout << "|        7- Salir del programa.               |" << endl;
		cout << "-----------------------------------------------" << endl;

		//El usuario elije que opcion desea utilizar del menu principal.
		cout << "\nIngrese que opcion desea realizar: ";
		cin >> OpcionMenu;

		switch (OpcionMenu)
		{
		case 1:
			Menu_Reserva(); //Se abre nuestro menu para hacer una reserva.
			system("pause");
			break;
		case 2:
			Menu_Confirmacion(); //Se abre nuestro menu para confirmar nuestra reserva.
			system("pause");
			break;
		case 3:
			Menu_Cancelar(); //Se abre nuestro menu para cancelar nuestra reserva.
			system("pause");
			break;
		case 4:
			Menu_Avion(); //Se abre nuestro menu para ver el estado de un avion.
			system("pause");
			break;
		case 5:
			Menu_Info(); //Se abre un menu con información variada acerca de la aerolinea.
			system("pause");
			break;
		case 6:
			Menu_Socio(); //Se abre un menu para poder registrarse como socio.
			break;
		case 7:
			exit(EXIT_SUCCESS); //Se cierra el programa.
			break;

		default: //En caso de que el usario escriba mal una opcion, le regresa este mensaje.
			cout << "La opcion ingresada no es valida. Por favor ingrese un numero valido." << endl;
			break;
		}
	}
}

void Menu_Reserva()
{
	system("cls");

	char OpcionReserva;

	for (i = 0; i < 49; i++)

		av1[i] = 0;

	for (i = 0; i < 49; i++)

		av2[i] = 0;

	for (i = 0; i < 49; i++)

		av3[i] = 0;

	cout << "--------------------------------------------------" << endl;
	cout << "|             RESERVA YA MISMO TU VUELO!         |" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "|  CON BALOT AIRLINES VIAJAR ES MUCHO MAS FACIL, |" << endl;
	cout << "|  RESERVA TU VUELO A CUALQUIER PARTE DEL MUNDO! |" << endl;
	cout << "--------------------------------------------------" << endl;

	//Seleccionamos nuestro destino.
	cout << "\n1.- Reservar vuelo a Brasil (Rio de Janeiro)." << endl;
	cout << "2.- Reservar vuelo a Mexico (Playa del Carmen)." << endl;
	cout << "3.- Reservar vuelo a Chile (Valparaiso)." << endl;
	cout << "\nSeleccione una opcion: "; cin >> av;

	//Seleccionamos la clase en la que deseamos viajar.
	cout << "---------------------------------------------------" << endl;
	cout << "|    SELECCIONA EN QUE CLASE TE GUSTARIA VIAJAR    |" << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "\n1.- Viajar en primera clase (Ejecutiva)." << endl;
	cout << "2.- Viajar en segunda clase (Economica)." << endl;
	cout << "\nSeleccione una opcion: "; cin >> clase;

	if (clase == 1) //Si seleccionamos primera clase.
	{
		do {
			cout << "--------------------------------------------------" << endl;
			cout << "|             RESERVA EN PRIMERA CLASE           |" << endl;
			cout << "--------------------------------------------------" << endl;
			cout << "\nSeleccione un asiento entre 0-14: "; cin >> asiento;

			if ((asiento < 0) || (asiento > 14))
				cout << "Error. No existe este asiento en primera clase." << endl; //Error si el asiento no se encuentra dentro del rango de primera clase.

		} while ((asiento < 0) || (asiento > 14));
	}
	else //Si seleccionamos segunda clase.
	{
		do {
			cout << "--------------------------------------------------" << endl;
			cout << "|             RESERVA EN SEGUNDA CLASE           |" << endl;
			cout << "--------------------------------------------------" << endl;
			cout << "Seleccione un asiento entre 15 y 49: "; cin >> asiento;

			if ((asiento < 15) || (asiento > 49))
				cout << "Error. No existe este asiento en segunda clase." << endl; //Error si el asiento no se encuentra dentro del rango de segunda clase.

		} while ((asiento < 15) || (asiento > 49));
	}

	//Reserva de asientos.

	if (av == 1)
	{
		if (av1[asiento] == 0)

		{//AVION 1 - El asiento pasa de 0 a 1 (es decir de disponible a reservado).
			av1[asiento] = 1;
			cout << "\nSu operacion se realizo con exito! Gracias por confiar en Balot Airlines" << endl;
		}
		else
			cout << "\nLo lamentamos. Este asiento no esta disponible!" << endl; //Si elejimos un asiento ocupado.

	}
	if (av == 2)
	{
		if (av2[asiento] == 0)

		{//AVION 2 - El asiento pasa de 0 a 1 (es decir de disponible a reservado).
			av2[asiento] = 1;
			cout << "\nSu operacion se realizo con exito! Gracias por confiar en Balot Airlines" << endl;
		}
		else
			cout << "\nLo lamentamos. Este asiento no esta disponible!" << endl; //Si elejimos un asiento ocupado.
	}

	if (av == 3)
	{
		if (av3[asiento] == 0)

		{//AVION 3 - El asiento pasa de 0 a 1 (es decir de disponible a reservado).
			av3[asiento] = 1;
			cout << "\nSu operacion se realizo con exito! Gracias por confiar en Balot Airlines" << endl;
		}
		else
			cout << "\nLo lamentamos. Este asiento no esta disponible!" << endl; //Si elejimos un asiento ocupado.
	}


}

void Menu_Confirmacion()
{
	system("cls");
	cout << "----------------------------------------------------------------------" << endl;
	cout << "|                          CONFIRMAR MI RESERVA                      |" << endl;
	cout << "|     AVISO: Una vez confirmada, no se puede cancelar la reserva.    |" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "\n1.- Brasil, Rio de Janeiro." << endl;
	cout << "2.- Mexico, Playa del Carmen." << endl;
	cout << "3.- Chile, Valparaiso." << endl;

	cout << "\nIngrese el destino que desea confirmar: "; cin >> av; //Para confirmar primero nos pregunta cual es el destino que queremos confirmar.
	cout << "\nIngrese el numero de asiento: "; cin >> asiento; //Luego nos pregunta cual fue el asiento que elejimos.


	//En el menu de confirmacion, el estado del asiento pasa de 1 a 2 (de RESERVADO a CONFIRMADO).
	if (av == 1)
	{
		if (av1[asiento] == 1)
		{
			av1[asiento] == 2;
			cout << "Su reserva se ha confirmado con exito!" << endl;
		}
		else
			cout << "Parece que el asiento que deseas confirmar no ha sido reservado anteriormente..." << endl; //Si tipeamos un asiento que no fue reservado.
	}

	if (av == 2)
	{
		if (av2[asiento] == 1)
		{
			av2[asiento] == 2;
			cout << "Su reserva se ha confirmado con exito!" << endl;
		}
		else
			cout << "Parece que el asiento que deseas confirmar no ha sido reservado anteriormente..." << endl; //Si tipeamos un asiento que no fue reservado.
	}

	if (av == 3)
	{
		if (av3[asiento] == 1)
		{
			av3[asiento] == 2;
			cout << "Su reserva se ha confirmado con exito!" << endl;
		}
		else
			cout << "Parece que el asiento que deseas confirmar no ha sido reservado anteriormente..." << endl; //Si tipeamos un asiento que no fue reservado.

	}
}

void Menu_Cancelar()
{
	system("cls");

	cout << "---------------------------------------" << endl;
	cout << "|           CANCELA TU RESERVA        |" << endl;
	cout << "---------------------------------------" << endl;
	cout << "\n1.- Brasil, Rio de Janeiro." << endl;
	cout << "2.- Mexico, Playa del Carmen." << endl;
	cout << "3.- Chile, Valparaiso." << endl;

	cout << "\nIngrese el destino que desea cancelar: "; cin >> av;
	cout << "\nIngrese el numero de asiento que desea cancelar: "; cin >> asiento;

	if (av == 1) {

		if (av1[asiento] == 0) {
			cout << "El asiento todavia no ha sido reservado, no se puede cancelar!" << endl;
		}
		if (av1[asiento] == 2) {
			cout << "El asiento ya ha sido confirmado, no se puede cancelar!" << endl;
		}
		else {
			if (av1[asiento] == 1) {
				av1[asiento] = 0;
				cout << "Su reserva ha sido cancelada con exito!" << endl;

			}
		}

	}

	if (av == 2) {

		if (av2[asiento] == 0) {
			cout << "El asiento todavia no ha sido reservado, no se puede cancelar!" << endl;
		}
		if (av2[asiento] == 2) {
			cout << "El asiento ya ha sido confirmado, no se puede cancelar!" << endl;
		}
		else {
			if (av2[asiento] == 1) {
				av2[asiento] = 0;
				cout << "Su reserva ha sido cancelada con exito!" << endl;

			}
		}

	}

	if (av == 3) {

		if (av3[asiento] == 0) {
			cout << "El asiento todavia no ha sido reservado, no se puede cancelar!" << endl;
		}
		if (av3[asiento] == 2) {
			cout << "El asiento ya ha sido confirmado, no se puede cancelar!" << endl;
		}
		else {
			if (av3[asiento] == 1) {
				av3[asiento] = 0;
				cout << "Su reserva ha sido cancelada con exito!" << endl;

			}
		}
	}

}

void Menu_Avion()
{
	system("cls");

	cout << "--------------------------------------------------" << endl;
	cout << "|              VER EL ESTADO DEL AVION           |" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "1.- AVION 1 - Brasil, Rio de Janeiro." << endl;
	cout << "2.- AVION 2 - Mexico, Playa del Carmen." << endl;
	cout << "3.- AVION 3 - Chile, Valparaiso." << endl;
	cout << "\nSeleccione un avion para saber su estado: "; cin >> av; //Seleccionar el avion/destino que queremos ver.

	cout << "--------------------------------------------------" << endl;
	cout << "|             SELECCIONE QUE DESEA VER           |" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "\n1.- Reservas." << endl;
	cout << "2.- Reservas confirmadas." << endl;
	cout << "3.- Asientos disponibles." << endl;
	cout << "\nIngrese una opcion: "; cin >> m;

	if ((av == 1) && (m == 1)) //Avion 1 - Asientos reservados.
	{
		cout << "Los asientos reservados son: " << endl;

		for (i = 0; i <= 49; i++) // Recorrido de los asientos.
		{
			if (av1[i] == 1)

				cout << i << "-";

		}
	}

	else

		if ((av == 1) && (m == 2)) //Avion 1 - Asientos confirmados.
		{
			cout << "Los asientos confirmados son: " << endl;

			for (i = 0; i <= 49; i++)
			{
				if (av1[i] == 2)

					cout << i << "-";
			}

		}
		else

			if ((av == 1) && (m == 3)) //Avion 1 - Asientos disponibles.
			{
				cout << "\nEl/Los asientos disponibles hasta la fecha son: " << endl;

				for (i = 0; i <= 49; i++)
				{
					if (av1[i] == 0)
						cout << i << "-";
				}


			}

	if ((av == 2) && (m == 1)) //Avion 2 - Asientos reservados.
	{
		cout << "Los asientos reservados son: " << endl;

		for (i = 0; i <= 49; i++)
		{
			if (av2[i] == 1)
				cout << i << "-";
		}
	}

	else

		if ((av == 2) && (m == 2)) //Avion 2 - Asientos confirmados.
		{
			cout << "Los asientos confirmados son: " << endl;

			for (i = 0; i <= 49; i++)
			{
				if (av2[i] == 2)

					cout << i << "-";
			}

		}
		else

			if ((av == 2) && (m == 3)) //Avion 2 - Asientos disponibles.
			{
				cout << "\nEl/Los asientos disponibles hasta la fecha son: " << endl;

				for (i = 0; i <= 49; i++)
				{
					if (av2[i] == 0)

						cout << i << "-";
				}

			}

	if ((av == 3) && (m == 1)) //Avion 3 - Asientos reservados.
	{
		cout << "Los asientos reservados son: " << endl;

		for (i = 0; i <= 49; i++)
		{
			if (av3[i] == 1)

				cout << i << "-";
		}
	}

	else

		if ((av == 3) && (m == 2)) //Avion 3 - Asientos confirmados.
		{
			cout << "Los asientos confirmados son: " << endl;

			for (i = 0; i <= 49; i++)
			{
				if (av3[i] == 2)

					cout << i << "-";
			}

		}
		else

			if ((av == 3) && (m == 3)) //Avion 3 - Asientos vacios.
			{
				cout << "\nEl/Los asientos disponibles hasta la fecha son: " << endl;

				for (i = 0; i <= 49; i++)
				{
					if (av3[i] == 0)

						cout << i << "-";
				}
			}
}

void Menu_Info()
{
	system("cls");

	//Dentro de este apartado se mostrara información. (No tiene ninguna funcionalidad, solo mostrar info).
	int Info_Opcion;
	cout << "-----------------------------------------------" << endl;
	cout << "|                MAS INFORMACION              |" << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "|        1- Contacto.                         |" << endl;
	cout << "|        2- Detalles de equipaje.             |" << endl;
	cout << "|        3- Articulos/Elementos prohibidos.   |" << endl;
	cout << "|        4- Volver al menu princiapal.        |" << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "Ingrese que opcion desea realizar: "; cin >> Info_Opcion;
	cout << endl;

	switch (Info_Opcion)
	{

	case 1: //  OPCION 1 - Se abre "acerca de nosotros".
		system("cls");

		cout << "-----------------------------------------------" << endl;
		cout << "|              CONTACTA CON NOSOTROS!         |" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "\n- E-mail: balotairlines@contacto.com " << endl;
		cout << "\n- Reclamos: 0291-7892365 " << endl;
		cout << "\n- Instagram: @balot-airlines " << endl;
		cout << "\n- Fecebook: Balot Airlines " << endl;
		cout << endl;

		system("pause");

		return Menu_Info();

		break;

	case 2: //  OPCION 2 -Se abre "detalles de equipaje".
		system("cls");

		int EquipajesOpc;
		cout << "-----------------------------------------------" << endl;
		cout << "|              DETALLES DE EQUIPAJE           |" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "|        1- Equipaje de mano.                 |" << endl;
		cout << "|        2- Equipaje de bodega.               |" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "\nIngrese una opcion: "; cin >> EquipajesOpc;

		if (EquipajesOpc == 1)
		{
			cout << "-----------------------------------------------" << endl;
			cout << "|               EQUIPAJE DE MANO              |" << endl;
			cout << "-----------------------------------------------" << endl;
			cout << "\nEl equipaje de mano se podra transportar a bordo, sujeto a la disponibilidad de la cabina." << endl;
			cout << "En caso de no poder ser transportado en la misma por temas operativos, se enviara a bodega sin cargo." << endl;
			cout << "\nPeso maximo segun vuelo:" << endl;
			cout << "- Cabotaje: 1 pieza de 8kg" << endl;
			cout << "- Internacionales: 1 pieza de 10kg" << endl;
			cout << endl;

			system("pause");

			return Menu_Info();
		}

		else if (EquipajesOpc == 2)
		{
			cout << "-----------------------------------------------" << endl;
			cout << "|              EQUIPAJE DE BODEGA             |" << endl;
			cout << "-----------------------------------------------" << endl;
			cout << "\nEl equipaje registrado en bodega debe contener SOLO elementos de uso personal." << endl;
			cout << "Solamente se considera como equipaje registrado : una valija, bolso o mochila." << endl;
			cout << "\nPeso maximo segun vuelo:" << endl;
			cout << "- Cabotaje: 1 pieza de 15kg" << endl;
			cout << "- Internacionales: 1 pieza de 23kg" << endl;
			cout << endl;

			system("pause");

			return Menu_Info();

		}

		else {
			cout << "Opcion incorrecta! Por favor ingrese una opcion valida." << endl;
		}
		break;


	case 3: // OPCION 3 - Se abre "elementos prohibidos para llevar".
		cout << "-----------------------------------------------" << endl;
		cout << "|              ELEMENTOS PROHIBIDOS           |" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "\nBaterias - Armas y municiones - Productos inflamables - Garrafa - Objetos punzantes -" << endl;
		cout << "Objetos contundentes - Sustancias quimicas - Explosivos." << endl;
		cout << endl;

		system("pause");

		return Menu_Info();

		break;

	case 4: // OPCION 4 - Nos regresa al menu principal.
		return Menu_Principal();
		break;

	default: // En caso de que el usuario tipee mal una opción.
		cout << "Opcion ingresada invalida. Ingrese un numero correcto." << endl;

		system("pause");

		return Menu_Info();
	}
}

// SOCIOS
void Menu_Socio()
{
	system("cls");

	int OpcionSocio;

	do {
		cout << "---------------------------------------------------" << endl;
		cout << "|            SE PARTE DE BALOT AIRLINES           |" << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "|  HACETE SOCIO DE BALOT AIRLINES Y PARTICIPA DE  |" << endl;
		cout << "|         MILES DE OFERTAS Y PROMOCIONES!         |" << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "|                                                 |" << endl;
		cout << "|            1- Registrarme como socio.           |" << endl;
		cout << "|            2- Agregar un nuevo socio.           |" << endl;
		cout << "|            3- Ver socios ingresados.            |" << endl;
		cout << "|            4- Regresar.                         |" << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "\nIngrese que opcion desea realizar: "; cin >> OpcionSocio;

		switch (OpcionSocio)
		{
		case 1:
			Crear_Socio();
			system("pause");
			break;

		case 2:
			Agregar_Socio();
			break;

		case 3:
			Ver_Socios();
			system("pause");
			break;

		case 4:
			return Menu_Principal();
			break;

		default:
			cout << "Opcion ingresada inconrrecta! Por favor ingrese una opcion valida." << endl;
			break;
		}
		system("cls");

	} while (OpcionSocio != 4);
}

void Crear_Socio()
{
	system("cls");

	char Rta;
	ofstream archivosocio;

	archivosocio.open("Socios.txt", ios::out); // Abrimos el archivo en modo escritura.

	if (archivosocio.fail()) {
		cout << "No se pudo crear el archivo!" << endl; // Si el archivo no se puede abrir, devuelve este mensaje.
		exit(1);
	}

	do {
		cout << "------------------------------------------------------------------------" << endl;
		cout << "|     PARA SER PARTE DE BALOT AIRLINES NECESITAMOS ALGUNOS DATOS...    |" << endl;
		cout << "------------------------------------------------------------------------" << endl;
		cout << " ";
		getline(cin, datos.Nombre);

		cout << "\n- Ingrese el Nombre y Apellido: ";
		getline(cin, datos.Apellido);

		cout << "\n- Ingrese una direccion: ";
		getline(cin, datos.Direccion);

		cout << "\n- Ingrese un numero telefonico: ";
		getline(cin, datos.Telefono);

		archivosocio << "- Nombre y Apellido: " << datos.Apellido << endl;
		archivosocio << "- Direccion: " << datos.Direccion << endl;
		archivosocio << "- Telefono: " << datos.Telefono << endl;

		cout << "--------------------------------------------------" << endl;
		cout << "|           SOCIO REGISTRADO EXITOSAMENTE!       |" << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "\nDesea registrar un nuevo socio? (SI-NO):"; cin >> Rta;

	} while (Rta == 'S' || Rta == 's');

	archivosocio.close(); // Se cierra el archivo .txt

}

void Agregar_Socio()
{
	system("cls");

	char Rpta;
	ofstream archivosocio;

	archivosocio.open("Socios.txt", ios::app); //Abrimos el archivo en modo "añadir", ios::app --> append.

	if (archivosocio.fail())
	{
		cout << "No se pudo abrir el archivo." << endl;
		exit(1);
	}
	do {
		cout << "------------------------------------------------------------------------" << endl;
		cout << "|     PARA SER PARTE DE BALOT AIRLINES NECESITAMOS ALGUNOS DATOS...    |" << endl;
		cout << "------------------------------------------------------------------------" << endl;

		cout << "";
		getline(cin, datos.Nombre);

		cout << "\n- Ingrese el Nombre y Apellido: ";
		getline(cin, datos.Apellido);

		cout << "\n- Ingrese una direccion: ";
		getline(cin, datos.Direccion);

		cout << "\n- Ingrese un numero telefonico: ";
		getline(cin, datos.Telefono);

		cout << endl;
		archivosocio << "               " << endl;
		archivosocio << "- Nombre y Apellido: " << datos.Apellido << endl;
		archivosocio << "- Direccion: " << datos.Direccion << endl;
		archivosocio << "- Telefono: " << datos.Telefono << endl;

		cout << "--------------------------------------------------" << endl;
		cout << "|           SOCIO REGISTRADO EXITOSAMENTE!       |" << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "\nDesea registrar un nuevo socio? (SI-NO):"; cin >> Rpta;


	} while (Rpta == 'S' || Rpta == 's');

	archivosocio.close(); // Se cierra el archivo .txt


}

void Ver_Socios()
{
	system("cls");
	string texto;

	ifstream archivosocio; //Como no vamos a escribir nada, usamos IFSTREAM en lugar de OFSTREAM.

	archivosocio.open("Socios.txt", ios::in); // Abrimos el archivo en modo lectura.

	cout << "--------------------------------------------------" << endl;
	cout << "|           LISTA DE SOCIOS REGISTRADOS:         |" << endl;
	cout << "--------------------------------------------------" << endl;

	if (archivosocio.fail())
	{
		cout << "No se pudo abrir el archivo." << endl;
		exit(1);
	}

	while (!archivosocio.eof()) // Mientras no sea el final del archivo.
	{
		cout << endl;
		getline(archivosocio, texto);
		cout << texto << endl;

	}
	archivosocio.close();
}