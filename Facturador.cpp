/*
Programa de facturas
10/10/2023  03:19
*/
#include <iostream>
#include <string>
using namespace std;
int ope,ope1;
string nom,nom1,ape,ape1,fecha;
int cog,registros,cel,regi;
int contra=24052022,conta;
int intentos=3;
void estructura ( ){ 
	
struct Producto {
	int idProducto;
	string nombre;
	string precio;
	string fecha_caducidad;
	};
	Producto productos[6] = {
		{001, "Cargador tipo C ", "Q.50.00", " " },
		{002, "Baterias para reloj", "Q.25.00", "20/10/25"},
		{003, "Cargador tipo V8 ", "Q.50.00", " " },
		{004, "Bocina JBL Para Oficina ", "Q.300.00", " " },
		{005, "Luces Led Para Decorar tu Habitacion", "Q.250.00", " " },
		{006, "Cigarros Electronicos 1000 plus ", "Q.150.00", " " }
	};
	
	for (int i = 0; i < 6; i++) {
        cout << "ID: " << productos[i].idProducto << endl;
        cout << "Nombre: " << productos[i].nombre << endl;
        cout << "Precio: " << productos[i].precio << endl;
        if (!productos[i].fecha_caducidad.empty()) {
            cout << "Fecha de Caducidad: " << productos[i].fecha_caducidad << endl;
        }// fin del if
    }// fin del for
	
}// fin de void de estructura

bool ingresarContrasena( ){
	for(int intento = 0; intento <3; intento ++ ){
		cout<<"Ingrese Contraseña Para Ingresar Para Registrar Nuevos Productos: ";
		cin>>conta;
		if(conta==contra ){
			return true;
		}else {
			cout<<"Contraseña Incorrecta Intente de Nuevo: " << intento +1 << " de 3 "<< endl;
		}
	}// fin de for de intentos
	cout << "Has agotado tus intentos de contraseña." << endl;
    return false;
}
void nuevosProductos( ){
	cout<<"Cuantos Productos Quiere Ingresar: ";
	cin>>regi;
	struct newProduc {
	int idProducto;
	string nombre;
	string precio;
	string fecha_caducidad;
	};// fin de la estructura de nuevos productos
    newProduc nuevosProductos[regi];

    for (int i = 0; i < regi; i++) {
        cout << "Ingrese Id De Producto " << i + 1 << ": ";
        cin >> nuevosProductos[i].idProducto;
        cout << "Ingrese Nombre del Producto: ";
        cin.ignore(); // Ayuda para ignorar el salto de línea pendiente
        getline(cin, nuevosProductos[i].nombre);
        cout << "Ingrese Precio: ";
        cin >> nuevosProductos[i].precio;
        cout << "Tiene Fecha de Caducidad Ingrese (si/no): ";
        cin >> fecha;
        if (fecha == "si") {
            cout << "Ingrese fecha de Caducidad: ";
            cin >> nuevosProductos[i].fecha_caducidad;
        }// fin del if de si
    }// fin del for
}// fin de la funcion para Nuevos Productos


int main(){

	cout<<"=========================================================================" << endl;
	cout<<"=========================================================================" << endl;
	cout<<"¡Bienvenido, al Facturador " << endl;
	cout<<" de Empresa Chapina S.A Dedicada a La venta Acesesorios electronicos " << endl;
	cout<<"=========================================================================" << endl;
	cout<<"=========================================================================" << endl;
	cout<<"Que Operacion Quieres Realizar " << endl;
	cout<<"1.¡Clientes! "<< endl;
    cout<<"2.¡Productos! "<< endl;
    cout<<"3.¡Ventas! "<< endl;
    cout<<"4.¡inventario! "<< endl;
    cout<<"5. ¡Proveedores! "<< endl;
	cin>>ope;
	cout<<"============================================" << endl;
	cout<<"============================================" << endl;
	
	switch (ope){
		case 1 :
			system("cls");
			cout<<"================================================== " << endl;
			cout<<"!Bienvenido al menu de Clientes! " << endl;
			cout<<"================================================== " << endl;
			cout<<"Cuantos Cientes Quieres Registar " << endl;
			cin>>registros;
			cout<<" " << endl;
			for(int i=1; i<=registros;  i++){
				cout<<"Ingrese Codigo De Identficacion " << endl;
				cin>>cog;
				cout<<"Ingrese El Nombre " << endl;
				cin>>nom;
				cin>>nom1;
				cout<<"Ingrese apellidos " << endl;
				cin>>ape;
				cin>>ape1;
				cout<<"Ingrese Su Numero Telefonico: "  << endl;
				cin>>cel;
			}
			 break;
		case 2:
		int ope1;
		system("cls");
	        cout<<"================================================== " << endl;	
			cout<<"!Bienvenido al menu de Productos " << endl;
			cout<<"===================================================" << endl;
			cout<<"Elija Tu Operacion a Realizar " << endl;
			cout<<"1.Quieres Ver Los Productos en Existencia " << endl;
			cout<<"2.Ingresar Nuevos Productos " << endl;
			cin>>ope1;
			switch (ope1){
				case 1: 
				cout<<"========================================================= " << endl; 
				cout<<"Bienvenido al Menú de Productos Ahora Verás Nuestros Productos en Existencia " << endl;
				cout<<"========================================================= " << endl; 
				estructura ( );
				break;
				case 2:
				if(ingresarContrasena()){
					nuevosProductos( );
				
				}else{
					cout<<"Contraseña Incorrecta. Intentod Agutados";
				}
				break;
			default:
				cout<<"Opcion no Valida " << endl;
	}//fin de switch de Operacion 1
			
			 break;
		
     	case 3: 
		system("cls");
		    cout<<"================================================== " << endl;
			cout<<"!Bienvenido al menu de Ventas " << endl;
			cout<<"================================================== " << endl;
			 break;
		
		case 4: 
		system("cls");
		    cout<<"================================================== " << endl;
			cout<<"!Bienvenido al menu de Iventario " << endl;
			cout<<"================================================== " << endl;
				while (true) {
                cout << "1. Ver inventario de productos" << endl;
                cout << "2. Salir" << endl;
                int opcion;
                cin >> opcion;
                switch (opcion) {
        case 1:
               mostrarInventario(inventario);
            break;
        case 2:
            return 0;
            default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
            break;
                }
            }
            break;
		
		case 5: 
		system("cls");
		    cout<<"================================================== " << endl;
			cout<<"!Bienvenido al menu de Proveedores" << endl;
			cout<<"================================================== " << endl;
			struct Proveedor {
        int idProveedor;
        string nombreProveedor;
        string productosSuministrados;
    };

    vector<Proveedor> proveedores;

    while (true) {
        cout << "1. Ver proveedores de productos electronicos" << endl;
        cout << "2. Registrar nuevo proveedor" << endl;
        cout << "3. Salir" << endl;
        int opcion;
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Proveedores registrados:" << endl;
                for (const Proveedor& proveedor : proveedores) {
                    cout << "ID: " << proveedor.idProveedor << endl;
                    cout << "Nombre: " << proveedor.nombreProveedor << endl;
                    cout << "Productos suministrados: " << proveedor.productosSuministrados << endl;
                    cout << "-----------------------------" << endl;
		 vector<Proveedor> proveedores;  // Almacenar proveedores

    // Agregar proveedores de productos electrónicos
    proveedores.push_back({1, "TecnoSuministros SA", "Cargadores, Baterías, Cables"});
    proveedores.push_back({2, "ElectroMega Distribuciones", "Componentes electrónicos, Cables, Accesorios"});
    proveedores.push_back({3, "Innovatech Pro", "Dispositivos móviles, Accesorios"});
    proveedores.push_back({4, "Elexpress Soluciones", "Electrónica industrial, Componentes"});
    proveedores.push_back({5, "ElectroniWorld", "Electrónica de consumo, Gadget"});
    
    // Mostrar los proveedores registrados
    cout << "Proveedores registrados de productos electrónicos:" << endl;
    for (const Proveedor& proveedor : proveedores) {
        cout << "ID: " << proveedor.idProveedor << endl;
        cout << "Nombre: " << proveedor.nombreProveedor << endl;
        cout << "Productos suministrados: " << proveedor.productosSuministrados << endl;
        cout << "-----------------------------" << endl;
    }

    return 0;
    }
                }
                break;

            case 2:
                Proveedor nuevoProveedor;
                cout << "Ingrese el ID del nuevo proveedor: ";
                cin >> nuevoProveedor.idProveedor;
                cout << "Ingrese el nombre del proveedor: ";
                cin.ignore();
                getline(cin, nuevoProveedor.nombreProveedor);
                cout << "Ingrese los productos suministrados por el proveedor: ";
                getline(cin, nuevoProveedor.productosSuministrados);
                proveedores.push_back(nuevoProveedor);
                cout << "Nuevo proveedor registrado con éxito." << endl;
                break;

            
                return 0;
                

            
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
        }
    }
    break;
			
			 break;
	}	
	
	system("pause");
	return 0;	
	
}
