/*
Programa de facturas
10/10/2023  03:19
*/
#include <iostream>
#include <string>
#include <vector> // libreria para crear vectores
#include <ctime>// libreria para las fechas
#include <fstream>// Libreria para leer archivo 
#include <iomanip>// Permite controlar la forma en que los datos se muestran en la salida estándar, como la consola, archivos y otros flujos de salida
using namespace std;
int ope,ope1;
double precio = 45.0;
string nom,nom1,ape,ape1,fecha;
int cog,registros,cel,regi;
int contra=24052022;
int conta,ope0;
int intentos=3;

// struct para ingresar Nuevos Clientes 
struct Cliente{
	int id;
	string nombre;
	string apellidos;
	int cel;
};

// Funcion para ingresar NueVo Cliente

// Función para ingresar un nuevo cliente y guardarlo en un archivo
void ingresarYGuardarCliente(vector<Cliente>& clientes) {
    Cliente nuevoCliente;
    cout << "Ingrese el ID del cliente: ";
    cin >> nuevoCliente.id;
    cout << "Ingrese el nombre del cliente: ";
    cin.ignore();
    getline(cin, nuevoCliente.nombre);
    cout << "Ingrese los apellidos del cliente: ";
    getline(cin, nuevoCliente.apellidos);
    cout << "Ingrese el número de celular del cliente: ";
    cin >> nuevoCliente.cel;

    clientes.push_back(nuevoCliente); // Agregar el nuevo cliente al vector

    // Guardar el cliente en el archivo "Clientes.txt"
    ofstream archivo("Clientes.txt", ios::app); // Abrir el archivo en modo "append"
    if (archivo.is_open()) {
        archivo << "Código: " << nuevoCliente.id << endl;
        archivo << "Nombre: " << nuevoCliente.nombre << " " << nuevoCliente.apellidos << endl;
        archivo << "Número de celular: " << nuevoCliente.cel << endl;
        archivo << "-----------------------------" << endl;
        archivo.close(); // Cerrar el archivo
        cout << "Cliente registrado y guardado correctamente." << endl;
    } else {
        cout << "No se pudo abrir el archivo para escritura." << endl;
    }
}// fin de la funcion para mostrar los clientes 

// Estructura para los Nuevos Productos
struct Producto {
    int idProducto;
    string Producnombre;
    double Producprecio;
    string fecha_caducidad;
    string fecha_ingreso;
    int Produccantidad;
};

// Función para obtener la fecha actual
string obtenerFechaActual() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d/%m/%Y", &tstruct);
    return buf;
}

// Función para ingresar y Guardar el contenido de un archivo
void ingresarYGuardarProductos(vector<Producto>& inventario){
    Producto nuevoProducto;
    cout<<"Ingrese El Id Del Producto: ";
    cin>>nuevoProducto.idProducto;
    cout<<"Ingrese Nombre de Producto: ";
    cin.ignore();
    getline(cin,nuevoProducto.Producnombre);
    cout<<"Ingrese Precio del Producto: ";
    cin>>nuevoProducto.Producprecio;
    cout<<"Tiene Fecha de Caducidad: (si/no): ";
    cin>>nuevoProducto.fecha_caducidad;
    
    if(nuevoProducto.fecha_caducidad== "si" ||nuevoProducto.fecha_caducidad=="Si"){
        cout << "Ingrese la fecha de caducidad (dd/mm/aaaa): ";
        cin >> nuevoProducto.fecha_caducidad;
    }
    nuevoProducto.fecha_ingreso=obtenerFechaActual();
    cout << "Ingrese la cantidad en stock: ";
    cin >> nuevoProducto.Produccantidad;

    inventario.push_back(nuevoProducto);
    
    ofstream archivo("Producto.txt", ios::app);
    if(archivo.is_open( )){
        archivo<<" Id :" << nuevoProducto.idProducto<< endl;
        archivo<<"Nombre de Producto: " << nuevoProducto.Producnombre<<endl;
        archivo<<"Precio del Producto: "<< nuevoProducto.Producprecio<< endl;
        if(!nuevoProducto.fecha_caducidad.empty( )){
          archivo<<"Fecha de Caducidad: " << nuevoProducto.fecha_caducidad<< endl;
        }
        archivo<<"Fecha de Ingreso: " << nuevoProducto.fecha_ingreso<< endl;
        archivo<<"Cantidad De Productos: "<< nuevoProducto.Produccantidad<<endl;
        if(nuevoProducto.fecha_ingreso== obtenerFechaActual()){
            cout<<"Nueva Mercadería. " << endl;
        }
        cout<<"-----------------------------------------" << endl;
        archivo.close( );// cierra el archivo
        cout<<"Nuevos Productos Ingresados Correctamente...!!" << endl;
    }else {
        cout<< "No se puede Abrir el archivo " << endl;
        
    }
    
}// fin de la funcion para mostrar los Productos.
//============================================================
// Estructura para Inventario
//===========================================================

void mostrarInventario(const vector<Producto>& inventario){
	cout<<"Invenatrio de Productos " << endl;
	
	if(inventario.empty()){
		cout<<"No hay productos en el Inventario." << endl;
	}else{
		for(const Producto& prod : inventario ){
			cout << "Id " << prod.idProducto<< endl;
			cout << "Nombre: " << prod.Producnombre << endl;
            cout << "Precio: " << prod.Producprecio << endl;
       if(!prod.fecha_caducidad.empty()){
       	cout<<"Fecha de Caducidad " << prod.fecha_caducidad << endl;
	   }
	        cout << "Cantidad en Stock: " << prod.Produccantidad << endl;
            cout << "Fecha de Ingreso: " << prod.fecha_ingreso << endl;
            cout << "---------------------------" << endl;
		}
		
	}	
}// fin de funcion para Mostrar los Productos en el inventario 

 // Función para cargar los productos desde el archivo al vector inventario
void cargarInventarioDesdeArchivo(vector<Producto>& inventario) {
    ifstream archivo("Producto.txt");
    if (archivo.is_open()) {
        inventario.clear(); // Limpiar el vector antes de cargar los datos
        Producto producto;

        while (archivo >> producto.idProducto >> producto.Producnombre >> producto.Producprecio >> producto.fecha_caducidad >> producto.fecha_ingreso >> producto.Produccantidad) {
           // verifica si la fecha de ingreso esta presente o no esta presente
           if (producto.fecha_ingreso.empty() || producto.fecha_ingreso != obtenerFechaActual()){
           	producto.fecha_ingreso = obtenerFechaActual();
		   }
		    inventario.push_back(producto);
        }

        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para lectura." << endl;
    }
}
void tablaProductos(const vector<Producto>& inventario) {
    if (inventario.empty()) {
        cout << "No hay productos en el Inventario." << endl;
    } else {
        cout << "=========================================================================================================" << endl;
        cout << "ID  | Nombre del Producto              | Precio  | Fecha de Caducidad | Cantidad en Stock | Fecha de Ingreso" << endl;
        cout << "=========================================================================================================" << endl;
// esto nos Permite controlar la forma en que los datos se van a  muestrar en la salida a la consola
        for (const Producto& prod : inventario) {
            cout << setw(4) << prod.idProducto << " | " << left << setw(30) << prod.Producnombre << " | " << right << setw(7) << prod.Producprecio << " | ";
            if (!prod.fecha_caducidad.empty()) {
                cout << left << setw(18) << prod.fecha_caducidad;
            } else {
                cout << left << setw(18) << "N/A";
            }
            cout << " | " << right << setw(17) << prod.Produccantidad << " | " << prod.fecha_ingreso << endl;
        }

        cout << "=========================================================================================================" << endl;
    }
}


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
}//  fin de La funcion

//============================================================
// Estructura para Proveedores
//===========================================================

struct Proveedor {
    int idProveedor;
    string nombreProveedor;
    string productosSuministrados;
    int cel;
};
            
 // Funcion para ingresar NueVo Proveedor

// Función para ingresar un nuevo proveedor y guardarlo en un archivo
void mostrarProveedores(vector<Proveedor>& proveedores) {
    Proveedor nuevoProveedor;
    cout << "Ingrese el ID del proveedor: ";
    cin >> nuevoProveedor.idProveedor;
    cout<<  "Ingrese el nombre de La Empresa: ";
    cin.ignore();
    getline(cin, nuevoProveedor.nombreProveedor);
    cout << "Ingrese los Productos que Suministra: ";
    getline(cin, nuevoProveedor.productosSuministrados);
    cout << "Ingrese el número de celular del proveedor: ";
    cin >> nuevoProveedor.cel;

    proveedores.push_back(nuevoProveedor); // Agregar el nuevo proveedor al vector

    // Guardar el proveedor en el archivo "proveedores.txt"
    ofstream archivo("Proveedores.txt", ios::app); // Abrir el archivo en modo "append"
    if (archivo.is_open()) {
        archivo << "Código: " << nuevoProveedor.idProveedor << endl;
        archivo << "Nombre: " << nuevoProveedor.nombreProveedor << endl;
        archivo << "Productos: " << nuevoProveedor.productosSuministrados << endl;
        archivo << "Número de celular: " << nuevoProveedor.cel << endl;
        archivo << "-----------------------------" << endl;
        archivo.close(); // Cerrar el archivo
        cout << "Proveedor registrado y guardado correctamente." << endl;
    } else {
        cout << "No se pudo abrir el archivo para escritura." << endl;
    }
}// fin de la funcion para mostrar los proveedores

// =================================================================
// estrutura para las  ventas 
//==================================================================

// Agrega un parámetro para pasar el inventario a la función ventas
void ventas(vector<Producto>& inventario) {
    char opc;
    int cantidad;
    double totalVenta = 0.0;

    do {
        system("cls");
        cout << "***********************VENTAS*************************" << endl
             << endl;
        cout << "Productos en inventario: " << endl;
        tablaProductos(inventario);

        int idProducto;
        cout << "Ingrese el ID del producto que desea comprar: ";
        cin >> idProducto;

        // Buscar el producto en el inventario
        for (auto& producto : inventario) {
            if (producto.idProducto == idProducto) {
                cout << "Producto seleccionado: " << producto.Producnombre << " - Precio por unidad: " << precio << endl;
                cout << "Ingrese la cantidad que desea comprar: ";
                cin >> cantidad;

                if (cantidad <= 0 || cantidad > producto.Produccantidad) {
                    cout << "Cantidad no válida. Verifique el inventario." << endl;
                    system("pause");
                    return;
                }

                // Actualizar inventario y registrar las ventas que se van hacer 
                producto.Produccantidad -= cantidad;
                double subtotal = cantidad * precio;
                totalVenta += subtotal;

                cout << "Venta registrada: " << cantidad << " unidades por Q" << precio << " cada una. Subtotal: Q" << subtotal << endl;
                system("pause");
                break;
            }
        }
         // pregunnta si quiere seguir comprando o ya no 
        cout << "¿Desea realizar otra venta? (s/n): ";
        cin >> opc;
    } while (opc == 's' || opc == 'S');

    cout << "Venta total realizada: Q" << totalVenta << endl;
    system("pause");
}

int main(){
	string nombreArchivo = "Clientes.txt"; 
	vector<Cliente> clientes;
	string nombreArchivoProductos = "Productos.txt"; 
    vector<Producto> productos;
    vector<Producto> inventario;
      // Llamas a esta función antes de mostrar el inventario para cargar los datos desde el archivo
    cargarInventarioDesdeArchivo(inventario);
    // Luego puedes mostrar el inventario
    mostrarInventario(inventario);
    string nombreArchivoProveedores = "Provedores.txt";
    vector<Proveedor> proveedores;
    // push_back: es un contenedor dinámico que almacena elementos en una secuencia contigua en la memoria a un vector de manera eficiente
    inventario.push_back({1, "Cargador tipo C", 50.00, "", "06/10/2023", 20});
    inventario.push_back({2, "Baterias para reloj", 25.00, "", "06/10/2023", 20});  
    inventario.push_back({3, "Cargador tipo V8", 50.00, "", "06/10/2023", 30});
    inventario.push_back({4, "Bocina JBL Para Oficina", 300.00, "", "06/10/2023", 40});
    inventario.push_back({5, "Luces Led Para Habitacion", 250.00, "", "06/10/2023", 30});
    inventario.push_back({6, "Cigarros Electrónicos 1000plus", 150.00, "", "06/10/2023", 50});
    
    // Inicio de Menú del Fcturador 
	cout<<"=========================================================================" << endl;
	cout<<"=========================================================================" << endl;
	cout<<"Bienvenido, al Facturador " << endl;
	cout<<" de Empresa Chapina S.A Dedicada a La venta Acesesorios electronicos " << endl;
	cout<<"=========================================================================" << endl;
	cout<<"=========================================================================" << endl;
	cout<<"Que Operacion Quieres Realizar " << endl;
	cout<<"1.Clientes "<< endl;
    cout<<"2.Productos "<< endl;
    cout<<"3.Ventas "<< endl;
    cout<<"4.Inventario "<< endl;
    cout<<"5.Proveedores "<< endl;
	cin>>ope;
	cout<<"============================================" << endl;
	cout<<"============================================" << endl;
	
	switch (ope){
		case 1 :
			// Menu de Registro de clientes 
			system("cls");
			cout<<"================================================== " << endl;
			cout<<"Bienvenido al menu de Clientes " << endl;
			cout<<"================================================== " << endl;
			cout<< "1. Ingresar un Nuevo Cliente "<< endl;
			cout<<"2. Mostar Clientes Registrados " << endl;
			cin>>ope0;
			
			switch(ope0){
				case 1:
					ingresarYGuardarCliente(clientes);  // manda a llamar la funcion 
					break;
					
                case 2:
				  // Llama a la función para mostrar los clientes
                cout << "Clientes registrados:" << endl;
                ifstream archivo("Clientes.txt");
                if (archivo.is_open()) {
                    string linea; // se utilizará para almacenar cada línea leída del archivo.
                    while (getline(archivo, linea)) { // seguirá ejecutándose mientras se puedan leer líneas del archivo. La función getline se utiliza para leer una línea completa del archivo                  
                        cout << linea << endl; //y almacenarla en la variabley almacenarla en la variable
                    }
                    archivo.close(); // Cierra el archivo
                } else {
                    cout << "No se pudo abrir el archivo para lectura." << endl;
                }
                break;	
			} 
		
			 break;
		case 2:
			// menu de Productos  
		int ope1;
		system("cls");
	        cout<<"================================================== " << endl;	
			cout<<"Bienvenido al menu de Productos " << endl;
			cout<<"===================================================" << endl;
			cout<<"Elija Tu Operacion a Realizar " << endl;
			cout<<"1.Ingresar Nuevos Productos. " << endl;
			cout<<"2.Mostrar Productos Ingresados. " << endl;
			cin>>ope1;
			switch (ope1){
     case 1:
     	while(true ){
		 
                    if (ingresarContrasena()) {
                            ingresarYGuardarProductos(productos);
                        } else {
                            cout << "Contraseña Incorrecta. Intentos Agotados." << endl;
                        }
                        break;
                        
                    }
                    case 2:
                 cout<<"========================================================= " << endl; 
				cout<<"Bienvenido al Menú de Productos Ahora Verás Nuestros Productos en Existencia " << endl;
				cout<<"========================================================= " << endl; 
				mostrarInventario(inventario);
                        cout<<" Productos Registrados: " << endl;
                        ifstream archivoProductos("Productos.txt ");
                        if(archivoProductos.is_open()){
                            string linea; // se utilizará para almacenar cada línea leída del archivo.
                            while(getline(archivoProductos, linea)){  // seguirá ejecutándose mientras se puedan leer líneas del archivo. La función getline se utiliza para leer una línea completa del archivo 
                                cout<<linea << endl;//y almacenarla en la variabley almacenarla en la variable
                            }
                            archivoProductos.close();// cierre de archivo
                        }else {
                            cout<<"No se puede abrir el archivo." << endl;
                        }
                        cout << "Opción no válida." << endl;
                         break;
                }
                break;

     	case 3:
     		// menu de ventas 
		system("cls");
		    cout<<"================================================== " << endl;
			cout<<"Bienvenido al menu de Ventas " << endl;
			cout<<"================================================== " << endl;
			  ventas(inventario);
			 break;
		
		case 4:
		// menu de inventario  
		system("cls");
		    cout<<"================================================== " << endl;
			cout<<"Bienvenido al menu de Inventario " << endl;
			cout<<"================================================== " << endl;
			while (true) {
                cout << "1. Ver inventario de productos" << endl;
                cout << "2. Salir" << endl;
                int opcion;
                cin >> opcion;
                switch (opcion) {
        case 1:
        	tablaProductos(inventario);
            break;
        case 2:
            return 0;
            default:
            cout << "Opción no válida. Intente de nuevo." << endl;
            break;
                }
            }
            break;
		case 5: 
		// menu de provedores 
		system("cls");
		    cout<<"================================================== " << endl;
			cout<<"Bienvenido al menu de Proveedores" << endl;
			cout<<"================================================== " << endl;
    while (true) {
        cout << "1.  Registrar nuevo proveedor" << endl;
        cout << "2. Ver Proveedores" << endl;
        cout << "3. Salir " << endl;
        int opc1;
        cin >> opc1;
        switch (opc1){
        	case 1:
        		mostrarProveedores(proveedores);
        		break;
        	case 2:
                cout<<"========================================================= " << endl; 
				cout<<"Proveedores Registrados: " << endl;
				cout<<"========================================================= " << endl; 
				ifstream archivoProveedores("Provedores.txt");
				if(archivoProveedores.is_open()){
				    string linea;
				    while(getline(archivoProveedores,linea)){
				        cout << linea << endl;
				    }
				}else {
				    cout<< "No se pudo abrir el archivo. " << endl; 
				}
				break;
		}
	}	 
	break;
}
	system("pause");
	return 0;	
	
}
