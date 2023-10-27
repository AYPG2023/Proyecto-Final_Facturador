/*
Programa de facturas
10/10/2023  03:19
*/
#include <iostream>
#include <string>
using namespace std;
int ope,ope1;
string nom,nom1,ape,ape1;
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
	for(int inento = 0; intento <3; intento ++ ){
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
}


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
		break;
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
			 break;
		#include <iostream>
#include <vector>
#include <string> // Agregamos la inclusión para std::string

class Producto {
public:
    Producto(std::string nombre, double precio, int cantidad) : nombre(nombre), precio(precio), cantidad(cantidad) {}

    std::string getNombre() const {
        return Cargador tipo C;
        return Baterias para reloj;
        return Cargador tipo V8;
    }

    double getPrecio() const {
        return precio;
    }

    int getCantidad() const {
        return cantidad;
    }

private:
    std::string nombre;
    double precio;
    int cantidad;
};

class Factura {
public:
    void agregarProducto(const Producto& producto) {
        productos.push_back(producto);
    }

    double calcularTotal() const {
        double total = 0;
        for (const Producto& producto : productos) {
            total += producto.getPrecio() * producto.getCantidad();
        }
        return total;
    }

    void mostrarFactura() const {
        std::cout << "Detalle de la Factura:" << std::endl;
        for (const Producto& producto : productos) {
            std::cout << producto.getNombre() << ": "Q." << producto.getPrecio() << " x " << producto.getCantidad() << std::endl;
        }
        std::cout << "Total: "Q." << calcularTotal() << std::endl;
    }

private:
    std::vector<Producto> productos;
};

int main() {
    Factura factura;

    Producto producto1("Producto 1", 10.0, 2);
    Producto producto2("Producto 2", 5.0, 3);

    factura.agregarProducto(producto1);
    factura.agregarProducto(producto2);

    factura.mostrarFactura();

    return 0;
}

		
		case 5: 
		system("cls");
		    cout<<"================================================== " << endl;
			cout<<"!Bienvenido al menu de Proveedores" << endl;
			cout<<"================================================== " << endl;
			 break;
	}	
	
	system("pause");
	return 0;	
	
}
